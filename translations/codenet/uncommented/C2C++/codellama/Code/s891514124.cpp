#include <iostream>

int main(void){

  int S;
  std::cin >> S;

  if (S < 60)
    {
      std::cout << "0:0:" << S << std::endl;
    }
  
  else if (S < 3600)
    {
      std::cout << "0:" << (int)S/60 << ":" << S%60 << std::endl;
    }
  
  else
    {
      std::cout << (int)S/3600 << ":" << (int)(S%3600)/60 << ":" << (S%60)%60 << std::endl;
    }
  return 0;
}

