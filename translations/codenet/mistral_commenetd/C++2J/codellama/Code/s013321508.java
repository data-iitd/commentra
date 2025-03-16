
import java.util.Scanner;
import java.util.Vector;
import java.util.Collections;
import java.util.Iterator;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();

        Vector<Integer> L = new Vector<Integer>();

        for (int i = 0; i < N; i++) {
            L.add(sc.nextInt());
        }

        Collections.sort(L);

        Iterator<Integer> itr = L.iterator();

        for (int i = 0; i < M; i++) {
            int max_L = L.lastElement();

            if (max_L == 0) {
                break;
            }

            max_L /= 2;

            itr = L.iterator();

            while (itr.hasNext()) {
                if (itr.next() >= max_L) {
                    itr.previous();
                    break;
                }
            }

            L.add(itr.nextIndex(), max_L);
            L.remove(L.size() - 1);
        }

        long ans = 0;

        for (int i = 0; i < L.size(); i++) {
            ans += L.get(i);
        }

        System.out.println(ans);

    }

}

