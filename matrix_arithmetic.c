#include <stdio.h>
#include <stdlib.h>
#define NMAX 100

int inputNum(int *a);

int inputValues(int **a, int c, int r);

void output(int **a, int c, int r);

int sum (int **a, int stc, int c, int n);

void margeArr(int **a, int str1, int str2, int c);

void sort(int **a, int r, int c, int n);


int main() {
//  int data[NMAX][NMAX];
  int n, R, C, flag = 0;
  int ***bPtr = 0;
//  int **bPtrN = 0;
  if (inputNum(&n) || n > 3)
    flag = 2;

  if (inputNum(&R) || inputNum(&C))
    flag = 2;

  if (!flag) {

      bPtr = malloc(3 * sizeof(int **));
       for (int i = 0; i < 3; ++i) {
            bPtr[i] = malloc(R * sizeof(int *));
            for (int j = 0; j < R; ++j)
              bPtr[i][j] = malloc(C * sizeof(int));
       }
//       bPtr = malloc(R * sizeof(int *));
//      for (int i = 0; i < R; ++i)
//        bPtr[i] = malloc(C * sizeof(int));

//      bPtrN = malloc(R * sizeof(int *));
//      for (int i = 0; i < R; ++i)
//        bPtrN[i] = malloc(C * sizeof(int));


  }

  if ((!flag) && inputValues(bPtr[0], C, R))
    flag = 1;
  if (!flag) {
//    sort(bPtr, R, C, n);


    output(bPtr[0], C, R);

  }
  if (flag < 2) {

      for (int i = 0; i < R; ++i)
        free(bPtr[i]);
      free(bPtr);

  }

  if (flag) {
    printf("n/a");
  }
  return flag;
}

int inputNum(int *n) {
  int flag = 0;
  if (scanf("%d", n) != 1 || *n < 1) {
    flag = 1;
  }
  return flag;
}

int inputValues(int **a, int c, int r) {
  int flag = 0;
  float s;
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j) {
      if ((!flag && !scanf("%f", &s)) || (s != (int)s)) {
        flag = 1;
      } else {
          a[i][j] = (int)s;
      }
    }
  return flag;
}

void output(int **a, int c, int r) {
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if ((i == r - 1) && (j == c - 1))
        printf("%d",  a[i][j]);
      else
        printf("%d ", a[i][j]);
    }
    printf("\n");
  }
}


//int sum (int **a, int str, int c, int n){
//    int sum = 0;
//    for (int i = 0; i < c; ++i)
//      sum += (n == 1 || n == 3) ? *((int *)a + c * str + i) : a[str][i];
//    return sum;
//}


//void margeArr(int **a, int str1, int str2, int c, int n){
//    int tmp1[c];
//    int tmp2[c];
//    for (int i = 0; i < c; ++i) {
//      tmp1[i] = (n == 1 || n == 3) ? *((int *)a + c * str1 + i) : a[str1][i];
//      (tmp2[i] = (n == 1 || n == 3) ? *((int *)a + c * str2 + i) : a[str2][i]);
//    }
//    for (int i = 0; i < c; ++i)
//        if (n == 1 || n == 3)
//            *((int *)a + c * str1 + i) = tmp2[i];
//        else
//            a[str1][i] = tmp2[i];

//    for (int i = 0; i < c; ++i)
//        if (n == 1 || n == 3)
//            *((int *)a + c * str2 + i) = tmp1[i];
//        else
//            a[str2][i] = tmp1[i];

////printf("\n = /n");
//}

//void sort(int **a, int r, int c, int n) {
//  for (int i = 0; i < r - 1; ++i) {
//    for (int j = 0; j < r - i - 1; ++j) {
//      if (sum(&a[0], j, c, n) > sum(&a[0], j + 1, c, n)) {

//          margeArr(&a[0], j, j+1, c, n);

//      }
//    }
//  }
//}

