public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();

        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        int curr = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == curr + 1) curr++;
        }
        if (curr > 0) {
            System.out.println(n - curr);
        } else {
            System.out.println("-1");
        }
    }
}
