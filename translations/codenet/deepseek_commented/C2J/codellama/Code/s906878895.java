import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a, b, x, w;
        while (sc.hasNextInt()) {
            a = sc.nextInt();
            b = sc.nextInt();
            x = a + b;
            w = 0;
            while (x > 0) {
                w++;
                x /= 10;
            }
            System.out.println(w);
        }
    }
}
