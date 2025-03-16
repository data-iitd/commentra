public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        while (true) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            int n = scanner.nextInt();
            if (!scanner.hasNext()) break;
            a -= a / b * b;
            int sum = 0;
            for (int i = 1; i <= n; i++) {
                a *= 10;
                for (int j = 9; j >= 0; j--) {
                    if (b * j <= a) break;
                }
                a -= b * j;
                sum += j;
            }
            System.out.println(sum);
        }
    }
}
