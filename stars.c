#include <ncurses.h>
#include <time.h>

void generateCoordinates(int arr_x[], int arr_y[], int arr_size, int row, int col){
    for(int i =0; i< arr_size; i++){
        
        int x = rand() % row;
        int y = rand() % col;

        for(int j=i;j>0;j--){
            if(arr_x[j] == x && arr_y[j]){
                x = (x+1)%row;
                y = (y+1)%col;
            }
            
        }

        arr_x[i] = x; 
        arr_y[i] = y;
    }
}

int main(){
    
    srand(time(NULL));
    int row, col;
   
    initscr();
    getmaxyx(stdscr,row,col);

    int nbr_stars = (row*col)*0.02;

    if(nbr_stars < 0){return -1;}

    cbreak();
    keypad(stdscr, FALSE);
    noecho();
    curs_set(0);
    
    if(has_colors()){
        start_color();
        init_pair(1, COLOR_WHITE, COLOR_BLACK);
    }

    int arr_x[nbr_stars];
    int arr_y[nbr_stars];

    generateCoordinates(arr_x, arr_y, nbr_stars, row, col);

    while(1){
        attron(COLOR_PAIR(1) | A_BOLD);
        
        for(int i =0;i<nbr_stars;i++){
            mvprintw(arr_x[i],arr_y[i],"*");           
            
        }

        refresh();
        attroff(COLOR_PAIR(1)| A_BOLD);
        nanosleep(1000000,1000000);

        erase();
        refresh();
        curs_set(0);

        nanosleep(500000,500000);
    }
    return 0;
}