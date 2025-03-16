
import java.util.*;

public class s963048401{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] as = new int[n];
        for (int i = 0; i < n; i++) {
            as[i] = sc.nextInt();
        }
        Arrays.sort(as);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0 || as[i] > as[i - 1]) {
                count++;
            }
        }
        System.out.println(count);
    }
}

// END-OF-CODE