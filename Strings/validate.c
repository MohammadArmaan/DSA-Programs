#include<stdio.h>
#include<string.h>

int valid(char *s)
{
    int i;
    for(i = 0; s[i]!='\0'; i++)
    {
        if(!(s[i]>=65 && s[i]<=90) && !(s[i]>=97 && s[i]<=122) && !(s[i]>=48 && s[i]<=57))
        {
            return -1;
        }

    }
    return 1;
}

int main()
{
    char *s = "Armaan@7786";
    if(valid(s) == 1)
    {
        printf("%s is Valid String",s);
    }

    else
    {
        printf("%s is Invalid String",s);
    }
}