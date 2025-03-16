public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        long l = 0, r = 0;
        if (k % 2 == 0) {
            for (int i = 1; i <= n; i++) {
                if (i % k == k / 2) l++;
                else if (i % k == 0) r++;
            }
            System.out.println(l * l * l + r * r * r);
        } else {
            for (int i = 1; i <= n; i++) {
                if (i % k == 0) r++;
            }
            System.out.println(r * r * r);
        }
    }
}
