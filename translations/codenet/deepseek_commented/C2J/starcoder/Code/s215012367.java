import java.util.Scanner; // Step 1: Include the standard input/output library.

public class Main {
    public static void main(String[] args) { // Step 2: Define the main function.
        Scanner sc = new Scanner(System.in); // Step 3: Create a Scanner object.
        int a, b, s; // Step 4: Declare three integer variables: a, b, and s.

        a = sc.nextInt(); // Step 5: Read an integer from the user input and store it in variable a.
        b = sc.nextInt(); // Step 6: Read an integer from the user input and store it in variable b.

        s = (a*b) - (a + b) + 1; // Step 7: Calculate the value of s using the formula (a*b) - (a + b) + 1.

        System.out.println(s); // Step 8: Print the value of s.
    }
}
