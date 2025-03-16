import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static List<Integer> getNums(int num, int t) {
        List<Integer> result = new ArrayList<>();
        int quotient = t / num;
        int remainder = t % num;

        for (int i = 0; i < num; i++) {
            if (i < remainder) {
                result.add(quotient + 1);
            } else {
                result.add(quotient);
            }
        }
        return result;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        int l = scanner.nextInt();
        int r = scanner.nextInt();
        int sa = scanner.nextInt();
        int sk = scanner.nextInt();

        List<Integer> ans = new ArrayList<>();
        ans.addAll(getNums(k, sk));
        ans.addAll(getNums(n - k, sa - sk));

        for (int i = 0; i < ans.size(); i++) {
            System.out.print(ans.get(i));
            if (i < ans.size() - 1) {
                System.out.print(" ");
            }
        }
        System.out.println();
    }
}
// <END-OF-CODE>
