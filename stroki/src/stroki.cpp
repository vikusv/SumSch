#include <stdio.h> 
#include <string.h>
#include "str_func.h"

#define RED_TEXT   "\033[0;31m" 
#define GREEN_TEXT "\033[0;32m"
#define WHITE_TEXT "\033[0m\n"
#define FIELDWEIGHT -11

void TestPuts(const char *str);
void TestStrlen(const char *str);
void TestStrlenAlt(const char *str);
void TestStrcpy(const char *str);
void TestStrncpy(const char *str, size_t n);
void TestStrcat(const char *str);
void TestStrcatAlt(const char *str);
void TestStrncat(char *str, size_t n);
void TestStrchr(const char *str, int letter);
void TestStrcmp(const char *str1, const char *str2, const char *str3);
void resultPrint(const char *funcName, const char *arr);

int main (void)
{    
    const char *str = "This is a sample string.";
    const char *str2 = "This is a sample string.";
    const char *str3 = "This is not a sample string.";
    char stradd[] = "The end.";
    size_t n = 9;
    int letter = 's';

    TestPuts(str);
    TestStrlen(str);
    TestStrlenAlt(str);
    TestStrcpy(str);
    TestStrncpy(str, n);
    TestStrcat(str);
    TestStrcatAlt(str);
    TestStrncat(stradd, n);
    TestStrchr(str, letter);
    TestStrcmp(str, str2, str3);
               
    return 0;
}

void TestPuts(const char *str)
{
    printf("%*s", FIELDWEIGHT, "Puts:");
    Puts(str);
    printf("%*s", FIELDWEIGHT, "puts:");
    puts(str);
}

void TestStrlen(const char *str)
{
    printf("%*s%zu.\n", FIELDWEIGHT, "Strlen:", Strlen(str));
    printf("%*s%zu.\n", FIELDWEIGHT, "strlen:", strlen(str));
}

void TestStrlenAlt(const char *str)
{
    printf("StrlenAlt: %zu.\n", StrlenAlt(str));
    printf("%*s%zu.\n", FIELDWEIGHT, "strlen:", strlen(str));
}

void TestStrcpy(const char *str)
{
    char arr1[40] = "";
    char arr2[40] = "";
    Strcpy(arr1, str);
    strcpy(arr2, str);
    resultPrint("Strcpy", arr1);
    resultPrint("strcpy", arr2);
}

void TestStrncpy(const char *str, size_t n)
{
    char arr1[40] = "";
    char arr2[40] = "";
    Strncpy(arr1, str, n);
    strncpy(arr2, str, n);
    resultPrint("Strncpy", arr1);
    resultPrint("strncpy", arr2);
}

void TestStrcat(const char *str)
{
    char arr1[40] = "";
    char arr2[40] = "";
    Strcat(arr1, str);
    strcat(arr2, str);
    resultPrint("Strcat", arr1);
    resultPrint("strcat", arr2);
}

void TestStrcatAlt(const char *str)
{
    char arr1[40] = "";
    char arr2[40] = "";
    StrcatAlt(arr1, str);
    strcat(arr2, str);
    resultPrint("StrcatAlt", arr1);
    resultPrint("strcat", arr2);
}

void TestStrncat(char *str, size_t n)
{
    char arr1[40] = "";
    char arr2[40] = "";
    Strncat(arr1, str, n);
    strncat(arr2, str, n);
    resultPrint("strncat", arr1);
    resultPrint("strncat", arr2);
}

void TestStrchr(const char *str, int letter)
{
    printf("%*s%ld.\n", FIELDWEIGHT, "Strchr:", (Strchr(str, letter) - str));
    printf("%*s%ld.\n", FIELDWEIGHT, "strchr:", (strchr(str, letter) - str));
}

void TestStrcmp(const char *str1, const char *str2, const char *str3)
{
    printf("%*s%d, %d.\n", FIELDWEIGHT, "Strcmp:", Strcmp(str1, str2), Strcmp(str1, str3));
    printf("%*s%d, %d.\n", FIELDWEIGHT, "strcmp:", strcmp(str1, str2), strcmp(str1, str3));
}

void resultPrint(const char *funcName, const char *arr)
{
    printf("%*s\"%s\"\n", FIELDWEIGHT, funcName, arr);
}
