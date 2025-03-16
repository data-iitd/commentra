
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;

public class s479324991{
    public static void main(String[] args) {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

        int n = sc.nextInt();
        double[] arr = new double[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        Arrays.sort(arr);
        double prev = arr[0];
        for (int i = 1; i < n; i++) {
            prev = (prev + arr[i]) / 2;
        }

        System.out.printf("%.6f\n", prev);
    }
}

