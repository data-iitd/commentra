import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int h = in.nextInt();
        int w = in.nextInt();
        int hh = in.nextInt();
        int ww = in.nextInt();
        System.out.println((h-hh) * (w-ww));
    }
}
