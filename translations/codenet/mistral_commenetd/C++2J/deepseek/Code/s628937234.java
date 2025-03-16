import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String s = scanner.next(); // Read a string from the standard input and store it in the variable s

        // The following block of code creates a new string t from the string s
        String t = s.charAt(0) + ""; // Extract the first character from string s and store it in variable t
        t += (s.length() - 2); // Convert the size of string s minus 2 to a string
        t += s.charAt(s.length() - 1); // Concatenate the extracted first character, the size minus 2 as a string, and the last character of string s to create the new string t

        // Output the newly created string t to the standard output
        System.out.println(t);
    }
}
