import java.util.Scanner;

public class Main {
    static final int N = 2000;
    static int num1;
    static int[] math = new int[N + 1];

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a, num2, ans, sum = 0;

        math[0] = 1;

        num1 = scanner.nextInt();
        for (int i = 0; i < num1; i++) {
            a = scanner.nextInt();
            sum += a;
            for (int j = sum - a; j >= 0; j--) {
                if (math[j] == 1) {
                    math[j + a] = 1;
                }
            }
        }

        num2 = scanner.nextInt();
        for (int i = 0; i < num2; i++) {
            ans = scanner.nextInt();
            System.out.println(math[ans] == 1 ? "yes" : "no");
        }

        scanner.close();
    }
}

// <END-OF-CODE>
