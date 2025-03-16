import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int num = scanner.nextInt();
        System.out.print(num + ":");

        while (num != 1) {
            int divisor = div(num);
            System.out.print(" " + divisor);
            num = num / divisor;
        }
        System.out.println();
        scanner.close();
    }

    public static int div(int n) {
        if (n % 2 == 0) return 2;
        int s = (int) Math.sqrt(n);
        for (int i = 3; i <= s; i += 2) {
            if (n % i == 0) return i;
        }
        return n;
    }
}

// <END-OF-CODE>
