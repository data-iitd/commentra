
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] l = sc.nextLine().split("\\.");
        String s = new String(l[0].toCharArray());
        String p = new String(l[1].toCharArray());
        int i = Integer.parseInt(p.charAt(0) + "");
        if (s.charAt(s.length() - 1) == '9') {
            System.out.println("GOTO Vasilisa.");
        } else if (s.charAt(s.length() - 1)!= '9' && i < 5) {
            System.out.println(s);
        } else {
            s = s + "";
            s = Integer.toString(Integer.parseInt(s) + 1);
            System.out.println(s);
        }
    }
}

