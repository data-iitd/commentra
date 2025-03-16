// Import necessary modules
import java.util.*;

// Function to read input from standard input
public static String readLine() throws IOException {
    return new BufferedReader(new InputStreamReader(System.in)).readLine();
}

// Main function
public static void main(String[] args) throws IOException {
    // Read the number of test cases
    int n = Integer.parseInt(readLine());

    // Initialize a HashMap 'w' to store the occurrences of numbers
    HashMap<Integer, Integer> w = new HashMap<Integer, Integer>();

    // Read the input and store the occurrences of numbers
    for (int i = 0; i < n; i++) {
        int x = Integer.parseInt(readLine());
        w.put(x, w.getOrDefault(x, 0) + 1);
    }

    // Initialize a counter 'c' to store the result
    int c = 0;

    // Iterate through each number 'i' in the HashMap 'w'
    for (int i : w.keySet()) {
        // If the number 'i' is zero, then add its occurrences multiplied by (its occurrences - 1) to the counter 'c'
        if (i == 0) {
            c += w.get(i) * (w.get(i) - 1);
        }
        // If the number '-i' is present in the HashMap 'w', then add its occurrences multiplied by the occurrences of 'i' to the counter 'c'
        else if (w.containsKey(-i)) {
            c += w.get(i) * w.get(-i);
        }
    }

    // Print the result divided by 2
    System.out.println(c / 2);
}

