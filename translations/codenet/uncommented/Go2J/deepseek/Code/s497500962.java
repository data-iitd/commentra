public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int R = scanner.nextInt();
        int G = scanner.nextInt();
        int B = scanner.nextInt();
        int N = scanner.nextInt();

        int ans = 0;
        for (int x = 0; x <= N; x++) {
            for (int y = 0; y <= N; y++) {
                int tmp = N - R * x - G * y;
                if (tmp >= 0 && tmp % B == 0) {
                    ans++;
                }
            }
        }

        System.out.println(ans);
    }
}
