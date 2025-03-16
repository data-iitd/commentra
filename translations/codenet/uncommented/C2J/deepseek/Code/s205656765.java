public class Main {
    public static void main(String[] args) {
        int A, B, C, X;
        int i = 0;
        int j = 0;
        int k = 0;
        int kosu = 0;

        // 整数の入力
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        A = scanner.nextInt();
        B = scanner.nextInt();
        C = scanner.nextInt();
        X = scanner.nextInt();

        X = X / 50;

        for (i = 0; i <= A; i++) {
            for (j = 0; j <= B; j++) {
                for (k = 0; k <= C; k++) {
                    if (X == (10 * i) + (2 * j) + k) kosu++;
                }
            }
        }

        System.out.println(kosu);
    }
}
