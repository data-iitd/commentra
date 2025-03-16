public class Main {
    public static void main(String[] args) {
        int a, b;
        java.util.Scanner scanner = new java.util.Scanner(System.in);

        a = scanner.nextInt();
        b = scanner.nextInt();

        System.out.println(a * b + " " + 2 * (a + b));
    }
}
