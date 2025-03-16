public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            int h = scanner.nextInt();
            if (h >= k) {
                cnt++;
            }
        }
        System.out.println(cnt);
    }
}
