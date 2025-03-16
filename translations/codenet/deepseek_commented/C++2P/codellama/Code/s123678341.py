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

int main(){
    # Step 1: Reading Inputs
    X, Y, Z, K = map(int, input().split())
    
    # Step 2: Vector Initialization and Input
    A = [0] * X
    B = [0] * Y
    C = [0] * Z
    for i in range(X):
        A[i] = int(input())
    for i in range(Y):
        B[i] = int(input())
    for i in range(Z):
        C[i] = int(input())
    
    # Step 3: Sorting
    A.sort(reverse=True)
    B.sort(reverse=True)
    C.sort(reverse=True)
    
    # Step 4: Combining A and B
    AB = []
    for i in range(X):
        for j in range(Y):
            AB.append(A[i] + B[j])
    
    # Step 5: Sorting AB
    AB.sort(reverse=True)
    
    # Step 6: Combining AB and C
    ABC = []
    for i in range(min(K, len(AB))):
        for j in range(Z):
            ABC.append(AB[i] + C[j])
    
    # Step 7: Sorting ABC
    ABC.sort(reverse=True)
    
    # Step 8: Output
    for i in range(K):
        print(ABC[i])
    
    return 0
}
