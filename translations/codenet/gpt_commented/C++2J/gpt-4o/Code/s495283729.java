import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare a Scanner to read input
        Scanner scanner = new Scanner(System.in);
        
        // Read a string from standard input
        String s = scanner.next();
        
        // Initialize variables: i for iteration and flag to track validity
        int flag = 0;
        
        // Iterate through each character in the string
        for (int i = 0; i < s.length(); i++) {
            // Check if the index is even
            if (i % 2 == 0) {
                // Switch case for characters at even indices
                switch (s.charAt(i)) {
                    case 'R':
                    case 'U':
                    case 'D':
                        // 'R', 'U', 'D' are valid, do nothing
                        break;
                    default:
                        // If character is not valid, set flag to indicate an error
                        flag = 1;
                        break;
                }
            } else {
                // Switch case for characters at odd indices
                switch (s.charAt(i)) {
                    case 'L':
                    case 'U':
                    case 'D':
                        // 'L', 'U', 'D' are valid, do nothing
                        break;
                    default:
                        // If character is not valid, set flag to indicate an error
                        flag = 1;
                        break;
                }
            }
        }
        
        // Check the flag to determine if the input string was valid
        if (flag == 0) {
            // If flag is still 0, print "Yes" indicating valid input
            System.out.println("Yes");
        } else {
            // If flag is set, print "No" indicating invalid input
            System.out.println("No");
        }
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
