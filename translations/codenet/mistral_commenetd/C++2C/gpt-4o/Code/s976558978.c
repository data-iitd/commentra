/*
URL_HERE
*/
/*
This is the main C file for solving a problem. Replace URL_HERE with the URL of the problem statement.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ten5p1 100001
#define ten6p1 1000001
#define ten8p1 100000001
#define ten9p1 1000000001
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define rep(var,n) for(int var=0; var<n; ++var)
#define zeroi(data,n) memset(data, 0, sizeof(int)*n);
#define zeroll(data,n) memset(data, 0, sizeof(long long)*n);
#define writei(var) printf("%d", var)
#define writeln() printf("\n")

int main()
{
    FILE *inputFile = fopen("dataabc155A.txt", "r");
    if (inputFile == NULL) {
        inputFile = stdin;
    }

    int a, b;
    fscanf(inputFile, "%d", &a);
    fscanf(inputFile, "%d", &b);
    /*
    Read the two integers a and b from the input file.
    */

    if (a < b)
    {
        rep(i, b) writei(a);
        writeln();
        /*
        If a is smaller than b, print a b times.
        */
    }
    else
    {
        rep(i, a) writei(b);
        writeln();
        /*
        If b is smaller than a, print b a times.
        */
    }

    if (inputFile != stdin) {
        fclose(inputFile);
    }
    
    return 0;
}

/* <END-OF-CODE> */
