
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

//str := ReadString()               // Read a single string
//i := ReadInt()                    // Read a single integer
//X := ReadIntSlice(n)              // Read a slice of n integers
//S := ReadruneSlice()               // Read a slice of runes
//a := ReadFloat64()                // Read a single float64
//A := ReadFloat64Slice(n)          // Read a slice of n float64s

/*******************************************************************/

// Constants used throughout the program
final int MOD = 1000000000 + 7; // Modulus value for calculations
final int ALPHABET_NUM = 26;      // Number of letters in the alphabet
final int INF_INT64 = Long.MAX_VALUE;   // Maximum int64 value
final int INF_BIT60 = 1L << 60;         // 2^60
final int INF_INT32 = Integer.MAX_VALUE;    // Maximum int32 value
final int INF_BIT30 = 1 << 30;         // 2^30
final int NIL = -1;              // Represents a null value

// Constants for graph algorithms
final int WHITE = 0; // Unvisited node
final int GRAY  = 1; // Visited node
final int BLACK = 2; // Processed node

public class s040219730{
	// Variables for input and output
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter stdout = new BufferedWriter(new OutputStreamWriter(System.out));

	// Read a single string
	static String ReadString() throws IOException {
		return br.readLine();
	}

	// Read a single integer
	static int ReadInt() throws IOException {
		return Integer.parseInt(ReadString());
	}

	// Read a single integer
	static long ReadLong() throws IOException {
		return Long.parseLong(ReadString());
	}

	// Read a single integer
	static double ReadDouble() throws IOException {
		return Double.parseDouble(ReadString());
	}

	// Read a single integer
	static char ReadChar() throws IOException {
		return ReadString().charAt(0);
	}

	// Read a single integer
	static String[] ReadStringArray() throws IOException {
		return br.readLine().split(" ");
	}

	// Read a single integer
	static String[] ReadStringArray(int n) throws IOException {
		String[] A = new String[n];
		for (int i = 0; i < n; i++) {
			A[i] = ReadString();
		}
		return A;
	}

	// Read a single integer
	static int[] ReadIntArray() throws IOException {
		return Arrays.stream(ReadStringArray()).mapToInt(Integer::parseInt).toArray();
	}

	// Read a single integer
	static int[] ReadIntArray(int n) throws IOException {
		int[] A = new int[n];
		for (int i = 0; i < n; i++) {
			A[i] = ReadInt();
		}
		return A;
	}

	// Read a single integer
	static long[] ReadLongArray() throws IOException {
		return Arrays.stream(ReadStringArray()).mapToLong(Long::parseLong).toArray();
	}

	// Read a single integer
	static long[] ReadLongArray(int n) throws IOException {
		long[] A = new long[n];
		for (int i = 0; i < n; i++) {
			A[i] = ReadLong();
		}
		return A;
	}

	// Read a single integer
	static double[] ReadDoubleArray() throws IOException {
		return Arrays.stream(ReadStringArray()).mapToDouble(Double::parseDouble).toArray();
	}

	// Read a single integer
	static double[] ReadDoubleArray(int n) throws IOException {
		double[] A = new double[n];
		for (int i = 0; i < n; i++) {
			A[i] = ReadDouble();
		}
		return A;
	}

	// Read a single integer
	static char[] ReadCharArray() throws IOException {
		return ReadString().toCharArray();
	}

	// Read a single integer
	static char[] ReadCharArray(int n) throws IOException {
		char[] c = new char[n];
		for (int i = 0; i < n; i++) {
			c[i] = ReadChar();
		}
		return c;
	}

	// Read a single integer
	static int[][] ReadIntMatrix(int H, int W) throws IOException {
		int[][] A = new int[H][W];
		for (int i = 0; i < H; i++) {
			A[i] = ReadIntArray();
		}
		return A;
	}

	// Read a single integer
	static int[][] ReadIntMatrix(int H, int W) throws IOException {
		int[][] A = new int[H][W];
		for (int i = 0; i < H; i++) {
			A[i] = ReadIntArray();
		}
		return A;
	}

	// Read a single integer
	static long[][] ReadLongMatrix(int H, int W) throws IOException {
		long[][] A = new long[H][W];
		for (int i = 0; i < H; i++) {
			A[i] = ReadLongArray();
		}
		return A;
	}

	// Read a single integer
	static String[] ReadStringArray(int n) throws IOException {
		String[] A = new String[n];
		for (int i = 0; i < n; i++) {
			A[i] = ReadString();
		}
		return A;
	}

	// Read a single integer
	static int[][] ReadIntMatrix(int H, int W) throws IOException {
		int[][] A = new int[H][W];
		for (int i = 0; i < H; i++) {
			A[i] = ReadIntArray();
		}
		return A;
	}

	// Read a single integer
	static int[][] ReadIntMatrix(int H, int W) throws IOException {
		int[][] A = new int[H][W];
		for (int i = 0; i < H; i++) {
			A[i] = ReadIntArray();
		}
		return A;
	}

	// Read a single integer
	static int[] ReadIntArray() throws IOException {
		int[] A = new int[n];
		for (int i = 0; i < n; i++) {
			A[i] = ReadInt()
		}
		return A;
	}

	// Read a single integer
	static int[] ReadIntArray(int n) throws IOException {
		int[] A = new int[n];
		for (int i = 0; i < n; i++) {
			A[i] = ReadInt()
		}
		return A;
	}

	// Read a single integer
	static int[][] ReadIntMatrix(int H, int W) throws IOException {
		int[][] A = new int[H][W];
		for (int i = 0; i < H; i++) {
			A[i] = ReadInt()
		}
		return A;
	}

	// Read a single integer
	static int[][] ReadIntMatrix(int H, int W) throws IOException {
		int[][] A = new int[H][W];
		for (int i = 0; i < H; i++) {
			A[i] = ReadInt()
		}
		return A;
	}

	// Read a single integer
	static int ReadInt() throws IOException {
		int[] A = new int[n];
		for (int i = 0; i < n; i++) {
			A[i] = ReadInt()
		}
		return A;
	}

	// Read a single integer
	static int ReadInt() throws IOException {
		int[] A = new int[n];
		for (int i = 0; i < n; i++) {
			A[i] = ReadInt()
		}
		return A;
	}

	// Read a single integer
	static int ReadInt() throws IOException {
		int[] A = new int[n];
		for (int i = 0; i < n; i++) {
			A[i] = ReadInt()
		}
		return A;
	}

	// Read a single integer
	static int ReadInt() throws IOException {
		int[] A = new int[n];
		for (int i = 0; i < n; i++) {
			A[i] = ReadInt()
		}
		return A;
	}

	// Read a single integer
	static int ReadInt() throws IOException {
		int[] A = new int[n];
		for (int i = 0; i < n; i++) {
			A[i] = ReadInt()
		}
		return A;
	}

	// Read a single integer
	static int ReadInt() throws IOException {
		int[] A = new int[n];
		for (int i = 0; i < n; i++) {
			A[i] = ReadInt()
		}
		return A;
	}

	// Read a single integer
	static int ReadInt() throws IOException {
		int[] A = new int[n];
		for (int i = 0; i < n; i++) {
			A[i] = ReadInt()
		}
		return A;
	}

	// Read a single integer
	static int ReadInt() throws IOException {
		int[] A = new int[n];
		for (int i = 0; i < n; i++) {
			A[i] = ReadInt()
		}
		return A;
	}

	// Read a single integer
	static int ReadInt() throws IOException {
		int[] A = new int[n];
		for (int i = 0; i < n; i++) {
			A[i] = ReadInt()
		}
		return A;
	}

	// Read a single integer
	static int ReadInt() throws IOException {
		int[] A = new int[n];
		for (int i = 0; i < n; i++) {
			A[i] = ReadInt()
		}
		return A;
	}

	// Read a single integer
	static int ReadInt() throws IOException {
		int[] A = new int[n];
		for (int i = 0; i < n; i++) {
			A[i] = ReadInt()
		}
		return A;
	}

	// Read a single integer
	static int ReadInt() throws IOException {
		int[] A = new int[n];
		for (int i = 0; i < n; i++) {
			A[i] = ReadInt()
		}
		return A;
	}

	// Read a single integer
	static int ReadInt() throws IOException {
		int[] A = new int[n];
		for (int i = 0; i < n; i++) {
			A[i] = ReadInt()
		}
		return A;
	}

	// Read a single integer
	static int ReadInt() throws IOException {
		int[] A = new int[n];
		for (int i = 0; i < n; i++) {
			A[i] = ReadInt()
		}
		return A;
	}

	// Read a single integer
	static int ReadInt() throws IOException {
		int[] A = new int[n];
		for (int i = 0; i < n; i++) {
			A[i] = ReadInt()
		}
		return A;
	}

	// Read a single integer
	static int ReadInt() throws IOException {
		int[] A = new int[n];
		for (int i = 0; i < n; i++) {
			A[i] = ReadInt()
		}
		return A;
	}

	// Read a single integer
	static int ReadInt() throws IOException {
		int[] A = new int[n];
		for (int i = 0; i < n; i++) {
			A[i] = ReadInt()
		}
		return A;
	}

	// Read a single integer
	static int ReadInt() throws IOException {
		int[] A = new int[n];
		for (int i = 0; i < n; i++) {
			A[i] = ReadInt()
		}
		return A;
	}

	// Read a single integer
	static int ReadInt() throws IOException {
		int[] A = new int[n];
		for (int i = 0; i < n; i++) {
			A[i] = ReadInt()
		}
		return A;
	}

	// Read a string
	static int ReadInt() throws IOException {
		int[] A = new int[n];
		for (int i = 0; i < n; i++) {
			A[i] = ReadInt()
		}
		return A;
	}

	// Read a string
	static int ReadInt() throws IOException {
		int[] A = new int[n];
		for (int i = 0; i < n; i++) {
			A[i] = ReadInt()
		}
		return A;
	}

	// Read a string
	static int ReadInt() throws IOException {
		int[] A = new int[n];
		for (int i = 0; i < n; i++) {
			A[i] = ReadInt()
		}
		return A;
	}

	// Read a string
	static int ReadInt() throws IOException {
		int[] A = new int[n];
		for (int i = 0; i < n; i++) {
			A[i] = ReadInt()
		}
		return A;
	}

	// Read a string
	static int ReadInt() throws IOException {
		int[] A = new int[n);
		for (int i = 0; i < n; i++) {
			A[i] = ReadInt()
		}
		return A;
	}

	// Read a string
	static int ReadInt() throws IOException {
		int[] A = new int[n];
		for (int i = 0; i < n; i++) {
			A[i] = ReadInt()
		}
		return A;
	}

	// Read a string
	static int ReadInt() throws IOException {
	int[] A = new int[n);
	for (int i = 0; i < n; i++) {
		A[i] = ReadInt()
		}
		return A;
	}

	// Read a string
	static int ReadInt() throws IOException {
		int[] A = new int[n] {
