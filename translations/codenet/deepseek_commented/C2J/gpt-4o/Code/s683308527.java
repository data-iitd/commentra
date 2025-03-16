import java.util.Scanner;  // Import necessary classes

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object for input
        int n = scanner.nextInt();  // Read the number of lines
        scanner.nextLine();  // Consume the newline character

        while (n-- > 0) {  // Loop through each line
            String s = scanner.nextLine();  // Read the input line
            s = s.replace("Hoshino", "Hoshina");  // Replace "Hoshino" with "Hoshina"
            System.out.println(s);  // Print the modified line
        }

        scanner.close();  // Close the scanner
    }
}  // End of class
// <END-OF-CODE>
