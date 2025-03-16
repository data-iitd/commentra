import java.util.Scanner; // Import the Scanner class for input operations

public class Main { // Define a public class named Main
    public static void main(String[] args) { // The main method is the entry point of the program
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input
        String str = scanner.next(); // Read the next string from the input and store it in the string variable str
        if (str.charAt(2) == str.charAt(3) && str.charAt(4) == str.charAt(5)) { // Check if the characters at positions 2 and 3 are the same and if the characters at positions 4 and 5 are the same
            System.out.println("Yes"); // If the conditions are met, output "Yes"
        } else {
            System.out.println("No"); // If the conditions are not met, output "No"
        }
    }
}
