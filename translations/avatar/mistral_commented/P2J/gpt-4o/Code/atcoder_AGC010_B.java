import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Take input from the user
        int n = scanner.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        
        // Check if the sum of the elements in the list is divisible by the formula
        int sum = 0;
        for (int num : a) {
            sum += num;
        }
        
        if (sum % (n * (n + 1) / 2) != 0) {
            System.out.println("NO");
            return;
        }
        
        // Calculate the average of the elements in the list
        double k = (double) sum / (n * (n + 1) / 2);
        
        // Add the first element to the end of the list for simplification
        int[] extendedA = new int[n + 1];
        System.arraycopy(a, 0, extendedA, 0, n);
        extendedA[n] = a[0];
        
        // Check if the differences between consecutive elements (modulo n) or the ratios of the differences to n are valid
        int modSum = 0;
        int ratioSum = 0;
        
        for (int i = 1; i <= n; i++) {
            int diff = (int) ((k - extendedA[i] + extendedA[i - 1]) % n);
            modSum += diff;
            if ((k - extendedA[i] + extendedA[i - 1]) / n >= 0) {
                ratioSum++;
            }
        }
        
        if (modSum != 0 || ratioSum != n) {
            System.out.println("NO");
            return;
        }
        
        // If all checks pass, print YES
        System.out.println("YES");
    }
}
// <END-OF-CODE>
