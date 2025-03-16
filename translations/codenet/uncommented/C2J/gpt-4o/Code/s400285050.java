import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int x, y, z;
        x = scanner.nextInt();
        y = scanner.nextInt();
        if (x >= y) {
            z = you(x, y);
        } else {
            z = you(y, x);
        }
        System.out.println(z);
        scanner.close();
    }

    public static int you(int x, int y) {
        int z;
        while (true) {
            z = x % y;
            x = y;
            y = z;
            if (y <= 0) break;
        }
        return x;
    }
}

// <END-OF-CODE>
