
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        long x1 = in.nextLong();
        long y1 = in.nextLong();
        long x2 = in.nextLong();
        long y2 = in.nextLong();
        long dx = x2 - x1;
        long dy = y2 - y1;
        long x3 = x2 - dy;
        long y3 = y2 + dx;
        long x4 = x1 - dy;
        long y4 = y1 + dx;
        System.out.println(x3 + " " + y3 + " " + x4 + " " + y4);
    }
}

