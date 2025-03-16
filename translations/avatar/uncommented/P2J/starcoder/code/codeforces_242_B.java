import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] l = new int[n];
        int[] r = new int[n];
        for (int i = 0; i < n; i++) {
            l[i] = sc.nextInt();
            r[i] = sc.nextInt();
        }
        int id = 0;
        int minl = l[0], maxr = r[0];
        for (int i = 1; i < n; i++) {
            if (l[i] <= minl && maxr <= r[i]) id = i;
            else if (l[i] < minl || maxr < r[i]) id = n;
            minl = Math.min(minl, l[i]);
            maxr = Math.max(maxr, r[i]);
        }
        System.out.println(id == n? -1 : id + 1);
    }
}
