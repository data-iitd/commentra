
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        String ans = "No";
        if (s.indexOf("C") < s.lastIndexOf("F")) {
            ans = "Yes";
        }
        if (s.indexOf("C") < 0) {
            ans = "No";
        }
        System.out.println(ans);
    }
}

