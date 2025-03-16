
import java.util.Scanner;
import java.util.Arrays;

public class codeforces_621_A{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] lst = new int[n];
        for (int i = 0; i < n; i++) {
            lst[i] = sc.nextInt();
        }
        Arrays.sort(lst);
        int od = 0;
        for (int i = 0; i < n; i++) {
            if (lst[i] % 2!= 0) {
                od++;
            }
        }
        int sum = 0;
        boolean ok = false;
        for (int i = 0; i < n; i++) {
            if (lst[i] % 2 == 0) {
                sum += lst[i];
            } else {
                if (ok || od > 1) {
                    sum += lst[i];
                    od--;
                    ok =!ok;
                }
            }
        }
        System.out.println(sum);
    }
}
