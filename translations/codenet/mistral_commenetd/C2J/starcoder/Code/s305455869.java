
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        int b = in.nextInt();
        int ans = 0;

        if (a >= 13) {
            ans = b;
        } else if (a >= 6) {
            ans = b/2;
        }

        System.out.println(ans);
    }
}

