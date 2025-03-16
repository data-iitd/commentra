import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();
        int flag = 0;

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (i % 2 == 0) {
                switch (c) {
                    case 'R':
                    case 'U':
                    case 'D':
                        break;
                    default:
                        flag = 1;
                        break;
                }
            } else {
                switch (c) {
                    case 'L':
                    case 'U':
                    case 'D':
                        break;
                    default:
                        flag = 1;
                        break;
                }
            }
        }

        if (flag == 0) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
// <END-OF-CODE>
