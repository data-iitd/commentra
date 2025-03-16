#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<ctype.h>
#include<stdbool.h>
#include<limits.h>
#include<float.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<ctype.h>
#include<stdbool.h>
#include<limits.h>
#include<float.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
int N;
scanf("%d",&N);
vector<int> X(N);
vector<int> Y(N);
for(int i = 0; i < N; i++){
scanf("%d",&X[i]);
Y[i] = X[i];
}
sort(Y.begin(),Y.end());
int y = Y[N/2];
for(int i = 0; i < N; i++){
if(X[i] < Y[N/2]){
printf("%d",Y[N/2]);
}
else{
printf("%d",Y[N/2 - 1]);
}
printf("\n");
}
return 0;}
