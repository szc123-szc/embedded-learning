#ifndef STR_UTILIZE_H
#define STR_UTILIZE_H

#include <stddef.h>

size_t my_strlen(const char* p);
char* my_strcpy(char* dst, const char* src);
int my_strcmp(const char* s1, const char* s2);
char* my_strcat(char* dst, const char* src);
int my_reverse(char* p, int n);
int my_symmetry(char* p, int n);
int my_symmetry_int(const int* p, int n);

#endif // STR_UTILIZE_H