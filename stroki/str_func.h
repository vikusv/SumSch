#ifndef STR_FUNC
#define STR_FUNC

#include <stdio.h>
int Puts(const char *str);
size_t Strlen(const char *str);
size_t StrlenAlt(const char *str);
char *Strcpy(char *arr, const char *str);
char *Strncpy(char *arr, const char *str, size_t size);
char *Strcat(char *arr, const char *str);
char *StrcatAlt(char *arr, const char *str);
char *Strncat(char *arr, char *str, size_t size);

#endif //STR_FUNC
