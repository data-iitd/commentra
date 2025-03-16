import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String txt = sc.next();
        int cu = 0, cl = 0;

        for (int z = 0; z < txt.length(); z++) {
            if (Character.isLowerCase(txt.charAt(z))) {
                cl++;
            } else {
                cu++;
            }
        }

        String out;
        if (cu > cl) {
            out = txt.toUpperCase();
        } else {
            out = txt.toLowerCase();
        }

        System.out.println(out);
    }
}

