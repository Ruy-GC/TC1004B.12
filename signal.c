#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle(int signal){
    printf("Señal %d ignorada",signal);
}

int main(){
    //sobreeescribe la señal 2 enviando el entero ala 
    //función que se da como parametro
    signal(2,handle);

    while(1){
        printf("trabajando\n");
        sleep(1);
    }
    return 0;
}