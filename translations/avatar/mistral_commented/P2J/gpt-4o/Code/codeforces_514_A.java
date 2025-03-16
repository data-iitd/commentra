import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Take an input string `ip` from the user
        Scanner scanner = new Scanner(System.in);
        String ip = scanner.nextLine();

        // Initialize an empty string `st`
        String st = "";

        // Check if the length of the input string is not equal to 1
        if (ip.length() != 1) {
            // Check if the first character of the input string is equal to "9"
            if (ip.charAt(0) == '9') {
                // Assign "9" to the variable `st`
                st = "9";
                // Slice the input string to exclude the first character
                ip = ip.substring(1);
            }

            // Iterate through each character in the input string `ip`
            for (char i : ip.toCharArray()) {
                // If the character is an integer greater than 4
                if (Character.getNumericValue(i) > 4) {
                    // Calculate the difference between 9 and the integer
                    int n = 9 - Character.getNumericValue(i);
                    // Add the difference to the string `st`
                    st += n;
                } else {
                    // Add the character directly to the string `st`
                    st += i;
                }
            }
        } else {
            // If the length of the input string is equal to 1
            // Assign the input string to the variable `st`
            st = ip;
        }

        // Print the integer value of the string `st` to the console
        System.out.println(Integer.parseInt(st));
    }
}
// <END-OF-CODE>
