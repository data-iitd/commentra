// Import necessary modules
import java.io.*;
import java.util.*;

// Function to read a list of integers from standard input
public static List<Integer> I() {
    return Arrays.stream(System.in.readLine().split(" ")).map(Integer::parseInt).collect(Collectors.toList());
}

// Function to read an integer from standard input
public static int IS() {
    return Integer.parseInt(System.in.readLine());
}

// Function to read an integer from standard input and convert it to an integer
public static int IN() {
    return Integer.parseInt(System.in.readLine());
}

// Function to read a float from standard input
public static float IF() {
    return Float.parseFloat(System.in.readLine());
}

// Read the number of test cases 'n'
int n = IN();

// Read the list 'l' of length 'n' containing 'n' integers
List<Integer> l = I();

// Initialize variable 'f' to 1
int f = 1;

// Sort the list 'l' in ascending order
Collections.sort(l);

// Initialize variable 'c' to 0
int c = 0;

// Iterate through the list 'l'
for (int i : l) {
    // If the current element 'i' is greater than the previous count 'c', increment 'c' by 1
    if (i > c) {
        c += 1;
    }
}

// Print the final result, which is the number of unique elements in the list 'l' plus 1
System.out.println(c + 1);

