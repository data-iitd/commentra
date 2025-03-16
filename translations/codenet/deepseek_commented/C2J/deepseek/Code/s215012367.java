public class Main {
    public static void main(String[] args) {
        int a, b, s;

        java.util.Scanner scanner = new java.util.Scanner(System.in);
        a = scanner.nextInt();
        b = scanner.nextInt();

        s = (a * b) - (a + b) + 1;

        System.out.println(s);
    }
}
