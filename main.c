#include <conio.h>
#include <stdio.h>

#include <unistd.h>

#define max_y 25
#define max_x 80

#define max_length_rocket 3



void clrscr(void)
{
//char a[80];
//    printf("\e[1;1H\e[2J");
//printf("\033[2J"); /* Clear the entire screen. */
//printf("\033[0;0f\n"); /* Move cursor to the top left hand corner

}

//void cross_and_toe_display(int cross_pos, int toe_pos);

struct movable_element{
    int x, y;
    int length;
} l_pl, r_pl, ball;



void display(char* screen){
    clrscr();
    usleep(100000);
    printf("%s", screen);
}


void input()
{
    char c = '\0';
    while(kbhit()) {
        c = getch();
/*        printf(" %d - %c\n", c, c);
        sleep(1);*///97        65
        if ((int)c == 97 || (int)c == 65)
            if (l_pl.y > 1) l_pl.y--;
//                122        90
        if (c == 'z' || c == 'Z')
            if (l_pl.y < max_y - l_pl.length - 1) l_pl.y++;
//                107        75
        if (c == 'k' || c == 'K')
            if (r_pl.y > 1) r_pl.y--;
//                109        77
        if (c == 'm' || c == 'M')
            if (r_pl.y < max_y - r_pl.length - 1) r_pl.y++;

    }
}

int paint_rocket(int x, int y){
    if (x == l_pl.x && ( y < (l_pl.y + l_pl.length) && y >= l_pl.y))
          return 1;
    if (x == r_pl.x && ( y < (r_pl.y + r_pl.length) && y >= r_pl.y))
          return 1;
    return 0;

}



int main() {

    l_pl.x = 2;
    r_pl.x = max_x - 3;
    l_pl.y = r_pl.y = ball.y= max_y/2;
    l_pl.length = r_pl.length = 3;
    ball.x = max_x/2;
    ball.length = 1;

    // У мячика ball элемент length будет работать как направление движения
    //
    //         0
    //         ↑
    //    3 ←  @  → 1             - это мячик и значения length в зависимости он направления движенияы
    //         ↓
    //         2
    char screen[25][81];
//    int cross_position, toe_position;
//    printf("Enter the \"X\" and \"O\" position:");

//    if (scanf("%d%d", &cross_position, &toe_position) != 2 || cross_position < 0 || toe_position < 0) {
//        printf("Invalid position");
//        return -1;
//    }

    for (int i = 0; i < 25; i++)
        for(int j = 0; j < 81; j++) {
            if (j == 80)
                screen[i][j] = '\n';
            else if(j == 79 || j == 0)
                screen[i][j] = '|';
            else if(i == 0 || i == 24)
                screen[i][j] = '-';
            else if(paint_rocket(j, i))
                screen[i][j] = '!';
            else
                screen[i][j] = ' ';
//            screen[i][j] = paint_rocket(j, i);
        }

int k = 0;
    while (1) {
        input();
        for (int i = 0; i < 25; i++)
            for(int j = 0; j < 81; j++) {
                if (j == 80)
                    screen[i][j] = '\n';
                else if(j == 79 || j == 0)
                    screen[i][j] = '|';
                else if(i == 0 || i == 24)
                    screen[i][j] = '-';
                else if(paint_rocket(j, i))
                    screen[i][j] = '!';
                else
                    screen[i][j] = ' ';
    //            screen[i][j] = paint_rocket(j, i);
            }
        display(screen);
        printf("%d L_P  %d %d    R_P  %d %d\n", k++, l_pl.x, l_pl.y, r_pl.x, r_pl.y);
    }

//    cross_and_toe_display(cross_position, toe_position);
}




void cross_and_toe_display(int cross_pos, int toe_pos) {
    char cross = 'X';
    char toe = '0';
    char space = ' ';
    int max_pos = (cross_pos > toe_pos) ? cross_pos : toe_pos;
    for (int i = 0; i <= max_pos; i++) {
        if (i == cross_pos) {
            printf("%c", cross);
        } else if (i == toe_pos) {
            printf("%c", toe);
        } else {
            printf("%c", space);
        }
    }
}
