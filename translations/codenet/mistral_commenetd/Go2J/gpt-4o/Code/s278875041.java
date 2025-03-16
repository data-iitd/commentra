// Importing required packages
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declaring a variable 'a' of type String
        Scanner scanner = new Scanner(System.in);
        String a = scanner.nextLine();

        // Replacing all occurrences of '1' with '0' in the string 'a'
        String tmp = a.replace("1", "0");

        // Replacing all occurrences of '9' with '1' in the string 'tmp'
        String b = tmp.replace("9", "1");

        // Replacing all occurrences of '0' with '9' in the string 'b'
        String ans = b.replace("0", "9");

        // Printing the final answer
        System.out.println(ans);
    }
}

// <END-OF-CODE>
