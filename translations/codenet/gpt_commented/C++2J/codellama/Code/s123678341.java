#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <random>
#include <chrono>
#include <queue>
#include <ctime>
using namespace std;

// Type definitions for convenience
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

// Constants for large values and precision
#define fs first
#define sc second
#define INF 1000000000
#define MOD 1000000007
#define EPS 0.00000001

public class Solution {
    public static void main(String[] args) {
        // Input the sizes of the three arrays and the number K
        int X, Y, Z, K; 
        Scanner sc = new Scanner(System.in);
        X = sc.nextInt();
        Y = sc.nextInt();
        Z = sc.nextInt();
        K = sc.nextInt();

        // Declare vectors to hold the input values
        Vector<ll> A = new Vector<ll>(X);
        Vector<ll> B = new Vector<ll>(Y);
        Vector<ll> C = new Vector<ll>(Z);

        // Read values into vector A
        for(int i = 0; i < X; i++) {
            A.add(sc.nextLong());
        }

        // Read values into vector B
        for(int i = 0; i < Y; i++) {
            B.add(sc.nextLong());
        }

        // Read values into vector C
        for(int i = 0; i < Z; i++) {
            C.add(sc.nextLong());
        }

        // Sort the vectors in descending order to facilitate maximum sum calculations
        Collections.sort(A, Collections.reverseOrder());
        Collections.sort(B, Collections.reverseOrder());
        Collections.sort(C, Collections.reverseOrder());

        // Create a vector to store the sums of elements from A and B
        Vector<ll> AB = new Vector<ll>();

        // Calculate all possible sums of elements from A and B
        for(int i = 0; i < X; i++) {
            for(int j = 0; j < Y; j++) {
                AB.add(A.get(i) + B.get(j));
            }
        }

        // Sort the sums in descending order
        Collections.sort(AB, Collections.reverseOrder());

        // Create a vector to store the final sums including elements from C
        Vector<ll> ABC = new Vector<ll>();

        // Calculate sums of the top K elements from AB with each element from C
        for(int i = 0; i < min(K, (int)AB.size()); i++) {
            for(int j = 0; j < Z; j++) {
                ABC.add(AB.get(i) + C.get(j));
            }
        }

        // Sort the final sums in descending order
        Collections.sort(ABC, Collections.reverseOrder());

        // Output the top K sums from the final vector
        for(int i = 0; i < K; i++) {
            System.out.println(ABC.get(i));
        }

        sc.close();
    }
}

