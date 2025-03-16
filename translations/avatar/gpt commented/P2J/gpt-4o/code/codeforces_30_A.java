import java.util.Scanner;

public class Main {
    public static int task4(int A, int B, int n) {
        // Iterate through a range of possible values for X from -1000 to 1000
        for (int X = -1000; X <= 1000; X++) {
            // Check if the equation A * (X ^ n) equals B
            if (A * Math.pow(X, n) == B) {
                // If a solution is found, return the value of X
                return X;
            }
        }
        // If no solution is found in the range, return a message indicating no solution
        return Integer.MIN_VALUE; // Using Integer.MIN_VALUE to indicate no solution
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Take input from the user and split it into three variables A, B, and n
        String[] input = scanner.nextLine().split(" ");
        int A = Integer.parseInt(input[0]);
        int B = Integer.parseInt(input[1]);
        int n = Integer.parseInt(input[2]);

        // Call the task4 function and print the result
        int result = task4(A, B, n);
        if (result == Integer.MIN_VALUE) {
            System.out.println("No solution");
        } else {
            System.out.println(result);
        }
        
        scanner.close();
    }
}

// <END-OF-CODE>
