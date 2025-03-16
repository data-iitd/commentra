// Import necessary libraries
import java.util.*;

// Define lambda functions for input handling
static int[] I() {
    return Arrays.stream(sc.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
}
static String IS() {
    return sc.nextLine();
}
static int IN() {
    return sc.nextInt();
}
static double IF() {
    return sc.nextDouble();
}

// Read the number of elements
int n = IN();

// Read the list of integers
int[] l = I();

// Initialize a variable to track unique counts
int f = 1;
Arrays.sort(l);

// Initialize a counter for unique elements
int c = 0;

// Iterate through the sorted list to count unique elements
for (int i : l) {
    if (i > c) {
        c++;
    }
}

// Output the total count of unique elements
System.out.println(c + 1);

