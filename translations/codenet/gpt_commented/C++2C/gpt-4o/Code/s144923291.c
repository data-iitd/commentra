#include <stdio.h>
#include <string.h>

<<<<<<< HEAD
#define MAX_HEIGHT 10
#define MAX_WIDTH 10

int main() {
    // Read height and width of the grid
    long long h, w;
=======
// Define maximum values for different data types
#define intmax INT_MAX
#define lmax LONG_MAX
#define uintmax UINT_MAX
#define ulmax ULONG_MAX
#define llmax LLONG_MAX
#define ll long long

// Macros for loop iterations
#define rep(i,a,N) for((i)=(a);(i)<(N);(i)++)
#define rrp(i,N,a) for((i)=(N)-1;(i)>=(a);(i)--)

// Input and output macros
#define sc(a) scanf("%s", a)
#define pr(a) printf("%lld\n", a)
#define pY puts("YES")
#define pN puts("NO")
#define py puts("Yes")
#define pn puts("No")
#define pnn printf("\n")

// Mathematical constants and utility functions
/*pi*/ double pi=acos(-1);
/* Ceiling division */ ll cei(ll x,ll y){ll ans=x/y;if(x%y!=0)ans++;return ans;}
/* Greatest common divisor */ ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
/* Least common multiple */ ll lcm(ll x,ll y){return x/gcd(x,y)*y;}

/* Variable declarations */
ll ans=0;////////////////////////////////////////////////////////////

int main(){
    // Read height and width of the grid
    ll h, w;
>>>>>>> 98c87cb78a (data updated)
    scanf("%lld %lld", &h, &w);

    // Initialize a temporary character array and the target string
    char t[10], s[10] = "snuke";

    // Iterate through the grid to find the target string
<<<<<<< HEAD
    for (long long i = 0; i < h; i++) {
        for (long long j = 0; j < w; j++) {
            // Read the current string from input
            scanf("%s", t);
=======
    ll i, j;
    rep(i, 0, h) {
        rep(j, 0, w) {
            // Read the current string from input
            sc(t);
>>>>>>> 98c87cb78a (data updated)
            // Check if the current string matches the target string
            if (strcmp(s, t) == 0) {
                // If found, calculate the position and print it
                char c = 'A' + j; // Convert column index to character
                printf("%c%lld\n", c, i + 1); // Output the position in the required format
                return 0; // Exit the program after finding the target
            }
        }
    }

    // Return 0 to indicate successful execution
    return 0;
}

// <END-OF-CODE>
