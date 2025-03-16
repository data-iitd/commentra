public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        int[] p = new int[99999];
        for (int i = 0; i < n; i++) {
            p[i] = scanner.nextInt();
        }
        java.util.Arrays.sort(p);
        int o = 0;
        for (int i = 0; i < k; i++) {
            o += p[i];
        }
        System.out.println(o);
    }
}
