import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int firstline = Integer.parseInt(scanner.nextLine());  // Read the first line of input
        int total = 0;  // Initialize a variable to keep track of the total sum
        List<String> memory = new ArrayList<>();  // Initialize a list to store the decisions

        // Loop through the range of firstline
        for (int x = 0; x < firstline; x++) {
            String[] input = scanner.nextLine().split(" ");  // Read a line of input
            int A = Integer.parseInt(input[0]);  // Parse the first integer
            int G = Integer.parseInt(input[1]);  // Parse the second integer
            
            if (total + A <= 500) {  // Check if adding A to total would not exceed 500
                total += A;  // Add A to total
                memory.add("A");  // Append "A" to memory
            } else {
                total -= G;  // Subtract G from total
                memory.add("G");  // Append "G" to memory
            }
        }

        // Join the elements of memory into a single string and print it
        System.out.println(String.join("", memory));
        
        scanner.close();  // Close the scanner
    }
}
// <END-OF-CODE>
