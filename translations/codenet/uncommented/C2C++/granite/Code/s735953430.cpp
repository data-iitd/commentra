
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main()
{
  int i_min,min;
  int i,j,k;
  int X,N;
  cin >> X >> N;
  if( N==0 ){
    cout << X << endl; 
    exit(0);
  }
  
  int plus[256];
  int minus[256];
  for(i=0;i<256;i++){
    plus[i] = i;
    minus[i] = (-1*i);
  }
  for(i=0;i<N;i++){
    cin >> j;
    plus[j] = 0;
  }
  
  i_min=0;
  min = 1000;
  for(i=255;i>=0;i--){
    if( plus[i] == 0 && i>0 ){
      continue;
    }
    k = X-plus[i];
    if(k<0){ k *= -1; }
    if( k<=min ){
      min = k;
      i_min = i;
    }
  }  
  
  cout << i_min << endl;
  
  return 0;
}

