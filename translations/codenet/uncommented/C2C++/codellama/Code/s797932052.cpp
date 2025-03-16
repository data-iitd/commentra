#include<iostream>

int main(void)
{
  int a,b;
  std::cin>>a;
  std::cin>>b;
  if((a*b)%2 == 0){
    std::cout<<"Even\n";
}else{
    std::cout<<"Odd\n";
  }
  return 0;
}

