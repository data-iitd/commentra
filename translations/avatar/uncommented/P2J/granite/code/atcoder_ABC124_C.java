
import java.util.*;
class atcoder_ABC124_C {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int[] even = new int[2];
        int[] odd = new int[2];
        for (int i = 0; i < s.length(); i++) {
            if (i % 2 == 0) {
                even[s.charAt(i) - '0']++;
            } else {
                odd[s.charAt(i) - '0']++;
            }
        }
        System.out.println(Math.min(s.length() - (even[0] + odd[1]), s.length() - (even[1] + odd[0])));
    }
}

Translate the above Python code to C++ and end with comment "