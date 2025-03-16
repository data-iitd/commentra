import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input
        String s = scanner.next(); // Read input from the user
        int l = s.length(); // Calculate the length of the string and store it in l
        String ans = "AC"; // Initialize the answer variable with "AC"

        // Check if the first character is 'A'
        if (s.charAt(0) != 'A') {
            ans = "WA"; // If the first character is not 'A', set ans to "WA"
        }

        int cnt = 0; // Initialize a counter to keep track of uppercase letters
        for (int i = 1; i < l; i++) { // Iterate over the string starting from the second character
            if (Character.isUpperCase(s.charAt(i))) { // Check if the character is an uppercase letter
                if (i == 1 || i == l - 1 || s.charAt(i) != 'C') { // Check if the character is 'C' or not at the second or second-to-last position
                    ans = "WA"; // If any of the conditions are met, set ans to "WA"
                }
                cnt++; // Increment the counter if the conditions are met
            }
        }

        // Check if there is exactly one uppercase letter that is not the first or last character and is 'C'
        if (cnt != 1) {
            ans = "WA"; // If cnt is not 1, set ans to "WA"
        }

        System.out.println(ans); // Print the final answer
    }
}

// <END-OF-CODE>
