
// Define a long long type for convenience
typedef long long ll;

// Macros for loop iterations
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)

// Macros for input and output
#define in(x) cin >> x
#define out(str) cout << str << endl

// Function to update the maximum value
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }

// Function to update the minimum value
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

// Global variables for number of strings and their length
int L, N;

int main() {
    // Read the number of strings (N) and the length of each string (L)
    cin >> N >> L;

    // Declare an array to hold the strings
    String S[N];

    // Input the strings from the user
    rep(i, N) cin >> S[i];

    // Sort the array of strings in lexicographical order
    Arrays.sort(S);

    // Output the sorted strings
    rep(i, N) cout << S[i];

    // Print a newline at the end of the output
    cout << endl;
}

