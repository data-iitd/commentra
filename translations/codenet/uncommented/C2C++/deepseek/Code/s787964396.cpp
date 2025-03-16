#include<iostream>
#include<vector>
#define I 10000
using namespace std;
void CountingSort(vector<int>&,vector<int>&,int);
int main(){
  int i,max=0,n;
  cin>>n;
  vector<int> a(n+1);
  vector<int> b(n+1);
  for(i=0;i<n;i++){
    cin>>a[i+1];
  }
  CountingSort(a,b,n);
  cout<<b[1];
  for(i=2;i<n+1;i++)cout<<" "<<b[i];
  cout<<endl;
  return 0;
}
void CountingSort(vector<int>& a,vector<int>& b,int k){
  vector<int> c(I+1,0);
  for(int j=0;j<k;j++)c[a[j+1]]++;
  for(int i=1;i<I+1;i++)c[i]+=c[i-1];
  for(int j=k;j>0;j--){
    b[c[a[j]]]=a[j];
    c[a[j]]--;
  }
}
