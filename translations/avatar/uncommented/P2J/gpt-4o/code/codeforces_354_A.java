import java.util.Scanner;

public class EnergyCalculation {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        int L = scanner.nextInt();
        int R = scanner.nextInt();
        int QL = scanner.nextInt();
        int QR = scanner.nextInt();
        
        int[] W = new int[n];
        for (int i = 0; i < n; i++) {
            W[i] = scanner.nextInt();
        }
        
        long[] sum_el = new long[n + 1];
        for (int i = 1; i <= n; i++) {
            sum_el[i] = W[i - 1] + sum_el[i - 1];
        }
        
        long answer = QR * (n - 1) + sum_el[n] * R;
        for (int i = 1; i <= n; i++) {
            long energy = L * sum_el[i] + R * (sum_el[n] - sum_el[i]);
            if (i > (n - i)) {
                energy += (i - (n - i) - 1) * QL;
            } else if ((n - i) > i) {
                energy += ((n - i) - i - 1) * QR;
            }
            if (energy < answer) {
                answer = energy;
            }
        }
        
        System.out.println(answer);
        scanner.close();
    }
}
//<END-OF-CODE>
