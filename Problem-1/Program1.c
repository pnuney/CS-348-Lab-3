#include <stdio.h>
#define MONTHS 12


char*months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
float sales[12];

double min, max, sum = 0;

int i;
int n;


int sales_report(float sales[]) {
    printf("\nMonthly sales report for 2022:\n");
    printf("\nMonth     Sales\n");
    for (i=0; i<12; i++) {
        printf("\n%s   $%.2f", months[i], sales[i]);
    }
    return 0;
}

void sales_summary(float sales [MONTHS]) {
    min=max= sales[0];
    for(i=1; i<12; i++) {
        if(min>sales[i])
            min=sales[i];
        if (max<sales[i])
            max=sales[i];
    }
    printf("\n\nSales Summary: \n");
    printf("\nMinimum sales:   $%.2lf", min);
    printf("\nMaximum sales:   $%.2lf", max);

    for(i = 0; i < 12; i++) {
        sum += sales[i];
    }

    printf("\nAverage Sales:  $%.2lf", (sum/12));
}

void six_month_report(float sales[MONTHS]) {
    printf("\n\n6 Month Moving Average Report: \n\n");
    float sum1;
    int j;
    for (i=0; i<7; i++) {
        for (j=0; j<6; j++) {
            sum1 += sales[j+i];
        }
        if (i == 0) {
            printf("January  -  June ");
        }
        if (i == 1) {
            printf("February -  July ");
        }
        if (i == 2) {
            printf("March  -  August ");
        }
        if (i == 3) {
            printf("April  -  September ");
        }
        if (i == 4) {
            printf("May  -  October ");
        }
        if (i == 5) {
            printf("June  -  November ");
        }
        if (iv== 6) {
            printf("July  -  December ");
        }

        printf("  $%.2f \n", sum1/6);
        sum1 = 0;
    }
}

void high_to_low_report(float sales[MONTHS]) {
    printf("\nSales Report (High to Low): \n");
    printf("\nMonth      Sales\n");
    int j;
    double temp;
    char * temp2;

    for (i=0; i<12; i++) {
        for (j=i+1; j<12; j++) {
            if (sales[i] < sales[j]) {
                temp = sales[i];
                temp2 = months[i];
                sales[i] = sales[j];
                months[i] = months[j];
                sales[j] = temp;
                months[j] = temp2;
            }
        }
    }

    for (i=0; i<12; i++) {
        printf("\n%s   $%.2f", months[i], sales[i]);
    }
}

int main()
{
    FILE* my_file;
    int i;

    my_file = fopen("samples.txt", "r");

    if (NULL == my_file) {
        printf("This file can't be opened \n");
        return 1;
    }

    for (i = 0; i < MONTHS; i++) {
        fscanf(my_file, "%f", &sales[i]);
    }
    fclose(my_file);

    sales_report(sales);
    sales_summary(sales);
    six_month_report(sales);
    high_to_low_report(sales);
}
