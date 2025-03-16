import java.util.Scanner; // Importing the Scanner class for user input

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Creating a Scanner object to read input
        String s = sc.next(); // Reading a string input from the user
        long k = sc.nextLong(); // Reading a long integer input from the user
        StringBuffer sb = new StringBuffer(); // Creating a StringBuffer object to build the resulting string

        // Iterating over each character in the input string
        for (int i = 0; i < s.length(); i++) {
            // Checking if the difference between 26 and the ASCII value of the current character minus 'a' is less than or equal to k
            // and if the current character is not 'a'
            if ((26 - (s.charAt(i) - 'a')) <= k && s.charAt(i) != 'a') {
                k -= 26 - (s.charAt(i) - 'a'); // Decrementing k by the difference calculated
                sb.append('a'); // Appending 'a' to the StringBuffer
            } else {
                sb.append(s.charAt(i)); // Appending the current character to the StringBuffer
            }
        }

        // If k is greater than 0, calculating the new character to append
        if (k > 0) {
            char t = sb.charAt(s.length() - 1); // Getting the last character in the StringBuffer
            sb.delete(s.length() - 1, s.length()); // Removing the last character from the StringBuffer
            sb.append((char)('a' + (t - 'a' + k) % 26)); // Appending the new character to the StringBuffer
        }

        System.out.println(sb); // Printing the resulting string
    }
}
