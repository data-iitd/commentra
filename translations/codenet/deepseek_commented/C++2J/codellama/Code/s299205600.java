import java.util.Scanner; // Import the Scanner class

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Create a Scanner object to read input from the command line
        int a = sc.nextInt(); // Read the value of 'a' from the command line
        int b = sc.nextInt(); // Read the value of 'b' from the command line
        int result; // Declare an integer variable 'result' to store the final result

        // Determine the value of 'result' based on the values of 'a' and 'b'
        if (a > b) {
            result = 2 * a - 1; // If 'a' is greater than 'b', calculate 'result' as 2 * 'a' - 1
        } else if (a == b) {
            result = 2 * a; // If 'a' is equal to 'b', calculate 'result' as 2 * 'a'
        } else {
            result = 2 * b - 1; // If 'a' is less than 'b', calculate 'result' as 2 * 'b' - 1
        }

        System.out.println(result); // Output the value of 'result' to the console
    }
}

