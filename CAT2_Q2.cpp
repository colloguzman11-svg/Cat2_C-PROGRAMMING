/*
Name : Colllins Kimani
Reg : PA106/G/29036/25
Description : CAT2_Q2
*/
#include <stdio.h>

int main() {
    float hours, wage, gross_pay, taxes, net_pay;
    
    // Request input from the user
    printf("Enter hours worked in a week: ");
    scanf("%f", &hours);
    
    printf("Enter hourly wage: ");
    scanf("%f", &wage);
    
    // Calculate gross pay
    if (hours <= 40)
        gross_pay = hours * wage;
    else
        gross_pay = (40 * wage) + ((hours - 40) * wage * 1.5);
    
    // Calculate taxes
    if (gross_pay <= 600)
        taxes = 0.15 * gross_pay;
    else
        taxes = (0.15 * 600) + (0.20 * (gross_pay - 600));
    
    // Calculate net pay
    net_pay = gross_pay - taxes;
    
    // Display results
    printf("\nGross Pay: $%.2f", gross_pay);
    printf("\nTaxes: $%.2f", taxes);
    printf("\nNet Pay: $%.2f\n", net_pay);
    
    return 0;
}