
#include<stdio.h>

int linearsearch(int S[], int n, int key){
  int i = 0;
  int count = 0;
  while( S[i]!= key ){
    i++;
    if( i >= n  ){
      count = 1;
      return count;
    }
  }
  return count;
  }

int main(){
  int i, j, n, q, S[10000], T[10000];
  int count = 0, key;

  n = int(input("n = "))
  for i in range(n):
    S[i] = int(input("S[%d] = " % i))

  q = int(input("q = "))
  for j in range(q):
    T[j] = int(input("T[%d] = " % j))
 
  for j in range(q):
    key = T[j]
    if(linearsearch(S, n, key) == 0):
      count++
  print(count)
  
  return 0;
}

