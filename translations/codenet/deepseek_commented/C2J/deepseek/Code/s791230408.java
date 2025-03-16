public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int j = scanner.nextInt();

        for (int i = 0; i < j; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            int c = scanner.nextInt();

            int max = a;
            int k = 0;
            if (max <= b) {
                max = b;
                k = 1;
            }
            if (max <= c) {
                max = c;
                k = 2;
            }

            max = max * max;
            a = a * a;
            b = b * b;
            c = c * c;

            if (k == 0 && max == b + c) {
                System.out.println("YES");
            } else if (k == 1 && max == a + c) {
                System.out.println("YES");
            } else if (k == 2 && max == a + b) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }
}
