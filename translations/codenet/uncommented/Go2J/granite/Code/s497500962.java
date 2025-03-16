
import java.util.*;

class s497500962 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int R = sc.nextInt();
        int G = sc.nextInt();
        int B = sc.nextInt();
        int N = sc.nextInt();

        int ans = 0;
        for (int x = 0; x <= N; x++) {
            for (int y = 0; y <= N; y++) {
                int tmp = N - R * x - G * y;
                if (tmp >= 0 && tmp % B == 0) {
                    ans++;
                }
            }
        }

        System.out.println(ans);
    }
}

// Input. ----------

// Util. ----------

// ---------- Util.

// ---------- Input.

// Translate the above Java code to Python and end with comment "