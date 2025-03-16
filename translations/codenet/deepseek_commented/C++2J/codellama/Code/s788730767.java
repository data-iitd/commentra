import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int a[] = new int[50];
        int p = sc.nextInt();
        int b = 0, c = 0;

        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
            if (a[i] % 2 == 0) {
                b++;
            } else {
                c++;
            }
        }

        // Calculate the number of subsets with even and odd numbers
        long bsum = (long) Math.pow(2, b);
        long csum = 0;

        if (p == 0) {
            // Sum combinations where the number of elements is even
            for (int i = 0; i <= c; i++) {
                if (i % 2 == 0) {
                    csum += nCr(c, i);
                }
            }
        } else {
            // Sum combinations where the number of elements is odd
            for (int i = 0; i <= c; i++) {
                if (i % 2 == 1) {
                    csum += nCr(c, i);
                }
            }
        }

        // Calculate the final answer as the product of bsum and csum
        long ans = bsum * csum;
        System.out.println(ans);
    }

    // Function to calculate nPr
    public static long nPr(int n, int r) {
        long res = 1;
        for (int i = 0; i < r; i++) {
            res *= (n - i);
        }
        return res;
    }

    // Function to calculate nCr
    public static long nCr(int n, int r) {
        double res = 1;
        for (int i = 0; i < r; i++) {
            res *= (n - i);
            res /= (i + 1);
        }
        return (long) res;
    }
}

