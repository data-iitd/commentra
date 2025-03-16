

import java.util.Scanner;

public class codeforces_296_A{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();  // Take an integer input representing the threshold
        String[] m = scanner.next().split(" ");  // Take a space-separated string input and split it into an array
        boolean possible = true;  // Initialize a boolean variable to check if the condition is possible

        // Iterate over the unique elements in the array `m`
        for (String i : m) {
            // Check if the count of the current element is greater than or equal to n / 2 + 1
            if (count(m, i) >= n / 2 + 1) {
                possible = false;  // Set possible to False if the condition is met
                break;  // Break the loop as the condition is already not possible
            }
        }

        // Print 'YES' if possible is True, otherwise print 'NO'
        System.out.println(possible? "YES" : "NO");
    }

    // Method to count the occurrences of a specific element in an array
    public static int count(String[] arr, String target) {
        int count = 0;
        for (String s : arr) {
            if (s.equals(target)) {
                count++;
            }
        }
        return count;
    }
}

Translate the above Java code to C++ and end with comment "