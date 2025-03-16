
```cpp
#include <bits/stdc++.h>
using namespace std;

// Define constants for general purpose usage
const int MOD = 1000000000 + 7;
const int ALPHABET_NUM = 26;
const int INF_INT64 = 1LL << 60;
const int INF_BIT60 = 1 << 30;
const int NIL = -1;
// Constants for graph algorithms
const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

// Type definition for generic operations
typedef int T;

// Structure for the re-rooting solver
struct ReRootingSolver {
    int NodeCount; // Number of nodes
    vector<vector<int>> Adjacents; // Adjacency list
    vector<vector<int>> IndexForAdjacents; // Index mapping for adjacency
    vector<T> Res; // Result array
    vector<vector<T>> DP; // Dynamic programming table

    T Identity; // Identity element for operations
    function<T(T, T)> Operate; // Operation function
    function<T(T, int)> OperateNode; // Node operation function

    ReRootingSolver(int nodeCount, vector<vector<int>> edges, int identity, function<T(T, T)> operate, function<T(T, int)> operateNode) {
        NodeCount = nodeCount;
        Identity = identity;
        Operate = operate;
        OperateNode = operateNode;

        // Initialize adjacency lists
        Adjacents.resize(nodeCount);
        IndexForAdjacents.resize(nodeCount);
        for (auto &e : edges) {
            // Build adjacency list and index mapping
            IndexForAdjacents[e[0]].push_back(Adjacents[e[1]].size());
            IndexForAdjacents[e[1]].push_back(Adjacents[e[0]].size());
            Adjacents[e[0]].push_back(e[1]);
            Adjacents[e[1]].push_back(e[0]);
        }

        // Initialize DP and result arrays
        DP.resize(nodeCount);
        Res.resize(nodeCount);

        if (NodeCount > 1) {
            Initialize();
        } else {
            // Base case for a single node
            Res[0] = OperateNode(Identity, 0);
        }
    }

    // Query function to get the result for a specific node
    T Query(int node) {
        return Res[node]; // Return the result for the queried node
    }

    // Initialize the re-rooting solver
    void Initialize() {
        vector<int> parents(NodeCount), order(NodeCount);

        // Depth-first search to establish parent-child relationships and order of nodes
        int index = 0;
        stack<int> stack;
        stack.push(0); // Start from the root node
        parents[0] = -1; // Root has no parent
        for (int i = 0; i < NodeCount; i++) {
            order[index] = i; // Record the order of nodes
            index++;
            for (int i = 0; i < NodeCount; i++) {
                stack.push(i); // Add child to the stack
                parents[i] = -1; // Set parent
            }
        }

        // Process nodes from leaves to root
        for (int i = NodeCount - 1; i >= 1; i--) {
            int node = order[i]; // Record the order of nodes
            int parent = parents[node];

            T accum = Identity; // Initialize accumulator
            int parentIndex = -1;
            for (int j = 0; j < Adjacents[node].size(); j++) {
                int adjacent = Adjacents[node][j];
                if (adjacent == parents[node]) {
                    continue; // Skip the parent node
                accum = Operate(accum, DP[node][j]); // Accumulate results from children
            }
            DP[parent][IndexForAdjacents[node][parentIndex] = accum; // Update DP for parent
        }

        // Process nodes from root to leaves
        for (int i = 0; i < NodeCount; i++) {
            T accum = Identity; // Initialize accumulator
            T accumsFromTail(int i = NodeCount - 1; i >= 1; i--) {
                T accumsFromTail(int j = len(accumsFromTail) - 1; j >= 1; j--) {
                    accumsFromTail[j-1] = Operate(DP[node][s.IndexForAdjacents[node][parentIndex] = OperateNode(accum, node) // Update DP for parent
                    accum = Operate(s.DP[s.Adjacents[node][s.IndexForAdjacents[node][j] = OperateNode(accum, node) // Update DP for node
                    accum = Operate(accum, node) // Update DP for node
                    accum = Operate(accum, node) // Update DP for node
                    accum = Operate(accum, node) // Update DP for node
                    accum = Operate(accum, node) // Update DP for node
                    accum = Operate(accum, node) // Update DP for node
                    accum = Operate(accum, node) // Update DP for node
                    accum = Operate(accum, node) // Update DP for node
                    accum = Operate(accum, node) // Update DP for node

// ReadInt returns an integer.
func ReadInt() int {
	i, err := strconv.ParseInt(ReadString(), 0, 64)
	if err!= nil {
		panic(err.Error()) // Panic if scanning fails
	}
	return i // Return scanned integer

// ReadInt2 returns two integers.
func ReadInt2() (int, int) {
	i, _ := strconv.Atoi(ReadString()) // Convert input string to int
	return i // Return parsed integer

// ReadInt64 returns an int64.
func ReadInt64() int64 {
	i, _ := strconv.ParseInt(ReadString(), 0, 64)
	if err!= nil {
		panic(err.Error()) // Panic if parsing fails
	}
	return i // Return parsed integer

// ReadIntSlice returns a slice of integers of size n.
func ReadIntSlice(n int) []int {
	b := make([]int, n) // Create a slice of size n
	for i := 0; i < n; i++ {
		b[i] = ReadInt() // ReadInt2 returns two integers.
func ReadInt2() (int, int) {
	return i, _ := strconv.ParseInt(ReadString(), 0, 64)
	if err!= nil {
		panic(err.Error()) // Panic if parsing fails
	}
	return i // Return parsed integer

// ReadInt64Slice returns a slice of int64 of size n.
func ReadInt64Slice(n int) []int64 {
	b := make([]int64, n) // Create a slice of size n
	for i := 0; i < n; i++ {
		b[i] = ReadInt() // Read int
		b[i] = ReadInt2() (int, int) {
	x, y := ReadInt() // Read two integers
	if err!= nil {
		panic(err.Error()) // Panic if parsing fails
	}
	return x // Return parsed integer

// ReadInt64Slice(n int) []int64 {
	b := make([]int, n) // Create a slice of size n
	for i := 0; i < n; i++ {
		b[i] = ReadInt() // Read int
		b[i] = ReadInt2() (int, int) {
	x, y := ReadInt2() // Read two integers
	if err!= nil {
		panic(err.Error()) // Panic if parsing fails
	}
	return x // Return parsed integer

// ReadInt64Slice(n int) []int64 {
	b := make([]int64, n) // Create a slice of size n
	for i := 0; i < n; i++ {
		b[i] = ReadInt() // Read int
		b[i] = ReadInt2() // Read two integers
	x, y := ReadInt2() // Read two integers
	if err!= nil {
		panic(err.Error()) // Panic if parsing fails
	}
	return x // Return parsed integer

// ReadInt64() // Read int64
	if err!= nil {
		panic(err.Error()) // Panic if parsing fails
	}
	return i, _ := strconv.ParseInt(ReadString(), 0, 64)
	if err!= nil {
		panic(err.Error()) // Panic if parsing fails
	}
	return i // Return parsed integer

// ReadIntSlice(n int) []int {
	b := make([]int, n) // Create a slice of size n
	for i := 0; i < n; i++ {
		b[i] = ReadInt() // Read int
		b[i] = ReadInt2() // Read two integers
		if err!= nil {
			panic(err.Error()) // Panic if parsing fails
	}
	return i, _ := strconv.ParseInt(ReadString(), 0, 64)
	if err!= nil {
		panic(err.Error()) // Panic if parsing fails
	}
	return i, _ := strconv.ParseInt(ReadString(), 0, 64)
	if err!= nil {
		panic(err.Error()) // Panic if parsing fails
	}
	return i, _ := strconv.ParseInt(ReadString(), 0, 64)
	if err!= nil {
		panic(err.Error()) // Panic if parsing fails
	}
	return i, _ := strconv.ParseInt(ReadString(), 0, 64)
	if err!= nil {
		panic(err.Error()) // Panic if parsing fails
	}
	return i, _ := strconv.ParseInt(ReadString(), 0, 64)
	if err!= nil {
		panic(err.Error()) // Panic if parsing fails
	}
	return i, _ := strconv.ParseInt(ReadString()) // Read int
	if err!= nil {
		panic(err.Error()) // Panic if parsing fails
	}
	return i, _ := strconv.ParseInt(ReadString()) // Read int
	if err!= nil {
		panic(err.Error()) // Panic if parsing fails
	}
	return i, _ := strconv.ParseInt(ReadString()) // Read int
	if err!= nil {
		panic(err.Error()) // Panic if parsing fails
	}
	return i, _ := strconv.ParseInt(ReadString()) // Read int
	if err!= nil {
		panic(err.Error()) // Panic if parsing fails
	}
	return i, _ := strconv.ParseInt(ReadString()) // Read int
	if err!= nil {
		panic(err.Error()) // Panic if parsing fails
	}
	return i, _ := strconv.ParseInt(ReadString(), 0, 64)
	if err!= nil {
		panic(err.Error()) // Panic if parsing fails
	}
	return i, _ := strconv.ParseInt(ReadString()) // Read int
	if err!= nil {
		panic(err.Error()) // Panic if parsing fails
	}
	return i, _ := strconv.ParseInt(ReadString()) // Read int
	if err!= nil {
		panic(err.Error()) // Panic if parsing fails
	}
	return i, _ := strconv.ParseInt(ReadString()) // Read int
	if err!= nil {
		panic(err.Error()) // Panic if parsing fails
	}
	return i, _ := strconv.ParseInt(ReadString()) // Read int
	if err!= nil {
		panic(err.Error()) // Panic if parsing fails
	}
	return i, _ := strconv.ParseInt(ReadString()) // Read int
	if err!= nil {
		panic(err.Error()) // Panic if parsing fails
	}
	return i, _ := strconv.ParseInt(ReadString()) // Read int
	if err!= nil {
		panic(err.Error()) // Panic if parsing fails
	}
	return i, _ := strconv.ParseInt(ReadString()) // Read int
	if err!= nil {
		panic(err.Error()) // Panic if parsing fails
	}
	return i, _ := strconv.ParseInt(ReadString()) // Read int
	if err!= nil {
		panic(err.Error()) // Panic if parsing fails
	}
	return i, _ := strconv.ParseInt(ReadString()) // Read int
	if err!= nil {
		panic(err.Error()) // Panic if parsing fails
	}
	return i, _ := strconv.ParseInt(ReadString()) // Read int
	if err!= nil {
		panic(err.Error()) // Panic if parsing fails
	}
	return i, _ := strconv.ParseInt(ReadString()) // Read int
	if err!= nil {
		panic(err.Error()) // Panic if parsing fails
	}
	return i, _ := strconv.ParseInt(ReadString()) // Read int
	if err!= nil {
		panic(err.Error()) // Panic if parsing fails
	}
	return i, _ := strconv.ParseInt(ReadString()) // Read int
	if err!= nil {
		panic(err.Err