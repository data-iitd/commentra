import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int a, b, c, d;
        a = in.nextInt();
        b = in.nextInt();
        c = a * b;
        d = 2 * a + 2 * b;
        System.out.println(c + " " + d);
    }
}
