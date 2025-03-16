#include<iostream>
using namespace std;

int main(){
  int a[3],b[3];
  int c[3][3];
  int i,j;
  for(i=0;i<3;i++){
    cin >> c[i][0] >> c[i][1] >> c[i][2];
  }
  a[0]=0;
  for(i=0;i<3;i++){
    b[i]=c[0][i];
  }
  for(i=1;i<3;i++){
    a[i]=c[i][0]-b[0];
  }
  for(i=0;i<3;i++){
    for(j=0;j<3;j++){
      if(c[i][j]!=a[i]+b[j]){
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}
