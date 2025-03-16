public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();

        for (int i = 1; i <= n; i++) {
            int x = i;
            String s = String.valueOf(x);
            if (x % 3 == 0 || s.contains("3")) {
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
