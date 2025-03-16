
#include<iostream>
using namespace std;
int main(){
  int n,l[2001],i,j,k,cnt=0,tmp=0;
  // Read the number of elements in the array
  cin>>n;
  // Read the elements of the array
  for(i=0; i<n; i++){
    cin>>l[i];
  }
  // Sort the array in ascending order using bubble sort
  for(i=0; i<n-1; i++){
    for(j=i+1; j<n; j++){
      if(l[j]<l[i]){
        tmp=l[i];
        l[i]=l[j];
        l[j]=tmp;
      }
    }
  }
  // Count the number of valid triangles that can be formed
  for(i=0; i<n-2; i++){
    for(j=i+1; j<n-1; j++){
      for(k=j+1; k<n; k++){
        if(l[i]+l[j]>l[k]){
          cnt++;
        }
        else{
          break;
        }
      }
    }
  }
  // Print the count of valid triangles
  cout<<cnt<<endl;
  return 0;
}
