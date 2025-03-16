import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Declare variables to store the input values.
        // `n` will store the integer input and `s` will store the string input.
        int n = scanner.nextInt();
        String s = scanner.next();
        
        // Read an integer `n` and a string `s` from the standard input.
        // The nextInt() method is used to read an integer, and next() is used to read a string.
        
        // Print the number of occurrences of the substring "ABC" in the string `s`.
        // The `String` method `split` is used to count the occurrences of the substring "ABC".
        int count = s.length() - s.replace("ABC", "").length();
        count /= "ABC".length(); // Divide by the length of "ABC" to get the number of occurrences.
        
        System.out.println(count);
        
        scanner.close();
    }
}

// <END-OF-CODE>
