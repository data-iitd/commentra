import java.util.Scanner;

public class Main {
    // The `group` method takes an integer `n` and returns "B" if `n` is 4, 6, 9, or 11, otherwise it returns "A".
    public static String group(int n) {
        if (n == 4 || n == 6 || n == 9 || n == 11) {
            return "B";
        } else {
            return "A";
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int x, y;

        // Reads two integers `x` and `y` from the standard input.
        x = scanner.nextInt();
        y = scanner.nextInt();

        // Checks if either `x` or `y` is 2. If so, it prints "No" and returns immediately.
        if (x == 2 || y == 2) {
            System.out.println("No");
            return;
        }

        // Calls the `group` method for both `x` and `y` to determine their respective groups.
        String xg = group(x);
        String yg = group(y);

        // Compares the groups of `x` and `y`. If they are the same, it prints "Yes"; otherwise, it prints "No".
        if (xg.equals(yg)) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }

        scanner.close();
    }
}

// <END-OF-CODE>
