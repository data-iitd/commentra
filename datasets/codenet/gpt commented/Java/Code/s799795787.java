import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in);
        
        // Read the number of strings to be inputted
        int n = sc.nextInt();
        
        // Initialize an array to hold the strings
        String array[] = new String[n];
        
        // Initialize counters for unique strings
        int cnt = 0;
        int cnt2 = 0; // This variable is declared but not used
        
        // Read n strings from the input and store them in the array
        for (int i = 0; i < n; i++) {
            array[i] = sc.next();
        }

        // Sort the array of strings in alphabetical order
        Arrays.sort(array);

        // Initialize the first string for comparison and increment the unique count
        String a = array[0];
        cnt++;

        // Loop through the sorted array to count unique strings
        for (int i = 0; i < n; i++) {
            // Check if the current string is different from the last unique string
            if (a.equals(array[i])) {
                // If they are the same, do nothing (continue to the next iteration)
            } else {
                // If they are different, increment the unique string count
                cnt++;
            }
            // Update the last unique string to the current one
            a = array[i];
        }

        // Output the count of unique strings
        System.out.println(cnt);
    }
}
