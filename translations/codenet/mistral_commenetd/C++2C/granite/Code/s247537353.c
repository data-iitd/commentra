
#include <stdio.h>

int main(){
  int A, B, C, K;
  scanf("%d %d %d %d", &A, &B, &C, &K);

  if(A+B>=K){
    printf("%d\n", A<K?A:K);
  }else{
    printf("%d\n", A-(K-(A+B)));
  }

  return 0;
}
// 