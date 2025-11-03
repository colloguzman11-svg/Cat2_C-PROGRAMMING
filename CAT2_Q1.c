/*
NAME:Collins Kimani
REG NO.PA106/G/29036/25
DESCRIPTION:CAT2_Q1
*/
#include <stdio.h>

#include <stdio.h> 

int main() {
    int i, j;
    int scores[4][2] = {
        {65, 92},
        {84, 72},
        {35, 70},
        {59, 67}
    };
    
printf(" Elements of the 2D array are: \n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d ", scores[i][j]);
        }
        printf("\n"); 
    }

    return 0;
}
