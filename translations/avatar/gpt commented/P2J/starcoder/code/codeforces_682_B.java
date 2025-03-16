// Import necessary libraries
import java.util.*;

// Define lambda functions for input handling
Supplier<Integer> I = () -> Arrays.stream(Arrays.stream(System.in.readLine().split(" ")).mapToInt(Integer::parseInt).toArray()).sum();
Supplier<String> IS = () -> System.console().readLine();
Supplier<Integer> IN = () -> Integer.parseInt(IS.get());
Supplier<Double> IF = () -> Double.parseDouble(IS.get());

// Read the number of elements
int n = IN.get();

// Read the list of integers
int[] l = new int[n];
for (int i = 0; i < n; i++) {
    l[i] = I.get();
}

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

