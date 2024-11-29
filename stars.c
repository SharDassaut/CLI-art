#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>


int main(){
    printf("\033[40m\033[37m"); // Set background to black and text to
    
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    int c = w.ws_col;
    int r = w.ws_row+15;

    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            if(j%13==0){printf("*");}
            else{printf(" ");}
        }
    }
    printf("\n");

    return 0;
}