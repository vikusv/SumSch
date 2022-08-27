#include "str_func.h"

int Puts(const char *str)
{
    int result = 0;
    while (*(str))
    {
        result = putc(*(str++), stdout);
        if (result == EOF)
        {
            return EOF;
        }
    }
    putc('\n', stdout);
    if (result == EOF)
    {
        return EOF;
    }  

    return result;  
}

size_t Strlen(const char *str) 
{
    size_t count = 0;
    for (; str[count] != '\0'; count++);
    return count;
}

size_t StrlenAlt(const char *str) 
{
    const char *step = str;
    while (*(++step));
    return (step - str);
}

char *Strcpy(char *arr, const char *str)
{
    char *arrstart = arr;
    unsigned int count = 0;
    for (; str[count] != '\0'; count++)
    {
        arr[count] = str[count];
    }
    return arrstart;
}

char *Strncpy(char *arr, const char *str, size_t size)
{
    char *arrstart = arr;
    for (unsigned int count = 0; ((count < size) && (str[count] != '\0')); count++) //
        arr[count] = str[count];
    arr[size] = '\0';

    return arrstart;
}

char *Strcat(char *arr, const char *str) //strcat_alt
{
    char *arrstart = arr;
    unsigned int count = 0;
    for (; arr[count] != '\0'; count++);
    for (unsigned int i = 0; str[i] != '\0'; i++, count++)
        arr[count] = str[i];
    arr[count] = '\0';

    return arrstart;
}

char *StrcatAlt(char *arr, const char *str) //strcat_alt
{
    char *arrstart = arr;
    while (*(arr))
    {
        arr++;
    }
    while (*(str))
    {
        (*(arr++)) = (*(str++));
    }
    (*(arr)) = '\0';

    return arrstart;
}

char *Strncat(char *arr, char *str, size_t size)
{
    char *arrstart = arr;
    unsigned int count = 0;
    for (; arr[count] != '\0'; count++);
    for (unsigned int i = 0; (str[i] != '\0' && i < size); i++, count++)
        arr[count] = str[i];
    arr[count] = '\0';

    return arrstart;
}