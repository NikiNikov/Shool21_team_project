#include <stdio.h>
#include <unistd.h>

void initfield(char field[][83], int n, int m);
//int interective(char *field, int n, int m);
void output(char field[][83], int n, int m);

int input(int* gameSpeed, char field[][83], int n, int m);

int inputNum(int *a, int max);

int inputField(char field[][83], int n, int m);

char setSymbol(char field[][83], int n, int m, int i, int j) {
    char c = field[i][j];
    int x = j - 1, y = i - 1;
    int aliveCount = 0;
    for (int p = 0; p < 3; ++p) {
        if ((y + p) < 1)
            y = 25 - p;
        if ((y + p) > 25)
            y = 1 - p;
        for (int k = 0; k < 3; ++k) {
            if ((x + k) < 1)
                x = 80 - k;
            if ((x + k) > 80)
                x = 1 - k;
            if (field[y + p][x + k] == '@') {
                aliveCount++;
//            printf(" i - %d    j - %d    y -  %d x - %d\n", i, j, y + p, x + k);
            }

        }

    }

    if (field[i][j] == '@' ) {
        --aliveCount;
        if (aliveCount == 3 || aliveCount == 2)
            c = '@';
        else
            c = ' ';
    }
    if (field[i][j] == ' ') {
        if (aliveCount == 3) {
            c = '@';
        }
    }
    return c;

}

void cp(char in[][83], char out[][83], int n, int m) {
    for(int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            in[i][j] = out[i][j];
}

int redraw(char field[][83], int n, int m) {
    char newField[n][m];
    initfield(newField, n, m);
    for(int i = 1; i < n - 1; ++i)
        for (int j = 1; j < m - 2; ++j) {
//            printf("%c - %c    %d  %d\n", field[i][j], setSymbol(field, n, m, i, j), i, j);
            newField[i][j] = setSymbol(field, n, m, i, j);
}
    cp(field, newField, n, m);
    return 0;
}


int main () {
    char field[27][83];
    int n = 27, m = 83, gameSpeed = 1;
    initfield(field, n, m);
    input(&gameSpeed, field, n, m);
    output(field, n, m);
    int f = 0;
    while(f++ < 10) {
        redraw(field, n, m);
        usleep(1000000 * gameSpeed);
        output(field, n, m);
    }

    return 0;
}

int input(int* gameSpeed, char field[][83], int n, int m) {

    int err = inputNum(gameSpeed, 5);
    if (!err)
        err = inputField(field, n, m);
    return err;
}

int inputNum(int *n, int max) {
  int flag = 0;
  if (scanf("%d", n) != 1 || *n < 1 || *n > max) {
    flag = 1;
  }
  return flag;
}

int inputField(char field[][83], int n, int m) {
  int flag = 0;
  char s;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      if (!flag && !scanf("%c", &s)) {
        flag = 1;
      } else {
          if (i && i < n - 1 && j && j < m - 2) {
              if ((int)s == 46)
                  field[i][j] = ' ';
              else
                  field[i][j] = s;

          }
      }
    }
  return flag;
}


void output(char field[][83], int n, int m) {
    for (int i  = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%c", field[i][j]);
        }
    }
}


void initfield(char field[][83], int n, int m) {

    for (int i  = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (j && j < 81 && i && i < 26)
                field[i][j] = '.';
            else if (( i == 0 || i == 26) && j && j < 81)
                field[i][j] = '-';
            else if ( j == 0 || j == 81)
                field[i][j] = '|';
            else
               field[i][j] = '\n';
}
