public class LinearSearch {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        int[] s = new int[n];
        for (int i = 0; i < n; i++) {
            s[i] = scanner.nextInt();
        }
        int q = scanner.nextInt();
        int count = 0;
        for (int i = 0; i < q; i++) {
            int t = scanner.nextInt();
            if (linearSearch(s, n, t)) count++;
        }
        System.out.println(count);
    }

    public static boolean linearSearch(int[] a, int n, int key) {
        for (int i = 0; i < n; i++) {
            if (a[i] == key) {
                return true;
            }
        }
        return false;
    }
}
