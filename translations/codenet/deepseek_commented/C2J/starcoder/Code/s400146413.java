
// Linear Search Function
// Purpose: This function performs a linear search to find the key in the array S.
// Parameters:
//   - S[]: The array to be searched.
//   - n: The size of the array S.
//   - key: The value to be searched for.
// Return Value: Returns 1 if the key is not found, otherwise returns 0.
public static int linearsearch(int S[], int n, int key){
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

// Main Function
// Purpose: This function reads two arrays S and T, and counts the number of elements in T that are present in S using the linearsearch function.
// Variables:
//   - i, j: Loop counters.
//   - n, q: Sizes of arrays S and T.
//   - S[]: The first array to be read.
//   - T[]: The second array to be read.
//   - count: Counter for the number of elements found.
//   - key: The current element being searched for in S.
public static void main(String[] args){
  int i, j, n, q, S[10000], T[10000];
  int count = 0, key;

  Scanner input = new Scanner(System.in);
  n = input.nextInt();
  for(i = 0; i < n; i++){
    S[i] = input.nextInt();
  }

  q = input.nextInt();
  for(j = 0; j < q; j++){
    T[j] = input.nextInt();
  }
 
  for( j = 0; j < q; j++){
    key = T[j];
    if(linearsearch(S, n, key) == 0){
      count++;
    }
  }
    
    System.out.println(count);
  
    return;
}

