
/*
                                                                                                     
                                             `-:://:::-                                             
                                           `//:-------:/:`                                          
                                         .+:--.......--:+`                                         
                                         `+:--..`````..--//`                                        
                                        .o:--..`` ``..--:o`                                        
                                        .o:--..`````..--:+/`                                        
                                       `/y+o/---....---:+o.                                         
                                   `...````-os+/:---:/+o/--.`                                       
              `-/+++++/:.      `...`       :h+d+oooo+/+-`  ...                                     
            `/++//:::://++-`....`         -.`//````````:`     `..`                                  
           `o+/::------://o/`           `-` -.          -`       `..`                               
 `---.-o/:./o/::-..``..-ЗАПУСKAЕМ     .. ..            -`        `...       ``..``                
  `....o+:-++/:--.```..-://s.        `-` .-              -`          `-o:.-//::::/:-`             
          `:s+/:--....-::/+s-`     .-   `-                -`           -///:--------:/:`           
          ./s+//:::::://oo-``..НЕЙРОННУЮ: СЕТЬ:::::::-`РАБОТЯГИ        `+:--........--:/`          
           .:ooo+++++osso-`    `.:-...`/`./::-------:/:`   -`         :+--..``````.--:+:...-+:-`  
             `.-/+++++/+-.-`    -.   ``:so:/:--.......--:+`  `-```````o+/+--..`````..--:o/-..:s+:.  
                 ```````:``.. `-`     -` `+:--..`````..--/+-.../.`````..-o:--.......---/o.    `     
                        `:  `:-      -. .o:--..`` ``..--:o`   `-`      `:o+:--------:+o-`          
                         `-`-...   ..  .o/--...```..--:+/`    `-`     `oy/so/////++o/.`           
                          -/`  `-` `- ``+s/o/:---...---:++.      `-`  .-../d://///:-.`             
                `.---..``-..-   .-/..`````-oo+/:::::/+o+-        `-``-`  `-.  ````                 
             `:++++/+++++- ..``.-/:`      /y-:/++o++/:.`..`      ./.   `-                         
            -++/::::::://+/..:-``:`..   `-.`  ```.```    `..`   `..`-` `-                          
       ``  -o//:--....-::/++` -.-`   `-`.-`                 `..`..`  `-.-                           
  -----ss+:++/:--.```..-://s.  /.     `::                    `-:.    ./`                           
  `````/:..+o/::-..``.--:/+s...-`   `-``-+o+/:::::::/+o/.  `-         `:+:-..`````..--:o/:--/ys+-  
            `-++///////+o/. ``....`-.    :` `.:++++++/:.` .-           -o/---......---/o.   `.`    
           `++//:-----::/+o:..`    .-`   :    ```````   .-           `+so+:--------:++-`          
  `````:-``:o/::-..`..--:/+o`         -.  `-            .-          `../../+o+////+o+:.`           
  -----syo/o+/:--.```..-://s.         .-` `-          .-        `...     ``-:////:-``             
      .` `/s//:--....-::/+s.            -. `-`       .-       `..`                                
          .+o+/:::--::/+s/-..`         .::+y  ``` .-     `..`                                   
           ./oo++////+oso-`   `....       :y-+:::::::/`  ...                                      
             `.:+oooooo/-`         `....-..//:-------:/:-.`                                        
                ``...``                 /+:+:--.......--:+`                                         
                                         `+:--..`````..--//`                                        
                                        .o:--..`` ``..--:o`                                        
                                        .+/--...```..--:+/`                                        
                                         `-o/:---...---:++.                                         
                                          `-+o+/:---:/+o/.                                          
                                            `.:+oooo+/-.`                                           
                                               ``````                                               
*/
#pragma GCC optimize("fast-math") // Optimize for fast mathematical operations
#pragma GCC optimize("unroll-loops") // Optimize loop unrolling
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <tuple>
#include <math.h>
#include <set>
#include <stack>
#include <bitset>
#include <map>
#include <queue>
#include <random>
#include <unordered_set>
#include <unordered_map>

// Define macros for convenience
#define DEBUG
#define fi first
#define se second
#define pqueue priority_queue
#define pb(x) push_back(x)
//#define endl '\n'
#define all(x) x.begin(), x.end()
#define int long long // Use long long for integer types
#define mk(a, b) make_pair(a, b)

using namespace std;

// Type definitions for convenience
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ull> vull;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;
typedef pair<ll, ll> pll;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<vector<ll>> vvll;
typedef vector<char> vc;

// Constants for mathematical operations and limits
const ll INF = 1e9 + 228; // Infinity constant
const ll INFLL = 1e18; // Long long infinity constant
const ll MOD = 1e9 + 7; // Modulus for operations
const ld eps = 1e-6; // Epsilon for floating point comparisons
const ld eps2 = 1e-9; // Another epsilon for precision
const ll MOD2 = 998244353; // Another modulus constant
const ll dosz = 5e5; // Size constant
const ll SZ = (1 << 18); // Size constant for bit manipulation
const ld PI = atan2l(0, -1); // Pi constant

// Function to optimize input/output
void fast_io() {
    ios_base::sync_with_stdio(0); // Fast input/output
    cin.tie(0); // Untie cin from cout
    // Uncomment the following lines to read from and write to files
    // freopen("cowjog.in", "r", stdin);
    // freopen("cowjog.out", "w", stdout);
}

// s634121896 logic to solve the problem
void solve() {
    int n; // Number of elements
    cin >> n; // Input number of elements
    vi nums(n); // Vector to store the elements
    int last = 0; // Variable to track the last index
    for (int i = 0; i < n; i++) {
        cin >> nums[i]; // Input each element
    }
    
    // Dynamic programming array to store results
    vi dp(n + 1, 0);
    dp[0] = 1; // Base case: one way to select zero elements
    unordered_map<int, int> kek; // Map to store the last occurrence of each number
    unordered_map<int, int> prev; // Map to store the previous index of each number
    
    // Fill the dynamic programming array
    for (int i = 1; i <= n; i++) {
        // Update dp[i] based on previous values and occurrences
        dp[i] = dp[i - 1] + (prev[nums[i - 1]]!= i - 1? kek[nums[i - 1]] : 0);
        dp[i] %= MOD; // Apply modulus to avoid overflow
        kek[nums[i - 1]] = dp[i]; // Update the last occurrence
        prev[nums[i - 1]] = i; // Update the previous index
    }
    
    cout << dp[n] << endl; // Output the result
}

// s634121896 function
signed main() {
    fast_io(); // Optimize input/output
    srand(time(NULL)); // Seed the random number generator
    cout << fixed << setprecision(12); // Set output precision
    int q = 1; // Number of queries
    // Uncomment the following line to read the number of queries
    // cin >> q;
    while (q--)
        solve(); // Solve the problem for each query
}

