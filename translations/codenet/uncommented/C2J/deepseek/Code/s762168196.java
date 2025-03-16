public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        int[] a = new int[10000];
        long sum = 0;
        int min = 0, max = 0;

        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
            sum += a[i];
        }

        min = max = a[0];
        for (int i = 1; i < n; i++) {
            if (a[i] > max) max = a[i];
            if (a[i] < min) min = a[i];
        }

        System.out.println(min + " " + max + " " + sum);
    }
}
