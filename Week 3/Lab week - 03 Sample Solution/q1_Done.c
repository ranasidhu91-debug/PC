#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#include <time.h>

bool isPrime(int n);

int main()
{
    int upperLimit;
    int *primeNumbers;
    printf("PLease Enter a number:\n");
    scanf("%d",&upperLimit);

    primeNumbers = malloc(upperLimit * sizeof(int));

    
}