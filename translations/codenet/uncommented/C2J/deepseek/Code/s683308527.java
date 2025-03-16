import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine(); // Consume newline
        while (n-- > 0) {
            String s = scanner.nextLine();
            char[] chars = s.toCharArray();
            for (int i = 0; i < chars.length - 5; i++) {
                if (chars[i] == 'H' && chars[i + 1] == 'o' && chars[i + 2] == 's' && chars[i + 3] == 'h' && chars[i + 4] == 'i' && chars[i + 5] == 'n' && chars[i + 6] == 'o') {
                    chars[i + 6] = 'a';
                }
            }
            System.out.println(new String(chars));
        }
    }
}
