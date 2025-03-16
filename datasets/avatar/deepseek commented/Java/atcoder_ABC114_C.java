import java.util.Scanner; // Importing the Scanner class for input

public class Main {
    static Scanner scanner; // Declaring a static Scanner object to read input

    public static void main(String[] args) {
        scanner = new Scanner(System.in); // Initializing the Scanner object
        int N = gi(); // Reading an integer N from the user
        long i = 357; // Initializing the starting number
        int c = 0; // Initializing the counter for valid numbers

        // Main loop to find numbers containing '3', '5', and '7'
        while (i <= N) {
            String s = String.valueOf(i); // Converting the current number to a string
            if (s.contains("3") && s.contains("5") && s.contains("7")) {
                c++; // Incrementing the counter if all required digits are present
            }

            // Building a new number by replacing the last digit
            StringBuilder sb = new StringBuilder();
            boolean f = false;
            for (int j = 0; j < s.length(); j++) {
                char a = s.charAt(s.length() - 1 - j);
                if (f) {
                    sb.append(a); // Appending characters after the replacement
                } else {
                    if (a == '3') {
                        sb.append('5'); // Replacing '3' with '5'
                        f = true;
                    } else if (a == '5') {
                        sb.append('7'); // Replacing '5' with '7'
                        f = true;
                    } else {
                        sb.append('3'); // Replacing other digits with '3'
                    }
                }
            }
            if (!f) sb.append('3'); // Appending '3' if no replacements were made

            // Reversing the new number and converting it back to a long
            StringBuffer sb2 = new StringBuffer(sb);
            i = Long.parseLong(sb2.reverse().toString());
        }

        // Output the result
        System.out.println(c); // Printing the count of valid numbers
    }

    // Helper methods to read different types of input
    public static String gs() {
        return scanner.next();
    }

    public static int gi() {
        return Integer.parseInt(scanner.next());
    }

    public static long gl() {
        return Long.parseLong(scanner.next());
    }

    public static double gd() {
        return Double.parseDouble(scanner.next());
    }
}
