
#include<iostream>
#include<cstring>

using namespace std;

#define M 1046527 /* Define the size of the hash table */
#define L 14      /* Define the length of each string in the hash table */

char H[M][L]; /* Declare a 2D array named H as the hash table */

int getChar(char ch){
  /* A helper function to convert a single character into its corresponding integer value */
  if ( ch == 'A') return 1;
  else if ( ch == 'C') return 2;
  else if ( ch == 'G') return 3;
  else if ( ch == 'T') return 4;
  return 0;
}

/* A function to convert a string into an integer value */
long long getKey(char str[]){
  long long sum = 0, p = 1;
  int i;
  /* Iterate through each character in the string and calculate the key */
  for ( i = 0; i < (int)strlen(str); i++ ){
    sum += p*(getChar(str[i]));
    p *= 5;
  }
  return sum;
}

/* A helper function to calculate the first hash index */
int h1(int key){ return key % M; }

/* A helper function to calculate the second hash index */
int h2(int key){ return 1 + (key % (M - 1));}

/* A function to check if a string is already present in the hash table */
int find(char str[]){
  int i,hash,key;
  key = getKey(str); /* Calculate the key for the given string */
  i = 0;
  /* Iterate through the hash table until the string is found or the hash table is exhausted */
  while(1){
    hash = (h1(key) + i * h2(key))%M;
    if(strcmp(H[hash],str) == 0)return 1;
    /* If the current index in the hash table is empty, insert the string and return */
    else if(strlen(H[hash]) == 0)return 0;
    i++;
  }
  return 0;
}

/* A function to insert a string into the hash table */
int insert(char str[]){
  int i,hash,key;
  key = getKey(str); /* Calculate the key for the given string */
  i = 0;
  /* Iterate through the hash table until an empty index is found */
  while(1){
    hash = (h1(key) + i * h2(key))%M;
    if(strlen(H[hash]) == 0){
      strcpy(H[hash],str); /* Copy the string into the empty index */
      return 0;
    }
    i++;
  }
  return 0;
}

int main(){
  int i, n;
  char str[L], com[9];
  for ( i = 0; i < M; i++ ) H[i][0] = '\0'; /* Initialize the hash table with empty strings */

  cin >> n; /* Read the number of operations */

  for ( i = 0; i < n; i++ ){
    cin >> com >> str; /* Read a command and a string */

    if ( com[0] == 'i' ){
      /* If the command is 'insert', insert the string into the hash table */
      insert(str);
    } else {
      /* If the command is 'find', check if the string is present in the hash table */
      if (find(str)){
        cout << "yes\n";
      } else {
        cout << "no\n";
      }
    }
  }

  return 0;
}

