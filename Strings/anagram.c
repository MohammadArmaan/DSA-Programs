#include<stdio.h>

int main()
{
    char A[] = "decimal";
    char B[] = "medical";
    int i, H[26] = {0};
    
    for(i = 0; A[i]!='\0'; i++)
    {
        H[A[i-97]]+=1;
    }

    for(i = 0; B[i]!='\0'; i++)
    {
        H[A[i-97]]-=1;
        if(H[A[i-97]]<0)
        {
            printf("%s and %s are not Anagram",A,B);
            break;
        }
    }
    if(B[i] == '\0')
    {
        printf("%s and %s are Anagram",A,B);
    }
}