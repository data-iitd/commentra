public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        long a = scanner.nextLong();
        long b = scanner.nextLong();

        // Calculate the maximum of the sum, difference, and product of a and b
        System.out.println(Math.max(a + b, Math.max(a - b, a * b)));
    }
}
