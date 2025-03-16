
/*
URL_HERE
*/

/*
This section includes necessary imports and defines various constants and macros.
*/
import java.io.*;
import java.util.*;

// File pointers for input and output
FileInputStream fin = System.in;
FileOutputStream fout = System.out;

// Mathematical constants and limits
final double PI = 3.141592653589793238462643383279502884197169399375105820974;
final int ten5p1 = 100001;
final int ten6p1 = 1000001;
final int ten8p1 = 100000001;
final int ten9p1 = 1000000001;

// Type definitions for convenience
class Pair {
    int x, y;
    Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

// Macros for loop iterations
#define rep(var,n) for(int var=0;var<n;++var)
#define repi(n) rep(i,n)
#define repj(n) rep(j,n)
#define repi1(n) for(int i=1;i<n;++i)
#define repj1(n) for(int j=1;j<n;++j)

// Macros for min and max operations
#define _min(a,b) (a)<(b)?(a):(b)
#define _max(a,b) (a)>(b)?(a):(b)

// Macros for initializing arrays
#define zeroi(data,n) Arrays.fill(data,0,n,0);
#define zeroll(data,n) Arrays.fill(data,0,n,0);
#define one(data,n) {for(int _ONEI=0;_ONEI<n;++_ONEI) data[_ONEI]=1;}

// Functions for reading input
char readc() throws IOException { char var; return (char)fin.read(); }
int readi() throws IOException { int var; return Integer.parseInt(next()); }
long readll() throws IOException { long var; return Long.parseLong(next()); }

// Function to read an array of integers
void repread(int[] data, int n) throws IOException { repi(n) data[i] = readi(); }

// Function to read an array of long long integers
void repread(long[] data, int n) throws IOException { repi(n) data[i] = readll(); }

// Function to read a string, ignoring empty lines
String next() throws IOException {
    String str = "";
    for (;;) {
        if (fin.available() == 0) return str;
        char c = (char)fin.read();
        if (c == '\n' || c == '\r') continue;
        str += c;
    }
}

// Macros for writing output
void writec(char var) throws IOException { fout.write(var); }
void writecsp(char var) throws IOException { fout.write(var); fout.write(' '); }
void writecln(char var) throws IOException { fout.write(var); fout.write('\n'); }
void writei(int var) throws IOException { fout.write(Integer.toString(var)); }
void writeisp(int var) throws IOException { fout.write(Integer.toString(var)); fout.write(' '); }
void writellsp(long var) throws IOException { fout.write(Long.toString(var)); fout.write(' '); }
void writeiln(int var) throws IOException { fout.write(Integer.toString(var)); fout.write('\n'); }
void writellln(long var) throws IOException { fout.write(Long.toString(var)); fout.write('\n'); }
void writeulln(long var) throws IOException { fout.write(Long.toString(var)); fout.write('\n'); }
void writefln(double var) throws IOException { fout.write(Double.toString(var)); fout.write('\n'); }
void writes(String str) throws IOException { fout.write(str.getBytes()); }
void writesp() throws IOException { fout.write(' '); }
void writeln() throws IOException { fout.write('\n'); }

// Macro to check if a number is even
#define iseven(x) ((x&1)==0 ? 1:0)

// Macro to run local tests with a specified input file
#define RUN_LOCAL(testfilename) {fin = new FileInputStream(testfilename); if(fin==null) fin=System.in;}

// Macros for swapping values
#define swap(type,a, b) {type t=a;a=b;b=t;}
#define swapxor(a,b) {a^=b;b^=a;a^=b;}

// Macro for sorting an array
#define sort(data,n) Arrays.sort(data,0,n)

// Macro for modular arithmetic
#define mod(a,b) b==0 ? 0 : a==0 ? 0 :(a>0 ? a%b : b + a % b)

// Function to compute the greatest common divisor (GCD)
long gcd(long a, long b) { if (b == 0) return a; return gcd(b, a % b); }

// Function to reverse an array of integers
void reversei(int[] data, int n) { 
    int k = n >> 1; 
    repi(k) { 
        int tmp = data[i]; 
        data[i] = data[n - i - 1]; 
        data[n - i - 1] = tmp; 
    } 
}

// Function for binary search in a sorted array
int bsearch(int val, int[] data, int n) { 
    if (data[0] > val) return -1; 
    if (data[n - 1] < val) return n; 
    int l = 0; 
    int r = n - 1; 
    for (; l < r;) { 
        int mid = (l + r + 1) >> 1; 
        if (data[mid] <= val) l = mid; 
        else r = mid - 1; 
    }
    if (data[r] != val) ++r; 
    return r; 
}

// Macro to define a dynamic array structure
#define _Vec(type, name) \
class name { type[] data; int size; int n; };\
void init(name t, int size) { t.data = new type[size]; t.size = size; t.n = 0; }\
void resize(name t) { int ns = t.size * 1.2f; t.data = Arrays.copyOf(t.data, ns); t.size = ns; }\
void add(name t, type val) { if (t.n >= t.size) resize(t); int k = t.n; t.data[k] = val; t.n = k + 1; }\
void free(name t) { t.data = null;}\

// Define dynamic array structures for integers, long longs, and strings
_Vec(int, Veci)
_Vec(long, Vecll)
_Vec(String, Vecs)

// Macro to check if two arrays are palindromes
#define _ispal(type, name) int name(type[] a, type[] b, int n){repi(n){if (a[i] != b[n - i - 1]){return 0;}}return 1;}
_ispal(int, ispali)
_ispal(char, ispalc)

// Macro to define a pair structure and comparison functions
#define _Pair(type, name) class name{type x, y;}; \
int cmp_##name(Pair a, Pair b){if (a.x == b.x){if (a.y < b.y) return -1;else return 1;}if (a.x < b.x) return -1;else return 1;}\
void sort_##name(name[] d, int n){Arrays.sort(d,0,n,new Comparator<name>() { public int compare(name a, name b) { return cmp_##name(a, b); } });}\

// Define pair structure and comparison functions for integers
_Pair(int, Pairi)

// Function to compare strings for sorting
int cmp_Str(String a, String b) { 
    return a.compareTo(b); 
}

// Function to sort an array of strings
void sort_Str(String[] str, int n) { 
    Arrays.sort(str,0,n,new Comparator<String>() { public int compare(String a, String b) { return cmp_Str(a, b); } });
}

// Function to compute modular exponentiation
long expmod(long x, long n, long m) {
	long ans = 1;
	for (;n;) {
		if (n & 1) ans = (ans * x) % m; // If n is odd, multiply x with result
		x = (x * x) % m; // Square x
		n >>= 1; // Divide n by 2
	}
	return ans; // Return the result
}

// Function to compute combinations modulo m
long combmod(long n, long k, long m) {
	long ret = 1; // Result of n choose k
	long div = 1; // Denominator for combinations
	for (long i = 0; i < k; ++i) {
		ret = (ret * (n - i) % m) % m; // Numerator
		div = (div * (i + 1)) % m; // Denominator
	}
	div = expmod(div, m - 2, m) % m; // Modular inverse of denominator
	return (ret * div) % m; // Return the result
}

//------------

public class Main {
    public static void main(String[] args) throws IOException {
        // Run local test with specified input file
        RUN_LOCAL("dataabc155A.txt");

        // Read two integers from input
        int a = readi();
        int b = readi();

        // Output the smaller integer b times
        if (a < b)
        {
            repi(b) writei(a); // Write 'a' b times
            writeln(); // New line after output
        }
        else
        {
            repi(a) writei(b); // Write 'b' a times
            writeln(); // New line after output
        }
        
        return; // End of program
    }
}

