import java.util.Scanner; // Import the Scanner class for input

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object

        // Read a string input from the user
        String str = scanner.next();

        // Check if the characters at positions 2 and 3 are the same,
        // and if the characters at positions 4 and 5 are the same
        if (str.charAt(2) == str.charAt(3) && str.charAt(4) == str.charAt(5)) 
            System.out.println("Yes"); // If both conditions are true, output "Yes"
        else 
            System.out.println("No"); // If either condition is false, output "No"
    }
}
