#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <math.h>

// Define a modulus for the result to prevent overflow
#define MOD 1000000007

// Define a macro to read a single integer input
#define readInt(N) scanf("%d",&N)

// Define a macro to read a single line input
#define readLine(A,N) scanf("%s",A)

// Define a macro to print a single integer output
#define printInt(N) printf("%d\n",N)

// Define a macro to print a single line output
#define printLine(A,N) printf("%s\n",A)

// Define a macro to print a single integer output
#define printLong(N) printf("%ld\n",N)

// Define a macro to print a single integer output
#define printLL(N) printf("%lld\n",N)

// Define a macro to print a single integer output
#define printFloat(N) printf("%f\n",N)

// Define a macro to print a single integer output
#define printDouble(N) printf("%lf\n",N)

// Define a macro to print a single integer output
#define printChar(N) printf("%c\n",N)

// Define a macro to print a single integer output
#define printString(N) printf("%s\n",N)

// Define a macro to print a single integer output
#define printPointer(N) printf("%p\n",N)

// Define a macro to print a single integer output
#define printArray(A,N) for(int i=0;i<N;i++) printf("%d ",A[i]); printf("\n")

// Define a macro to print a single integer output
#define print2DArray(A,N,M) for(int i=0;i<N;i++){for(int j=0;j<M;j++) printf("%d ",A[i][j]); printf("\n")}

// Define a macro to print a single integer output
#define print3DArray(A,N,M,P) for(int i=0;i<N;i++){for(int j=0;j<M;j++){for(int k=0;k<P;k++) printf("%d ",A[i][j][k]); printf("\n");} printf("\n")}

// Define a macro to print a single integer output
#define print4DArray(A,N,M,P,Q) for(int i=0;i<N;i++){for(int j=0;j<M;j++){for(int k=0;k<P;k++){for(int l=0;l<Q;l++) printf("%d ",A[i][j][k][l]); printf("\n");} printf("\n");} printf("\n")}

// Define a macro to print a single integer output
#define print5DArray(A,N,M,P,Q,R) for(int i=0;i<N;i++){for(int j=0;j<M;j++){for(int k=0;k<P;k++){for(int l=0;l<Q;l++){for(int m=0;m<R;m++) printf("%d ",A[i][j][k][l][m]); printf("\n");} printf("\n");} printf("\n");} printf("\n")}

// Define a macro to print a single integer output
#define print6DArray(A,N,M,P,Q,R,S) for(int i=0;i<N;i++){for(int j=0;j<M;j++){for(int k=0;k<P;k++){for(int l=0;l<Q;l++){for(int m=0;m<R;m++){for(int n=0;n<S;n++) printf("%d ",A[i][j][k][l][m][n]); printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n")}

// Define a macro to print a single integer output
#define print7DArray(A,N,M,P,Q,R,S,T) for(int i=0;i<N;i++){for(int j=0;j<M;j++){for(int k=0;k<P;k++){for(int l=0;l<Q;l++){for(int m=0;m<R;m++){for(int n=0;n<S;n++){for(int o=0;o<T;o++) printf("%d ",A[i][j][k][l][m][n][o]); printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n")}

// Define a macro to print a single integer output
#define print8DArray(A,N,M,P,Q,R,S,T,U) for(int i=0;i<N;i++){for(int j=0;j<M;j++){for(int k=0;k<P;k++){for(int l=0;l<Q;l++){for(int m=0;m<R;m++){for(int n=0;n<S;n++){for(int o=0;o<T;o++){for(int p=0;p<U;p++) printf("%d ",A[i][j][k][l][m][n][o][p]); printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n")}

// Define a macro to print a single integer output
#define print9DArray(A,N,M,P,Q,R,S,T,U,V) for(int i=0;i<N;i++){for(int j=0;j<M;j++){for(int k=0;k<P;k++){for(int l=0;l<Q;l++){for(int m=0;m<R;m++){for(int n=0;n<S;n++){for(int o=0;o<T;o++){for(int p=0;p<U;p++){for(int q=0;q<V;q++) printf("%d ",A[i][j][k][l][m][n][o][p][q]); printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n")}

// Define a macro to print a single integer output
#define print10DArray(A,N,M,P,Q,R,S,T,U,V,W) for(int i=0;i<N;i++){for(int j=0;j<M;j++){for(int k=0;k<P;k++){for(int l=0;l<Q;l++){for(int m=0;m<R;m++){for(int n=0;n<S;n++){for(int o=0;o<T;o++){for(int p=0;p<U;p++){for(int q=0;q<V;q++){for(int r=0;r<W;r++) printf("%d ",A[i][j][k][l][m][n][o][p][q][r]); printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n")}

// Define a macro to print a single integer output
#define print11DArray(A,N,M,P,Q,R,S,T,U,V,W,X) for(int i=0;i<N;i++){for(int j=0;j<M;j++){for(int k=0;k<P;k++){for(int l=0;l<Q;l++){for(int m=0;m<R;m++){for(int n=0;n<S;n++){for(int o=0;o<T;o++){for(int p=0;p<U;p++){for(int q=0;q<V;q++){for(int r=0;r<W;r++){for(int s=0;s<X;s++) printf("%d ",A[i][j][k][l][m][n][o][p][q][r][s]); printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n")}

// Define a macro to print a single integer output
#define print12DArray(A,N,M,P,Q,R,S,T,U,V,W,X,Y) for(int i=0;i<N;i++){for(int j=0;j<M;j++){for(int k=0;k<P;k++){for(int l=0;l<Q;l++){for(int m=0;m<R;m++){for(int n=0;n<S;n++){for(int o=0;o<T;o++){for(int p=0;p<U;p++){for(int q=0;q<V;q++){for(int r=0;r<W;r++){for(int s=0;s<X;s++){for(int t=0;t<Y;t++) printf("%d ",A[i][j][k][l][m][n][o][p][q][r][s][t]); printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n")}

// Define a macro to print a single integer output
#define print13DArray(A,N,M,P,Q,R,S,T,U,V,W,X,Y,Z) for(int i=0;i<N;i++){for(int j=0;j<M;j++){for(int k=0;k<P;k++){for(int l=0;l<Q;l++){for(int m=0;m<R;m++){for(int n=0;n<S;n++){for(int o=0;o<T;o++){for(int p=0;p<U;p++){for(int q=0;q<V;q++){for(int r=0;r<W;r++){for(int s=0;s<X;s++){for(int t=0;t<Y;t++){for(int u=0;u<Z;u++) printf("%d ",A[i][j][k][l][m][n][o][p][q][r][s][t][u]); printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n")}

// Define a macro to print a single integer output
#define print14DArray(A,N,M,P,Q,R,S,T,U,V,W,X,Y,Z,A1) for(int i=0;i<N;i++){for(int j=0;j<M;j++){for(int k=0;k<P;k++){for(int l=0;l<Q;l++){for(int m=0;m<R;m++){for(int n=0;n<S;n++){for(int o=0;o<T;o++){for(int p=0;p<U;p++){for(int q=0;q<V;q++){for(int r=0;r<W;r++){for(int s=0;s<X;s++){for(int t=0;t<Y;t++){for(int u=0;u<Z;u++){for(int v=0;v<A1;v++) printf("%d ",A[i][j][k][l][m][n][o][p][q][r][s][t][u][v]); printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n")}

// Define a macro to print a single integer output
#define print15DArray(A,N,M,P,Q,R,S,T,U,V,W,X,Y,Z,A1,B1) for(int i=0;i<N;i++){for(int j=0;j<M;j++){for(int k=0;k<P;k++){for(int l=0;l<Q;l++){for(int m=0;m<R;m++){for(int n=0;n<S;n++){for(int o=0;o<T;o++){for(int p=0;p<U;p++){for(int q=0;q<V;q++){for(int r=0;r<W;r++){for(int s=0;s<X;s++){for(int t=0;t<Y;t++){for(int u=0;u<Z;u++){for(int v=0;v<A1;v++){for(int w=0;w<B1;w++) printf("%d ",A[i][j][k][l][m][n][o][p][q][r][s][t][u][v][w]); printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n")}

// Define a macro to print a single integer output
#define print16DArray(A,N,M,P,Q,R,S,T,U,V,W,X,Y,Z,A1,B1,C1) for(int i=0;i<N;i++){for(int j=0;j<M;j++){for(int k=0;k<P;k++){for(int l=0;l<Q;l++){for(int m=0;m<R;m++){for(int n=0;n<S;n++){for(int o=0;o<T;o++){for(int p=0;p<U;p++){for(int q=0;q<V;q++){for(int r=0;r<W;r++){for(int s=0;s<X;s++){for(int t=0;t<Y;t++){for(int u=0;u<Z;u++){for(int v=0;v<A1;v++){for(int w=0;w<B1;w++){for(int x=0;x<C1;x++) printf("%d ",A[i][j][k][l][m][n][o][p][q][r][s][t][u][v][w][x]); printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n")}

// Define a macro to print a single integer output
#define print17DArray(A,N,M,P,Q,R,S,T,U,V,W,X,Y,Z,A1,B1,C1,D1) for(int i=0;i<N;i++){for(int j=0;j<M;j++){for(int k=0;k<P;k++){for(int l=0;l<Q;l++){for(int m=0;m<R;m++){for(int n=0;n<S;n++){for(int o=0;o<T;o++){for(int p=0;p<U;p++){for(int q=0;q<V;q++){for(int r=0;r<W;r++){for(int s=0;s<X;s++){for(int t=0;t<Y;t++){for(int u=0;u<Z;u++){for(int v=0;v<A1;v++){for(int w=0;w<B1;w++){for(int x=0;x<C1;x++){for(int y=0;y<D1;y++) printf("%d ",A[i][j][k][l][m][n][o][p][q][r][s][t][u][v][w][x][y]); printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n")}

// Define a macro to print a single integer output
#define print18DArray(A,N,M,P,Q,R,S,T,U,V,W,X,Y,Z,A1,B1,C1,D1,E1) for(int i=0;i<N;i++){for(int j=0;j<M;j++){for(int k=0;k<P;k++){for(int l=0;l<Q;l++){for(int m=0;m<R;m++){for(int n=0;n<S;n++){for(int o=0;o<T;o++){for(int p=0;p<U;p++){for(int q=0;q<V;q++){for(int r=0;r<W;r++){for(int s=0;s<X;s++){for(int t=0;t<Y;t++){for(int u=0;u<Z;u++){for(int v=0;v<A1;v++){for(int w=0;w<B1;w++){for(int x=0;x<C1;x++){for(int y=0;y<D1;y++){for(int z=0;z<E1;z++) printf("%d ",A[i][j][k][l][m][n][o][p][q][r][s][t][u][v][w][x][y][z]); printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n")}

// Define a macro to print a single integer output
#define print19DArray(A,N,M,P,Q,R,S,T,U,V,W,X,Y,Z,A1,B1,C1,D1,E1,F1) for(int i=0;i<N;i++){for(int j=0;j<M;j++){for(int k=0;k<P;k++){for(int l=0;l<Q;l++){for(int m=0;m<R;m++){for(int n=0;n<S;n++){for(int o=0;o<T;o++){for(int p=0;p<U;p++){for(int q=0;q<V;q++){for(int r=0;r<W;r++){for(int s=0;s<X;s++){for(int t=0;t<Y;t++){for(int u=0;u<Z;u++){for(int v=0;v<A1;v++){for(int w=0;w<B1;w++){for(int x=0;x<C1;x++){for(int y=0;y<D1;y++){for(int z=0;z<E1;z++){for(int a=0;a<F1;a++) printf("%d ",A[i][j][k][l][m][n][o][p][q][r][s][t][u][v][w][x][y][z][a]); printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n");} printf("\n");} print