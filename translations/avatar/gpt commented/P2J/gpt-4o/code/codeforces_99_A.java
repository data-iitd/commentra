import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Read input from the user
        Scanner scanner = new Scanner(System.in);
        String l = scanner.nextLine();

        // Split the input string into two parts using '.' as the delimiter
        String[] parts = l.split("\\.");

        // Convert the first part of the input into a character array
        char[] s = parts[0].toCharArray();

        // Convert the second part of the input into a character array
        char[] p = parts[1].toCharArray();

        // Extract the first character from the second part and convert it to an integer
        int i = Character.getNumericValue(p[0]);

        // Check if the last character of the first part is '9'
        if (s[s.length - 1] == '9') {
            // If it is '9', print the message "GOTO Vasilisa."
            System.out.println("GOTO Vasilisa.");
        } 
        // Check if the last character is not '9' and the integer i is less than 5
        else if (s[s.length - 1] != '9' && i < 5) {
            // If both conditions are true, join the character array into a string and print it
            System.out.println(new String(s));
        } else {
            // If the last character is not '9' and i is 5 or more
            // Join the character array into a string, convert it to an integer, increment it by 1, and convert it back to a string
            String incrementedValue = String.valueOf(Integer.parseInt(new String(s)) + 1);
            // Print the incremented value
            System.out.println(incrementedValue);
        }

        scanner.close();
    }
}

// <END-OF-CODE>
