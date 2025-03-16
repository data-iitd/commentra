import java.util.*;
public class Hoshino {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        while (n-- > 0) {
            String s = in.nextLine();
            while (s.indexOf("Hoshino") >= 0) {
                s = s.substring(0, s.indexOf("Hoshino")) + "a" + s.substring(s.indexOf("Hoshino") + 6);
            }
            System.out.println(s);
        }
    }
}
