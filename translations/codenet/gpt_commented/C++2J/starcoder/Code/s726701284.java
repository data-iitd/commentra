import java.util.*;
public class Main {
    public static void main(String[] args) {
        // Read input string from the user
        Scanner sc = new Scanner(System.in);
        String s = sc.next();

        // Loop through each character from 'a' to 'z'
        for (char i = 'a'; i <= 'z'; i++)
        {
            // Initialize a counter to track occurrences of the current character
            int a = 0;

            // Loop through each character in the input string
            for (int j = 0; j < s.length(); j++)
            {
                // Check if the current character matches the character being checked
                if (i == s.charAt(j))
                {
                    // Increment the counter if a match is found
                    a++;
                }
            }

            // If the character was not found in the input string
            if (a == 0)
            {
                // Output the first missing character and exit the loop
                System.out.println(i);
                break;
            } 

            // If we reach the end of the alphabet and all characters are present
            if (i == 'z')
            {
                // Output "None" if no characters are missing
                System.out.println("None");
                break;
            }
        }
    }
}
