
#include<iostream>

using namespace std;

int main(){
  while(1){
    int n,r;
    cin>>n>>r;
    if(n==0&&r==0)break;
    
    int a[100],b[100];
    for(int i=0;i<n;i++){
      a[i]=n-i;
    }
    
    for(int i=0;i<r;i++){
      
      for(int j=0;j<n;j++){
        b[j]=a[j];
      }
      int p,c;
      cin>>p>>c;

      for(int j=0;j<c;j++){
        a[j]=b[p-1+j];
      }
      
      for(int j=c;j<c+p-1;j++){
        a[j]=b[j-c];
      }
    }
    cout<<a[0]<<endl;
  }
  return 0;
}
