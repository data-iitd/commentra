import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String mes = sc.next();

        // Calculate the length of the string excluding the first and last character
        int length = mes.length() - 2;

        // Print the first character, the calculated length, and the last character of the string
        System.out.printf("%c%d%c\n", mes.charAt(0), length, mes.charAt(mes.length() - 1));
    }
}
