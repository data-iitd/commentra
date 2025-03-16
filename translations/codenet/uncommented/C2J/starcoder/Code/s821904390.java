import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int in = sc.nextInt();
        int h,m,s;
        h = in / 3600;
        in %= 3600;
        m = in / 60;
        in %= 60;
        s = in;
        System.out.printf("%d:%d:%d\n",h,m,s);
    }
}
