import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read the values of n and m from input
        int n = sc.nextInt();
        int m = sc.nextInt();

        // Read a list of integers from input
        int[] lst = new int[n];
        for (int i = 0; i < n; i++) {
            lst[i] = sc.nextInt();
        }

        // Initialize a dictionary to count occurrences of each integer in the list
        Map<Integer, Integer> l = new HashMap<Integer, Integer>();

        // Count the occurrences of each integer in the list
        for (int i = 0; i < n; i++) {
            if (!l.containsKey(lst[i])) {
                // If the integer is not in the dictionary, add it with a count of 1
                l.put(lst[i], 1);
            } else {
                // If the integer is already in the dictionary, increment its count
                l.put(lst[i], l.get(lst[i]) + 1);
            }
        }

        // Initialize the result variable to store the final count
        int res = 0;

        // Calculate the result based on the occurrences of integers
        for (int i = 0; i < n; i++) {
            if (l.get(lst[i]) > 1) {
                // If the current integer appears more than once
                res += n - i - l.get(lst[i]);  // Add the number of valid pairs
                l.put(lst[i], l.get(lst[i]) - 1);  // Decrease the count of this integer
            } else {
                // If the current integer appears only once
                res += n - i - 1;  // Add the number of valid pairs for unique integers
            }
        }

        // Print the final result
        System.out.println(res);
    }
}

