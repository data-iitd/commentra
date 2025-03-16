
import java.util.Scanner;
import java.util.Arrays;
import java.util.Map;
import java.util.HashMap;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        double[] arr = new double[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextDouble();
        }
        Arrays.sort(arr);
        double prev = arr[0];
        for (int i = 1; i < n; i++) {
            prev = (prev + arr[i]) / 2;
        }
        System.out.println(prev);
    }
}

