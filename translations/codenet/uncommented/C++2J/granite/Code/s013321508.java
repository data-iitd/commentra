
import java.util.*;
import java.io.*;

class s013321508 {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();

        List<Integer> L = new ArrayList<Integer>();
        int l;
        for (int i = 0; i < N; i++) {
            l = sc.nextInt();
            L.add(l);
        }

        Collections.sort(L);

        ListIterator<Integer> itr;
        
        for (int i = 0; i < M; i++) {
            int max_L = L.get(L.size() - 1);
            if (max_L == 0) {
                break;
            }

            max_L /= 2;
            itr = Collections.binarySearch(L, max_L);
            L.add(itr, max_L);
            L.remove(L.size() - 1);
        }

        long ans = 0;
        for (int i = 0; i < L.size(); i++) {
            ans += L.get(i);
        }

        System.out.println(ans);

    }

}
