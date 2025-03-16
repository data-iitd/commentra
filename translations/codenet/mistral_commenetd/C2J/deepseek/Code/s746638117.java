public class Main {
    public static void main(String[] args) {
        int a, b, ar, le;

        java.util.Scanner scanner = new java.util.Scanner(System.in);
        a = scanner.nextInt();
        b = scanner.nextInt();

        ar = a * b;
        le = 2 * (a + b);

        System.out.println(ar + " " + le);
    }
}
