import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String txt = scanner.nextLine();
        int cu = 0;
        int cl = 0;

        for (char z : txt.toCharArray()) {
            if (Character.isLowerCase(z)) {
                cl++;
            } else {
                cu++;
            }
        }

        String out;
        if (cu > cl) {
            out = txt.toUpperCase();
        } else {
            out = txt.toLowerCase();
        }

        System.out.println(out);
        scanner.close();
    }
}
// <END-OF-CODE>
