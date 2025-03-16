import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Creating a Scanner object for input
        int n = scanner.nextInt(); // Reading the integer input
        String s = scanner.next(); // Reading the string input
        int count = countOccurrences(s, "ABC"); // Counting occurrences of "ABC" in s
        System.out.println(count); // Printing the result
        scanner.close(); // Closing the scanner
    }

    // Method to count occurrences of a substring in a string
    private static int countOccurrences(String str, String subStr) {
        int count = 0;
        int index = 0;
        while ((index = str.indexOf(subStr, index)) != -1) {
            count++;
            index += subStr.length(); // Move past the last found occurrence
        }
        return count;
    }
}

// <END-OF-CODE>
