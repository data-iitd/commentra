import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String s = in.next();
        String t = in.next();
        s += s;
        System.out.println(s.indexOf(t) + 1);
    }
}
