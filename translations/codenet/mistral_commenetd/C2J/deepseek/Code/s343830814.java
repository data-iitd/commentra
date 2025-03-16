public class Main {
    public static void main(String[] args) {
        // Declare a character array 'buf' of size 512
        char[] buf = new char[512];

        // Declare an integer variable 'len' to store the length of the string read
        int len;

        // Read a line from standard input using java.util.Scanner and store it in 'buf'
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        buf = scanner.nextLine().toCharArray();

        // Calculate the length of the string read and store it in 'len'
        len = buf.length;

        // Print the first character of the string, its length (minus 3), and the last character of the string
        System.out.println(buf[0] + "" + (len - 3) + "" + buf[len - 2]);
    }
}
