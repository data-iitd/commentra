import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare an integer 2D array `input` of size 4x4 and an integer `tc` to store the number of test cases.
        int[][] input = new int[4][4];
        Scanner scanner = new Scanner(System.in);
        
        // Use a nested for loop to read the elements of the `input` array from the standard input.
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                input[i][j] = scanner.nextInt();
                // Read the elements of the input array
            }
        }
        
        int tc = scanner.nextInt();
        // Read the number of test cases `tc` from the standard input.
        
        // Use another nested for loop to iterate through each test case and check if the given testcase is present in the `input` array or not. If present, we set its value to 0.
        for (int i = 0; i < tc; i++) {
            int testcase = scanner.nextInt();
            for (int m = 0; m < 3; m++) {
                for (int n = 0; n < 3; n++) {
                    if (input[m][n] == testcase) {
                        input[m][n] = 0;
                        // If the given testcase is present in the input array, set its value to 0.
                    }
                }
            }
        }
        
        // Check if all the elements of any of the three 1x1 sub-arrays are 0 or not.
        if (input[0][0] == 0 && input[1][1] == 0 && input[2][2] == 0) {
            System.out.println("Yes");
            // If yes, print "Yes" and exit the program.
            System.exit(0);
        } else if (input[0][2] == 0 && input[1][1] == 0 && input[2][0] == 0) {
            System.out.println("Yes");
            // If yes, print "Yes" and exit the program.
            System.exit(0);
        } else if (input[0][0] == 0 && input[0][1] == 0 && input[0][2] == 0) {
            System.out.println("Yes");
            // If yes, print "Yes" and exit the program.
            System.exit(0);
        } else if (input[1][0] == 0 && input[1][1] == 0 && input[1][2] == 0) {
            System.out.println("Yes");
            // If yes, print "Yes" and exit the program.
            System.exit(0);
        } else if (input[2][0] == 0 && input[2][1] == 0 && input[2][2] == 0) {
            System.out.println("Yes");
            // If yes, print "Yes" and exit the program.
            System.exit(0);
        } else if (input[0][0] == 0 && input[1][0] == 0 && input[2][0] == 0) {
            System.out.println("Yes");
            // If yes, print "Yes" and exit the program.
            System.exit(0);
        } else if (input[0][1] == 0 && input[1][1] == 0 && input[2][1] == 0) {
            System.out.println("Yes");
            // If yes, print "Yes" and exit the program.
            System.exit(0);
        } else if (input[0][2] == 0 && input[1][2] == 0 && input[2][2] == 0) {
            System.out.println("Yes");
            // If yes, print "Yes" and exit the program.
            System.exit(0);
        } else {
            System.out.println("No");
            // If none of the above conditions are satisfied, print "No" and exit the program.
            System.exit(1);
        }
    }
}
// <END-OF-CODE>
