import java.util.Scanner;

class Block {
    String value;
    int len;

    Block(String value, int len) {
        this.value = value;
        this.len = len;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        String S = scanner.next();
        
        Block[] blocks = runLength(S);
        int sum = 0, zero = 0, l = 0, ans = 0;

        for (int r = 0; r < blocks.length; r++) {
            sum += blocks[r].len;
            if (blocks[r].value.equals("0")) {
                zero++;
            }
            while (zero > K) {
                sum -= blocks[l].len;
                if (blocks[l].value.equals("0")) {
                    zero--;
                }
                l++;
            }
            ans = Math.max(ans, sum);
        }
        System.out.println(ans);
    }

    public static Block[] runLength(String s) {
        if (s.length() == 0) {
            return new Block[0];
        }
        java.util.List<Block> r = new java.util.ArrayList<>();
        Block t = new Block(String.valueOf(s.charAt(0)), 1);
        
        for (int i = 1; i < s.length(); i++) {
            char v = s.charAt(i);
            if (t.value.equals(String.valueOf(v))) {
                t.len++;
            } else {
                r.add(t);
                t = new Block(String.valueOf(v), 1);
            }
        }
        r.add(t);
        return r.toArray(new Block[0]);
    }
}
