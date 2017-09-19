#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
void add( int N, float A[N][N], float B[N][N], float C[N][N]);
void sub(int N, float A[N][N], float B[N][N], float C[N][N]);
void split(int N, float A[N/2][N/2], float B[N][N], int iB, int jB);
void join(int N, float A[N][N] , float B[N/2][N/2] , int iB, int jB);
void standardMultiplication(int N, float A[N][N], float B[N][N], float D[N][N]);
//calling strassensMultiplication function
void strassensMultiplication(int N, float A[N][N], float B[N][N], float C[N][N]) {
  int n = N;
  int i,j;
  if(n == 1) {
    C[0][0] = A[0][0] * B[0][0];
  } else if(n == 2){
    standardMultiplication(N,A,B,C);
  }else {
    float A11[n/2][n/2];
    float A12[n/2][n/2];
    float A21[n/2][n/2];
    float A22[n/2][n/2];

    float B11[n/2][n/2];
    float B12[n/2][n/2];
    float B21[n/2][n/2];
    float B22[n/2][n/2];

    float C11[N/2][N/2];
    float C12[N/2][N/2];
    float C21[N/2][N/2];
    float C22[N/2][N/2];
    // calling split function
    split(N,A11,A, 0 , 0);
    split(N,A12,A, 0 , n/2);
    split(N,A21,A, n/2, 0);
    split(N,A22,A, n/2, n/2);

    split(N,B11,B,  0 , 0);
    split(N,B12,B,  0 , n/2);
    split(N,B21,B,  n/2, 0);
    split(N,B22,B,  n/2, n/2);

    split(N,C11,C,  0 , 0);
    split(N,C12,C,  0 , n/2);
    split(N,C21,C,  n/2, 0);
    split(N,C22,C,  n/2, n/2);

    float M1[n/2][n/2];
    float M2[n/2][n/2];
    float M3[n/2][n/2];
    float M4[n/2][n/2];
    float M5[n/2][n/2];
    float M6[n/2][n/2];
    float M7[n/2][n/2];
    float M8[n/2][n/2];
    float M9[n/2][n/2];
    float M10[n/2][n/2];

    add(N/2,A11, A22,M9);
    add(N/2,B11, B22, M10);
    strassensMultiplication((n / 2), M9, M10, M1);
    add(N/2,A21, A22, M9);
    strassensMultiplication((n / 2), M9, B11, M2);
    sub(N/2,B12, B22, M10);
    strassensMultiplication((n / 2), A11, M10, M3);
    sub(N/2,B21, B11, M10);
    strassensMultiplication((n / 2), A22, M10, M4);
    add(N/2,A11, A12,M9);
    strassensMultiplication((n / 2), M9, B22, M5);
    sub(N/2,A21, A11, M9);
    add(N/2,B11, B12,M10);
    strassensMultiplication((n / 2), M9, M10, M6);
    sub(N/2,A12, A22,M9);
    add(N/2,B21, B22,M10);
    strassensMultiplication((n / 2), M9, M10, M7);

    add(N/2,M1, M4, M8);
    sub(N/2,M8, M5, M9);
    add(N/2,M9, M7, C11);
    add(N/2,M3, M5, C12);
    add(N/2,M2, M4, C21);
    sub(N/2,M1, M2, M8);
    add(N/2,M8, M3, M9);
    add(N/2,M9, M6, C22);
    // calling join function
    join(N, C,C11,  0, 0);
    join(N, C,C12,  0, n/2);
    join(N, C,C21, n/2, 0);
    join(N, C,C22, n/2, n/2);
  }
}
//sub function
void sub(int N, float A[N][N], float B[N][N], float C[N][N]) {
  int i,j;
  for (i = 0; i < N; i++)
  for (j = 0; j < N; j++)
  C[i][j] = A[i][j] - B[i][j];
}
//add function
void add(int N, float A[N][N], float B[N][N], float C[N][N]) {
  int i,j;
  for (i = 0; i < N; i++)
  for (j = 0; j < N; j++)
  C[i][j] = A[i][j] + B[i][j];
}
//split function
void split(int N, float A[N/2][N/2], float B[N][N], int iB, int jB) {
  int n = N;
  int i1,i2,j1,j2,i,j;
  for(i1 = 0, i2 = iB; i1 < n/2; i1++, i2++)
  for(j1 = 0, j2 = jB; j1 < n/2; j1++, j2++)
  A[i1][j1] = B[i2][j2];

}
//join function
void join(int N, float A[N][N] , float B[N/2][N/2] , int iB, int jB) {
  int n = N;
  int i1,i2,j1,j2,i,j;
  for(i1 = 0, i2 = iB; i1 < n/2; i1++, i2++)
  for(j1 = 0, j2 = jB; j1 < n/2; j1++, j2++)
  A[i2][j2] = B[i1][j1];
}
//standard Multiplication
void standardMultiplication(int N, float A[N][N], float B[N][N], float D[N][N]) {
  int n = N;
  float sum = 0;
  int i,j,k;
  for (i = 0; i < n; i++) {
    for (j = 0 ; j < n ; j++ ) {
      for (k = 0 ; k < n ; k++ ) {
        sum = sum + A[i][k] * B[k][j];
      }
      D[i][j] = sum;
      sum = 0;
    }
  }
}

int main (int argc, char *argv[]) {

  int N = atoi(argv[1]);
  float A[N][N], B[N][N];
  float C[N][N], D[N][N];
  int i,j,g;
  time_t t;
  int OldMatrix = N,NewMatrix;
  for (i = 0; i < 1000; i++) {
    if(pow(2,i)>=N){
      NewMatrix = pow(2,i);
      break;
    }
  }
  srand((unsigned) time(&t));
  for (i = 0; i < N; i++)
  for (j = 0; j < N; j++)
  A[i][j] = (round((((float)rand()/RAND_MAX * 10) - 5)*100)/100);
  for (i = 0; i < N; i++)
  for (j = 0; j < N; j++)
  B[i][j] = (round((((float)rand()/RAND_MAX * 10) - 5)*100)/100);
  printf("\nMatrix A\n");
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++)
    printf("%.2f  ", A[i][j]);
    printf("\n");
  }
  printf("\nMatrix B\n");
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++)
    printf("%.2f  ", B[i][j]);
    printf("\n");
  }
  standardMultiplication(N, A, B, D);
  if (NewMatrix!=OldMatrix) {
    float tempMatrixA[NewMatrix][NewMatrix],tempMatrixB[NewMatrix][NewMatrix],tempMatrixc[NewMatrix][NewMatrix];
    for (i=0; i <NewMatrix; i++) {
      for (j = 0; j < OldMatrix; j++) {
        tempMatrixA[i][j]=A[i][j];
        tempMatrixB[i][j]=B[i][j];
      }
      for (g = OldMatrix; g < NewMatrix; g++) {
        tempMatrixA[i][g]=0;
        tempMatrixB[i][g]=0;
      }
    }
    for (i = OldMatrix; i < NewMatrix; i++) {
      for (j = 0; j < NewMatrix; j++) {
        tempMatrixA[i][j]=0;
        tempMatrixB[i][j]=0;
      }
    }
    strassensMultiplication(NewMatrix,tempMatrixA,tempMatrixB,tempMatrixc);
    printf("\nStrassen's Multiplication Output:\n");
    for (i = 0; i < OldMatrix; i++) {
      for (j = 0; j < OldMatrix; j++)
      printf("%.2f\t", tempMatrixc[i][j]);
      printf("\n");
    }
  } else {
    strassensMultiplication(N, A, B, C);
    printf("\nStrassen's Multiplication Output:\n");
    for (i = 0; i < N; i++){
      for (j = 0; j < N; j++)
      printf("%.2f\t", C[i][j]);
      printf("\n");
    }
  }
  printf("\nStandard Multiplication Output:\n");
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++)
    printf("%.2f\t", D[i][j]);
    printf("\n");
  }
  return 0;
}
