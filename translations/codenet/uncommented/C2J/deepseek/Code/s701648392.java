public class Main {
    public static void main(String[] args) {
        int a, b, c;
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();
        if (a < b && b < c) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
