
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
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
#define fs first
#define sc second
#define INF 1000000000
#define MOD 1000000007
#define EPS 0.00000001

// Main function starts here
int main(){
    // Initialize input variables
    int X, Y, Z, K; // Number of elements in vectors A, B, C and the limit for output
    cin >> X >> Y >> Z >> K; // Read input values for X, Y, Z, and K from standard input

    // Initialize vectors A, B, and C
    vector<ll> A(X); // A vector of size X, initialized with zeroes
    vector<ll> B(Y); // B vector of size Y, initialized with zeroes
    vector<ll> C(Z); // C vector of size Z, initialized with zeroes

    // Read input values for vectors A, B, and C from standard input
    for(ll &a:A)
        cin >> a; // Read each element of vector A
    for(ll &b:B)
        cin >> b; // Read each element of vector B
    for(ll &c:C)
        cin >> c; // Read each element of vector C

    // Sort vectors A, B, and C in descending order
    sort(A.begin(), A.end(), greater<ll>());
    sort(B.begin(), B.end(), greater<ll>());
    sort(C.begin(), C.end(), greater<ll>());

    // Create a new vector AB by adding each element of A to each element of B
    vector<ll> AB;
    for(int i=0; i<X; i++){
        for(int j=0; j<Y; j++){
            AB.push_back(A[i]+B[j]); // Add A[i] and B[j] and push the sum into vector AB
        }
    }

    // Sort vector AB in descending order
    sort(AB.begin(), AB.end(), greater<ll>());

    // Create a new vector ABC by adding each element of AB to each element of C
    vector<ll> ABC;
    for(int i=0; i<min(K, (int)AB.size()); i++){
        for(int j=0; j<Z; j++){
            ABC.push_back(AB[i] + C[j]); // Add AB[i] and C[j] and push the sum into vector ABC
        }
    }

    // Sort vector ABC in descending order
    sort(ABC.begin(), ABC.end(), greater<ll>());

    // Print K smallest elements of vector ABC
    for(int i=0; i<K; i++){
        cout << ABC[i] << endl; // Print each element of vector ABC
    }

    // Main function ends here
    return 0;
}