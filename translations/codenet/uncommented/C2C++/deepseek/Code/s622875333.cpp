#include<iostream>
using namespace std;

int n, r, i, j, p, c;
int a[100], b[100];

int main(){
  while(true){
    cin >> n >> r;
    if(n == 0 && r == 0) break;
    
    for(i = 0; i < n; i++){
      a[i] = n - i;
    }
    
    for(i = 0; i < r; i++){
      
      for(j = 0; j < n; j++){
        b[j] = a[j];
      }
      cin >> p >> c;

      for(j = 0; j < c; j++){
        a[j] = b[p - 1 + j];
      }
      
      for(j = c; j < c + p - 1; j++){
        a[j] = b[j - c];
      }
    }
    cout << a[0] << endl;
  }
  return 0;
}
