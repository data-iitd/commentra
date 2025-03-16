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
        
        List<Double> filteredList = new ArrayList<>();
        for (Double num : arr) {
            if (num != (int) num) {
                filteredList.add(num - (int) num);
            }
        }
        
        Collections.sort(filteredList);
        
        int o = 2 * n - filteredList.size();
        
        double arr_sum = 0;
        for (Double num : filteredList) {
            arr_sum += num;
        }
        
        double res = Double.MAX_VALUE;
        
        for (int i = 0; i <= n; i++) {
            if (i + o >= n) {
                res = Math.min(res, Math.abs(i - arr_sum));
            }
        }
        
        System.out.printf("%.3f\n", res);
    }
}

