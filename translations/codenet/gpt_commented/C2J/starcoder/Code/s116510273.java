import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare a character array to hold the input string with a maximum length of 100 characters
        char[] mes = new char[101];

        // Read a string from standard input and store it in the'mes' array
        Scanner sc = new Scanner(System.in);
        mes = sc.next().toCharArray();

        // Print the first character of the string, the length of the string minus 2, and the last character of the string
        System.out.printf("%c%lu%c\n", mes[0], mes.length - 2, mes[mes.length - 1]);
    }
}
