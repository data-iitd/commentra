import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int l = scanner.nextInt();
        int r = scanner.nextInt();
        int curr = r;
        int s = 0;
        while (curr > 0) {
            s++;
            curr /= 10;
        }
        int first = (int) Math.pow(10, s);
        int second = first / 2;
        int ans = -1;
        for (int i : new int[]{l, r, first, second}) {
            if (i >= l && i <= r) {
                curr = i;
                StringBuilder rev = new StringBuilder();
                String currStr = String.valueOf(curr);
                for (char k : currStr.toCharArray()) {
                    rev.append((char) ('9' - k + '0'));
                }
                int revNum = Integer.parseInt(rev.toString());
                ans = Math.max(ans, revNum * curr);
            }
        }
        System.out.println(ans);
    }
}
