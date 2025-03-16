import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        int pmin = 1000;
        int mmin = 0;
        s = "0" + s;
        for (int i = 0; i < s.length() - 1; i++) {
            int v = Integer.parseInt(s.substring(i, i + 1));
            int npmin = Math.min(pmin + 10 - (v + 1), mmin + 10 - v);
            int nmmin = Math.min(pmin + v + 1, mmin + v);
            pmin = npmin;
            mmin = nmmin;
        }
        System.out.println(Math.min(pmin, mmin));
    }
}
