public class Main {
    public static void main(String[] args) {
        int a, b, c, x, y;
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();
        x = scanner.nextInt();
        y = scanner.nextInt();
        c *= 2;
        if (a + b <= c) {
            System.out.println(a * x + b * y);
        } else {
            if (x <= y) {
                if (b <= c) {
                    System.out.println(c * x + (y - x) * b);
                } else {
                    System.out.println(c * y);
                }
            } else {
                if (a <= c) {
                    System.out.println(c * y + (x - y) * a);
                } else {
                    System.out.println(c * x);
                }
            }
        }
    }
}
