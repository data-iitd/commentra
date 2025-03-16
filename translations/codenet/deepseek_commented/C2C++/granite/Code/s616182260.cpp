
#include<iostream>
using namespace std;
int main(){
  int a[3],b[3];
  int c[3][3];
  int i,j;
  
  // Read the 3x3 matrix from the input
  for(i=0;i<3;i++){
    cin>>c[i][0]>>c[i][1]>>c[i][2];
  }
  
  // Initialize the first element of array a to 0
  a[0]=0;
  
  // Assign the first row of the matrix to array b
  for(i=0;i<3;i++){
    b[i]=c[0][i];
  }
  
  // Calculate the remaining elements of array a
  for(i=1;i<3;i++){
    a[i]=c[i][0]-b[0];
  }
  
  // Check if each element of the matrix is equal to the sum of the corresponding elements of a and b
  for(i=0;i<3;i++){
    for(j=0;j<3;j++){
      if(c[i][j]!=a[i]+b[j]){
        cout<<"No";
        return 0;
      }
    }
  }
  
  // If all elements match, print "Yes"
  cout<<"Yes";
  return 0;
}
