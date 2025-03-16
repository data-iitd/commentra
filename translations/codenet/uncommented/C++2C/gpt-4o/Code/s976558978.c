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

FILE* _fin = stdin;
FILE* _fout = stdout;

int readi() {
    int var;
    fscanf(_fin, "%d", &var);
    return var;
}

<<<<<<< HEAD
#define writei(var) fprintf(_fout,"%d",var)
#define writeln() fprintf(_fout,"\n")
=======
void writei(int var) {
    fprintf(_fout, "%d", var);
}

void writeln() {
    fprintf(_fout, "\n");
}
>>>>>>> 98c87cb78a (data updated)

int main() {
    int a = readi();
    int b = readi();
    
    if (a < b) {
<<<<<<< HEAD
        rep(i, b) {
            writei(a);
            writeln();
        }
    } else {
        rep(i, a) {
            writei(b);
            writeln();
        }
=======
        rep(i, b) writei(a);
        writeln();
    } else {
        rep(i, a) writei(b);
        writeln();
>>>>>>> 98c87cb78a (data updated)
    }
    
    return 0;
}

/<END-OF-CODE>
