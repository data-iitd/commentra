import java.util.Scanner; // Import the Scanner class for input

public class Main { // Define the Main class
    static final int N = 2000; // Define a constant N for the size of the array
    static int num1; // Declare a static variable num1
    static int[] math = new int[N + 1]; // Declare a static array math

    public static void main(String[] args) { // Main method is the entry point of the program
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int a, num2, ans, sum = 0; // Declare local variables a, num2, ans, and sum

        math[0] = 1; // Initialize the first element of math to 1

        num1 = scanner.nextInt(); // Read the number of elements in the first set of inputs
        for (int i = 0; i < num1; i++) { // Loop through num1 times
            a = scanner.nextInt(); // Read each element
            sum += a; // Update the sum
            for (int j = sum - a; j >= 0; j--) { // Loop to mark possible sums
                if (math[j] == 1) math[j + a] = 1; // If the sum j is possible, mark sum j+a as possible
            }
        }

        num2 = scanner.nextInt(); // Read the number of elements in the second set of inputs
        for (int i = 0; i < num2; i++) { // Loop through num2 times
            ans = scanner.nextInt(); // Read each element
            System.out.println(math[ans] == 1 ? "yes" : "no"); // Check if the sum is possible and print the result
        }

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
