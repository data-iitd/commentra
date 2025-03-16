import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] input = scanner.nextLine().split(" ");
        int x = Integer.parseInt(input[0]);
        int y = Integer.parseInt(input[1]);
        int a = Integer.parseInt(input[2]);
        int b = Integer.parseInt(input[3]);

        int lcm = L(x, y);
        System.out.println(b / lcm - (a - 1) / lcm);
    }

    public static int G(int a, int b) {
        while (a % b != 0) {
            int temp = a;
            a = b;
            b = temp % b;
        }
        return b;
    }

    public static int L(int a, int b) {
        return a * b / G(a, b);
    }
}

// <END-OF-CODE>
