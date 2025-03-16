/*
URL_HERE
*/

/*
This section includes necessary headers and defines various constants and macros.
*/
import java.io.*;
import java.util.*;

// File pointers for input and output
static BufferedReader _fin = new BufferedReader(new InputStreamReader(System.in));
static BufferedWriter _fout = new BufferedWriter(new OutputStreamWriter(System.out));

// Mathematical constants and limits
static final double PI = 3.141592653589793238462643383279502884197169399375105820974;
static final int ten5p1 = 100001;
static final int ten6p1 = 1000001;
static final int ten8p1 = 100000001;
static final int ten9p1 = 1000000001;

// Type definitions for convenience
static final int uint = int.class;
static final long long ll = long.class;
static final long long ull = long.class;

// Macros for loop iterations
static final int rep(int var, int n) { for(int var=0;var<n;++var) return var; }
static final int repi(int n) { return rep(i,n); }
static final int repj(int n) { return rep(j,n); }
static final int repi1(int n) { for(int i=1;i<n;++i) return i; }
static final int repj1(int n) { for(int j=1;j<n;++j) return j; }

// Macros for min and max operations
static final int _min(int a, int b) { return (a)<(b)?(a):(b); }
static final int _max(int a, int b) { return (a)>(b)?(a):(b); }

// Macros for initializing arrays
static final void zeroi(int[] data, int n) { Arrays.fill(data, 0, n, 0); }
static final void zeroll(long[] data, int n) { Arrays.fill(data, 0, n, 0); }
static final void one(int[] data, int n) { for(int _ONEI=0;_ONEI<n;++_ONEI) data[_ONEI]=1; }

// Functions for reading input
static char readc() { char var; try { var = (char) _fin.read(); } catch (IOException e) { var = 0; } return var; }
static int readi() { int var; try { var = Integer.parseInt(_fin.readLine()); } catch (IOException e) { var = 0; } return var; }
static long readll() { long var; try { var = Long.parseLong(_fin.readLine()); } catch (IOException e) { var = 0; } return var; }

// Function to read an array of integers
static void repread(int[] data, int n) { repi(n) data[i] = readi(); }

// Function to read an array of long long integers
static void repread(long[] data, int n) { repi(n) data[i] = readll(); }

// Function to read a string, ignoring empty lines
static int reads(char[] str, int maxsize)
{
	for (;;) { 
        if (fgets(str, maxsize, _fin) == null) break; 
        if (str[0]!= '\n' && str[0]!= '\r') break; 
    }
	int slen = strlen(str); 
    if (slen == 0) return 0;
	if (str[slen - 1] == '\n' || str[slen - 1] == '\r') str[--slen] = 0;
	return slen;
}

// Macros for writing output
static final void writec(char var) { try { _fout.write(var); } catch (IOException e) {} }
static final void writecsp(char var) { try { _fout.write(var + " "); } catch (IOException e) {} }
static final void writecln(char var) { try { _fout.write(var + "\n"); } catch (IOException e) {} }
static final void writei(int var) { try { _fout.write(var); } catch (IOException e) {} }
static final void writeisp(int var) { try { _fout.write(var + " "); } catch (IOException e) {} }
static final void writellsp(long var) { try { _fout.write(var + " "); } catch (IOException e) {} }
static final void writeiln(int var) { try { _fout.write(var + "\n"); } catch (IOException e) {} }
static final void writellln(long var) { try { _fout.write(var + "\n"); } catch (IOException e) {} }
static final void writeulln(long var) { try { _fout.write(var + "\n"); } catch (IOException e) {} }
static final void writefln(double var) { try { _fout.write(var + "\n"); } catch (IOException e) {} }
static final void writes(char[] str) { try { _fout.write(str); } catch (IOException e) {} }
static final void writesp() { try { _fout.write(" "); } catch (IOException e) {} }
static final void writeln() { try { _fout.write("\n"); } catch (IOException e) {} }

// Macro to check if a number is even
static final int iseven(int x) { return (x&1)==0? 1:0; }

// Macro to run local tests with a specified input file
static final void RUN_LOCAL(String testfilename) { _fin = new BufferedReader(new FileReader(testfilename)); }

// Macros for swapping values
static final void swap(int[] data, int a, int b) { int t=data[a];data[a]=data[b];data[b]=t; }
static final void swap(long[] data, int a, int b) { long t=data[a];data[a]=data[b];data[b]=t; }
static final void swap(int[] data, int a, int b, int c) { int t=data[a];data[a]=data[b];data[b]=data[c];data[c]=t; }
static final void swap(long[] data, int a, int b, int c) { long t=data[a];data[a]=data[b];data[b]=data[c];data[c]=t; }
static final void swapxor(int[] data, int a, int b) { data[a]^=data[b];data[b]^=data[a];data[a]^=data[b]; }
static final void swapxor(long[] data, int a, int b) { data[a]^=data[b];data[b]^=data[a];data[a]^=data[b]; }

// Macro for sorting an array
static final void sort(int[] data, int n) { Arrays.sort(data, 0, n); }
static final void sort(long[] data, int n) { Arrays.sort(data, 0, n); }

// Macro for modular arithmetic
static final int mod(int a, int b) { return b==0? 0 : a==0? 0 :(a>0? a%b : b + a % b); }

// Function to compute the greatest common divisor (GCD)
static final long gcd(long a, long b) { return b==0? a:gcd(b, a % b); }

// Function to reverse an array of integers
static final void reversei(int[] data, int n) { 
    int k = n >> 1; 
    repi(k) { 
        int tmp = data[i]; 
        data[i] = data[n - i - 1]; 
        data[n - i - 1] = tmp; 
    } 
}

// Function for binary search in a sorted array
static final int bsearch(int val, int[] data, int n) { 
    if (data[0] > val) return -1; 
    if (data[n - 1] < val) return n; 
    int l = 0; 
    int r = n - 1; 
    for (; l < r;) { 
        int mid = (l + r + 1) >> 1; 
        if (data[mid] <= val) l = mid; 
        else r = mid - 1; 
    }
    if (data[r]!= val) ++r; 
    return r; 
}

// Macro to define a dynamic array structure
#define _Vec(type, name) \
static class name { \
	type[] data; \
	int size; \
	int n; \
	name(int size) { this.size = size; data = new type[size]; n = 0; } \
	void resize() { int ns = size * 1.2f; type[] tmp = new type[ns]; System.arraycopy(data, 0, tmp, 0, n); data = tmp; size = ns; } \
	void add(type val) { if (n >= size) resize(); data[n++] = val; } \
	void free() { data = null; } \
}

// Define dynamic array structures for integers, long longs, and strings
_Vec(int, Veci)
_Vec(long, Vecll)
_Vec(String, Vecs)

// Macro to check if two arrays are palindromes
#define _ispal(type, name) static final int name(type[] a, type[] b, int n){repi(n){if (a[i]!= b[n - i - 1]){return 0;}}return 1;}
_ispal(int, ispali)
_ispal(char, ispalc)

// Macro to define a pair structure and comparison functions
#define _Pair(type, name) static class name {type x, y;} \
static int cmp_##name(name a, name b) {if (a.x == b.x){if (a.y < b.y) return -1;else return 1;}if (a.x < b.x) return -1;else return 1;} \
static void sort_##name(name[] d, int n) { Arrays.sort(d, 0, n, new Comparator<name>() { public int compare(name a, name b) { return cmp_##name(a, b); } }); }
_Pair(int, Pairi)

// Function to compare strings for sorting
static int cmp_Str(String a, String b) { return a.compareTo(b); }

// Function to sort an array of strings
static void sort_Str(String[] str, int n) { Arrays.sort(str, 0, n, new Comparator<String>() { public int compare(String a, String b) { return cmp_Str(a, b); } }); }

// Function to compute modular exponentiation
static long expmod(long x, long n, long m) {
	long ans = 1;
	for (;n;) {
		if (n & 1) ans = (ans * x) % m; // If n is odd, multiply x with result
		x = (x * x) % m; // Square x
		n >>= 1; // Divide n by 2
	}
	return ans; // Return the result
}

// Function to compute combinations modulo m
static long combmod(long n, long k, long m) {
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

public static void main(String[] args)
{
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

