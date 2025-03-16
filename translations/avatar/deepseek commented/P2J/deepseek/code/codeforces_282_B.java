import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int firstline = scanner.nextInt();  // Read the first line of input, which determines the number of iterations
        int total = 0;  // Initialize a variable to keep track of the total sum
        List<Character> memory = new ArrayList<>();  // Initialize an empty list to store the decisions

        // Loop through the range of firstline
        for (int x = 0; x < firstline; x++) {
            int A = scanner.nextInt();  // Read the first integer from a single line of input
            int G = scanner.nextInt();  // Read the second integer from a single line of input
            if (total + A <= 500) {  // Check if adding A to total would not exceed 500
                total += A;  // Add A to total
                memory.add('A');  // Append "A" to memory
            } else {
                total -= G;  // Subtract G from total
                memory.add('G');  // Append "G" to memory
            }
        }

        // Join the elements of memory into a single string and print it
        StringBuilder result = new StringBuilder();
        for (char decision : memory) {
            result.append(decision);
        }
        System.out.println(result.toString());
    }
}
