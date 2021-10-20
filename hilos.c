#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define NUM_THREADS 10
int saldo;
//crea un lock y lo inicializa para que pueda abrir y cerrar
pthread_mutex_t lockSaldo = PTHREAD_MUTEX_INITIALIZER;


//codigo que se corre en cada hilo
void *printHola(void *arg){
    int saldolocal = saldo;

    //se encierra entre las funciones lock el codigo que se quiera proteger
    pthread_mutex_lock(&lockSaldo);
    saldolocal += 100;
    saldo = saldolocal;
    pthread_mutex_unlock(&lockSaldo);
    pthread_exit(NULL);
}

int main(){

    //arreglo de hilos
    pthread_t threads[NUM_THREADS];
    saldo = 0;

    for(int i = 0; i<NUM_THREADS; i++){
        //crea los hilos de la referencia al arreglo
        pthread_create(&threads[i],NULL,printHola,NULL);   
    }
    for(int i = 0; i<NUM_THREADS; i++){
        //al no llevar &  solo estamos indicando que vanos a esperar el hilo
        //null se refiere a que no va a regresar nada
        pthread_join(threads[i],NULL);   
    }

    printf("Saldo: %d\n",saldo);
    //hace que el proceso principal espere a los hilos para terminar
    pthread_exit(NULL);
}