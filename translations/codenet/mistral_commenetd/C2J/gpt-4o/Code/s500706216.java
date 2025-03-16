import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read input n and k
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        
        // Read input array a
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }

        // Initialize light array based on initial a array
        int[] light = new int[n + 2]; // light array of size n + 2
        for (int i = 0; i < n; i++) {
            int r = i - a[i];
            int l = i + a[i];
            light[Math.max(0, r)]++;
            if (l + 1 <= n) {
                light[l + 1]--;
            }
        }

        // Perform k iterations
        for (int i = 0; i < k; i++) {
            // Initialize temporary array tmpa
            int[] tmpa = new int[n];
            int sum = 0;
            for (int j = 0; j < n; j++) {
                tmpa[j] = a[j];
                sum += light[j];
                a[j] = sum;
            }

            // Update light array based on new a array
            for (int j = 0; j < n; j++) {
                int r = j - a[j];
                int l = j + a[j];
                light[Math.max(0, r)]--;
                if (l + 1 <= n) {
                    light[l + 1]++;
                }
                r = j - a[j];
                l = j + a[j];
                light[Math.max(0, r)]++;
                if (l + 1 <= n) {
                    light[l + 1]--;
                }
            }

            // Check if a array is the same for all elements except the first one, and if the first element is equal to the size of the array
            boolean isSame = true;
            for (int j = 0; j < n - 1; j++) {
                if (a[j] != a[j + 1]) {
                    isSame = false;
                    break;
                }
            }
            if (isSame && a[0] == n) {
                break;
            }
        }

        // Print out updated a array
        for (int j = 0; j < n; j++) {
            System.out.print(a[j]);
            if (j < n - 1) {
                System.out.print(" ");
            }
        }
        System.out.println();

        scanner.close();
    }
}
// <END-OF-CODE>
