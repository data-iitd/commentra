import java.util.ArrayList;
import java.util.List;
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
        scanner.nextLine(); // Consume newline
        String S = scanner.nextLine();

        List<Block> blocks = runLength(S);
        int ans = 0, sum = 0, zero = 0, l = 0;

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

    private static List<Block> runLength(String s) {
        List<Block> result = new ArrayList<>();
        if (s.length() == 0) {
            return result;
        }

        Block current = new Block(String.valueOf(s.charAt(0)), 1);
        for (int i = 1; i < s.length(); i++) {
            if (current.value.equals(String.valueOf(s.charAt(i)))) {
                current.len++;
            } else {
                result.add(current);
                current = new Block(String.valueOf(s.charAt(i)), 1);
            }
        }
        result.add(current);
        return result;
    }
}

