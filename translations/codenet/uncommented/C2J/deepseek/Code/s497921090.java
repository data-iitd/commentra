public class Main {
    public static void main(String[] args) {
        long n, a, b = 0, i, j;
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        n = scanner.nextLong();
        b = (n * (n - 1)) / 2;
        System.out.println(b);
    }
}
