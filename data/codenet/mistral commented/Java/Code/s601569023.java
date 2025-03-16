
import java.util.Scanner;

class Main {
    public static void main(String[] args){
        // Create a new Scanner object to read input from the standard input stream
        Scanner sc = new Scanner(System.in);

        // Read an integer value `num` from the user input
        int num = sc.nextInt();

        // Check if the number is less than 1200
        if(num < 1200){
            // If the condition is true, print the string "ABC" to the standard output stream
            System.out.println("ABC");
        } else {
            // If the condition is false, print the string "ARC" to the standard output stream
            System.out.println("ARC");
        }

        // Close the Scanner object to free up system resources
        sc.close();
    }
}

