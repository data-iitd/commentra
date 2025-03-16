public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);

        while (true) {
            int a = scanner.nextInt();
            char S = scanner.next().charAt(0);
            int b = scanner.nextInt();

            if (S == '+') System.out.println(a + b);
            if (S == '-') System.out.println(a - b);
            if (S == '*') System.out.println(a * b);
            if (S == '/') System.out.println(a / b);
            if (S == '?') break;
        }
    }
}
