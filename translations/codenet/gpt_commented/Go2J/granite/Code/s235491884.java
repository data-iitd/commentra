
import java.util.Scanner; // Importing the Scanner class for reading input

public class s235491884{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input from the console
        String s = scanner.nextLine(); // Read a string from the console and store it in's'

        // Count the occurrences of the letter 'o' in the input string's'
        int n = countOccurrences(s, 'o');

        // Calculate the result based on the count of 'o' and print it
        // The formula adds 700 to 100 times the count of 'o'
        System.out.println(700 + n * 100);
    }

    // Function to count the occurrences of a character in a string
    public static int countOccurrences(String str, char ch) {
        int count = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == ch) {
                count++;
            }
        }
        return count;
    }
}
