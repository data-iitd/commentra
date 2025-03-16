
import java.util.*;
import java.io.*;

// Define long long type alias for convenience
typedef long long int lint;

// Constants for large values and mathematical constants
long long int INF = 1001001001001001LL;
int inf = 1000000007;
long long int MOD = 1000000007LL;
double PI = 3.1415926535897932;

// Function to update the minimum value
template<typename T1,typename T2>inline void chmin(T1 &a,const T2 &b){if(a>b) a=b;}

// Function to update the maximum value
template<typename T1,typename T2>inline void chmax(T1 &a,const T2 &b){if(a<b) a=b;}

// Macros for convenience in iterating through containers
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()

/* do your best */

public class Main {

  public static void main(String[] args) {

    // Read the number of elements
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();

    // Initialize a vector to store the input values and a vector for prefix sums
    ArrayList<lint> a = new ArrayList<lint>();
    ArrayList<lint> acc = new ArrayList<lint>();

    // Read input values and compute prefix sums modulo MOD
    for (int i = 0; i < n; i++) {
      a.add(sc.nextInt());
      acc.add(acc.get(i) + a.get(i)); // Update prefix sum
      acc.set(i + 1, acc.get(i + 1) % MOD); // Ensure the prefix sum is within MOD
    }

    // Initialize the answer variable
    lint ans = 0;

    // Calculate the final answer using the prefix sums
    for (int i = 0; i < n; i++) {
      ans += a.get(i) % MOD * (MOD + acc.get(n) - acc.get(i + 1)) % MOD; // Update answer based on current element and remaining sum
      ans %= MOD; // Ensure the answer is within MOD
    }

    // Output the final result
    System.out.println(ans);

  } // End of the program

} // End of the class

