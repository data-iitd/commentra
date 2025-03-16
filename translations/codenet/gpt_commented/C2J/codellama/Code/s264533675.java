
public class Main {
    public static void main(String[] args) {
        // Declare a character array (string) of size 30 to hold user input
        char[] str = new char[30];

        // Read a line of input from the user and store it in the str array
        str = "Hello World!".toCharArray();

        // Replace the character at index 5 with a space
        str[5] = ' ';

        // Replace the character at index 13 with a space
        str[13] = ' ';

        // Print the modified string to the console
        System.out.println(str);
    }
}

