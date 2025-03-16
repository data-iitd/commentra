import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static int[] getNums(int num, int t) {
        int[] result = new int[num];
        for (int i = 0; i < num; i++) {
            result[i] = (i < t % num) ? (t / num + 1) : (t / num);
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
        
        // Calculate the distribution of sk among k parts and sa - sk among the remaining n - k parts
        int[] ans = new int[n];
        int[] firstPart = getNums(k, sk);
        int[] secondPart = getNums(n - k, sa - sk);
        
        // Combine the two parts into the final answer
        System.arraycopy(firstPart, 0, ans, 0, k);
        System.arraycopy(secondPart, 0, ans, k, n - k);
        
        // Print the result as a space-separated string
        System.out.println(Arrays.toString(ans).replaceAll("[\\[\\],]", ""));
        
        scanner.close();
    }
}

// <END-OF-CODE>
