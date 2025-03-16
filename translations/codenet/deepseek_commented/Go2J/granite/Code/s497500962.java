

import java.util.*;

public class s497500962{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int R = sc.nextInt();
        int G = sc.nextInt();
        int B = sc.nextInt();
        int N = sc.nextInt();

        int ans = 0;
        // Iterate over all possible values of x and y
        for (int x = 0; x <= N; x++) {
            for (int y = 0; y <= N; y++) {
                // Calculate the remaining value after subtracting x*R and y*G
                int tmp = N - R*x - G*y;
                // Check if the remaining value is non-negative and a multiple of B
                if (tmp >= 0 && tmp % B == 0) {
                    ans++;
                }
            }
        }

        System.out.println(ans);
    }
}

// Input. ----------

import java.util.*;

public class s497500962{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int R = sc.nextInt();
        int G = sc.nextInt();
        int B = sc.nextInt();
        int N = sc.nextInt();

        int ans = 0;
        // Iterate over all possible values of x and y
        for (int x = 0; x <= N; x++) {
            for (int y = 0; y <= N; y++) {
                // Calculate the remaining value after subtracting x*R and y*G
                int tmp = N - R*x - G*y;
                // Check if the remaining value is non-negative and a multiple of B
                if (tmp >= 0 && tmp % B == 0) {
                    ans++;
                }
            }
        }

        System.out.println(ans);
    }
}

// ---------- Input.

// Util. ----------

import java.util.*;

public class s497500962{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int R = sc.nextInt();
        int G = sc.nextInt();
        int B = sc.nextInt();
        int N = sc.nextInt();

        int ans = 0;
        // Iterate over all possible values of x and y
        for (int x = 0; x <= N; x++) {
            for (int y = 0; y <= N; y++) {
                // Calculate the remaining value after subtracting x*R and y*G
                int tmp = N - R*x - G*y;
                // Check if the remaining value is non-negative and a multiple of B
                if (tmp >= 0 && tmp % B == 0) {
                    ans++;
                }
            }
        }

        System.out.println(ans);
    }
}

// ---------- Util.