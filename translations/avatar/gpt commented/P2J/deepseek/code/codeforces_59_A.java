import java.util.Scanner;

public class CaseConverter {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String txt = scanner.nextLine();

        int cu = 0;  // Counter for uppercase letters
        int cl = 0;  // Counter for lowercase letters

        for (char z : txt.toCharArray()) {
            if (Character.isLowerCase(z)) {
                cl++;  // Increment lowercase counter
            } else {
                cu++;  // Increment uppercase counter
            }
        }

        if (cu > cl) {
            // If there are more uppercase letters, convert the text to uppercase
            String out = txt.toUpperCase();
            System.out.println(out);
        } else {
            // If there are more lowercase letters or they are equal, convert the text to lowercase
            String out = txt.toLowerCase();
            System.out.println(out);
        }
    }
}
