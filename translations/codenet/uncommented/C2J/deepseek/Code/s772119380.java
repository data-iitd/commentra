public class BubbleSort {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        int[] a = new int[1000];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        int d = 0;
        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j >= i + 1; j--) {
                if (a[j] < a[j - 1]) {
                    int temp = a[j];
                    a[j] = a[j - 1];
                    a[j - 1] = temp;
                    d++;
                }
            }
        }
        System.out.print(a[0]);
        for (int i = 1; i < n; i++) {
            System.out.print(" " + a[i]);
        }
        System.out.println();
        System.out.println(d);
    }
}
