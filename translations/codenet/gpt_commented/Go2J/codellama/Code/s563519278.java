
import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] v = new int[N];
        int a;
        for (int i = 1; i < N; i++) {
            a = sc.nextInt();
            v[a - 1]++;
        }
        for (int e : v) {
            System.out.println(e);
        }
    }
}

