
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

// Go:

// Constants for general purpose use
const int MOD = 1000000000 + 7; // Modulus value
const int ALPHABET_NUM = 26; // Number of letters in the alphabet
const int INF_INT64 = 1 << 60; // Maximum value for int64
const int INF_BIT60 = 1 << 60; // 2^60
const int INF_INT32 = 1 << 30; // Maximum value for int32
const int INF_BIT30 = 1 << 30; // 2^30
const int NIL = -1; // Represents a null value

// Constants for graph algorithms like Dijkstra and Prim
const int WHITE = 0; // Unvisited state
const int GRAY = 1; // Visited state
const int BLACK = 2; // Processed state

// Function declarations for input reading
string ReadString();

// Go:

// Constants for general purpose use
const int MOD = 1000000000 + 7; // Modulus value
const int ALPHABET_NUM = 26; // Number of letters in the alphabet
const int INF_INT64 = 1 << 60; // Maximum value for int64
const int INF_BIT60 = 1 << 60; // 2^60
const int INF_INT32 = 1 << 30; // Maximum value for int32
const int INF_BIT30 = 1 << 30; // 2^30
const int NIL = -1; // Represents a null value

// Constants for graph algorithms like Dijkstra and Prim
const int WHITE = 0; // Unvisited state
const int GRAY = 1; // Visited state
const int BLACK = 2; // Processed state

// Function declarations for input reading
string ReadString();

// Go:

// Constants for general purpose use
const int MOD = 1000000000 + 7; // Modulus value
const int ALPHABET_NUM = 26; // Number of letters in the alphabet
const int INF_INT64 = 1 << 60; // Maximum value for int64
const int INF_BIT60 = 1 << 60; // 2^60
const int INF_INT32 = 1 << 30; // Maximum value for int32
const int INF_BIT30 = 1 << 30; // 2^30
const int NIL = -1; // Represents a null value

// Constants for graph algorithms like Dijkstra and Prim
const int WHITE = 0; // Unvisited state
const int GRAY = 1; // Visited state
const int BLACK = 2; // Processed state

// Function declarations for input reading
string ReadString();

// Go:

// Constants for general purpose use
const int MOD = 1000000000 + 7; // Modulus value
const int ALPHABET_NUM = 26; // Number of letters in the alphabet
const int INF_INT64 = 1 << 60; // Maximum value for int64
const int INF_BIT60 = 1 << 60; // 2^60
const int INF_INT32 = 1 << 30; // Maximum value for int32
const int INF_BIT30 = 1 << 30; // 2^30
const int NIL = -1; // Represents a null value

// Constants for graph algorithms like Dijkstra and Prim
const int WHITE = 0; // Unvisited state
const int GRAY = 1; // Visited state
const int BLACK = 2; // Processed state

// Function declarations for input reading
string ReadString();

// Go:

// Constants for general purpose use
const int MOD = 1000000000 + 7; // Modulus value
const int ALPHABET_NUM = 26; // Number of letters in the alphabet
const int INF_INT64 = 1 << 60; // Maximum value for int64
const int INF_BIT60 = 1 << 60; // 2^60
const int INF_INT32 = 1 << 30; // Maximum value for int32
const int INF_BIT30 = 1 << 30; // 2^30
const int NIL = -1; // Represents a null value

// Constants for graph algorithms like Dijkstra and Prim
const int WHITE = 0; // Unvisited state
const int GRAY = 1; // Visited state
const int BLACK = 2; // Processed state

// Function declarations for input reading
string ReadString();

// Go:

// Constants for general purpose use
const int MOD = 1000000000 + 7; // Modulus value
const int ALPHABET_NUM = 26; // Number of letters in the alphabet
const int INF_INT64 = 1 << 60; // Maximum value for int64
const int INF_BIT60 = 1 << 60; // 2^60
const int INF_INT32 = 1 << 30; // Maximum value for int32
const int INF_BIT30 = 1 << 30; // 2^30
const int NIL = -1; // Represents a null value

// Constants for graph algorithms like Dijkstra and Prim
const int WHITE = 0; // Unvisited state
const int GRAY = 1; // Visited state
const int BLACK = 2; // Processed state

// Function declarations for input reading
string ReadString();

// Go:

// Constants for general purpose use
const int MOD = 1000000000 + 7; // Modulus value
const int ALPHABET_NUM = 26; // Number of letters in the alphabet
const int INF_INT64 = 1 << 60; // Maximum value for int64
const int INF_BIT60 = 1 << 60; // 2^60
const int INF_INT32 = 1 << 30; // Maximum value for int32
const int INF_BIT30 = 1 << 30; // 2^30
const int NIL = -1; // Represents a null value

// Constants for graph algorithms like Dijkstra and Prim
const int WHITE = 0; // Unvisited state
const int GRAY = 1; // Visited state
const int BLACK = 2; // Processed state

// Function declarations for input reading
string ReadString();

// Go:

// Constants for general purpose use
const int MOD = 1000000000 + 7; // Modulus value
const int ALPHABET_NUM = 26; // Number of letters in the alphabet
const int INF_INT64 = 1 << 60; // Maximum value for int64
const int INF_BIT60 = 1 << 60; // 2^60
const int INF_INT32 = 1 << 30; // Maximum value for int32
const int INF_BIT30 = 1 << 30; // 2^30
const int NIL = -1; // Represents a null value

// Constants for graph algorithms like Dijkstra and Prim
const int WHITE = 0; // Unvisited state
const int GRAY = 1; // Visited state
const int BLACK = 2; // Processed state

// Function declarations for input reading
string ReadString();

// Go:

// Constants for general purpose use
const int MOD = 1000000000 + 7; // Modulus value
const int ALPHABET_NUM = 26; // Number of letters in the alphabet
const int INF_INT64 = 1 << 60; // Maximum value for int64
const int INF_BIT60 = 1 << 60; // 2^60
const int INF_INT32 = 1 << 30; // Maximum value for int32
const int INF_BIT30 = 1 << 30; // 2^30
const int NIL = -1; // Represents a null value

// Constants for graph algorithms like Dijkstra and Prim
const int WHITE = 0; // Unvisited state
const int GRAY = 1; // Visited state
const int BLACK = 2; // Processed state

// Function declarations for input reading
string ReadString();

// Go:

// Constants for general purpose use
const int MOD = 1000000000 + 7; // Modulus value
const int ALPHABET_NUM = 26; // Number of letters in the alphabet
const int INF_INT64 = 1 << 60; // Maximum value for int64
const int INF_BIT60 = 1 << 60; // 2^60
const int INF_INT32 = 1 << 30; // Maximum value for int32
const int INF_BIT30 = 1 << 30; // 2^30
const int NIL = -1; // Represents a null value

// Constants for graph algorithms like Dijkstra and Prim
const int WHITE = 0; // Unvisited state
const int GRAY = 1; // Visited state
const int BLACK = 2; // Processed state

// Function declarations for input reading
string ReadString();

// Go:

// Constants for general purpose use
const int MOD = 1000000000 + 7; // Modulus value
const int ALPHABET_NUM = 26; // Number of letters in the alphabet
const int INF_INT64 = 1 << 60; // Maximum value for int64
const int INF_BIT60 = 1 << 60; // 2^60
const int INF_INT32 = 1 << 30; // Maximum value for int32
const int INF_BIT30 = 1 << 30; // 2^30
const int NIL = -1; // Represents a null value

// Constants for graph algorithms like Dijkstra and Prim
const int WHITE = 0; // Unvisited state
const int GRAY = 1; // Visited state
const int BLACK = 2; // Processed state

// Function declarations for input reading
string ReadString();

// Go:

// Constants for general purpose use
const int MOD = 1000000000 + 7; // Modulus value
const int ALPHABET_NUM = 26; // Number of letters in the alphabet
const int INF_INT64 = 1 << 60; // Maximum value for int64
const int INF_BIT60 = 1 << 60; // 2^60
const int INF_INT32 = 1 << 30; // Maximum value for int32
const int INF_BIT30 = 1 << 30; // 2^30
const int NIL = -1; // Represents a null value

// Constants for graph algorithms like Dijkstra and Prim
const int WHITE = 0; // Unvisited state
const int GRAY = 1; // Visited state
const int BLACK = 2; // Processed state

// Function declarations for input reading
string ReadString();

// Go:

// Constants for general purpose use
const int MOD = 1000000000 + 7; // Modulus value
const int ALPHABET_NUM = 26; // Number of letters in the alphabet
const int INF_INT64 = 1 << 60; // Maximum value for int64
const int INF_BIT60 = 1 << 60; // 2^60
const int INF_INT32 = 1 << 30; // Maximum value for int32
const int INF_BIT30 = 1 << 30; // 2^30
const int NIL = -1; // Represents a null value

// Constants for graph algorithms like Dijkstra and Prim
const int WHITE = 0; // Unvisited state
const int GRAY = 1; // Visited state
const int BLACK = 2; // Processed state

// Function declarations for input reading
string ReadString();

// Go:

// Constants for general purpose use
const int MOD = 1000000000 + 7; // Modulus value
const int ALPHABET_NUM = 26; // Number of letters in the alphabet
const int INF_INT64 = 1 << 60; // Maximum value for int64
const int INF_BIT60 = 1 << 60; // 2^60
const int INF_INT32 = 1 << 30; // Maximum value for int32
const int INF_BIT30 = 1 << 30; // 2^30
const int NIL = -1; // Represents a null value

// Constants for graph algorithms like Dijkstra and Prim
const int WHITE = 0; // Unvisited state
const int GRAY = 1; // Visited state
const int BLACK = 2; // Processed state

// Function declarations for input reading
string ReadString();

// Go:

// Constants for general purpose use
const int MOD = 1000000000 + 7; // Modulus value
const int ALPHABET_NUM = 26; // Number of letters in the alphabet
const int INF_INT64 = 1 << 60; // Maximum value for int64
const int INF_BIT60 = 1 << 60; // 2^60
const int INF_INT32 = 1 << 30; // Maximum value for int32
const int INF_BIT30 = 1 << 30; // 2^30
const int NIL = -1; // Represents a null value

// Constants for graph algorithms like Dijkstra and Prim
const int WHITE = 0; // Unvisited state
const int GRAY = 1; // Visited state
const int BLACK = 2; // Processed state

// Function declarations for input reading
string ReadString();

// Go:

// Constants for general purpose use
const int MOD = 1000000000 + 7; // Modulus value
const int ALPHABET_NUM = 26; // Number of letters in the alphabet
const int INF_INT64 = 1 << 60; // Maximum value for int64
const int INF_BIT60 = 1 << 60; // 