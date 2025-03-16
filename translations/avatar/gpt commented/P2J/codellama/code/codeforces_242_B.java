import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

// Define a lambda function to read a list of integers from input
List<Integer> I = () -> {
    String[] arr = br.readLine().split(" ");
    List<Integer> list = new ArrayList<>();
    for (int i = 0; i < arr.length; i++) {
        list.add(Integer.parseInt(arr[i]));
    }
    return list;
};
// Define a lambda function to read a single line of input as a string
String IS = () -> br.readLine();
// Define a lambda function to read a single integer from input
int IN = () -> Integer.parseInt(br.readLine());
// Define a lambda function to read a single float from input
float IF = () -> Float.parseFloat(br.readLine());

// Read the number of intervals
int n = IN();

// Initialize the index for the result
int id = 0;

// Read the first interval's bounds
int l = IN(), r = IN();

// Iterate through the remaining intervals
for (int i = 1; i < n; i++) {
    // Read the current interval's bounds
    int li = IN(), ri = IN();
    
    // Check if the current interval completely contains the previous one
    if (li <= l && r <= ri) {
        id = i;  // Update the index to the current interval
    }
    // Check if the current interval overlaps with the previous one
    else if (li < l || r < ri) {
        id = n;  // Mark as overlapping by setting id to n
    }
    
    // Update the bounds of the union of intervals
    l = Math.min(l, li);  // Update the left bound
    r = Math.max(r, ri);  // Update the right bound
}

// Print the result: -1 if no valid interval found, otherwise print the 1-based index of the interval
System.out.println(id == n ? -1 : id + 1);

