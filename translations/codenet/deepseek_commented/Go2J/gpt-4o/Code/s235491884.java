import java.util.Scanner; // Importing the Scanner class for reading input
import java.util.regex.Pattern; // Importing the Pattern class for string manipulation

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Creating a Scanner object to read input
        String s = scanner.nextLine(); // Reading input from the user and storing it in the variable s

        int n = (int) Pattern.compile("o").matcher(s).results().count(); // Counting the number of occurrences of "o" in the string s
        System.out.println(700 + n * 100); // Printing the final score based on the count of "o" characters

        scanner.close(); // Closing the scanner
    }
}

// <END-OF-CODE>
