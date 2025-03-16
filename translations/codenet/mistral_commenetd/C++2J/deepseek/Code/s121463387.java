public class Main {
    public static void main(String[] args) {
        int n, x;
        String s;

        java.util.Scanner scanner = new java.util.Scanner(System.in);
        n = scanner.nextInt();

        for (int i = 1; i <= n; i++) {
            x = i;
            s = String.valueOf(x);

            if (x % 3 == 0 || s.endsWith("3")) {
                System.out.print(" " + i);
                continue;
            } else {
                int k = s.length();

                while (k > 0) {
                    k--;
                    int j = (int) Math.pow(10, k);

                    if ((x / j) % 10 == 3) {
                        System.out.print(" " + i);
                        break;
                    }
                }
            }
        }
        System.out.println();
    }
}
