public class Main {
    public static void main(String[] args) {
        int n, k, x, y;
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        k = scanner.nextInt();
        x = scanner.nextInt();
        y = scanner.nextInt();
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            if (i > k)
                sum += y;
            else
                sum += x;
        }
        System.out.println(sum);
    }
}
