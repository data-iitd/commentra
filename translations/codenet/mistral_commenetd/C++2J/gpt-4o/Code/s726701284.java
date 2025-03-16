import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Declare a string variable 's' and read its value from the standard input using scanner.
        String s = scanner.nextLine();
        
        // Start a for loop that iterates through all the lowercase letters from 'a' to 'z'.
        for (char i = 'a'; i <= 'z'; i++) {
            int a = 0; // Initialize an integer variable 'a' to 0.

            // Start another for loop that iterates through all the characters in the string 's'.
            for (int j = 0; j < s.length(); j++) {
                // Inside the inner for loop, we check if the current character 'i' matches the character at the current position 'j' in the string 's'. If it does, we increment the value of 'a'.
                if (i == s.charAt(j)) {
                    a++;
                }
            }

            // After the inner for loop, we check if the value of 'a' is 0. If it is, it means that the character 'i' does not appear in the string 's', so we print it to the standard output and break out of the outer for loop using the 'break' statement.
            if (a == 0) {
                System.out.println(i);
                break;
            }

            // If the character 'i' is 'z', we print "None" to the standard output and break out of the outer for loop using the 'break' statement.
            if (i == 'z') {
                System.out.println("None");
                break;
            }
        }
        
        scanner.close();
    }
}

// <END-OF-CODE>
