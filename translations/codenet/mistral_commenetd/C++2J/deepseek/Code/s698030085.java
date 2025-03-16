public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        long a = scanner.nextLong();
        long b = scanner.nextLong();

        if ((a + b) % 2 == 0) {
            System.out.println((a + b) / 2);
        } else {
            System.out.println("IMPOSSIBLE");
        }
    }
}
