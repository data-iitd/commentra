import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String str = in.next();
        int max = 0, cnt = 0;
        for (char sc : str.toCharArray()) {
            if (sc == 'A' || sc == 'C' || sc == 'G' || sc == 'T') {
                cnt++;
            } else {
                cnt = 0;
            }
            max = max < cnt? cnt : max;
        }
        System.out.println(max);
    }
}
