//calen.h


#ifndef TRAINIG_CALEN_H
#define TRAINIG_CALEN_H
#include <stdlib.h>
#include <windows.h>
#include <dos.h>
#include <dir.h>
WORD wColor;



int calcday(int date,int month,int year)
{
    int temp[]={0,3,2,5,0,3,5,1,4,6,2,4};//Tomohiko Sakamoto’s Algorithm.
    year -= month<3;
    return (year+(year/4)-(year/100)+(year/400)+temp[month-1]+date)%7;
}

int monthdays(int num, int year)
{
    if (num == 0 || num == 2 || num == 4 || num==6 || num==7 || num==9 || num==11)
        return (31);

    if (num==1) {
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
            return (29);
        else
            return (28);
    }

    if (num==3 || num==5 || num==8 || num==10)
        return (30);
}

char* monthname(int day_num)
{
    char *month = NULL;
    if (day_num==0)
    {
        month= "January";
    }
    else if (day_num==1)
    {
        month= "feburary";
    }
    else if (day_num==2)
    {
        month= "march";
    }
    else if (day_num==3)
    {
        month= "april";
    }
    else if (day_num==4)
    {
        month= "may";
    }
    else if (day_num==5)
    {
        month= "june";
    }
    else if (day_num==6)
    {
        month="july";
    }
    else if (day_num==7)
    {
        month="august";
    }
    else if (day_num==8)
    {
        month="september";
    }
    else if (day_num==9)
    {
        month="october";
    }
    else if (day_num==10)
    {
        month="november";
    }
    else if (day_num==11)
    {
        month="december";
    }
    return month;
}

char* print(int day_num)
{
    char *month = NULL;
    if (day_num==1)
    {
        month= "monday";
    }
    else if (day_num==2)
    {
        month= "tueday";
    }
    else if (day_num==3)
    {
        month= "wednesday";
    }
    else if (day_num==4)
    {
        month= "thursday";
    }
    else if (day_num==5)
    {
        month= "friday";
    }
    else if (day_num==6)
    {
        month= "saturday";
    }
    else
    {
        month="sunday";
    }
    return month;
}



void SetColor(int ForgC)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    //We use csbi for the wAttributes word.
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        //Mask out all but the background attribute, and add in the forgournd color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
}

int* printcalender(int month,int year,int space,int numberofdays)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    static int a[10];
    int k,temp;
    temp=space;
    SetColor(9);
    printf("******************************************************************");
    SetColor(5);
    printf("\n%d\n",year);
    printf("\n  \t\t\t%s\n",monthname(month));
    printf("\tsun");
    printf("\tMon\tTue\tWed\tThu\tFri\tSat\n");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    WORD saved_attributes;
    wColor = (csbi.wAttributes & 0xF1) + (90 & 0x0F);

    for (k = 0; k < space; k++)
    {
        printf("\t");
    }
    for (int j = 1; j <= numberofdays; j++) {
        if(k==0)
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            printf("\t %d", j);
            SetConsoleTextAttribute(hConsole, saved_attributes);
        }
        else
        {
            SetConsoleTextAttribute(hConsole,0x3);
            printf("\t %d", j);
            SetConsoleTextAttribute(hConsole, saved_attributes);
        }

        if (++k > 6) {
            k = 0;
            printf("\n");
        }
    }


    printf("\n");
    SetColor(9);
    printf("******************************************************************");
    SetColor(0);
    space = k;
    a[0]=temp;
    a[1]=month;
    a[2]=year;
    return a;
}

void Printcalender(int month,int year,int space,int numberofdays,int pos)
{
    int k,inc=0;
    SetColor(9);
    printf("******************************************************************");
    SetColor(5);
    printf("\n%d\n",year);
    printf("\n  \t\t\t%s\n",monthname(month));
    printf("\tsun");
    printf("\tMon\tTue\tWed\tThu\tFri\tSat\n");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    WORD saved_attributes;

    for (k = 0; k < space; k++)
    {
        printf("\t");inc++;
    }
    for (int j = 1; j <= numberofdays; j++) {
        inc++;
        if(k==0 && j!=pos)
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            printf("\t %d", j);
            SetConsoleTextAttribute(hConsole, saved_attributes);
        }
        else if(k!=0 && j!=pos)
        {
            SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN);
            printf("\t %d", j);
            SetConsoleTextAttribute(hConsole, saved_attributes);
        }
        if(j==pos)
        {
            SetConsoleTextAttribute(hConsole,FOREGROUND_BLUE);
            printf("\t %d", j);
            SetConsoleTextAttribute(hConsole, saved_attributes);
        }
        if (++k > 6) {
            k = 0;
            printf("\n");
        }
    }


    printf("\n");
    SetColor(9);
    printf("******************************************************************");
    SetColor(0);
    space = k;
}

#endif 
