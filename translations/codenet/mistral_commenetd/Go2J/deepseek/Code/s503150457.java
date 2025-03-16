import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read user input for strings s1, s2, and s3
        String s1 = scanner.next();
        String s2 = scanner.next();
        String s3 = scanner.next();

        // Convert the first character of each string to uppercase and concatenate them
        String result = String.valueOf(s1.charAt(0)).toUpperCase() +
                        String.valueOf(s2.charAt(0)).toUpperCase() +
                        String.valueOf(s3.charAt(0)).toUpperCase();

        // Print the concatenated result
        System.out.println(result);
    }
}
