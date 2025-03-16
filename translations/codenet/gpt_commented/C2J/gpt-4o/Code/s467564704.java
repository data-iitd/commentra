import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare a 3x3 array to hold input values and a variable for test cases
        int[][] input = new int[3][3];
        Scanner scanner = new Scanner(System.in);

        // Read 3x3 input values from the user
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                input[i][j] = scanner.nextInt(); // Store each input value in the array
            }
        }

        // Read the number of test cases
        int tc = scanner.nextInt();
        int testcase;

        // Process each test case
        for (int i = 0; i < tc; i++) {
            testcase = scanner.nextInt(); // Read the current test case value

            // Check the input array for the testcase value and set it to 0 if found
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (input[j][k] == testcase) {
                        input[j][k] = 0; // Replace the found value with 0
                    }
                }
            }
        }

        // Check for winning conditions in the modified input array
        if (input[0][0] == 0 && input[1][1] == 0 && input[2][2] == 0) { // Check diagonal from top-left to bottom-right
            System.out.println("Yes");
        } else if (input[0][2] == 0 && input[1][1] == 0 && input[2][0] == 0) { // Check diagonal from top-right to bottom-left
            System.out.println("Yes");
        } else if (input[0][0] == 0 && input[0][1] == 0 && input[0][2] == 0) { // Check first row
            System.out.println("Yes");
        } else if (input[1][0] == 0 && input[1][1] == 0 && input[1][2] == 0) { // Check second row
            System.out.println("Yes");
        } else if (input[2][0] == 0 && input[2][1] == 0 && input[2][2] == 0) { // Check third row
            System.out.println("Yes");
        } else if (input[0][0] == 0 && input[1][0] == 0 && input[2][0] == 0) { // Check first column
            System.out.println("Yes");
        } else if (input[0][1] == 0 && input[1][1] == 0 && input[2][1] == 0) { // Check second column
            System.out.println("Yes");
        } else if (input[0][2] == 0 && input[1][2] == 0 && input[2][2] == 0) { // Check third column
            System.out.println("Yes");
        } else {
            System.out.println("No"); // If no winning condition is met, output "No"
        }

        scanner.close(); // Close the scanner
    }
}
// <END-OF-CODE>
