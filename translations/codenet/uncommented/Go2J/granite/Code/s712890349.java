
import java.util.*;

public class s712890349{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();
        String S = sc.next();
        List<Block> blocks = runLength(S);
        int sum = 0, zero = 0, l = 0;
        int ans = 0;
        for (int r = 0; r < blocks.size(); r++) {
            sum += blocks.get(r).len;
            if (blocks.get(r).value.equals("0")) {
                zero++;
            }
            while (K < zero) {
                sum -= blocks.get(l).len;
                if (blocks.get(l).value.equals("0")) {
                    zero--;
                }
                l++;
            }
            ans = Math.max(ans, sum);
        }
        System.out.println(ans);
    }

    static class Block {
        String value;
        int len;

        public Block(String value, int len) {
            this.value = value;
            this.len = len;
        }
    }

    static List<Block> runLength(String s) {
        List<Block> r = new ArrayList<>();
        if (s.length() == 0) {
            return r;
        }
        Block t = new Block(String.valueOf(s.charAt(0)), 1);
        for (int i = 1; i < s.length(); i++) {
            if (t.value.equals(String.valueOf(s.charAt(i)))) {
                t.len++;
            } else {
                r.add(t);
                t = new Block(String.valueOf(s.charAt(i)), 1);
            }
        }
        r.add(t);
        return r;
    }
}

