#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#include <time.h>

bool isPrime(int n);

int main()
{
    FILE *fp;
    int upperLimit;
    int *primeNumbers;
    int primeCounter;
    printf("Please Enter a number:\n");
    scanf("%d",&upperLimit);

    primeNumbers = malloc(upperLimit * sizeof(int));

    for (int i = 2; i < upperLimit; i++)
    {
        if (isPrime(i))
        {
            primeNumbers[primeCounter] = i;
            primeCounter++;
        }
    }

    fp = fopen("primes.txt","w");
    for (int i = 0; i < primeCounter; i++)
    {
        fprintf(fp,"%d\n",primeNumbers[i]);
    }
    fclose(fp);
    return 0;

}

bool isPrime(int n)
{
    if(n <= 1)
    {
        return false;
    }
    if(n != 2 && n%2==0)
    {
        return false;
    }
    for (int i = 3; i <= sqrt(n); i++)
    {
        if (n%i == 0)
        {
            return false;
        }
    }
    return true;
}