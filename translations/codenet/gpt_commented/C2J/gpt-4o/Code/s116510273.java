import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare a string to hold the input
        Scanner scanner = new Scanner(System.in);
        String mes = scanner.next();

        // Print the first character of the string, the length of the string minus 2, and the last character of the string
        System.out.printf("%c%d%c%n", mes.charAt(0), mes.length() - 2, mes.charAt(mes.length() - 1));

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
