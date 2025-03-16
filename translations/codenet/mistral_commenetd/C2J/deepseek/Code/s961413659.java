public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();

        if (a == 1) {
            a = 14;
        }

        if (b == 1) {
            b = 14;
        }

        if (a < b) {
            System.out.println("Bob");
        } else if (a > b) {
            System.out.println("Alice");
        } else {
            System.out.println("Draw");
        }
    }
}
