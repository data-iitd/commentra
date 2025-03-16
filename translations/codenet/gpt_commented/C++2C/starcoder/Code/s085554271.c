#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// Macros for convenience
#define IOS ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define prec printf("%.15f\n",);
#define endl "\n"
#define MOD 1000000007
#define Int int64_t
#define PI 3.14159265358979
#define ssort(z) qsort(z, sizeof(z)/sizeof(z[0]), sizeof(z[0]), cmpfunc)
#define rsort(z) qsort(z, sizeof(z)/sizeof(z[0]), sizeof(z[0]), rcmpfunc)
#define eerase(z) z = eerase_unique(z, sizeof(z)/sizeof(z[0]))
#define ccnt(z, w) count(z, z+sizeof(z)/sizeof(z[0]), w)
#define rep(i,a,n) for(Int (i)=(a); (i)<(n); (i)++)
#define repq(i,a,n) for(Int (i)=(a); (i)<=(n); (i)++)

// Constants for maximum limits
const int MAX_N = 1000000;
const Int MAX_N_Int = 1000000000000;

// Function to print a vector with a specified separator
void printV(const int *v, int n, const char * const separator)
{
    if(!n) return;
    printf("%d", v[0]);
    for(int i=1; i<n; i++) printf("%s%d", separator, v[i]);
    printf("\n");
}

// Function to check if a number is prime
bool isPrime(int num)
{
    if (num < 2) return false; // Numbers less than 2 are not prime
    else if (num == 2) return true; // 2 is prime
    else if (num % 2 == 0) return false; // Exclude even numbers

    double sqrtNum = sqrt(num); // Calculate square root for optimization
    for (int i = 3; i <= sqrtNum; i += 2) // Check for factors from 3 to sqrt(num)
    {
        if (num % i == 0)
        {
            return false; // Not a prime number
        }
    }

    return true; // Number is prime
}

// Function to calculate the greatest common divisor (GCD)
Int gcd(Int a, Int b) {
    return b!= 0? gcd(b, a % b) : a; // Recursive GCD calculation
}

// Function to calculate the least common multiple (LCM)
Int lcm(Int a, Int b) {
    return a / gcd(a, b) * b; // LCM using GCD
    // a*b may cause 64-bit integer overflow
}

// Function to find the maximum of three integers
int Max(int a, int b, int c) {
    int temp = max(a, b);
    return max(temp, c); // Return the maximum value
}

// Function to find the minimum of three integers
int Min(int a, int b, int c) {
    int temp = min(a, b);
    return min(temp, c); // Return the minimum value
}

// Function to check if a double is an integer
bool integer(double num) {
    return floor(num) == num; // Check if the number is an integer
}

// Recursive function to calculate factorial
Int fact(int num) {
    if (num == 0)
        return 1; // Base case for factorial
    else
        return num * fact(num - 1); // Recursive case
}

// Function to count the number of divisors of n
Int yakusu(int n) {
    int cnt = 0; // Counter for divisors
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            cnt++; // Count the divisor
            if (i * i!= n) cnt++; // Count the complementary divisor if it's different
        }
    }
    return cnt; // Return the count of divisors
}

// Function to calculate factorial modulo a given number
Int fact_mod(Int n, Int mod) {
    Int f = 1; 
    repq(i,2,n) f = f * (i % MOD) % MOD; // Calculate factorial with modulo
    return f; // Return the result
}

// Function to perform modular exponentiation
Int mod_pow(Int x, Int n, Int mod) {
    Int res = 1; // Initialize result
    while(n > 0) {
        if(n & 1) res = (res * x) % mod; // If n is odd, multiply x with result
        x = (x * x) % mod; // Square x
        n >>= 1; // Divide n by 2
    }
    return res; // Return the result
}

// Function to calculate combinations nCr modulo a given number
Int combination_mod(Int n, Int r, Int mod) {
    if(r > n-r) r = n-r; // Use symmetry property of combinations
    if(r == 0) return 1; // Base case for combinations
    Int a = 1; 
    rep(i, 0, r) a = a * ((n-i) % mod) % mod; // Calculate numerator
    Int b = mod_pow(fact_mod(r, mod), mod-2, mod); // Calculate denominator using Fermat's Little Theorem
    return (a % mod) * (b % mod) % mod; // Return the result
}

// Function to check if a string is a palindrome
bool rev(char *s){
    char *t=s;
    int n=strlen(s);
    for(int i=0; i<n/2; i++) swap(s[i], s[n-i-1]); // Reverse the string
    return!strcmp(s, t); // Check if the original string is equal to the reversed string
}

// Function to compare two integers
int cmpfunc(const void *a, const void *b) {
    return *(int*)a - *(int*)b; // Compare two integers
}

// Function to compare two integers in reverse order
int rcmpfunc(const void *a, const void *b) {
    return *(int*)b - *(int*)a; // Compare two integers in reverse order
}

// Function to remove duplicates from an array
int *eerase_unique(int *z, int n) {
    int *p = z; // Pointer to the current element
    for(int i=1; i<n; i++) {
        if(z[i]!= z[i-1]) {
            p++; // Move the pointer to the next element
            z[p] = z[i]; // Copy the element to the next element
        }
    }
    return p+1; // Return the pointer to the next element
}

// Main function
int main() {
    IOS; // Optimize input/output
    prec; // Set precision for output
    Int a,b,c,n,m,k,x,y=0,ans=0; // Declare variables
    char str[1000000],s[1000000],t[1000000],u[1000000]; // Declare string variables
    scanf("%d%d%d", &k, &a, &b); // Input values for k, a, and b

    // Check for multiples of k in the range [a, b]
    for (int i = a; i <=b; ++i) {
        if(i%k==0){
            printf("OK\n"); // Output OK if a multiple is found
            return 0; // Exit the program
        }
    }
    printf("NG"); // Output NG if no multiples are found

    printf("\n"); // Print a newline
    return 0; // Return success
}

/*
テレビも無ェ ラジオも無ェ
自動車もそれほど走って無ェ
ピアノも無ェ バーも無ェ
巡査 毎日ぐーるぐる
朝起ぎで 牛連れで
二時間ちょっとの散歩道
電話も無ェ 瓦斯も無ェ
バスは一日一度来る
俺らこんな村いやだ 俺らこんな村いやだ
東京へ出るだ 東京へ出だなら
銭コァ貯めで 東京でベコ(牛)飼うだ
*/

