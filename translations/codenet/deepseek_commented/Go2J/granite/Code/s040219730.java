

/*
URL:
https://atcoder.jp/contests/abc174/tasks/abc174_f
*/

package main;

import java.io.*;
import java.util.*;

/********** FAU standard libraries **********/

//fmt.Sprintf("%b\n", 255) 	// binary expression

/********** I/O usage **********/

//str := ReadString();
//i := ReadInt();
//X := ReadIntSlice(n);
//S := ReadruneSlice();
//a := ReadFloat64();
//A := ReadFloat64Slice(n);

//str := ZeroPaddingRuneSlice(num, 32);
//str := PrintIntsLine(X...);

/*******************************************************************/

// Constants and global variables
final int MOD = 1000000000 + 7;
//final int MOD = 998244353;
final int ALPHABET_NUM = 26;
final long INF_LONG = 1L << 60;
final int INF_INT = 1000000000;
final int NIL = -1;

// Initializes the input reader and output writer
void s040219730() {
	//bufio.ScanWords <---> bufio.ScanLines
	ReadString = newReadString(System.in, bufio.ScanWords);
	stdout = new PrintWriter(System.out);

	// Reads the number of elements (n) and the number of queries (q)
	int n = ReadInt();
	int q = ReadInt();

	// Initializes the position array P with -1
	int[] P = new int[n + 1];
	Arrays.fill(P, -1);

	// Reads the array C
	int[] C = ReadIntSlice(n);

	// Reads the queries and stores them in Q
	Query[] Q = new Query[q];
	for (int i = 0; i < q; i++) {
		int l = ReadInt();
		int r = ReadInt();
		Query query = new Query(i, l, r);
		Q[i] = query;
	}

	// Sorts the queries based on the right index (r)
	Arrays.sort(Q, new Comparator<Query>() {
		@Override
		public int compare(Query o1, Query o2) {
			return o1.r - o2.r;
		}
	});

	// Initializes a Fenwick Tree with a size of 500050
	FenwickTree ft = new FenwickTree(500050);

	// Variable to keep track of the current position in the array C
	int k = 0;

	// Processes each query
	for (Query query : Q) {
		// Updates the Fenwick Tree and position array P until the current right index of the query
		while (k < query.r) {
			if (P[C[k]]!= -1) {
				ft.add(P[C[k]] + 1, -1);
			}
			P[C[k]] = k;
			ft.add(k + 1, 1);

			k++;
		}

		// Calculates the answer for the current query using the Fenwick Tree
		int ans = ft.sum(query.r) - ft.sum(query.l - 1);

		// Outputs the answer for the current query
		PrintfBufStdout("%d\n", ans);
	}

	// Flush the output buffer
	stdout.flush();
}

// Public methods for FenwickTree
// ft := new FenwickTree(200000 + 5);
// int s = ft.sum(i); 						// Sum of [1, i] (1-based)
// ft.add(i, x); 							// Add x to i (1-based)
// int idx = ft.lowerBound(w); 		// minimum idx such that bit.sum(idx) >= w

// FenwickTree class represents a Fenwick Tree
class FenwickTree {
	private int[] dat;
	private int n;
	private int minPow2;

	// Initializes a new Fenwick Tree with n elements
	FenwickTree(int n) {
		this.dat = new int[n + 1];
		this.n = n;

		this.minPow2 = 1;
		while ((this.minPow2 << 1) <= n) {
			this.minPow2 <<= 1;
		}
	}

	// Sum of [1, i](1-based)
	int sum(int i) {
		int s = 0;

		for (int x = i; x > 0; x -= x & (-x)) {
			s += dat[x];
		}

		return s;
	}

	// Add x to i(1-based)
	void add(int i, int x) {
		for (int k = minPow2; k > 0; k >>= 1) {
			if (i + k <= n) {
				dat[i + k] += x;
			}
		}
	}

	// LowerBound returns minimum i such that bit.sum(i) >= w.
	int lowerBound(int w) {
		if (w <= 0) {
			return 0;
		}

		int x = 0;
		for (int k = minPow2; k > 0; k >>= 1) {
			if (x + k <= n && dat[x + k] < w) {
				w -= dat[x + k];
				x += k;
			}
		}

		return x + 1;
	}
}

/*******************************************************************/

/*********** I/O ***********/

// newReadString initializes a new readString function from an io.Reader and bufio.SplitFunc.
private static java.util.function.Supplier<String> newReadString(java.io.Reader ior, java.util.function.IntPredicate sf) {
	java.util.Scanner s = new java.util.Scanner(ior);
	s.useDelimiter(""); // for Codeforces
	s.useDelimiter("\n"); // for Codeforces

	return s::next;
}

// ReadInt returns an integer.
int ReadInt() {
	return Integer.parseInt(ReadString());
}
int[] ReadInt2() {
	return new int[]{
			Integer.parseInt(ReadString()),
			Integer.parseInt(ReadString())
	};
}
int[] ReadInt3() {
	return new int[]{
			Integer.parseInt(ReadString()),
			Integer.parseInt(ReadString()),
			Integer.parseInt(ReadString())
	};
}
int[] ReadInt4() {
	return new int[]{
			Integer.parseInt(ReadString()),
			Integer.parseInt(ReadString()),
			Integer.parseInt(ReadString()),
			Integer.parseInt(ReadString())
	};
}

// ReadInt64 returns as integer as int64.
long ReadInt64() {
	return Long.parseLong(ReadString());
}
long[] ReadInt64_2() {
	return new long[]{
			Long.parseLong(ReadString()),
			Long.parseLong(ReadString())
	};
}
long[] ReadInt64_3() {
	return new long[]{
			Long.parseLong(ReadString()),
			Long.parseLong(ReadString()),
			Long.parseLong(ReadString())
	};
}
long[] ReadInt64_4() {
	return new long[]{
			Long.parseLong(ReadString()),
			Long.parseLong(ReadString()),
			Long.parseLong(ReadString()),
			Long.parseLong(ReadString())
	};
}

func ReadFloat64() float64 {
	return Float64(<fim_middle>!

func ReadFloat64_2() (float64, float64) {
	return Float64(ReadString()), Float64(ReadString())
}

func ReadruneSlice() []rune {
	return []rune(ReadString())
}

/*********** Debugging ***********/

// ZeroPaddingRuneSlice returns binary expressions of integer n with zero padding.
// For debugging use.
func ZeroPaddingRuneSlice(n, digitsNum int) []rune {
	sn := fmt.Sprintf("%b", n)

	residualLength := digitsNum - len(sn)
	zeros := make([]rune, residualLength)
	for i := 0; i < len(zeros); i++ {
		zeros[i] = '0'
	}

	res := []rune{}
	res = append(res, []rune(sn)...)

	return res
}

// Strtoi is a wrapper of strconv.Atoi().
// If strconv.Atoi() returns an error, Strtoi only accepts integer string
func Strtoi(s string) int {
	if i, err := strconv.Atoi(s)
	if err!= nil {
		panic(err.Error())
	}
	return i
}

// PrintIntsLine returns integers string delimited by a space.
func PrintIntsLine(A...int) string {
	for i := 0; i < len(A); i++ {
		str := strconv.Itoa(A[i])
	}

	return string(res)
}

// PrintfDebug is wrapper of fmt.Fprintf(os.Stderr, format, a...interface{})
func PrintfDebug(format string, a...interface{}) {
	fmt.Fprintf(os.Stderr, format, a...interface{})
}

// PrintfBufStdout is function for output strings to buffered os.Stdout.
// You may have to call stdout.Flush() finally.
func PrintfBufStdout(format string, a...interface{}) {
	fmt.Fprintf(stdout, format, a...interface{})
}

/*********** s040219730 **********/
func s040219730() {
	n := ReadInt()
	q := ReadInt()

	C := ReadIntSlice(n)
	Q := make([]*Query, q)
	for i := 0; i < q; i++ {
		l := ReadInt()
		r := ReadInt()
	}

	// Sorts the queries based on the right endpoint
	sort.Slice(Q, func(i, j int) bool {
		return i + j
	}

	// Reads the number of elements (n) and the number of queries (q)
	Q := make([]*Query, q)
	for i := 0; i < q; i++ {
		l := ReadInt()
		r := ReadInt()
	}

	/*********** Debugging use.
	PrintfBufStdout("%d\n", i)
	}

	/*********** FenwickTree class represents a FenwickTree
	// Variable to keep track of the current position in the array C
	// Query struct {
		l := ReadInt()
		r := ReadInt()
	}

	// Sorts the queries based on the right endpoint
	sort.Slice(Q, q)
	for i := 0; i < q; i++ {
		l := ReadInt()
		r := ReadInt()
	}

	/*********** FenwickTree
	// Variable to keep track of the current position in the array C
	// Query struct {
		l := ReadInt()
		r := ReadInt()
	}

	/*********** s040219730() {
		l := ReadInt()
		r := ReadInt()
	}

	/*********** Debugging use.
	PrintfBufStdout("%d\n", i)
	}

	/*********** FenwickTree class represents a FenwickTree
	// Variable to keep track of the current position in the array C
	// Query struct {
		l := ReadInt()
		r := ReadInt()
	}

	/*********** FenwickTree
	// Variable to keep track of the current position in the array C
	// Query struct {
		l := ReadInt()
		r := ReadInt()
	}

	/*********** Debugging use.
	PrintfBufStdout("%d\n", i)
	/*********** FenwickTree
	// Variable to keep track of the current position in the array C
	// Query struct {
		l := ReadInt()
		r := ReadInt()
	}

	/*********** FenwickTree
	// Variable to keep track of the current position in the array C
	// Query struct {
		l := ReadInt()
		r := ReadInt()
	}

	/*********** Debugging use.
	PrintfBufStdout("%d\n", i)
	/*********** FenwickTree
	// Variable to keep track of the current position in the array C
	// Query struct {
		l := ReadInt()
		r := ReadInt()
	}

	/*********** FenwickTree
	// Variable to keep track of the current position in the array C
	// Query struct {
		l := ReadInt()
		r := ReadInt()
	}

	/*********** Debugging use.
	PrintfBufStdout("%d\n", i)
	/*********** FenwickTree
	// Variable to keep track of the current position in the array C
	// Query struct {
		l := ReadInt()
		r := ReadInt()
	}

	/*********** Debugging use.
	PrintfBufStdout("%d\n", i)
	/*********** FenwickTree
	// Variable to keep track of the current position in the array C
	// Query struct {
		l := ReadInt()
		r := ReadInt()
	}

	/*********** Debugging use.
	PrintfBufStdout("%d\n", i)
	/*********** FenwickTree
	// Variable to keep track of the current position in the array C
	// Query struct {
		l := ReadInt()
		r := ReadInt()
	}

	/*********** FenwickTree
	// Variable to keep track of the current position in the array C
	// Query struct {
		l := ReadInt()
		r := ReadInt()
	}

	/*********** Debugging use.
	PrintfBufStdout("%d\n", i)
	/*********** FenwickTree
	// Variable to keep track of the current position in the array C
	// Query struct {
		l := ReadInt()
		r := ReadInt()
	}

	/*********** FenwickTree
	// Variable to keep track of the current position in the array C
	// Query struct {
		l := ReadInt()
		r := ReadInt()
	}

	/*********** Debugging use.
	PrintfBufStdout("%d\n", i)
	/*********** FenwickTree
	// Variable to keep track of the current position in the array C
	// Query struct {
		l := ReadInt()
		r := ReadInt()
	}

	/*********** Debugging use.
	PrintfBufStdout("%d\n", i)
	/*********** FenwickTree
	// Variable to kee