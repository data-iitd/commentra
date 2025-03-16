public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int[] s = new int[m];
        int[] c = new int[m];
        for (int i = 0; i < m; i++) {
            s[i] = scanner.nextInt() - 1;
            c[i] = scanner.nextInt();
        }
        for (int i = 0; i < 1000; i++) {
            String st = String.valueOf(i);
            if (st.length() != n) {
                continue;
            }
            int f = 1;
            for (int j = 0; j < m; j++) {
                if (st.charAt(s[j]) == (char) (c[j] + '0')) {
                    // do nothing
                } else {
                    f = 0;
                }
            }
            if (f == 1) {
                System.out.println(i);
                return;
            }
        }
        System.out.println(-1);
    }
}
