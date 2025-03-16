import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static int[] getNums(int num, int t) {
        // This function distributes the value t among num parts.
        // It calculates the base number for each part by dividing t by num.
        // It adds 1 to the base number for the first t % num parts.
        int[] result = new int[num];
        int base = t / num;
        int extra = t % num;

        for (int i = 0; i < num; i++) {
            result[i] = base + (i < extra ? 1 : 0);
        }
        return result;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read input values for n, k, l, r, sa, and sk
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        int l = scanner.nextInt();
        int r = scanner.nextInt();
        int sa = scanner.nextInt();
        int sk = scanner.nextInt();

        // Use the getNums function to calculate the distribution of sk and sa - sk
        int[] ans = new int[k + (n - k)];
        int[] skDistribution = getNums(k, sk);
        int[] saDistribution = getNums(n - k, sa - sk);

        // Combine the two distributions into the final answer
        System.arraycopy(skDistribution, 0, ans, 0, k);
        System.arraycopy(saDistribution, 0, ans, k, n - k);

        // Print the result as a space-separated string of numbers
        System.out.println(Arrays.toString(ans).replaceAll("[\\[\\],]", ""));
        
        scanner.close();
    }
}

// <END-OF-CODE>
