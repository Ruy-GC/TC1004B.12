#include <unistd.h>
#include <stdio.h>
#include <ctype.h>

int main(){
    char c;
    char upperC;
    int n;

    do{
        //STDIN_FILENO standard input, variable, chars
        n = read(STDIN_FILENO,&c,1);

        upperC = toupper(c);

        //STDOUT_FILENO standard output, variable, chars
        write(STDOUT_FILENO,&upperC,1);

    }while(n!= 0);
  
    return 0;
}