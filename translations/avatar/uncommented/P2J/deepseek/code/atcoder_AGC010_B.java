import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        
        if (sum(a) % (n * (n + 1) / 2) != 0) {
            System.out.println("NO");
        } else {
            double k = (double) sum(a) / (n * (n + 1) / 2);
            int[] extendedA = new int[n + 1];
            System.arraycopy(a, 0, extendedA, 0, n);
            extendedA[n] = a[0];
            
            if (sum(new int[] {(int) ((k - i + j) % n), (int) ((k - i + j) / n)}) != 0 || sum(new int[] {(int) ((k - i + j) / n), (int) ((k - i + j) / n)}) != n) {
                System.out.println("NO");
            } else {
                System.out.println("YES");
            }
        }
    }
    
    private static int sum(int[] arr) {
        int sum = 0;
        for (int num : arr) {
            sum += num;
        }
        return sum;
    }
}
