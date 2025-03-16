
import java.util.Scanner;

public class atcoder_ABC111_C{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();  // Read an integer n from input
        int[] x = new int[n];  // Read a list of integers x from input
        for (int i = 0; i < n; i++) {
            x[i] = scanner.nextInt();
        }

        // Split the list x into two lists, a and b, based on their indices (even and odd)
        int[] a = new int[n / 2];
        int[] b = new int[n / 2];
        for (int i = 0; i < n / 2; i++) {
            if (i % 2 == 0) {
                a[i] = x[i];
            } else {
                b[i] = x[i];
            }
        }

        // Initialize two lists to count the frequency of each element in a and b
        int[] cnta = new int[100002 + 1];
        int[] cntb = new int[100002 + 1];

        // Find the most frequent element in list a and its first and second most frequent elements
        int vala = 0;
        int vala1 = 0;
        int maxCnta = 0;
        int maxCnta1 = 0;
        for (int i = 0; i < n / 2; i++) {
            cnta[a[i]] += 1;
        }
        for (int i = 0; i < n / 2; i++) {
            if (maxCnta < cnta[a[i]]) {
                vala = a[i];
                maxCnta = cnta[a[i]];
            }
        }
        for (int i = 0; i < n / 2; i++) {
            if (maxCnta1 < cnta[a[i]] && vala!= a[i]) {
                maxCnta1 = cnta[a[i]];
                vala1 = a[i];
            }
        }

        // Find the most frequent element in list b and its first and second most frequent elements
        int valb = 0;
        int valb1 = 0;
        int maxCntb = 0;
        int maxCntb1 = 0;
        for (int i = 0; i < n / 2; i++) {
            cntb[b[i]] += 1;
        }
        for (int i = 0; i < n / 2; i++) {
            if (maxCntb < cntb[b[i]]) {
                valb = b[i];
                maxCntb = cntb[b[i]];
            }
        }
        for (int i = 0; i < n / 2; i++) {
            if (maxCntb1 < cntb[b[i]] && valb!= b[i]) {
                maxCntb1 = cntb[b[i]];
                valb1 = b[i];
            }
        }

        // Compare the most frequent elements of a and b
        if (valb!= vala) {
            int res = 0;
            for (int i = 0; i < n / 2; i++) {
                if (a[i]!= vala) {
                    res += 1;
                }
            }
            for (int i = 0; i < n / 2; i++) {
                if (b[i]!= valb) {
                    res += 1;
                }
            }
            System.out.println(res);
        } else {
            int resa = 0;
            int resb = 0;
            int resa1 = 0;
            int resb1 = 0;
            for (int i = 0; i < n / 2; i++) {
                if (a[i]!= vala) {
                    resa += 1;
                }
                if (a[i]!= vala1) {
                    resa1 += 1;
                }
            }
            for (int i = 0; i < n / 2; i++) {
                if (b[i]!= valb) {
                    resb += 1;
                }
                if (b[i]!= valb1) {
                    resb1 += 1;
                }
            }
            System.out.println(Math.min(resa + resb1, resa1 + resb));
        }
    }
}

Translate the above Java code to C++ and end with comment "