
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        float[] arr = new float[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextFloat();
        }

        List<Float> arr_flt = new ArrayList<Float>();
        for (float x : arr) {
            if (x - (int) x!= 0) {
                arr_flt.add(x - (int) x);
            }
        }
        Collections.sort(arr_flt);

        int o = 2 * n - arr_flt.size();
        float arr_sum = 0;
        for (float x : arr_flt) {
            arr_sum += x;
        }

        int res = (int) 2e9;
        for (int i = 0; i <= n; i++) {
            if (i + o >= n) {
                res = Math.min(res, Math.abs(i - arr_sum));
            }
        }

        System.out.printf("%.3f", res);
    }
}

