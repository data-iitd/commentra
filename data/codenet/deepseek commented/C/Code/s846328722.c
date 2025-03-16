#include<stdio.h>
int linersearch(int [],int ,int );

int main(){
  int i,n,s[100000],q,t,count=0;

  // Read the number of elements
  scanf("%d",&n);

  // Read the elements into the array s
  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  }

  // Read the number of queries
  scanf("%d",&q);

  // Perform a linear search for each query
  for(i=0;i<q;i++){
    scanf("%d",&t);
    if( linersearch(s,n,t) ) count++;
  }

  // Print the total count of successful searches
  printf("%d\n",count);
  
  return 0;
}

int linersearch(int a[],int n,int key){
  int i=0;

  // Modify the array to facilitate the search
  a[n]=key;
  
  // Perform the linear search
  while(a[i]!=key){
    i++;
  }

  // Return true if the key is found, false otherwise
  return i!=n;
}
