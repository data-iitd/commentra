
#####
// Import necessary libraries
#####

import java.util.*;
import java.io.*;

// Define helper functions
class Helper {
    public static <T> T hpop(PriorityQueue<T> heap) { return heap.poll(); }
    public static <T> boolean hpush(PriorityQueue<T> heap, T item) { return heap.offer(item); }
}

#####
// Function to find the solution
#####

class Solution {
    public static void solution() {
        // Read the first line and count the number of occurrences of each color
        Scanner sc = new Scanner(System.in);
        String line = sc.nextLine();
        Map<Character, Integer> bought_count = new HashMap<>();
        for (char color : line.toCharArray()) {
            bought_count.put(color, bought_count.getOrDefault(color, 0) + 1);
        }

        // Read the second line and count the number of occurrences of each color
        line = sc.nextLine();
        Map<Character, Integer> made_cout = new HashMap<>();
        for (char color : line.toCharArray()) {
            made_cout.put(color, made_cout.getOrDefault(color, 0) + 1);
        }

        // Initialize result to 0
        int res = 0;

        // Iterate through each color in made_cout
        for (char color : made_cout.keySet()) {
            // Check if the color is present in bought_count
            if (!bought_count.containsKey(color)) {
                // If not, print -1 and exit the function
                System.out.println(-1);
                return;
            }

            // Update the result by adding the minimum of bought and made counts
            res += Math.min(bought_count.get(color), made_cout.get(color));
        }

        // Print the result
        System.out.println(res);
    }

    // codeforces_408_B function to run the solution function for multiple test cases
    public static void main(String[] args) {
        // Read the number of test cases
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        // Run the solution function for each test case
        for (int i = 0; i < t; i++) {
            solution();
        }
    }
}

// Translate the above Java code to C++ and end with comment "