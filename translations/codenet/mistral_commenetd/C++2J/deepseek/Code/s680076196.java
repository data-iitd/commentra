public class Main {
    public static void main(String[] args) {
        // Declare variables a, b, c, and d of type int
        int a, b, c, d;

        // Read values of variables a, b, c, and d from standard input
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();
        d = scanner.nextInt();

        // Calculate the difference between a and c, and the difference between b and d
        long difference_ab = (long) a - (long) c;
        long difference_cd = (long) b - (long) d;

        // Multiply the differences and print the result to standard output
        System.out.println(difference_ab * difference_cd);
    }
}
