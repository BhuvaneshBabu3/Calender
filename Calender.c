
#include <stdio.h>
#include <stdlib.h>
#include "calen.h"

int main()
{
    int space,numofdays,year,month,date,month1,year1,num,space1;
    int ch,ch1;
    printf("Enter the year");
    scanf("%d",&year);
    month=0;
    space=calcday(1,month+1,year);
    numofdays=monthdays(month,year);

    int *a=printcalender(month,year,space,numofdays);
    space=a[0];
    month=a[1];
    year=a[2];
//    printf("\n%d,%d,%d\n",space,month,year);

    while (1)
    {
        printf("\n1-uparrow 2-downarrow 3-leftarrow 4-rightarrow 5-go to date: ");
        //ch = 'a';
        scanf("%d",&ch);
        //printf("%c",ch);
        switch (ch) {
            case 1:
                year=year-1;
                space=calcday(1,month+1,year);
                numofdays=monthdays(month,year);
                int *b=printcalender(month,year,space,numofdays);
                space=b[0];
                month=b[1];
                year=b[2];
                break;
            case 2:
                year=year+1;
                space=calcday(1,month+1,year);
                numofdays=monthdays(month,year);
                int *c=printcalender(month,year,space,numofdays);
                space=c[0];
                month=c[1];
                year=c[2];
                break;
            case 3:
                month++;
                if (month>=12)
                {
                    month=0;
                    year++;
                }
                space=calcday(1,month+1,year);
                numofdays=monthdays(month,year);
                int *d=printcalender(month,year,space,numofdays);
                space=d[0];
                month=d[1];
                year=d[2];
                break;
            case 4:
                month--;
                if (month<0)
                {
                    month=12;
                    year--;
                    space=calcday(1,month,year);
                    numofdays=monthdays(month-1,year);
                    int *e=printcalender(month-1,year,space,numofdays);
                    space=e[0];
                    month=e[1];
                    year=e[2];
                } else{
                    space=calcday(1,month+1,year);
                    numofdays=monthdays(month,year);
                    int *e=printcalender(month,year,space,numofdays);
                    space=e[0];
                    month=e[1];
                    year=e[2];
                }
                break;
            case 5:
                printf("\n Enter date ,month ,year(dd/mm/yyyy) :");
                scanf("%d/%d/%d",&date,&month1,&year1);
                space1=calcday(1,month1,year1);
                numofdays=monthdays(month1-1,year1);
                if (month1==2)
                {
                    if (year1%400==0 || (year1%4==0 && year1%100!=0))
                    {
                        Printcalender(month1-1,year1,space1,numofdays,date);
                    }
                    else
                    {
                        printf("\n Enter correct date....\n");
                    }
                }
                else{
                    Printcalender(month1-1,year1,space1,numofdays,date);
                }

                break;
            case 6:
                exit(0);
            default:
                break;
        }
    }

    return 0;
}
