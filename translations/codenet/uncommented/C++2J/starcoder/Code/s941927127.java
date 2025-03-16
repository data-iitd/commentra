
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String W = in.next();
        in.close();

        char[] w = W.toCharArray();
        Arrays.sort(w);

        for (int i = 0; i < w.length; i+=2) {
            if (w[i]!= w[i+1]) {
                System.out.println("No");
                return;
            }
        }
        System.out.println("Yes");
    }
}

