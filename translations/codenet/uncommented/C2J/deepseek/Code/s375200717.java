public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        for (int i = 1; i <= n; i++) {
            int a = i;
            if (a % 3 == 0) {
                System.out.print(" " + i);
            } else {
                for (; a != 0; ) {
                    if (a % 10 == 3) {
                        System.out.print(" " + i);
                        a = 0;
                    }
                    a = a / 10;
                }
            }
        }
        System.out.println();
    }
}
