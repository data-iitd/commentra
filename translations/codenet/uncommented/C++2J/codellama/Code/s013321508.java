
import java.util.Scanner;
import java.util.Arrays;
import java.util.List;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.ListIterator;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();

        int[] L = new int[100000];
        for (int i = 0; i < N; i++) {
            L[i] = sc.nextInt();
        }

        Arrays.sort(L);

        List<Integer> list = new ArrayList<Integer>();
        for (int i = 0; i < N; i++) {
            list.add(L[i]);
        }

        for (int i = 0; i < M; i++) {
            int max_L = Collections.max(list);
            if (max_L == 0) {
                break;
            }

            max_L /= 2;
            ListIterator<Integer> itr = list.listIterator();
            while (itr.hasNext()) {
                if (itr.next() > max_L) {
                    itr.previous();
                    itr.add(max_L);
                    break;
                }
            }
            list.remove(list.size() - 1);
        }

        long ans = 0;
        for (int i = 0; i < list.size(); i++) {
            ans += list.get(i);
        }

        System.out.println(ans);
    }
}

