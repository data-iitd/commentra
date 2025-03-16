import java.util.Scanner;

public class Main {
    static final int MOD = 1000000007;
    static boolean isTest = false;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        int result = mainFunction(s);
        if (result != -1) {
            System.out.println(result);
        }
        scanner.close();
    }

    static int mainFunction(String s) {
        int pmin = 1000;
        int mmin = 0;
        s = '0' + s; // Prepend '0' to the string
        for (int i = s.length() - 1; i >= 0; i--) {
            int v = Character.getNumericValue(s.charAt(i));
            int npmin = Math.min(pmin + 10 - (v + 1), mmin + 10 - v);
            int nmmin = Math.min(pmin + v + 1, mmin + v);
            pmin = npmin;
            mmin = nmmin;
        }
        return Math.min(pmin, mmin);
    }

    static void pa(int v) {
        if (isTest) {
            System.out.println(v);
        }
    }
}
