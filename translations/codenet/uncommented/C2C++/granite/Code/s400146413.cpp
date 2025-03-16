
#include<iostream>

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

  std::cin >> n;
  for(i = 0; i < n; i++){
    std::cin >> S[i];
  }

  std::cin >> q;
  for(j = 0; j < q; j++){
    std::cin >> T[j];
  }
 
  for( j = 0; j < q; j++){
    key = T[j];
    if(linearsearch(S, n, key) == 0){
      count++;
    }
  }
    
    std::cout << count << std::endl;
  
    return 0;
  }

