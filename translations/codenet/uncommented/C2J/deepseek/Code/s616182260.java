public class Main {
    public static void main(String[] args) {
        int[] a = new int[3];
        int[] b = new int[3];
        int[][] c = new int[3][3];
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                c[i][j] = scanner.nextInt();
            }
        }
        a[0] = 0;
        for (int i = 0; i < 3; i++) {
            b[i] = c[0][i];
        }
        for (int i = 1; i < 3; i++) {
            a[i] = c[i][0] - b[0];
        }
        boolean valid = true;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (c[i][j] != a[i] + b[j]) {
                    valid = false;
                    break;
                }
            }
            if (!valid) {
                break;
            }
        }
        if (valid) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
