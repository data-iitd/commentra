public class Main {
    public static void main(String[] args) {
        int n, k, x, y, z;
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        n = scanner.nextInt();
        k = scanner.nextInt();
        x = n / k;
        y = n % k;
        if (y != 0) {
            z = x + 1 - x;
        } else {
            z = x - x;
        }
        System.out.println(z);
    }
}
