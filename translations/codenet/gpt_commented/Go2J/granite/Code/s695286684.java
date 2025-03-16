
import java.util.Scanner; // Importing the Scanner class for user input

public class s695286684{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read user input
        String s = scanner.nextLine(); // Read a string input from the user and store it in variable's'

        // Replace all occurrences of "2017" with "2018" in the input string and print the result
        System.out.println(s.replaceAll("2017", "2018"));
    }
}
