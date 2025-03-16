import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int x = 1;

        while (true) {
            if (isPowerOfTwo(n)) {
                break;
            }

            x++;
            n -= (int) Math.pow(2, (int) (Math.log(n) / Math.log(2)));
        }

        System.out.println(x);
    }

    private static boolean isPowerOfTwo(int n) {
        return (n & (n - 1)) == 0;
    }
}
