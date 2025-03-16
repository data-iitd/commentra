import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] w = new int[n];

        for (int i = 0; i < n; i++) {
            w[i] = sc.nextInt();
        }

        int c = 2;

        for (int number : w) {
            if (number == 1) {
                System.out.println(c);
            } else if (number % 2 == 0) {
                c = 3 - c;
                System.out.println(c);
            } else {
                System.out.println(c);
            }
        }
    }
}

