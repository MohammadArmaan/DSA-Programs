#include<stdio.h>
#include<stdlib.h>

struct Day
{
    char *dayName;
    int date;
    char *activityDescription;
};

struct Day *createCalender()
{
    struct day * calender = (struct day*) malloc(7 * sizeof(struct Day));
    return calender;
}

void readData(struct Day *calender)
{   
    for(int i=0; i<7; i++)
    {
        printf("Enter details for Day %d:\n",i+1);
        calender[i].dayName = (char*)malloc(20 * sizeof(char));
        calender[i].activityDescription = (char*)malloc(100 * sizeof(char));

        printf("Enter Day Name: ");
        scanf("%s", calender[i].dayName);

        printf("Enter Date: ");
        scanf("%d",&calender[i].date);

        printf("Enter Activity Description: ");
        scanf(" %[^\n]", calender[i].activityDescription);
    }
}

void displayCalender(struct Day * calender)
{
    printf("\n Calender:\n");
    for(int i=0; i<7; i++)
    {
        printf("Day %d:%s, Date: %d Activity : %s\n",i+1,calender[i].dayName, calender[i].date, calender[i].activityDescription);

    }
}

void freeMemory(struct Day *calender)
{
    for(int i=0; i<7; i++)
    {
        free(calender[i].dayName);
        free(calender[i].activityDescription);
    }
    free(calender);
}

int main(){
    struct Day *calender = createCalender();
    readData(calender);
    displayCalender(calender);
    freeMemory(calender);
    return 0;

}