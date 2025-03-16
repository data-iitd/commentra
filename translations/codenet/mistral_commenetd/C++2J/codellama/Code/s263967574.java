import java.util.Scanner; // Import the Scanner class for input operations

public class Main { // Beginning of the Main class
    public static void main(String[] args) { // Beginning of the main function
        Scanner sc = new Scanner(System.in); // Create a new Scanner object to read input from the standard input

        int x = sc.nextInt(); // Read an integer value from the standard input and store it in variable x

        if (x >= 1200) { // Beginning of the if statement block
            System.out.println("ARC"); // Output the string "ARC" to the standard output if the condition is true
        }
        else { // Beginning of the else statement block
            System.out.println("ABC"); // Output the string "ABC" to the standard output if the condition is false
        }
    }
}

