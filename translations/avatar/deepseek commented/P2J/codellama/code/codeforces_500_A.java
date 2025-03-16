
import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int t = sc.nextInt();
        int[] s = new int[n];
        for (int i = 0; i < n; i++) {
            s[i] = sc.nextInt();
        }
        int currentCell = 0;
        while (currentCell <= t) {
            currentCell += s[currentCell];
            if (currentCell == t) {
                System.out.println("YES");
                sc.close();
                return;
            }
        }
        System.out.println("NO");
        sc.close();
    }
}

