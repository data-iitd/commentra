// Import necessary libraries and modules
import java.util.*;
import java.io.*;

// Define constants and global variables
final int N = 100000;  // Number of inputs
final String[] march = {"M", "A", "R", "C", "H"};  // List of marching orders
int[] march_lis = new int[5];  // List to store the count of each marching order
int ans = 0;  // Variable to store the answer
final int INF = 1000000000;  // Infinity value
final int mod = 1000000007;  // Modulus value

// Define functions if any
// Function to read input as integer
public static int input() {
    return Integer.parseInt(new BufferedReader(new InputStreamReader(System.in)).readLine());
}
// Function to read input as list of integers
public static List<Integer> LIST() {
    return new BufferedReader(new InputStreamReader(System.in)).readLine().split(" ").stream().map(Integer::parseInt).collect(Collectors.toList());
}
// Function to read input as list of integers with given number of inputs
public static List<Integer> ZIP(int n) {
    return new BufferedReader(new InputStreamReader(System.in)).readLine().split(" ").stream().map(Integer::parseInt).limit(n).collect(Collectors.toList());
}

// Main logic of the code
// Initialize march_lis with zeros
Arrays.fill(march_lis, 0);
// Iterate through each string in S and increment the count of the corresponding marching order in march_lis
for (String[] s : S) {
    if (s[0].toUpperCase().equals(march[0])) {
        march_lis[0]++;
    } else if (s[0].toUpperCase().equals(march[1])) {
        march_lis[1]++;
    } else if (s[0].toUpperCase().equals(march[2])) {
        march_lis[2]++;
    } else if (s[0].toUpperCase().equals(march[3])) {
        march_lis[3]++;
    } else if (s[0].toUpperCase().equals(march[4])) {
        march_lis[4]++;
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

