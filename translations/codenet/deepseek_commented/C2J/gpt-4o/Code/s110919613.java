import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        while (true) {
            int[] an = new int[20];
            int[] a1 = new int[6];
            int[] a2 = new int[6];
            int L = scanner.nextInt();
            an[0] = scanner.nextInt();
            if (L == 0) break; // If L is 0, break out of the loop
            
            int aj = an[0];
            boolean end = false;
            for (int k = 1; k < 21; k++) {
                for (int i = L - 1; i >= 0; i--, aj /= 10) {
                    a1[i] = aj % 10; 
                    a2[i] = aj % 10; // Initialize a1 and a2 with the digits of aj
                }
                for (int i = 1; i < L; i++) {
                    for (int j = 1; j < L; j++) {
                        if (a1[j - 1] < a1[j]) { // Sort a1 in ascending order
                            int tmp = a1[j - 1];
                            a1[j - 1] = a1[j];
                            a1[j] = tmp;
                        }
                        if (a2[j - 1] > a2[j]) { // Sort a2 in descending order
                            int tmp = a2[j - 1];
                            a2[j - 1] = a2[j];
                            a2[j] = tmp;
                        }
                    }
                }
                int d = 1;
                int max = 0;
                int min = 0;
                for (int i = L - 1; i >= 0; i--, d *= 10) {
                    max += (a1[i] % 10) * d; // Calculate max by combining sorted digits
                    min += (a2[i] % 10) * d; // Calculate min by combining sorted digits
                }
                int def = max - min; // Calculate the difference def
                for (int i = 0; i < k; i++) {
                    if (def == an[i]) { // Check if def has been seen before
                        System.out.printf("%d %d %d\n", i, def, k - i); // Print the index, def, and steps taken
                        end = true; 
                        break; // Set end to true to break out of the loop
                    }
                }
                if (end) break; // If end is true, break out of the loop
                an[k] = def; 
                aj = def; // Add def to an and update aj
            }
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
