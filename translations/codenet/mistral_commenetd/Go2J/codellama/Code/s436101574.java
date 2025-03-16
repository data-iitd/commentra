
import java.util.*;
import java.io.*;

// Initializing scanner and writer
Scanner sc = new Scanner(System.in);
PrintWriter wr = new PrintWriter(System.out);

// Function to read a single string
String scanString() {
	return sc.next();
}

// Function to read a single integer
int scanInt() {
	return sc.nextInt();
}

// Function to read a single integer64
long scanInt64() {
	return sc.nextLong();
}

// Function to read a single float64
double scanFloat64() {
	return sc.nextDouble();
}

// Function to read multiple integers
int[] scanInts(int n) {
	int[] res = new int[n];
	for (int i = 0; i < n; i++) {
		res[i] = sc.nextInt();
	}
	return res;
}

// Function to print debug information
void debug(Object... a) {
	System.err.println(Arrays.deepToString(a));
}

// Function to get absolute value of an integer
int abs(int a) {
	if (a < 0) {
		return -a;
	}
	return a;
}

// Function to get minimum of two integers
int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

// Function to get maximum of two integers
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

// Main function
public static void main(String[] args) {
	wr.println("Hello, World!");
	wr.flush();
	sc.close();
}

