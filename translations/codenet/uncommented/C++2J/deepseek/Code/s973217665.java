public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        while (n-- > 0) {
            int p = scanner.nextInt();
            int q = scanner.nextInt();
            int l = (int) Math.sqrt(p * p + q * q);
            boolean isprime = true;
            for (int i = 0; i <= l; i++) {
                for (int j = 0; j <= l; j++) {
                    int x = i * i + j * j;
                    if (x <= 1 || x >= p * p + q * q) continue;
                    if ((i * p + j * q) % x == 0 && (i * q - j * p) % x == 0) isprime = false;
                }
            }
            System.out.println(isprime ? "P" : "C");
        }
    }
}
