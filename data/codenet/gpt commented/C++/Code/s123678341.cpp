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

int main() {
    // Input the sizes of the three arrays and the number K
    int X, Y, Z, K; 
    cin >> X >> Y >> Z >> K;

    // Declare vectors to hold the input values
    vector<ll> A(X);
    vector<ll> B(Y);
    vector<ll> C(Z);

    // Read values into vector A
    for(ll &a : A)
        cin >> a;

    // Read values into vector B
    for(ll &b : B)
        cin >> b;

    // Read values into vector C
    for(ll &c : C)
        cin >> c;

    // Sort the vectors in descending order to facilitate maximum sum calculations
    sort(A.begin(), A.end(), greater<ll>());
    sort(B.begin(), B.end(), greater<ll>());
    sort(C.begin(), C.end(), greater<ll>());

    // Create a vector to store the sums of elements from A and B
    vector<ll> AB;

    // Calculate all possible sums of elements from A and B
    for(int i = 0; i < X; i++) {
        for(int j = 0; j < Y; j++) {
            AB.push_back(A[i] + B[j]);
        }
    }

    // Sort the sums in descending order
    sort(AB.begin(), AB.end(), greater<ll>());

    // Create a vector to store the final sums including elements from C
    vector<ll> ABC;

    // Calculate sums of the top K elements from AB with each element from C
    for(int i = 0; i < min(K, (int)AB.size()); i++) {
        for(int j = 0; j < Z; j++) {
            ABC.push_back(AB[i] + C[j]);
        }
    }

    // Sort the final sums in descending order
    sort(ABC.begin(), ABC.end(), greater<ll>());

    // Output the top K sums from the final vector
    for(int i = 0; i < K; i++) {
        cout << ABC[i] << endl;
    }

    return 0;
}
