public class Main {
    public static void main(String[] args) {
        int a, b, c, d;

        java.util.Scanner scanner = new java.util.Scanner(System.in);
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();
        d = scanner.nextInt();

        if (a + b > c + d) {
            System.out.println("Left");
        } else if (a + b < c + d) {
            System.out.println("Right");
        } else {
            System.out.println("Balanced");
        }
    }
}
