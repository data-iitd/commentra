
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        String myStr = "";
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '0' || s.charAt(i) == '1') {
                myStr += s.charAt(i);
            } else if (s.charAt(i) == 'B' && myStr.length() != 0) {
                myStr = myStr.substring(0, myStr.length() - 1);
            }
        }
        System.out.println(myStr);
    }
}

