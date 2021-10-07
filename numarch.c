#include <unistd.h>
#include <stdio.h>

int main(){
    int fd[2];
    //crea tubería para la conexión
    pipe(fd);
    int pid = fork();

    if(pid == 0){
        //cierro entrada estandar
        close(0);
        //dup de la entrada del pipe
        dup(fd[0]);
        close(fd[1]);
        //parametros: archivo a ejectuar,nombre,argumentos del programa
        execlp("wc","wc","-l",NULL);
    }else{
        //cierro salida estandar
        close(1);
        //dup de la salida del pipe
        dup(fd[1]);
        close(fd[0]); 
        execlp("ls","ls",NULL);
    }
    
    return 0;
}