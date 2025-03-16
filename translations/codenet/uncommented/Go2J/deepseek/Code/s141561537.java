public class Main {
    public static void main(String[] args) {
        int a, b, c, x, sum = 0;
        Scanner scanner = new Scanner(System.in);
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();
        x = scanner.nextInt();
        for (int i = 0; i <= a; i++) {
            for (int j = 0; j <= b; j++) {
                for (int k = 0; k <= c; k++) {
                    if (500 * i + 100 * j + 50 * k == x) {
                        sum++;
                    }
                }
            }
        }
        System.out.println(sum);
    }
}
