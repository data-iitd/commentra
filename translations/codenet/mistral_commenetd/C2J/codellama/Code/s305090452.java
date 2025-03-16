
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int d = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        int[] b = new int[n];
        for (int i = 0; i < n; i++) {
            b[i] = a[i] + (n - 1 - i) * d;
        }
        int[] c = new int[n];
        for (int i = 0; i < n; i++) {
            c[i] = a[i] + i * d;
        }
        int[] d = new int[n];
        for (int i = 0; i < n; i++) {
            d[i] = a[i] + (n - 1 - i) * d + i * d;
        }
        int[] e = new int[n];
        for (int i = 0; i < n; i++) {
            e[i] = a[i] + (n - 1 - i) * d + (n - 1 - i) * d;
        }
        int[] f = new int[n];
        for (int i = 0; i < n; i++) {
            f[i] = a[i] + i * d + i * d;
        }
        int[] g = new int[n];
        for (int i = 0; i < n; i++) {
            g[i] = a[i] + (n - 1 - i) * d + i * d;
        }
        int[] h = new int[n];
        for (int i = 0; i < n; i++) {
            h[i] = a[i] + i * d + (n - 1 - i) * d;
        }
        int[] i = new int[n];
        for (int i = 0; i < n; i++) {
            i[i] = a[i] + i * d + i * d;
        }
        int[] j = new int[n];
        for (int i = 0; i < n; i++) {
            j[i] = a[i] + (n - 1 - i) * d + (n - 1 - i) * d;
        }
        int[] k = new int[n];
        for (int i = 0; i < n; i++) {
            k[i] = a[i] + i * d + (n - 1 - i) * d;
        }
        int[] l = new int[n];
        for (int i = 0; i < n; i++) {
            l[i] = a[i] + (n - 1 - i) * d + i * d;
        }
        int[] m = new int[n];
        for (int i = 0; i < n; i++) {
            m[i] = a[i] + i * d + i * d;
        }
        int[] n = new int[n];
        for (int i = 0; i < n; i++) {
            n[i] = a[i] + (n - 1 - i) * d + i * d;
        }
        int[] o = new int[n];
        for (int i = 0; i < n; i++) {
            o[i] = a[i] + i * d + (n - 1 - i) * d;
        }
        int[] p = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = a[i] + i * d + i * d;
        }
        int[] q = new int[n];
        for (int i = 0; i < n; i++) {
            q[i] = a[i] + (n - 1 - i) * d + (n - 1 - i) * d;
        }
        int[] r = new int[n];
        for (int i = 0; i < n; i++) {
            r[i] = a[i] + i * d + (n - 1 - i) * d;
        }
        int[] s = new int[n];
        for (int i = 0; i < n; i++) {
            s[i] = a[i] + i * d + i * d;
        }
        int[] t = new int[n];
        for (int i = 0; i < n; i++) {
            t[i] = a[i] + (n - 1 - i) * d + (n - 1 - i) * d;
        }
        int[] u = new int[n];
        for (int i = 0; i < n; i++) {
            u[i] = a[i] + i * d + (n - 1 - i) * d;
        }
        int[] v = new int[n];
        for (int i = 0; i < n; i++) {
            v[i] = a[i] + i * d + i * d;
        }
        int[] w = new int[n];
        for (int i = 0; i < n; i++) {
            w[i] = a[i] + (n - 1 - i) * d + (n - 1 - i) * d;
        }
        int[] x = new int[n];
        for (int i = 0; i < n; i++) {
            x[i] = a[i] + i * d + (n - 1 - i) * d;
        }
        int[] y = new int[n];
        for (int i = 0; i < n; i++) {
            y[i] = a[i] + i * d + i * d;
        }
        int[] z = new int[n];
        for (int i = 0; i < n; i++) {
            z[i] = a[i] + (n - 1 - i) * d + (n - 1 - i) * d;
        }
        int[] aa = new int[n];
        for (int i = 0; i < n; i++) {
            aa[i] = a[i] + i * d + (n - 1 - i) * d;
        }
        int[] bb = new int[n];
        for (int i = 0; i < n; i++) {
            bb[i] = a[i] + i * d + i * d;
        }
        int[] cc = new int[n];
        for (int i = 0; i < n; i++) {
            cc[i] = a[i] + (n - 1 - i) * d + (n - 1 - i) * d;
        }
        int[] dd = new int[n];
        for (int i = 0; i < n; i++) {
            dd[i] = a[i] + i * d + (n - 1 - i) * d;
        }
        int[] ee = new int[n];
        for (int i = 0; i < n; i++) {
            ee[i] = a[i] + i * d + i * d;
        }
        int[] ff = new int[n];
        for (int i = 0; i < n; i++) {
            ff[i] = a[i] + (n - 1 - i) * d + (n - 1 - i) * d;
        }
        int[] gg = new int[n];
        for (int i = 0; i < n; i++) {
            gg[i] = a[i] + i * d + (n - 1 - i) * d;
        }
        int[] hh = new int[n];
        for (int i = 0; i < n; i++) {
            hh[i] = a[i] + i * d + i * d;
        }
        int[] ii = new int[n];
        for (int i = 0; i < n; i++) {
            ii[i] = a[i] + (n - 1 - i) * d + (n - 1 - i) * d;
        }
        int[] jj = new int[n];
        for (int i = 0; i < n; i++) {
            jj[i] = a[i] + i * d + (n - 1 - i) * d;
        }
        int[] kk = new int[n];
        for (int i = 0; i < n; i++) {
            kk[i] = a[i] + i * d + i * d;
        }
        int[] ll = new int[n];
        for (int i = 0; i < n; i++) {
            ll[i] = a[i] + (n - 1 - i) * d + (n - 1 - i) * d;
        }
        int[] mm = new int[n];
        for (int i = 0; i < n; i++) {
            mm[i] = a[i] + i * d + (n - 1 - i) * d;
        }
        int[] nn = new int[n];
        for (int i = 0; i < n; i++) {
            nn[i] = a[i] + i * d + i * d;
        }
        int[] oo = new int[n];
        for (int i = 0; i < n; i++) {
            oo[i] = a[i] + (n - 1 - i) * d + (n - 1 - i) * d;
        }
        int[] pp = new int[n];
        for (int i = 0; i < n; i++) {
            pp[i] = a[i] + i * d + (n - 1 - i) * d;
        }
        int[] qq = new int[n];
        for (int i = 0; i < n; i++) {
            qq[i] = a[i] + i * d + i * d;
        }
        int[] rr = new int[n];
        for (int i = 0; i < n; i++) {
            rr[i] = a[i] + (n - 1 - i) * d + (n - 1 - i) * d;
        }
        int[] ss = new int[n];
        for (int i = 0; i < n; i++) {
            ss[i] = a[i] + i * d + (n - 1 - i) * d;
        }
        int[] tt = new int[n];
        for (int i = 0; i < n; i++) {
            tt[i] = a[i] + i * d + i * d;
        }
        int[] uu = new int[n];
        for (int i = 0; i < n; i++) {
            uu[i] = a[i] + (n - 1 - i) * d + (n - 1 - i) * d;
        }
        int[] vv = new int[n];
        for (int i = 0; i < n; i++) {
            vv[i] = a[i] + i * d + (n - 1 - i) * d;
        }
        int[] ww = new int[n];
        for (int i = 0; i < n; i++) {
            ww[i] = a[i] + i * d + i * d;
        }
        int[] xx = new int[n];
        for (int i = 0; i < n; i++) {
            xx[i] = a[i] + (n - 1 - i) * d + (n - 1 - i) * d;
        }
        int[] yy = new int[n];
        for (int i = 0; i < n; i++) {
            yy[i] = a[i] + i * d + i * d;
        }
        int[] zz = new int[n];
        for (int i = 0; i < n; i++) {
            zz[i] = a[i] + (n - 1 - i) * d + (n - 1 - i) * d;
        }
        int[] aa1 = new int[n];
        for (int i = 0; i < n; i++) {
            aa1[i] = a[i] + i * d + (n - 1 - i) * d;
        }
        int[] bb1 = new int[n];
        for (int i = 0; i < n; i++) {
            bb1[i] = a[i] + i * d + i * d;
        }
        int[] cc1 = new int[n];
        for (int i = 0; i < n; i++) {
            cc1[i] = a[i] + (n - 1 - i) * d + (n - 1 - i) * d;
        }
        int[] dd1 = new int[n];
        for (int i = 0; i < n; i++) {
            dd1[i] = a[i] + i * d + (n - 1 - i) * d;
        }
        int[] ee1 = new int[n];
        for (int i = 0; i < n; i++) {
            ee1[i] = a[i] + i * d + i * d;
        }
        int[] ff1 = new int[n];
        for (int i = 0; i < n; i++) {
            ff1[i] = a[i] + (n - 1 - i) * d + (n - 1 - i) * d;
        }
        int[] gg1 = new int[n];
        for (int i = 0; i < n; i++) {
            gg1[i] = a[i] + i * d + (n - 1 - i) * d;
        }
        int[] hh1 = new int[n];
        for (int i = 0; i < n; i++) {
            hh1[i] = a[i] + i * d + i * d;
        }
        int[] ii1 = new int[n];
        for (int i = 0; i < n; i++) {
            ii1[i] = a[i] + (n - 1 - i) * d + (n - 1 - i) * d;
        }
        int[] jj1 = new int[n];
        for (int i = 0; i < n; i++) {
            jj1[i] = a[i] + i * d + (n - 1 - i) * d;
        }
        int[] kk1 = new int[n];
        for (int i = 0; i < n; i++) {
            kk1[i] = a[i] + i * d + i * d;
       