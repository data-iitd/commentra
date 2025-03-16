#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++) // Macro for repetition of a loop 'n' times
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++) // Macro for repetition of a loop from 'a' to 'b'
#define in(x) scanf("%d", &x); // Macro for taking input from the user
#define out(str) printf("%s\n", str); // Macro for printing output to the console

template<class T> // Template for 'chmax' function to find the maximum value between two variables
bool chmax(T *a, const T b) {
 if (*a<b) { // If the first variable is smaller than the second variable
 *a=b; // Assign the second variable to the first variable
 return 1; // Return true to indicate that the value of the first variable has been updated
 }
 return 0; // Return false if the first variable was already greater than or equal to the second variable
}

template<class T> // Template for 'chmin' function to find the minimum value between two variables
bool chmin(T *a, const T b) {
 if (b<*a) { // If the second variable is smaller than the first variable
 *a=b; // Assign the second variable to the first variable
 return 1; // Return true to indicate that the value of the first variable has been updated
 }
 return 0; // Return false if the first variable was already smaller than or equal to the second variable
}

int main(){ // Main function
 int L,N; // Declare variables for the length of the string and the number of strings
 scanf("%d %d", &N, &L); // Read the number of strings and their length from the user
 char S[N][L+1]; // Declare an array of strings 'S' of size 'N'
 rep(i,N)scanf("%s", S[i]); // Read each string from the user and store it in the array 'S'
 rep(i,N)printf("%s", S[i]); // Print each sorted string to the console
 printf("\n"); // Print an empty line at the end
}

