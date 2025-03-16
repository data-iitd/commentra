import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] s = sc.nextLine().split(" ");
        int x1 = Integer.parseInt(s[0]);
        int y1 = Integer.parseInt(s[1]);
        int x2 = Integer.parseInt(s[2]);
        int y2 = Integer.parseInt(s[3]);
        int d = (int)Math.sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
        int x3 = x1+d;
        int y3 = y1+d;
        int x4 = x2+d;
        int y4 = y2+d;
        System.out.println(x3+" "+y3+" "+x4+" "+y4);
    }
}
