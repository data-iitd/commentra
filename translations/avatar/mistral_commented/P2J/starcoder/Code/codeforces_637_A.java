// Import necessary modules
import java.util.*;

// Set input function to read from standard input
Scanner input = new Scanner(System.in);

// Read the number of strings to be processed
int n = input.nextInt();

// Read the strings and split the last string by space
String[] s = input.nextLine().split(" ");

// Create a HashMap object to store the occurrences of each string
HashMap<String, Integer> w = new HashMap<String, Integer>();

// Iterate through each string
for (int i = 0; i < s.length - 1; i++) {
    // If the string is not in the HashMap
    if (!w.containsKey(s[i])) {
        // Add the string to the HashMap with a value of 1
        w.put(s[i], 1);
    } else {
        // If the string is already in the HashMap, increment its value by 1
        w.put(s[i], w.get(s[i]) + 1);
    }
}

// Initialize variables for storing the index of the longest string and its value
int c = -1, a = 0;

// Iterate through each string in the HashMap
for (String i : w.keySet()) {
    // If the current string has the maximum occurrences
    if (w.get(i) == Collections.max(w.values())) {
        // If its index in the original list is greater than the current index of the longest string
        if (Arrays.asList(s).indexOf(i) > c) {
            // Update the longest string and its index
            a = i;
            c = Arrays.asList(s).indexOf(i);
        }
    }
}

// Print the longest string
System.out.println(a);

