#include <iostream>

using namespace std;

int main(void){

  int S;
  cin >> S;

  if (S < 60)
    {
      cout << "0:0:" << S << endl;
    }
  
  else if (S < 3600)
    {
      cout << "0:" << (int)S/60 << ":" << S%60 << endl;
    }
  
  else
    {
      cout << (int)S/3600 << ":" << (int)(S%3600)/60 << ":" << (S%60)%60 << endl;
    }
  return 0;
}

