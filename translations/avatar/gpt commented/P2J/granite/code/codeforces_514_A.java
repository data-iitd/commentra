
import java.util.Scanner;

public class codeforces_514_A{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String ip = scanner.nextLine();
        String st = "";

        if (ip.length()!= 1) {
            if (ip.charAt(0) == '9') {
                st = "9";
                ip = ip.substring(1);
            }

            for (int i = 0; i < ip.length(); i++) {
                int digit = Character.getNumericValue(ip.charAt(i));
                if (digit > 4) {
                    int complement = 9 - digit;
                    st += complement;
                } else {
                    st += digit;
                }
            }
        } else {
            st = ip;
        }

        System.out.println(Integer.parseInt(st));
    }
}
