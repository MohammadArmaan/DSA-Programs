#include<stdio.h>
#include<string.h>

int main()
{
    char s[] = "How are you";
    int i, vcount = 0, ccount = 0;
    for(i=0; s[i]!='\0'; i++)
    {

        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
        {
            vcount++;
        }

        else if((s[i]>=65 && s[i]<=90)||(s[i]>=97 && s[i]<=122))
        {
            ccount++;
        }
    }
    printf("Vowel Count: %d\n Consonant: Count %d\n",vcount,ccount);

    return 0;

}