public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        long a = scanner.nextLong();
        long b = scanner.nextLong();
        long c = scanner.nextLong();

        long d = c - a - b;
        if (d > 0 && (4 * a * b) < d * d) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
