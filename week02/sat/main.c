#include <stdio.h>
#include "command.h"
int main(void)
{
	char buf[64];
	printf("LED register CLI\n");
	printf("Commands: ON n | OFF n | TOGGLE n | SHOW   (n = 0..7)\n");
	printf("Quit: Ctrl+Z then Enter (Windows) / Ctrl+D (Linux)\n");
	while (1)
	{
		printf(">");
		if (fgets(buf, sizeof(buf), stdin) == NULL)//stdin意思是键盘输入
		{
			break; /* 输入结束（EOF）就退出 */
		}
		if (comexecute(buf) == 0)
		{
			printf("OK\n");
		}
		else
		{
			printf("ERROR\n");
		}
			
	}
	return 0;
}