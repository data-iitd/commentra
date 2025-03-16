import java.util.Scanner;

public class EnergyCalculation {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Reading inputs for n, L, R, QL, QR
        int n = scanner.nextInt();
        int L = scanner.nextInt();
        int R = scanner.nextInt();
        int QL = scanner.nextInt();
        int QR = scanner.nextInt();
        
        // Reading the list of weights W
        int[] W = new int[n];
        for (int i = 0; i < n; i++) {
            W[i] = scanner.nextInt();
        }
        
        // Calculating the prefix sum of the weights
        int[] sum_el = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            sum_el[i] = W[i - 1] + sum_el[i - 1];
        }
        
        // Initial answer calculation based on the formula
        int answer = QR * (n - 1) + sum_el[n] * R;
        
        // Loop to calculate energy for each possible split point
        for (int i = 1; i <= n; i++) {
            int energy = L * sum_el[i] + R * (sum_el[n] - sum_el[i]); // Energy calculation
            if (i > (n - i)) { // If the left side is heavier
                energy += (i - (n - i) - 1) * QL; // Adding QL if needed
            } else if ((n - i) > i) { // If the right side is heavier
                energy += ((n - i) - i - 1) * QR; // Adding QR if needed
            }
            if (energy < answer) { // Updating the answer if a new minimum energy is found
                answer = energy;
            }
        }
        
        System.out.println(answer); // Output the minimum energy
        scanner.close();
    }
}
// <END-OF-CODE>
