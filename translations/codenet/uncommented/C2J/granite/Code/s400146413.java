
import java.util.Scanner;

public class s400146413{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] S = new int[n];
        for (int i = 0; i < n; i++) {
            S[i] = sc.nextInt();
        }
        int q = sc.nextInt();
        int[] T = new int[q];
        for (int j = 0; j < q; j++) {
            T[j] = sc.nextInt();
        }
        int count = 0;
        for (int j = 0; j < q; j++) {
            int key = T[j];
            if (linearsearch(S, n, key) == 0) {
                count++;
            }
        }
        System.out.println(count);
    }

    public static int linearsearch(int[] S, int n, int key) {
        int i = 0;
        int count = 0;
        while (S[i]!= key) {
            i++;
            if (i >= n) {
                count = 1;
                return count;
            }
        }
        return count;
    }
}
