public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int[] h = new int[n];
        for (int i = 0; i < n; i++) {
            h[i] = scanner.nextInt();
        }
        int a, b;
        java.util.Set<Integer> counter = new java.util.HashSet<>();
        for (int i = 0; i < m; i++) {
            a = scanner.nextInt();
            b = scanner.nextInt();
            if (h[a - 1] < h[b - 1]) {
                counter.add(a);
            } else if (h[a - 1] > h[b - 1]) {
                counter.add(b);
            } else if (h[a - 1] == h[b - 1]) {
                counter.add(a);
                counter.add(b);
            }
        }
        System.out.println(n - counter.size());
    }
}
