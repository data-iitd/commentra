public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int a, b;
        char m;
        int[] c = new int[256];
        int i = 0;

        while (true) {
            a = scanner.nextInt();
            m = scanner.next().charAt(0);
            b = scanner.nextInt();

            if (m == '?') {
                break;
            }

            switch (m) {
                case '+':
                    c[i] = a + b;
                    break;
                case '-':
                    c[i] = a - b;
                    break;
                case '*':
                    c[i] = a * b;
                    break;
                case '/':
                    c[i] = a / b;
                    break;
            }
            i++;
        }

        for (int j = 0; j < i; j++) {
            System.out.println(c[j]);
        }
    }
}
