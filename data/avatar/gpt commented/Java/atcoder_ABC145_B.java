import java.util.*; // Importing the utility package for Scanner
import java.math.*; // Importing the math package (not used in this code)

public class Main {
    // Method to print a string to the console
    public static void cout(String str) {
        System.out.println(str);
    }

    // Main method where the program execution begins
    public static void main(String args[]) {
        // Creating a Scanner object to read input from the console
        Scanner cin = new Scanner(System.in);
        
        // Initializing variables to hold parts of the input string
        String a = "", b = "", str;
        int n;

        // Reading an integer input which represents the length of the string
        n = cin.nextInt();
        cin.nextLine(); // Consuming the newline character after the integer input
        
        // Reading the actual string input
        str = cin.nextLine();

        // Loop to construct the first half of the string
        for (int i = 0; i < n / 2; i++) {
            a = a + str.charAt(i); // Appending characters from the first half of the string to 'a'
        }

        // Checking if the string is made up of two identical halves
        if (str.equals(a + a)) {
            cout("Yes"); // If true, print "Yes"
        } else {
            cout("No"); // If false, print "No"
        }
    }
}
