
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] s = sc.nextLine().split(".");
        String[] p = s[1].split("");
        int i = Integer.parseInt(p[0]);
        if (s[0].charAt(s[0].length() - 1) == '9') {
            System.out.println("GOTO Vasilisa.");
        } else if (s[0].charAt(s[0].length() - 1) != '9' && i < 5) {
            System.out.println(s[0]);
        } else {
            System.out.println(Integer.toString(Integer.parseInt(s[0]) + 1));
        }
    }
}

