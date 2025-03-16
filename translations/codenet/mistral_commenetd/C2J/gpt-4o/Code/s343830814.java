import java.util.Scanner;

/* The main class is the entry point of the program */
public class Main {
    public static void main(String[] args) {
        /* Create a Scanner object to read input from standard input */
        Scanner scanner = new Scanner(System.in);

        /* Declare a string variable 'buf' to store the input */
        String buf;

        /* Read a line from standard input using Scanner and store it in 'buf' */
        buf = scanner.nextLine();

        /* Calculate the length of the string read */
        int len = buf.length();

        /* Print the first character of the string, its length (minus 3), and the last character of the string */
        System.out.printf("%c%d%c\n", buf.charAt(0), len - 3, buf.charAt(len - 2));

        /* Close the scanner */
        scanner.close();
    }
}

/* <END-OF-CODE> */
