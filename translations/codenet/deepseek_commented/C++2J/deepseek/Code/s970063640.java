public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        int a = scanner.nextInt();
        int[] s = new int[n];
        for (int i = 0; i < n; i++) {
            s[i] = scanner.nextInt();
        }
        java.util.Arrays.sort(s);
        int sum = 0;
        for (int i = n - 1; i > n - a - 1; i--) {
            sum += s[i];
        }
        System.out.println(sum);
    }
}
