import java.util.Scanner; // Import the Scanner class to read input

public class Main { // Declare the main class
    public static void main(String[] args) { // Declare the main method
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input
        String str = scanner.next(); // Read the first string from the standard input
        String p = scanner.next(); // Read the second string from the standard input

        StringBuilder tmp = new StringBuilder(str); // Create a StringBuilder object to manipulate the string str
        str = str.concat(tmp.toString()); // Concatenate str with itself

        int slen = str.length(); // Get the length of str
        int plen = p.length(); // Get the length of p

        boolean flag = false; // Declare a boolean variable flag and initialize it to false
        for (int i = 0; i <= slen - plen; i++) { // Iterate through the string str from the beginning to the end - plen characters
            if (str.substring(i, i + plen).equals(p)) { // Compare the substring of str starting from index i with length plen to p
                flag = true; // If the comparison is successful, set flag to true
            }
        }

        if (flag) System.out.println("Yes"); // If flag is true, print "Yes" to the standard output
        else System.out.println("No"); // If flag is false, print "No" to the standard output
    }
}
