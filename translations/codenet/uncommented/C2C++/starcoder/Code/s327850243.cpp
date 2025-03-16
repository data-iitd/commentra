#include<iostream>
using namespace std;
int main(){
 int m,n;
 int i,j;
 int A[100][100];
 int B[100];
 int S[100]={0};

 cin>>m>>n;

 for(i=0;i<m;i++){

   for(j=0;j<n-1;j++){
     cin>>A[i][j];
    }
     cin>>A[i][n-1];

 }

 for(i=0;i<n;i++){
  cin>>B[i];
 }

 for(i=0;i<m;i++){
 
  for(j=0;j<n;j++){
    S[i]=S[i]+A[i][j]*B[j];
  }

 }


 for(i=0;i<m;i++){
  cout<<S[i]<<endl;
 }

return 0;

}
