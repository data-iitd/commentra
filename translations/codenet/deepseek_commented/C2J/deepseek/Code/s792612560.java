public class Factorial {
    public static void main(String[] args) {
        int n; // Step 3: Declare an integer variable n
        long m; // Step 3: Declare a long integer variable m
        java.util.Scanner scanner = new java.util.Scanner(System.in); // Step 4: Create a Scanner object to read input
        n = scanner.nextInt(); // Step 4: Read an integer input from the user and store it in n
        m = n; // Step 5: Copy the value of n to m
        n--; // Step 6: Decrement the value of n by 1
        for (; n > 1; n--) { // Step 7: Start a for loop that runs while n is greater than 1
            m *= n; // Inside the loop, multiply m by n and decrement n by 1
        }
        System.out.println(m); // Step 8: Print the value of m, which represents the factorial of the input number
    }
}
