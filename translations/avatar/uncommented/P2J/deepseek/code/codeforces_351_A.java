import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        List<Double> arr = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            arr.add(scanner.nextDouble());
        }
        List<Double> fractionalPartList = new ArrayList<>();
        for (Double num : arr) {
            double fractionalPart = num - Math.floor(num);
            if (fractionalPart != 0) {
                fractionalPartList.add(fractionalPart);
            }
        }
        Collections.sort(fractionalPartList);
        int o = 2 * n - fractionalPartList.size();
        double arrSum = fractionalPartList.stream().mapToDouble(Double::doubleValue).sum();
        double res = 2e9;
        for (int i = 0; i <= n; i++) {
            if (i + o >= n) {
                res = Math.min(res, Math.abs(i - arrSum));
            }
        }
        System.out.printf("%.3f", res);
    }
}
