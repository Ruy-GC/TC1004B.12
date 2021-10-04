#include <stdio.h>
#include <unistd.h>

int main(){
    int i = 0;
    while(i<2){
        //fork crea un proceso hijo
        int pid = fork();
        //al clonar el hijo se ejecuta desde la linea desdpués del fork evitando ciclos infinitos
        if(pid == 0){
            printf("Proceso hijo\n");
        }else{
            printf("Proceso padre, mi hijo es %d\n",pid);
        }
        i++;
    }
    return 0;  
}