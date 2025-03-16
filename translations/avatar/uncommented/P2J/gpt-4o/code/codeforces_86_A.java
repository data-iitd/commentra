import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int l = scanner.nextInt();
        int r = scanner.nextInt();
        int curr = r;
        int s = 0;

        while (curr != 0) {
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
                for (char k : String.valueOf(curr).toCharArray()) {
                    rev.append(9 - Character.getNumericValue(k));
                }
                ans = Math.max(ans, Integer.parseInt(rev.toString()) * curr);
            }
        }
        System.out.println(ans);
    }
}
//<END-OF-CODE>
