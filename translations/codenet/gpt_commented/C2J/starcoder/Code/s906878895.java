import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int x = a + b;
            int w = 0;
            while (x > 0) {
                w++;
                x /= 10;
            }
            System.out.println(w);
        }
    }
}
