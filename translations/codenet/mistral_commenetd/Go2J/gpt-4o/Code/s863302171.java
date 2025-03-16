import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare a variable 'n' of type String
        Scanner scanner = new Scanner(System.in);
        String n = scanner.nextLine();

        // Initialize a loop counter 'i'
        for (int i = 0; i < 3; i++) {
            // Check if the current character in the string 'n' is equal to '7'
            if (i < n.length() && n.charAt(i) == '7') {
                // If yes, print "Yes" and exit the function
                System.out.println("Yes");
                return;
            }
        }

        // If no '7' is found in the first three characters, print "No"
        System.out.println("No");
    }
}
// <END-OF-CODE>
