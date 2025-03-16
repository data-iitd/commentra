import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] as = new int[n];
        for (int i = 0; i < n; i++) {
            as[i] = scanner.nextInt();
        }
        
        int[] xs = new int[n];
        int length = 0;

        for (int j = 0; j < n; j++) {
            int idx = Arrays.binarySearch(xs, 0, length, as[j]);
            if (idx < 0) {
                idx = -(idx + 1);
            }
            if (idx == length) {
                xs[length++] = as[j];
            } else {
                xs[idx] = as[j];
            }
        }
        
        System.out.println(length);
        scanner.close();
    }
}

// <END-OF-CODE>
