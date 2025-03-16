import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] x = new int[n];
        for (int i = 0; i < n; i++) {
            x[i] = sc.nextInt();
        }
        int[] a = new int[n];
        int[] b = new int[n];
        int cnta = 0;
        int cntb = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                a[cnta++] = x[i];
            } else {
                b[cntb++] = x[i];
            }
        }
        int[] cnta1 = new int[100002];
        int[] cntb1 = new int[100002];
        for (int i = 0; i < cnta; i++) {
            cnta1[a[i]]++;
        }
        for (int i = 0; i < cntb; i++) {
            cntb1[b[i]]++;
        }
        int maxCnta = 0;
        int maxCntb = 0;
        int vala = 0;
        int valb = 0;
        for (int i = 0; i < 100002; i++) {
            if (maxCnta < cnta1[i]) {
                maxCnta = cnta1[i];
                vala = i;
            }
            if (maxCntb < cntb1[i]) {
                maxCntb = cntb1[i];
                valb = i;
            }
        }
        if (vala != valb) {
            int res = 0;
            for (int i = 0; i < cnta; i++) {
                if (a[i] != vala) {
                    res++;
                }
            }
            for (int i = 0; i < cntb; i++) {
                if (b[i] != valb) {
                    res++;
                }
            }
            System.out.println(res);
        } else {
            int resa = 0;
            int resb = 0;
            for (int i = 0; i < cnta; i++) {
                if (a[i] != vala) {
                    resa++;
                }
            }
            for (int i = 0; i < cntb; i++) {
                if (b[i] != valb) {
                    resb++;
                }
            }
            System.out.println(Math.min(resa + resb, resa + resb));
        }
    }
}