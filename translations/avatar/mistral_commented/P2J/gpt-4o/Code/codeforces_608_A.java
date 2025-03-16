import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Creating a Scanner object for input
        Scanner scanner = new Scanner(System.in);
        
        // Reading the first line of input and storing the number of test cases and the target sum in variables n and s
        int n = scanner.nextInt();
        int s = scanner.nextInt();
        
        // Initializing a variable c to 0
        int c = 0;

        // Iterating through the test cases using a for loop
        for (int i = 0; i < n; i++) {
            // Reading the start and end time of each activity from the input
            int f = scanner.nextInt();
            int t = scanner.nextInt();
            
            // Calculating the difference between the end time and the difference between the target sum and start time
            int x = t - (s - f);
            
            // Updating the variable c with the maximum value of x calculated in the current iteration
            if (x > c) {
                c = x;
            }
        }

        // Printing the final answer which is the sum of the target sum and the maximum overlap calculated
        System.out.println(s + c);
        
        // Closing the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
