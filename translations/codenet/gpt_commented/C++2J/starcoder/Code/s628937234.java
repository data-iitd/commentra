import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String t = s.substring(0, 1);
        t += s.length() - 2 + "";
        t += s.substring(s.length() - 1, s.length());
        System.out.println(t);
    }
}

