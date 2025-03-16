import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = Integer.parseInt(scanner.nextLine());
        String[] input = scanner.nextLine().split(" ");
        double[] arr = new double[n];
        
        for (int i = 0; i < n; i++) {
            arr[i] = Double.parseDouble(input[i]);
        }
        
        List<Double> fractionalParts = new ArrayList<>();
        for (double x : arr) {
            double fractionalPart = x - (int) x;
            if (fractionalPart != 0) {
                fractionalParts.add(fractionalPart);
            }
        }
        
        Collections.sort(fractionalParts);
        int o = 2 * n - fractionalParts.size();
        double arrSum = 0;
        for (double x : fractionalParts) {
            arrSum += x;
        }
        
        double res = 2e9;
        for (int i = 0; i <= n; i++) {
            if (i + o >= n) {
                res = Math.min(res, Math.abs(i - arrSum));
            }
        }
        
        System.out.printf("%.3f%n", res);
    }
}
// <END-OF-CODE>
