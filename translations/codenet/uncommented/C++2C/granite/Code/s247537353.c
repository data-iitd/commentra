
#include <stdio.h>

int main(){
  long long A,B,C,K;
  scanf("%lld %lld %lld %lld",&A,&B,&C,&K);
  if(A+B>=K){
    printf("%lld\n",(A<K)?A:K);
  }else{
    printf("%lld\n",A-(K-(A+B)));
  }
  return 0;
}
// 