import java.util.Scanner;

public class AnagramCheck {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String str1 = scanner.nextLine();
        String str2 = scanner.nextLine();

        if (str1.length() != str2.length()) {
            System.out.println("NO");
        } else {
            String temp = new StringBuilder(str1).reverse().toString();
            if (temp.equals(str2)) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }
}
