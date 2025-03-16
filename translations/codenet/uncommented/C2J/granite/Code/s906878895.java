
import java.util.Scanner;

public class s906878895{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNextInt()) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int x = a + b;
            int w = 0;
            while (x!= 0) {
                w++;
                x /= 10;
            }
            System.out.println(w);
        }
    }
}
// END-OF-CODE