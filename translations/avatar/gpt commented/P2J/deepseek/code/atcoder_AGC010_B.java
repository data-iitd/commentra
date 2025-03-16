import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements and the list of integers from input
        int n = scanner.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        
        // Check if the sum of the list 'a' is divisible by the sum of the first n natural numbers
        int sumA = 0;
        for (int num : a) {
            sumA += num;
        }
        
        int sumNaturalNumbers = n * (n + 1) / 2;
        if (sumA % sumNaturalNumbers != 0) {
            // If not divisible, print "NO" and exit
            System.out.println("NO");
            return;
        }
        
        // Calculate the average value 'k' that each element should contribute
        int k = sumA / sumNaturalNumbers;
        
        // Append the first element of 'a' to the end of the list to facilitate circular calculations
        int[] aWithCircular = new int[n + 1];
        System.arraycopy(a, 0, aWithCircular, 0, n);
        aWithCircular[n] = a[0];
        
        // Check if the sum of the adjusted values is zero and if all adjusted values are non-negative
        int sumAdjustedValues = 0;
        for (int i = 1; i <= n; i++) {
            int adjustedValue = (k - aWithCircular[i] + aWithCircular[i - 1]) % n;
            if (adjustedValue < 0) {
                adjustedValue += n;
            }
            sumAdjustedValues += adjustedValue;
        }
        
        if (sumAdjustedValues != 0 || sumAdjustedValues / n < 0) {
            // If either condition fails, print "NO"
            System.out.println("NO");
        } else {
            // If both conditions are satisfied, print "YES"
            System.out.println("YES");
        }
    }
}
