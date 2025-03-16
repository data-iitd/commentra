import java.util.Scanner;
import java.util.ArrayList;
import java.util.HashMap;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        int K = in.nextInt();
        ArrayList<Integer> L = new ArrayList<Integer>();
        L.add(-1);
        for (int i = 0; i < N; i++) {
            L.add(in.nextInt());
        }
        ArrayList<Integer> path = new ArrayList<Integer>();
        path.add(1);
        int ind = 0;
        int count = 0;
        int x = 1;
        int t = -1;
        boolean flag = false;
        HashMap<Integer, Integer> Hash = new HashMap<Integer, Integer>();
        for (int i = 0; i < N + 1; i++) {
            int ne = L.get(x);
            if (Hash.containsKey(ne)) {
                flag = true;
                t = Hash.get(ne);
                break;
            }
            path.add(ne);
            ind += 1;
            Hash.put(ne, ind);
            x = ne;
        }
        if (flag == true) {
            ArrayList<Integer> loop = new ArrayList<Integer>();
            loop = path.subList(t, path.size());
            if (K < path.size()) {
                System.out.println(path.get(K));
            } else {
                K = K - path.size();
                K = K % loop.size();
                System.out.println(loop.get(K));
            }
        } else {
            System.out.println(path.get(K - 1));
        }
    }
}

