#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#define NUM_THREADS 2

void *print_numbers(void *arg)
{
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n",i);
    }
    return NULL;
}

void *print_alphabets(void *arg)
{
    for (char c = 'A'; c <= 'J'; c++)
    {
        printf("%c\n",c);
    }
    return NULL;
}

int main()
{
    pthread_t thread1,thread2;
    pthread_create(&thread1,NULL,&print_numbers,NULL);
    pthread_create(&thread2,NULL,&print_alphabets,NULL);
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    return 0;
}