public class Main {
    public static int abs(int x) {
        if (x < 0) {
            return -x;
        }
        return x;
    }

    public static int min(int a, int b) {
        if (a > b) {
            return b;
        }
        return a;
    }

    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();

        int x = N % K;
        x = min(abs(x - K), x);
        System.out.println(x);
    }
}
