#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "led.h"
#include "command.h"
#define WORD_MAX 8
typedef enum
{
	ST_CMD,
	ST_GAP,
	ST_NUM,
	ST_ERR
}parse_state_t;

int comexecute(const char* line)
{
	parse_state_t sat = ST_CMD;
	char word[WORD_MAX] = { 0 };
	int word_len = 0;
	int num = 0;
	int has_digit = 0;
	int i;
	char c;
	for (i = 0; line[i] != '\n'&&line[i]!='\0'&&line[i]!='\r'; i++)
	{
		c = line[i];
		switch (sat)
		{
		case ST_CMD:
			if (isalpha((unsigned char)c))//a-z/A-Z
			{
				if (word_len < WORD_MAX-1)
				{
					word[word_len++] = (char)toupper((unsigned char)c);
				}
				else
					sat = ST_ERR;
			}
			else if (c == ' ')
			{
				sat = ST_GAP;
			}
			else
				sat = ST_ERR;
			break;
		case ST_GAP:
			if (c == ' ')
			{
				sat = ST_GAP;
			}
			else if (isdigit((unsigned char)c))
			{
				num = c - '0';
				has_digit = 1;
				sat = ST_NUM;
			}
			else
				sat = ST_ERR;
			break;
		case ST_NUM:
			if (isdigit((unsigned char)c))
			{
				num = num * 10 + (c - '0');
				if (num >= LED_COUNT)
				{
					sat = ST_ERR;
				}	
			}
			else
				sat = ST_ERR;
			break;
		case ST_ERR:
			break;
		}
		if (sat == ST_ERR)
		{
			return - 1;
		}
	}
	if (strcmp(word, "SHOW") == 0)
	{
		if (has_digit)
		{
			return -1;
		}
		else
		{
			led_show();
			return 0;
		}
	}
	if (!has_digit) 
	{
		return -1; /* ON/OFF/TOGGLE 必须带数字；空行、乱写的单词也在这里被拦下 */
	}
	if (strcmp(word, "ON") == 0)
	{
		return led_on((uint8_t)num);
	}
	if (strcmp(word, "OFF") == 0)
	{
		return led_off((uint8_t)num);
	}
	if (strcmp(word, "TOGGLE") == 0)
	{
		return led_tog((uint8_t)num);
	}
	return -1;
}
