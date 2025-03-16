import java.util.Scanner;

public class NearestNonExcludedValue {
    public static void main(String[] args) {
        // Step 1: Reading Input
        Scanner scanner = new Scanner(System.in);
        int X = scanner.nextInt();
        int N = scanner.nextInt();
        
        // If no values are excluded, print X and exit
        if (N == 0) {
            System.out.println(X);
            return;
        }
        
        // Step 2: Initializing Arrays
        int[] plus = new int[256];
        int[] minus = new int[256];
        for (int i = 0; i < 256; i++) {
            plus[i] = i;
            minus[i] = -i;
        }
        
        // Step 3: Marking Excluded Values
        for (int i = 0; i < N; i++) {
            int j = scanner.nextInt();
            plus[j] = 0;
        }
        
        // Step 4: Finding the Nearest Non-Zero Value
        int i_min = 0;
        int min = 1000;
        for (int i = 255; i >= 0; i--) {
            if (plus[i] == 0 && i > 0) {
                continue;
            }
            int k = X - plus[i];
            if (k < 0) { 
                k *= -1; 
            }
            if (k <= min) {
                min = k;
                i_min = i;
            }
        }
        
        // Step 5: Outputting the Result
        System.out.println(i_min);
        
        scanner.close();
    }
}
// <END-OF-CODE>
