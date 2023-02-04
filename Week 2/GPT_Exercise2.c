// Create a program that creates a specified number of threads, 
// each of which increments a shared global variable. 
// Use pthread_join() to ensure that all threads have completed before 
// printing the final value of the global variable.

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int shared_variable = 0;
pthread_mutex_t g_Mutex = PTHREAD_MUTEX_INITIALIZER;

void *increment_variable(void *arg)
{
    int *p = (int*) arg;
    int number = *p;
    for (int i = 0; i < number; i++)
    {
        pthread_mutex_lock(&g_Mutex);
        shared_variable++;
        pthread_mutex_unlock(&g_Mutex);
    }
    return NULL;
}

int main(int argc,char *argv[])
{
    int threadNumber = atoi(argv[1]);
    pthread_t threads[threadNumber];
    int increments[threadNumber];
    pthread_mutex_init(&g_Mutex,NULL);
    for (int i = 0; i < threadNumber; i++)
    {
        increments[i] = 100;
        pthread_create(&threads[i],NULL,&increment_variable,&increments[i]);
    }
    for (int i = 0; i < threadNumber; i++)
    {
        pthread_join(threads[i],NULL);
    }

    pthread_mutex_destroy(&g_Mutex);
    printf("The final value is %d\n",shared_variable);
    return 0;
}