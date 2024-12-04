#include <ncurses.h>
#include <time.h>

void generateCoordinates(int *px, int *py, int arr_size, int row, int col){
    
    int aux_x;
    int aux_y;
    for(int i =0; i< arr_size; i++){
        int x = rand() % row;
        int y = rand() % col;
        
        aux_x = px;
        aux_y = py;
        for(int j=i;j>0;j--){
            if(*px == x){x++;}
            if(*py==y){y++;}
        }
        *px = x;
        *py = y;
        px++;
        py++;
    }
}

int main(){
    
    srand(time(NULL));
    int row, col;
   
    initscr();
    getmaxyx(stdscr,row,col);

    int area = row*col;
    int nbr_stars = (area*0.05)/7;

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


    while(1){
        generateCoordinates(&arr_x, &arr_y, nbr_stars, row, col);

        attron(COLOR_PAIR(1));
        attron(A_BOLD);
        attron(A_BLINK);
        for(int i =0;i<nbr_stars;i++){
            mvprintw(arr_x[i],arr_y[i],"*");           
        }
        refresh();
        attroff(COLOR_PAIR(1));
        attroff(A_BOLD);
        attroff(A_BLINK);
        
        earese();
        refresh();
        curs_set(0);
    }

    getch();
    endwin();

    return 0;
}