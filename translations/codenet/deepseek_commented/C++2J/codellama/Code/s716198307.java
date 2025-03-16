import java.util.Scanner;

public class ClosestToAverage {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[100];
        double avg = 0;
        double s = 0;
        int ans = 0;
        
        // Step 1: Input the number of elements (n) and the array elements (a[100])
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
            avg += a[i];
        }
        
        // Step 2: Calculate the average of the array elements
        avg /= n;
        
        // Step 3: Find the element closest to the average
        s = Math.abs(a[0] - avg);
        for (int i = 1; i < n; i++) {
            if (s > Math.abs(a[i] - avg)) {
                s = Math.abs(a[i] - avg);
                ans = i;
            }
        }
        
        // Step 4: Output the index of the closest element
        System.out.println(ans);
    }
}
