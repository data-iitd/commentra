#include<iostream>
using namespace std;

int main(){
  while(1){
    // Read the values of n and r
    int n,r;
    cin>>n>>r;
    // Break the loop if both n and r are zero
    if(n==0&&r==0)break;
    
    // Initialize array a with values from n down to 1
    int a[n];
    for(int i=0;i<n;i++){
      a[i]=n-i;
    }
    
    // For each round of r
    for(int i=0;i<r;i++){
      // Copy array a to array b
      int b[n];
      for(int j=0;j<n;j++){
        b[j]=a[j];
      }
      // Read the values of p and c
      int p,c;
      cin>>p>>c;

      // Perform the shift operation on array a
      for(int j=0;j<c;j++){
        a[j]=b[p-1+j];
      }
      
      // Fill the remaining positions in array a
      for(int j=c;j<c+p-1;j++){
        a[j]=b[j-c];
      }
    }
    // Print the first element of array a
    cout<<a[0]<<endl;
  }
  return 0;
}
