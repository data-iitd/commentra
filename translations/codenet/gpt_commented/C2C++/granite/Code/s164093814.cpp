
#include<iostream>
#include<cstring>

#define M 1046527 /* Size of the hash table */
#define L 14      /* Maximum length of strings to be stored in the hash table */

char H[M][L]; /* Hash Table to store strings */

/* Function to convert a character to a corresponding integer value */
int getChar(char ch){
  if ( ch == 'A') return 1; // A maps to 1
  else if ( ch == 'C') return 2; // C maps to 2
  else if ( ch == 'G') return 3; // G maps to 3
  else if ( ch == 'T') return 4; // T maps to 4
  return 0; // Return 0 for any other character
}

/* Convert a string into a unique integer key using a polynomial rolling hash */
long long getKey(char str[]){
  long long sum = 0, p = 1; // Initialize sum and power
  int i;
  for ( i = 0; i < (int)strlen(str); i++ ){
    sum += p * (getChar(str[i])); // Update sum with the character's value
    p *= 5; // Increase power of 5 for the next character
  }
  return sum; // Return the computed key
}

/* Hash function h1: Computes the primary hash index */
int h1(int key){ return key % M; }

/* Hash function h2: Computes the secondary hash index for collision resolution */
int h2(int key){ return 1 + (key % (M - 1)); }

/* Function to find a string in the hash table */
int find(char str[]){
  int i, hash, key;
  key = getKey(str); // Get the key for the string
  i = 0; // Initialize index for probing
  while(1){
    // Compute the hash index using double hashing
    hash = (h1(key) + i * h2(key)) % M;
    if(strcmp(H[hash], str) == 0) return 1; // String found
    else if(strlen(H[hash]) == 0) return 0; // Empty slot indicates string not found
    i++; // Increment index for next probe
  }
  return 0; // Should not reach here
}

/* Function to insert a string into the hash table */
int insert(char str[]){
  int i, hash, key;
  key = getKey(str); // Get the key for the string
  i = 0; // Initialize index for probing
  while(1){
    // Compute the hash index using double hashing
    hash = (h1(key) + i * h2(key)) % M;
    if(strcmp(H[hash], str) == 0) return 1; // String already exists
    else if(strlen(H[hash]) == 0){ // If the slot is empty
      strcpy(H[hash], str); // Insert the string
      return 0; // Insertion successful
    }
    i++; // Increment index for next probe
  }
  return 0; // Should not reach here
}

int main(){
  int i, n;
  char str[L], com[9];
  
  // Initialize the hash table with empty strings
  for ( i = 0; i < M; i++ ) H[i][0] = '\0';

  // Read the number of commands
  std::cin >> n;

  // Process each command
  for ( i = 0; i < n; i++ ){
    std::cin >> com >> str; // Read command and string

    // Check if the command is to insert a string
    if ( com[0] == 'i' ){
      insert(str); // Insert the string into the hash table
    } else {
      // If the command is not insert, check if the string exists
      if (find(str)){
        std::cout << "yes\n"; // String found
      } else {
        std::cout << "no\n"; // String not found
      }
    }
  }

  return 0; // End of program
}
