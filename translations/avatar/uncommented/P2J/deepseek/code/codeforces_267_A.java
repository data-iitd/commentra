import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Subtract {
    public static int subtract(int a, int b) {
        if (a > b) {
            int total = 0;
            while (a > 0 && b > 0) {
                total += a / b;
                a = a % b;
                if (a > 0) {
                    total += b / a;
                    b = b % a;
                }
            }
            return total;
        }
        if (a < b) {
            int total = 0;
            while (a > 0 && b > 0) {
                total += b / a;
                b = b % a;
                if (b > 0) {
                    total += a / b;
                    a = a % b;
                }
            }
            return total;
        }
        if (a == b) {
            return 1;
        }
        return 0; // This line is added to handle the case where none of the above conditions are met.
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = Integer.parseInt(scanner.nextLine());
        List<Integer> lst = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String[] inputs = scanner.nextLine().split(" ");
            int a = Integer.parseInt(inputs[0]);
            int b = Integer.parseInt(inputs[1]);
            lst.add(subtract(a, b));
        }
        for (int i : lst) {
            System.out.println(i);
        }
    }
}
