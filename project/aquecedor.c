#include <pthread.h>
#include <limits.h>

void loopzao(){
    int i;
    while(1){
        if(i< INT_MAX){
            i++;
        }else 
            i=0;
    }
}

int main (){
    pthread_t threads;
    pthread_create(&threads, NULL, (void *)loopzao, NULL);
    pthread_create(&threads, NULL, (void *)loopzao, NULL);
    pthread_create(&threads, NULL, (void *)loopzao, NULL);
    pthread_create(&threads, NULL, (void *)loopzao, NULL);
    pthread_join(threads, NULL);
    return 0;
}