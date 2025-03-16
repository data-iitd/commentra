public class Main {
    public static void main(String[] args) {
        // Declare a buffer to hold the input string and an integer to store its length
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String buf;
        int len;

        // Read a line of input from standard input (stdin) into the buffer
        buf = scanner.nextLine();

        // Calculate the length of the input string
        len = buf.length();

        // Print the first character, the length of the string minus 3, and the second to last character
        System.out.println(buf.charAt(0) + "" + (len - 3) + "" + buf.charAt(len - 2));
    }
}
