#include<stdio.h>

void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void prem(char s[], int l, int h)
{
    int i;
    if(l == h)
    {
        printf("%s\n",s);
    }

    else
    {
        for(i = l; i<=h; i++)
        {
            swap(&s[l], &s[i]);
            prem(s, l+1, h);
            swap(&s[l], &s[i]);
        }
    }
}

int main()
{
    char s[] = "ABC";
    int l = 0;
    int h = 2;
    prem(s, l, h);

    return 0;
}