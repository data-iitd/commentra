public class Main {
    public static void main(String[] args) {
        // Take a string input from the user
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String s = scanner.nextLine();

        // Initialize an empty string to store the result
        String result = "";

        // Initialize a variable 'i' to traverse the string 's'
        int i = 0;

        // Use a while loop to traverse the string 's' until the end
        while (i < s.length()) {

            // Check if the current character is a '.'
            if (s.charAt(i) == '.') {

                // If yes, append '0' to the result string
                result += '0';

            } else {

                // Move to the next character if it's not a '.'
                i++;

                // Check if the next character is also a '.'
                if (i < s.length() && s.charAt(i) == '.') {

                    // If yes, append '1' to the result string
                    result += '1';

                } else {

                    // If not, append '2' to the result string
                    result += '2';
                }
            }

            // Increment the index 'i' to move to the next character
            i++;
        }

        // Print the final result string
        System.out.println(result);
    }
}
