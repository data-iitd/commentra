#include <stdio.h>

int A[1000000], n; // initialize an integer array A of size 1,000,000 and an integer n

/* 二分探索 */
int binarySearch(int key) { // function to perform binary search
  int left = 0; // initialize left index to 0
  int right = n; // initialize right index to the last index of the array
  int mid; // initialize middle index

  while(left < right) { // while left index is less than right index
    mid = (left + right) / 2; // calculate middle index
    if(key == A[mid]) { // if key is equal to the middle element
      return 1; // return 1 to indicate key is found
    }
    if(key > A[mid]) { // if key is greater than the middle element
      left = mid + 1; // update left index to search in the right half
    } else { // if key is less than the middle element
      right = mid; // update right index to search in the left half
    }
  }
  return 0; // if key is not found, return 0
}

int main(void) { // main function
  int i, q, k, sum = 0; // initialize variables i, q, k, and sum

  scanf("%d",&n); // read the number of elements in the array from the standard input
  for(i=0; i<n; i++) { // for loop to read and store the elements of the array
    scanf("%d",&A[i]);
  }
  scanf("%d",&q); // read the number of queries from the standard input
  for(i=0;i<q;i++) { // for loop to perform binary search for each query
    scanf("%d",&k);
    if(binarySearch(k)) // if key is found in the array
      sum++; // increment sum by 1
  }
  printf("%d\n",sum); // print the number of queries with a matching element in the array
  return 0; // return 0 to indicate successful execution of the program
}

