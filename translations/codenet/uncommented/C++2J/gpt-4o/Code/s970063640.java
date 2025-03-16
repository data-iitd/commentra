import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int a = scanner.nextInt();
        int sum = 0;
        int[] s = new int[n];
        
        for (int i = 0; i < n; i++) {
            s[i] = scanner.nextInt();
        }
        
        Arrays.sort(s);
        
        for (int i = n - 1; i > n - a - 1; i--) {
            sum += s[i];
        }
        
        System.out.println(sum);
        scanner.close();
    }
}

// <END-OF-CODE>
