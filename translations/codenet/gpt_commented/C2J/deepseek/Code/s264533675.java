public class Main {
    public static void main(String[] args) {
        // Declare a character array (string) of size 30 to hold user input
        char[] str = new char[30];

        // Read a line of input from the user and store it in the str array
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        str = scanner.nextLine().toCharArray();

        // Replace the character at index 5 with a space
        str[5] = ' ';

        // Replace the character at index 13 with a space
        str[13] = ' ';

        // Print the modified string to the console
        System.out.println(str);

        // Return 0 to indicate successful execution of the program
    }
}
