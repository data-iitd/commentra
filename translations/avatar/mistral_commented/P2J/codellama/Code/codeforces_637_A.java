// Import necessary modules
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

// Set input function to read from standard input
Scanner input = new Scanner(System.in);

// Read the number of strings to be processed
int n = input.nextInt();

// Read the strings and split the last string by space
ArrayList<String> s = new ArrayList<String>();
for (int i = 0; i < n - 1; i++) {
    s.add(input.next());
}

// Create a Counter object to store the occurrences of each string
ArrayList<String> w = new ArrayList<String>();
for (int i = 0; i < s.size(); i++) {
    if (!w.contains(s.get(i))) {
        w.add(s.get(i));
    }
}

// Initialize variables for storing the index of the longest string and its value
int c = -1, a = 0;

// Iterate through each string in the Counter object
for (int i = 0; i < w.size(); i++) {
    // If the current string has the maximum occurrences
    if (Collections.frequency(s, w.get(i)) == Collections.max(w, new Comparator<String>() {
        @Override
        public int compare(String o1, String o2) {
            return Collections.frequency(s, o1) - Collections.frequency(s, o2);
        }
    })) {
        // If its index in the original list is greater than the current index of the longest string
        if (s.indexOf(w.get(i)) > c) {
            // Update the longest string and its index
            a = w.get(i);
            c = s.indexOf(w.get(i));
        }
    }
}

// Print the longest string
System.out.println(a);

