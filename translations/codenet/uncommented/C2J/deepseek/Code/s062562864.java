public class Main {
    public static void main(String[] args) {
        int a, b, c, d, i, j;
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();
        d = scanner.nextInt();
        i = a * b;
        j = c * d;
        if (i > j) {
            System.out.println(i);
        } else {
            System.out.println(j);
        }
    }
}
