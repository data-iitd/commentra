import java.util.Scanner;  // Step 1: Import the Scanner class to read input from the user.

public class Main {  // Step 2: Define the Main class which contains the main method.
    public static void main(String[] args) {  // Step 3: Define the main method which is the entry point of the program.
        Scanner scanner = new Scanner(System.in);  // Step 4: Create a Scanner object to read input.

        int sheep;  // Step 5: Declare two integer variables, sheep and wolf, to store the number of sheep and wolves.
        int wolf;

        sheep = scanner.nextInt();  // Step 6: Read the number of sheep from the user.
        wolf = scanner.nextInt();  // Step 7: Read the number of wolves from the user.

        if (wolf >= sheep) {  // Step 8: Check if the number of wolves is greater than or equal to the number of sheep.
            System.out.println("unsafe");  // Step 9: If the condition is true, print "unsafe".
        } else {
            System.out.println("safe");  // Step 10: Otherwise, print "safe".
        }

        scanner.close();  // Step 11: Close the scanner to prevent resource leaks.
    }  // End of main method.
}  // End of Main class.
