
// Import necessary libraries and modules
import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;

// Define constants and global variables
int N;  // Number of inputs
String[][] S;  // List of strings as inputs
String[] march = {"M", "A", "R", "C", "H"};  // List of marching orders
int[] march_lis = new int[5];  // List to store the count of each marching order
int ans = 0;  // Variable to store the answer
int INF = 1000000007;  // Infinity value

// Define functions if any
// Function to read input as integer
static int input() {
    return sc.nextInt();
}
// Function to read input as list of integers
static int[] LIST() {
    return Arrays.stream(sc.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
}
// Function to read input as list of integers with given number of inputs
static int[][] ZIP(int n) {
    int[][] arr = new int[n][];
    for (int i = 0; i < n; i++) {
        arr[i] = LIST();
    }
    return arr;
}
// Set recursion limit
Thread.setStackSize(100000000);

// Main logic of the code
// Initialize march_lis with zeros
march_lis = new int[5];
// Iterate through each string in S and increment the count of the corresponding marching order in march_lis
for (String[] s : S) {
    if (s[0].toUpperCase().equals(march[0]) || s[0].toUpperCase().equals(march[1]) || s[0].toUpperCase().equals(march[2]) || s[0].toUpperCase().equals(march[3]) || s[0].toUpperCase().equals(march[4])) {
        march_lis[march.indexOf(s[0].toUpperCase())] += 1;
    }
}
// Calculate the answer by finding the triple product of the counts of each marching order
for (int x : march_lis) {
    for (int y : march_lis) {
        for (int z : march_lis) {
            ans += x * y * z;
        }
    }
}
// Print the answer
System.out.println(ans);


Translate the above Java code to C++ and end with comment "