// Import necessary modules
import java.util.Scanner;
import java.util.HashMap;
import java.util.Map;

// Function to read input from standard input
public static void input(Scanner sc) {
    // Read the number of test cases
    int n = sc.nextInt();

    // Initialize a HashMap 'w' to store the occurrences of numbers
    Map<Integer, Integer> w = new HashMap<>();

    // Iterate through each test case
    for (int i = 0; i < n; i++) {
        // Read the input
        String s = sc.next();

        // Iterate through each number in the input
        for (int j = 0; j < s.length(); j++) {
            // If the number is not already in the HashMap 'w', then add it with an occurrence of 1
            if (!w.containsKey(s.charAt(j))) {
                w.put(s.charAt(j), 1);
            }
            // Otherwise, increment its occurrence by 1
            else {
                w.put(s.charAt(j), w.get(s.charAt(j)) + 1);
            }
        }
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

// Main function
public static void main(String[] args) {
    // Initialize a Scanner object 'sc' to read input from standard input
    Scanner sc = new Scanner(System.in);

    // Call the function 'input' to read input from standard input
    input(sc);

    // Close the Scanner object 'sc'
    sc.close();
}

// End of code
