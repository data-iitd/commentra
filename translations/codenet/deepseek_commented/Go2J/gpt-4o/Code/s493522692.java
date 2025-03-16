import java.util.Scanner;

public class Main {
    // Utility Functions

    // Returns the maximum of two integers
    public static int maxInt(int a, int b) {
        return Math.max(a, b);
    }

    // Returns the minimum of two integers
    public static int minInt(int a, int b) {
        return Math.min(a, b);
    }

    // Main Function
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // 'S'がN個、'c'がM個
        int N = sc.nextInt();
        int M = sc.nextInt();
        
        int tmp = minInt(N, M / 2);
        int ans = 0;
        ans += tmp;
        N -= tmp;
        M -= tmp * 2;

        System.out.println(ans + M / 4);
        sc.close();
    }
}
// <END-OF-CODE>
