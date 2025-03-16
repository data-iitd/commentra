public class Main {
    public static void main(String[] args) {
        int n, k;
        long l = 0, r = 0;

        java.util.Scanner scanner = new java.util.Scanner(System.in);
        n = scanner.nextInt();
        k = scanner.nextInt();

        if (k % 2 == 0) {
            for (int i = 1; i <= n; i++) {
                if (i % k == k / 2) {
                    l++;
                } else if (i % k == 0) {
                    r++;
                }
            }
            System.out.println(l * l * l + r * r * r);
        } else {
            for (int i = 1; i <= n; i++) {
                if (i % k == 0) {
                    r++;
                }
            }
            System.out.println(r * r * r);
        }
    }
}
