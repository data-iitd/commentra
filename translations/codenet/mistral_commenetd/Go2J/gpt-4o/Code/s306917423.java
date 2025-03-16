import java.util.Scanner; // Importing the Scanner class for input operations

public class Main {
    public static void main(String[] args) {
        // Creating a Scanner object to read input
        Scanner scanner = new Scanner(System.in);

        // Declaring a variable 's' of type 'String' to store the input string
        String s = scanner.nextLine();

        // Declaring a variable 'ans' of type 'int' to store the answer
        int ans = 0;

        // Looping through each character 'c' in the string 's'
        for (char c : s.toCharArray()) {
            // Checking if the current character 'c' is equal to '1'
            if (c == '1') {
                // Incrementing the answer if the character is '1'
                ans++;
            }
        }

        // Printing the answer
        System.out.println(ans);

        // Closing the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
