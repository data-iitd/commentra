#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cctype>
#include <climits>
#include <cassert>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <utility>
#include <bitset>
#include <complex>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <functional>
#include <numeric>
#include <climits>
#include <cfloat>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <memory>
#include <tuple>
#include <utility>
#include <functional>
#include <numeric>
#include <bitset>
#include <cctype>
#include <cassert>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <functional>
#include <numeric>
#include <utility>
#include <climits>
#include <cfloat>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <memory>
#include <tuple>
#include <utility>
#include <functional>
#include <numeric>
#include <bitset>
#include <cctype>
#include <cassert>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;

// Initialize a new scanner to read from standard input
int sc = 0;

// Function to read the next integer from input
int nextInt() {
    cin >> sc; // Read the next token from input
    return atoi(sc.c_str()); // Convert the token to an integer
}

int main() {
    cin.sync_with_stdio(false); // Turn off synchronization with C-streams
    cin.tie(0); // Tie cin to standard input
    
    // Read the number of apples and pieces from input
    int appleNum = nextInt(); 
    int pieceNum = nextInt(); 
    
    // Calculate the number of pieces made from apples (3 pieces per apple)
    int pieceNumMadeFromApples = appleNum * 3
    
    // Calculate the total number of pieces (pieces from apples + existing pieces)
    int totalPiece = pieceNumMadeFromApples + pieceNum
    
    // Output the total number of complete sets of 2 pieces
    cout << totalPiece / 2 << endl;
}

