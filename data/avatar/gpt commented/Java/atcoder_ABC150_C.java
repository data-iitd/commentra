import java.util.ArrayList; 
import java.util.Arrays; 
import java.util.List; 
import java.util.Scanner; 

public class Main {
    
    // Method to generate all permutations of a given target string
    public static List<String> permutation(List<String> list, String target, String ans) {
        // Base case: if the target string is of length 1 or less, add the current answer to the list
        if (target.length() <= 1) {
            list.add(ans + target);
        } else {
            // Recursive case: iterate through each character in the target string
            for (int i = 0; i < target.length(); i++) {
                // Recursively call permutation with the remaining characters and the current character added to the answer
                permutation(list, target.substring(0, i) + target.substring(i + 1), ans + target.charAt(i));
            }
        }
        // Return the list of permutations
        return list;
    }

    public static void main(String[] args) {
        // Create a scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements to be processed
        Integer n = Integer.parseInt(scanner.next());
        
        // Initialize a 2D array to store input strings
        String[][] line = new String[2][1];
        
        // Fill the 2D array with empty strings
        for (int i = 0; i < 2; i++) {
            Arrays.fill(line[i], "");
            // Read n strings from the user and concatenate them into the first column of the array
            for (int j = 0; j < n; j++) {
                line[i][0] += scanner.next();
            }
        }
        
        // Create a string containing numbers from 1 to n
        String number = "";
        for (int i = 1; i <= n; i++) {
            number += i;
        }
        
        // List to hold all permutations of the number string
        List<String> listA = new ArrayList<>();
        // Generate all permutations of the number string
        permutation(listA, number, "");
        
        // Variable to hold the sum of indices based on matching permutations
        int sum = 0;
        
        // Iterate through each row of the input strings
        for (int j = 0; j < line.length; j++) {
            // Check each permutation against the input strings
            for (int i = 0; i < listA.size(); i++) {
                // If a permutation matches the input string, adjust the sum based on the index
                if (listA.get(i).equals(line[j][0])) {
                    if (sum == 0) {
                        sum += i; // Add index if sum is initially zero
                    } else {
                        sum -= i; // Subtract index if sum is not zero
                    }
                }
            }
        }
        
        // Output the absolute value of the sum
        System.out.println(Math.abs(sum));
    }
}
