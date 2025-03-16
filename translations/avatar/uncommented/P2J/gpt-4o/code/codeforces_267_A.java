import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static int subtract(int a, int b) {
        int total = 0;
        if (a > b) {
            while (a > 0 && b > 0) {
                total += a / b;
                a = a % b;
                if (a > 0) {
                    total += b / a;
                    b = b % a;
                }
            }
        } else if (a < b) {
            while (a > 0 && b > 0) {
                total += b / a;
                b = b % a;
                if (b > 0) {
                    total += a / b;
                    a = a % b;
                }
            }
        } else {
            return 1;
        }
        return total;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        List<Integer> lst = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            lst.add(subtract(a, b));
        }
        for (int result : lst) {
            System.out.println(result);
        }
        scanner.close();
    }
}

// <END-OF-CODE>
