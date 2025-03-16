import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        long sum = 0;
        int m, n, min = Integer.MAX_VALUE, max = Integer.MIN_VALUE;
        Scanner scanner = new Scanner(System.in);
        
        n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            m = scanner.nextInt();
            sum += m;
            if (m < min) {
                min = m;
            }
            if (m > max) {
                max = m;
            }
        }
        
        System.out.printf("%d %d %d\n", min, max, sum);
        scanner.close();
    }
}

// <END-OF-CODE>
