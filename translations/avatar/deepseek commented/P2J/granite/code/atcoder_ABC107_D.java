
import java.io.*;
import java.util.*;

class BIT {
    int size;
    int[] tree;
    int depth;

    BIT(int N) {
        size = N;
        tree = new int[N + 1];
        depth = N.bitLength();
    }

    int _bitsum(int i) {
        int ret = 0;
        while (i > 0) {
            ret += tree[i];
            i ^= i & -i;
        }
        return ret;
    }

    int bitsum(int l, int r) {
        if (r == null) {
            return _bitsum(l);
        } else {
            return _bitsum(r) - _bitsum(l);
        }
    }

    void bitadd(int i, int x) {
        i++;
        while (i <= size) {
            tree[i] += x;
            i += i & -i;
        }
    }
}

public class atcoder_ABC107_D{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int m = n * (n + 1) / 4;
        String[] line = br.readLine().split(" ");
        int[] a = new int[n];
        Map<Integer, Integer> d = new HashMap<>();
        List<Integer> _a = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(line[i]);
            _a.add(a[i]);
        }
        Collections.sort(_a);
        for (int i = 0; i < _a.size(); i++) {
            d.put(_a.get(i), i);
        }
        for (int i = 0; i < n; i++) {
            a[i] = d.get(a[i]);
        }

        int[] b = new int[n + 1];
        for (int i = 0; i < n; i++) {
            b[i + 1] = (a[i] >= m)? 2 : 1;
        }
        for (int i = 1; i <= n; i++) {
            b[i] += b[i - 1];
        }
        int c = Arrays.stream(b).min().getAsInt();
        for (int i = 0; i <= n; i++) {
            b[i] -= c;
        }

        BIT bit = new BIT(n + 1);
        long ans = 0;
        for (int i = 0; i <= n; i++) {
            ans += bit.bitsum(b[i] + 1);
            bit.bitadd(b[i], 1);
        }
        int l = 0, r = _a.size();
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (bit.bitsum(mid) >= m) {
                r = mid;
            } else {
                l = mid;
            }
        }
        System.out.println(_a.get(r - 1));
    }
}

Translate the above Java code to C++ and end with comment "