
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int a[] = new int[m];
        int b[] = new int[m];
        int cnt = 0;
        int t = 0;
        for(int i = 0;i < m;i++) {
            a[i] = sc.nextInt();
            b[i] = sc.nextInt();
        }
        quicksort(a,b,0,m-1);
        for(int i = 0;i < m;i++) {
            if(t <= a[i]) {
                t = b[i];
                cnt++;
            }
        }
        System.out.println(cnt);
    }

    public static void quicksort(int a[],int b[],int l,int r) {
        int i,j,x,t;
        if(l >= r) return;
        i = l - 1;
        j = r;
        x = b[r];
        while(1) {
            while(b[++i] < x);
            while(i < --j && x < b[j]);
            if(i >= j) break;
            t = a[i]; a[i] = a[j]; a[j] = t;
            t = b[i]; b[i] = b[j]; b[j] = t;
        }
        t = a[i]; a[i] = a[r]; a[r] = t;
        t = b[i]; b[i] = b[r]; b[r] = t;
        quicksort(a,b,l,i-1);
        quicksort(a,b,i+1,r);
    }
}

