import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();
        String t = s.substring(0, 1) + (s.length() - 2) + s.substring(s.length() - 1);
        System.out.println(t);
    }
}

