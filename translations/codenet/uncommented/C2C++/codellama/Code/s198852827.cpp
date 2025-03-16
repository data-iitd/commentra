#include<iostream>

#define ABS(x) (((x)<(0))?(-(x)):(x))

int main(void){
  int N,t,x,y,nx=0,ny=0,nt=0;
  int i,j,k,tmp;
  std::cin>>N;
  for(i=0;i<N;i++){
    std::cin>>t>>x>>y;
    tmp=t-nt-(ABS(x-nx)+ABS(y-ny));
      if(tmp<0 || tmp%2){
	std::cout<<"No"<<std::endl;
	return 0;
      }
  }
  std::cout<<"Yes"<<std::endl;
  return 0;
}

