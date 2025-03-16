#include<stdio.h>

int n,r,i,j,p,c;
int a[100],b[100];

int main(){
  while(1){
    // Read the values of n and r
    scanf("%d %d",&n,&r);
    // Break the loop if both n and r are zero
    if(n==0&&r==0)break;
    
    // Initialize array a with values from n down to 1
    for(i=0;i<n;i++){
      a[i]=n-i;
    }
    
    // For each round of r
    for(i=0;i<r;i++){
      // Copy array a to array b
      for(j=0;j<n;j++){
        b[j]=a[j];
      }
      // Read the values of p and c
      scanf("%d %d",&p,&c);

      // Perform the shift operation on array a
      for(j=0;j<c;j++){
        a[j]=b[p-1+j];
      }
      
      // Fill the remaining positions in array a
      for(j=c;j<c+p-1;j++){
        a[j]=b[j-c];
      }
    }
    // Print the first element of array a
    printf("%d\n",a[0]);
  }
  return 0;
}

