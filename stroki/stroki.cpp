#include <stdio.h> 
#include "str_func.h"


/*
причесать
возвращаемые значения        +
переписать StrlenAlt         +
написать fgets (исп. fgetc)  
написать strdup (calloc)
написать тесты
*/


int main (void)
{    
    const char *str = "string string";
    char a[20]="String a";
    char b[20]={'S','t','r','i','n','g',' ','b','\0'};  
    char str1[]="Sample string sample string";
    char str2[40];
    char str3[40];
    char str4[]= "To be or not to be";
    char str5[40];
    char str6[40];
    char str7[80];
    char str8[20];
    char str9[20];
   // char str9[100];



    Strcpy(str2,str1);
    Strcpy(str3,"copy successful");
    Strncpy(str5,str4,sizeof(str5));
    Strncpy(str6,str4,5);
    Strcpy(str7,"these ");
    StrcatAlt(str7,"strings ");
    Strcat(str7,"are ");
    Strcat(str7,"concatenated.");
    Strcpy(str8,"To be ");
    Strcpy(str9,"or not to be");
    Strncat(str8, str9, 6);
      
 
    Puts(str);
    Puts(a);
    Puts(b);
    printf("Длина строки a = %zu \n",StrlenAlt(a));
    printf("Длина строки b = %zu \n",Strlen(b));
    printf("Длина строки b = %zu \n",Strlen(str));
    printf("%s\n", str2);
    printf("%s\n", str3);
    printf("%s\n", str5);
    printf("%s\n", str6);
    printf("%s\n", str7);
    printf("%s\n", str8);
               
    return 0;
}
