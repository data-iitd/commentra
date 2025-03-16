import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();
        boolean flag = false;

        for (int i = 0; i < s.length(); i++) {
            if (i % 2 == 0) {
                if (s.charAt(i) != 'R' && s.charAt(i) != 'U' && s.charAt(i) != 'D') {
                    flag = true;
                    break;
                }
            } else {
                if (s.charAt(i) != 'L' && s.charAt(i) != 'U' && s.charAt(i) != 'D') {
                    flag = true;
                    break;
                }
            }
        }

        if (!flag) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
