import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int h = in.nextInt();
        int ans = 0, cnt = 1;
        while (h!= 1) {
            if (h % 2!= 0) h--;
            h /= 2;
            cnt *= 2;
            ans += cnt;
        }
        System.out.println(ans + 1);
    }
}

