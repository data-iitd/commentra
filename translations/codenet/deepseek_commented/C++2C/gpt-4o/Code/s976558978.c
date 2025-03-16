/*
URL_HERE
*/

/*

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.141592653589793238462643383279502884197169399375105820974
#define ten5p1 100001
#define ten6p1 1000001
#define ten8p1 100000001
#define ten9p1 1000000001
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define rep(var,n) for(int var=0;var<n;++var)
<<<<<<< HEAD
#define zeroi(data,n) memset(data,0,sizeof(int)*n);
#define zeroll(data,n) memset(data,0,sizeof(long long)*n);
#define writei(var) fprintf(stdout,"%d",var)
#define writeln() fprintf(stdout,"\n")

int readi() {
    int var;
    fscanf(stdin, "%d", &var);
    return var;
=======

FILE* _fin = stdin; // Set the input file to standard input
FILE* _fout = stdout; // Set the output file to standard output

int readi() { 
    int var; 
    fscanf(_fin, "%d", &var); 
    return var; 
}

void writei(int var) { 
    fprintf(_fout, "%d", var); 
}

void writeln() { 
    fprintf(_fout, "\n"); 
>>>>>>> 98c87cb78a (data updated)
}

int main() {
    int a = readi(); // Read integer a
    int b = readi(); // Read integer b
    if (a < b) { // Check if a is less than b
        rep(i, b) writei(a); // Print a b times
        writeln(); // New line
    } else { // Otherwise
        rep(i, a) writei(b); // Print b a times
        writeln(); // New line
    }
    
    return 0;
}

<<<<<<< HEAD
/* <END-OF-CODE> */
=======
/<END-OF-CODE>
>>>>>>> 98c87cb78a (data updated)
