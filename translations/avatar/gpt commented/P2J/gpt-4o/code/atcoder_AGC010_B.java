import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements
        int n = scanner.nextInt();
        int[] a = new int[n];
        
        // Read the list of integers
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
        } else {
            // Calculate the average value 'k' that each element should contribute
            double k = (double) sumA / sumNaturalNumbers;
            
            // Create a new array to facilitate circular calculations
            int[] extendedA = new int[n + 1];
            System.arraycopy(a, 0, extendedA, 0, n);
            extendedA[n] = a[0]; // Append the first element of 'a' to the end
            
            // Check if the sum of the adjusted values is zero and if all adjusted values are non-negative
            boolean valid = true;
            for (int i = 1; i <= n; i++) {
                double adjustedValue = (k - extendedA[i] + extendedA[i - 1]) % n;
                if (adjustedValue != 0) {
                    valid = false;
                    break;
                }
            }
            
            if (valid) {
                for (int i = 1; i <= n; i++) {
                    double adjustedValue = (k - extendedA[i] + extendedA[i - 1]) / n;
                    if (adjustedValue < 0) {
                        valid = false;
                        break;
                    }
                }
            }
            
            // If both conditions are satisfied, print "YES"
            if (valid) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
