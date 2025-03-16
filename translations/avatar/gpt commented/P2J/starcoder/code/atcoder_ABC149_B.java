import java.util.*;

public class CookieCounter {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int[] cookies = new int[3];
        for (int i = 0; i < 3; i++) {
            cookies[i] = in.nextInt();
        }
        int leftOver = cookies[0] - cookies[2];
        int takahashi = Math.max(0, leftOver);
        System.out.println(takahashi + " " + (cookies[1] < 0? cookies[1] - Math.abs(leftOver) : cookies[1]));
    }
}

