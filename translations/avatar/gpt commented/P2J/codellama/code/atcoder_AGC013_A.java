
// Import necessary libraries
import java.util.*;
import java.lang.*;
import java.io.*;

// Function to read a line of input and strip whitespace
public static String input() throws IOException {
    return br.readLine().trim();
}

// Function to read an integer from input
public static int INT() throws IOException {
    return Integer.parseInt(input());
}

// Function to read a list of integers from input
public static List<Integer> MAP() throws IOException {
    return Arrays.stream(input().split(" ")).map(Integer::parseInt).collect(Collectors.toList());
}

// Function to read a list of integers and return it as an array
public static int[] LIST() throws IOException {
    return Arrays.stream(input().split(" ")).mapToInt(Integer::parseInt).toArray();
}

// Function to read multiple lists of integers and return them as tuples
public static List<List<Integer>> ZIP(int n) throws IOException {
    List<List<Integer>> lists = new ArrayList<>();
    for (int i = 0; i < n; i++) {
        lists.add(MAP());
    }
    return lists;
}

// Set the recursion limit to a high value
Thread.setStackSize(1000000);

// Define a constant for infinity
final int INF = 1000000000;

// Define a constant for the modulo value
final int mod = 1000000007;

// Read the number of elements
int N = INT();

// Read the list of integers
int[] A = LIST();

// Remove consecutive duplicates from the list
Set<Integer> set = new HashSet<>();
for (int i : A) {
    set.add(i);
}
A = set.stream().mapToInt(i -> i).toArray();

// Update N to the new length of A after removing duplicates
N = A.length;

// Initialize the index and answer counter
int i = 1;
int ans = 0;

// Loop through the list to count the number of peaks and valleys
while (i < N - 1) {
    // Check if the current element is a peak or a valley
    if (A[i - 1] < A[i] > A[i + 1] || A[i - 1] > A[i] < A[i + 1]) {
        ans++; // Increment the answer for each peak/valley found
        i++; // Skip the next element to avoid double counting
    }
    i++; // Move to the next element
}

// Print the total count of peaks and valleys plus one
System.out.println(ans + 1);

