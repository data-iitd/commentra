import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();
        String t = scanner.next();
        s += s;
        System.out.println(s.contains(t) ? "Yes" : "No");
    }
}
// <END-OF-CODE>
