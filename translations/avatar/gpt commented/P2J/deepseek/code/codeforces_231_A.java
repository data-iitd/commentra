import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read an integer input which represents the number of lists to process
        int n = scanner.nextInt();
        
        // Initialize a counter to keep track of lists with a sum greater than 1
        int c = 0;
        
        // Loop through the range of n to process each list
        for (int i = 0; i < n; i++) {
            // Read a line of input, split it into individual string elements, convert them to integers, and store them in a list
            Scanner lineScanner = new Scanner(scanner.nextLine());
            lineScanner.useDelimiter("\\s+");
            int sum = 0;
            while (lineScanner.hasNextInt()) {
                sum += lineScanner.nextInt();
            }
            
            // Check if the sum of the current list is greater than 1
            if (sum > 1) {
                // Increment the counter if the condition is met
                c++;
            }
        }
        
        // Print the final count of lists that had a sum greater than 1
        System.out.println(c);
        
        scanner.close();
    }
}
