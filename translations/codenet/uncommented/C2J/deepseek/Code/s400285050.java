public class GCD {
    public static int gcd(int x, int y) {
        while (true) {
            int z = x % y;
            x = y;
            y = z;
            if (y <= 0) {
                break;
            }
        }
        return x;
    }

    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int x = scanner.nextInt();
        int y = scanner.nextInt();
        int z;
        if (x >= y) {
            z = gcd(x, y);
        } else {
            z = gcd(y, x);
        }
        System.out.println(z);
    }
}
