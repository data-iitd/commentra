/*
URL:
https://atcoder.jp/contests/abc174/tasks/abc174_f
*/

package main

import (
	"bufio"
	"errors"
	"fmt"
	"io"
	"math"
	"os"
	"sort"
	"strconv"
)

/********** FAU standard libraries **********/

//fmt.Sprintf("%b\n", 255) 	// binary expression

/********** I/O usage **********/

//str := ReadString()               // Read a single string
//i := ReadInt()                    // Read a single integer
//X := ReadIntSlice(n)              // Read a slice of n integers
//S := ReadRuneSlice()               // Read a slice of runes
//a := ReadFloat64()                // Read a single float64
//A := ReadFloat64Slice(n)          // Read a slice of n float64s

//str := ZeroPaddingRuneSlice(num, 32) // Zero pad a rune slice
//str := PrintIntsLine(X...)           // Print integers in a single line

/*******************************************************************/

// Constants used throughout the program
const (
	MOD          = 1000000000 + 7 // Modulus value for calculations
	ALPHABET_NUM = 26              // Number of letters in the alphabet
	INF_INT64    = math.MaxInt64   // Maximum int64 value
	INF_BIT60    = 1 << 60         // 2^60
	INF_INT32    = math.MaxInt32    // Maximum int32 value
	INF_BIT30    = 1 << 30         // 2^30
	NIL          = -1              // Represents a null value

	// Constants for graph algorithms
	WHITE = 0 // Unvisited node
	GRAY  = 1 // Visited node
	BLACK = 2 // Processed node
)

func init() {
	// Initialize the input reader and output writer
	ReadString = newReadString(os.Stdin, bufio.ScanWords) // Set up the string reader
	stdout = bufio.NewWriter(os.Stdout)                    // Set up the buffered writer for stdout
}

var (
	n, q int                // Number of elements and number of queries
	C    []int              // Slice to hold the input values
	Q    []Query            // Slice to hold the queries

	P       [500000 + 50]int // Array to track the last position of each value
	Answers [500000 + 50]int // Array to hold the answers for each query
)

// Query struct to hold the details of each query
class Query {
	int idx, l, r; // Index, left, and right bounds of the query
}

public static void main(String[] args) {
	// Read the number of elements and queries
	n, q = ReadInt2();
	C = ReadIntSlice(n); // Read the slice of integers

	// Initialize the position array with -1 (indicating unvisited)
	for (int i = 1; i <= n; i++) {
		P[i] = -1;
	}

	// Read each query and store it in the Q slice
	for (int i = 0; i < q; i++) {
		int l, r = ReadInt2(); // Read the left and right bounds of the query
		Query query = new Query(i, l, r); // Create a new query
		Q = append(Q, query); // Append the query to the list
	}

	// Sort the queries based on the right bound
	Arrays.sort(Q, (q1, q2) -> q1.r - q2.r);
	FenwickTree ft = new FenwickTree(500000 + 50); // Initialize a Fenwick Tree for range queries

	int k = 0; // Pointer to track the current position in the input array
	// Process each query
	for (Query query : Q) {
		// Update the Fenwick Tree for all elements up to the right bound of the current query
		for (k = 0; k < query.r; k++) {
			if (P[C[k]]!= -1) { // If the current value has been seen before
				ft.add(P[C[k]] + 1, -1); // Remove its previous occurrence from the Fenwick Tree
			}
			P[C[k]] = k; // Update the last position of the current value
			ft.add(k + 1, 1); // Add the current value to the Fenwick Tree
		}
		// Calculate the answer for the current query using the Fenwick Tree
		Answers[query.idx] = ft.sum(query.r) - ft.sum(query.l - 1);
	}

	// Output the answers for all queries
	for (int i = 0; i < q; i++) {
		// System.out.println(Answers[i]); // Print each answer
		PrintfBufStdout("%d\n", Answers[i]); // Output the answer to stdout
	}
	stdout.flush(); // Flush the buffered output
}

// Fenwick Tree structure for efficient range queries
class FenwickTree {
	int[] dat; // Array to store the tree data
	int n; // Number of elements
	int minPow2; // Minimum power of 2 greater than or equal to n
}

// NewFenwickTree initializes a new Fenwick Tree
public FenwickTree(int n) {
	this.dat = new int[n + 1]; // Create the data array
	this.n = n; // Set the number of elements

	// Calculate the minimum power of 2 greater than or equal to n
	minPow2 = 1;
	while (minPow2 < n) {
		minPow2 <<= 1;
	}
}

// Sum calculates the prefix sum from 1 to i (1-based)
public int sum(int i) {
	int s = 0; // Variable to hold the sum

	// Traverse the tree to calculate the sum
	while (i > 0) {
		s += dat[i]; // Add the current index value to the sum
		i -= i & (-i); // Move to the parent index
	}

	return s; // Return the calculated sum
}

// Add updates the Fenwick Tree by adding x to the index i (1-based)
public void add(int i, int x) {
	// Update the tree for the given index
	while (i <= n) {
		dat[i] += x; // Add x to the current index
		i += i & (-i); // Move to the next index
	}
}

// LowerBound returns the minimum index such that the sum is greater than or equal to w
public int lowerBound(int w) {
	if (w <= 0) {
		return 0; // If w is non-positive, return 0
	}

	int x = 0; // Variable to hold the index
	// Traverse the tree to find the lower bound
	for (int k = minPow2; k > 0; k >>= 1) {
		if (x + k <= n && dat[x + k] < w) {
			w -= dat[x + k]; // Decrease w by the current index value
			x += k; // Move to the next index
		}
	}

	return x + 1; // Return the found index (1-based)
}

