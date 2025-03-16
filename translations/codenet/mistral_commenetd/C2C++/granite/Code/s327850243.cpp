

#include<iostream>
// Declare variables
int m, n;
int i, j;
int A[100][100];
int B[100];
int S[100]={0};

// Read the dimensions of the matrices from user
std::cin>>m>>n;
// Comments for the for loop: Read the elements of matrix A row-wise
for(i=0;i<m;i++){
  for(j=0;j<n-1;j++){
    std::cin>>A[i][j];
  }
  // Read the last element of the row
  std::cin>>A[i][n-1];
}
// Comments for the for loop: Read the elements of vector B
for(i=0;i<n;i++){
  std::cin>>B[i];
}
// Comments for the for loop: Perform element-wise multiplication of matrices A and B, and store the result in vector S
for(i=0;i<m;i++){
  for(j=0;j<n;j++){
    S[i] += A[i][j] * B[j];
  }
}
// Comments for the for loop: Print the elements of vector S
for(i=0;i<m;i++){
  std::cout<<S[i]<<std::endl;
}

// The program ends with a return statement with value 0
return 0;

