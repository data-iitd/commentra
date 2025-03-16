import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = Integer.parseInt(scanner.nextLine());  // Take an integer input representing the number of elements
        List<String[]> q = new ArrayList<>();  // Initialize a list to store the elements
        int count = 0;  // Initialize a counter to keep track of valid pairs

        // Loop to take input and append to the list `q`
        for (int i = 0; i < n; i++) {
            String input = scanner.nextLine();  // Read the input line
            String[] a = input.split(" ");  // Split the input into an array of strings
            q.add(a);  // Append the split input to the list `q`
        }

        // Nested loop to compare each element with every other element
        for (String[] j : q) {
            for (String[] k : q) {
                if (k == j) {  // Skip if the same element is compared with itself
                    continue;
                } else if (j[0].equals(k[k.length - 1])) {  // Check if the first character of `j` matches the last character of `k`
                    count++;  // Increment the counter if the condition is met
                } else {
                    continue;
                }
            }
        }

        System.out.println(count);  // Print the total count of valid pairs
        scanner.close();
    }
}
// <END-OF-CODE>
