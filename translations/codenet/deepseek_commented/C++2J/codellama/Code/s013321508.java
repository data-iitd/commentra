
import java.util.Scanner;
import java.util.Vector;
import java.util.Collections;
import java.util.Iterator;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();

        Vector<Integer> L = new Vector<Integer>(100000);
        int l;
        for (int i = 0; i < N; i++) {
            l = sc.nextInt();
            L.add(l);
        }

        Collections.sort(L);

        Iterator<Integer> itr;

        for (int i = 0; i < M; i++) {
            int max_L = L.lastElement();
            if (max_L == 0) {
                break;
            }

            max_L /= 2;
            itr = Collections.binarySearch(L, max_L);
            L.add(itr, max_L);
            L.remove(L.lastElement());
        }

        long ans = 0;
        for (int i = 0; i < L.size(); i++) {
            ans += L.get(i);
        }

        System.out.println(ans);

    }

}

