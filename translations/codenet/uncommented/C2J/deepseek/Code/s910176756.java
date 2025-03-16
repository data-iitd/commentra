public class SimpleCalculator {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        while (true) {
            int a = scanner.nextInt();
            char op = scanner.next().charAt(0);
            int b = scanner.nextInt();
            if (op == '+') {
                int c = a + b;
                System.out.println(c);
            } else if (op == '-') {
                int c = a - b;
                System.out.println(c);
            } else if (op == '*') {
                int c = a * b;
                System.out.println(c);
            } else if (op == '/') {
                int c = a / b;
                System.out.println(c);
            } else {
                break;
            }
        }
    }
}
