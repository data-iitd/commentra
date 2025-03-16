import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n;
        while(sc.hasNextInt()) {
            n = sc.nextInt();
            int[] maps = new int[n + 1];
            int[] num = new int[n + 1];
            for(int i = 1; i <= n; i++) {
                maps[i] = sc.nextInt();
                num[i] = maps[i];
            }
            Arrays.sort(maps);
            int m = n / 2;
            for(int i = 1; i <= n; i++) {
                if(num[i] <= maps[m])
                    System.out.println(maps[m + 1]);
                else
                    System.out.println(maps[m]);
            }
        }
    }
}
