
import java.util.Scanner;

public class atcoder_ABC111_C{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] x = new int[n];
        for (int i = 0; i < n; i++) {
            x[i] = scanner.nextInt();
        }
        int[] a = new int[n / 2];
        int[] b = new int[n / 2];
        int[] cnta = new int[100002 + 1];
        int[] cntb = new int[100002 + 1];
        int vala = 0;
        int vala1 = 0;
        int maxCnta = 0;
        int maxCnta1 = 0;
        int valb = 0;
        int valb1 = 0;
        int maxCntb = 0;
        int maxCntb1 = 0;
        int res = 0;
        int resa = 0;
        int resb = 0;
        int resa1 = 0;
        int resb1 = 0;

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                a[i / 2] = x[i];
                cnta[x[i]]++;
            } else {
                b[i / 2] = x[i];
                cntb[x[i]]++;
            }
        }

        for (int i = 0; i < n / 2; i++) {
            if (maxCnta < cnta[a[i]]) {
                vala = a[i];
                maxCnta = cnta[a[i]];
            }
            if (maxCnta1 < cnta[a[i]] && vala!= a[i]) {
                maxCnta1 = cnta[a[i]];
                vala1 = a[i];
            }
            if (maxCntb < cntb[b[i]]) {
                valb = b[i];
                maxCntb = cntb[b[i]];
            }
            if (maxCntb1 < cntb[b[i]] && valb!= b[i]) {
                maxCntb1 = cntb[b[i]];
                valb1 = b[i];
            }
        }

        if (valb!= vala) {
            for (int i = 0; i < n / 2; i++) {
                if (a[i]!= vala) {
                    res++;
                }
                if (b[i]!= valb) {
                    res++;
                }
            }
            System.out.println(res);
        } else {
            for (int i = 0; i < n / 2; i++) {
                if (a[i]!= vala) {
                    if (a[i]!= vala1) {
                        resa++;
                    } else {
                        resa1++;
                    }
                }
                if (b[i]!= valb) {
                    if (b[i]!= valb1) {
                        resb++;
                    } else {
                        resb1++;
                    }
                }
            }
            System.out.println(Math.min(resa + resb1, resa1 + resb));
        }
    }
}
