import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare a variable to hold the input string
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        
        // Loop through each character in the string
        for (int i = 0; i < s.length(); i++) {
            // Print 'x' for each character in the input string
            System.out.print("x");
        }
        
        // Print a newline after printing all 'x's
        System.out.println("");
        
        scanner.close();
    }
}

// <END-OF-CODE>
