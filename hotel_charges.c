// This file manages hotel data, sorting and filtering by grade and average charge.
#include <stdio.h>

struct hotel 
{
    char name[50];
    char address[50];
    char grade;
    float charge_avg;
    int no;
}h[50],temp;

void sort(int n)
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n-i-1; j++)
        {
            if(h[j].charge_avg > h[j+1].charge_avg)
            {
                temp=h[j];
                h[j]=h[j+1];
                h[j+1]=temp;
            }
        }
    }
}

void disp(char g,int n)
{
    printf("name\taddress\tgrade\tavg charge\tno of rooms\n");
    for (int i=0; i<n; i++)
    {
        if(h[i].grade==g)
        {
            printf("%s\t%s\t%c\t%f\t%d\n",h[i].name,h[i].address,h[i].grade,h[i].charge_avg,h[i].no);
        }
    }
}

void max_charge(float max,int n)
{
    printf("name\taddress\tgrade\tavg charge\tno of rooms\n");
    for (int i=0; i<n; i++)
    {
        if (h[i].charge_avg <= max)
        {
            printf("%s\t%s\t%c\t%f\t%d\n",h[i].name,h[i].address,h[i].grade,h[i].charge_avg,h[i].no);
        }
    }
}

void main()
{
    int n,i;
    char g;
    float max;
    printf("Enter the no.of hotels: ");
    scanf("%d",&n);
    for (i=0; i<n; i++)
    {
        printf("Enter name: ");
        scanf("%s",h[i].name);
        printf("Enter address: ");
        scanf("%s",h[i].address);
        printf("Enter grade: ");
        getchar();
        scanf(" %c",&h[i].grade);
        printf("Enter avg charge: ");
        scanf("%f",&h[i].charge_avg);
        printf("Enter the no: ");
        scanf("%d",&h[i].no);
    }
getchar();
printf("\n");
printf("Enter the grade to search for: ");
scanf(" %c",&g);
printf("\n");
sort(n);
disp(g,n);
printf("\n");
printf ("Enter the charge avg: ");
scanf("%f",&max);
max_charge(max,n);
}