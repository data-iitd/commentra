
import java.util.Scanner;

public class s326049239{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNextInt()) {
            int a = sc.nextInt();
            int c = 0, k = 0;
            if (a < 3) {
                System.out.println(0);
            } else {
                int b = a;
                while (a-- > 0) {
                    b--;
                    c++;
                    if (c == 3) {
                        k++;
                        c = 0;
                    }
                }
                System.out.println(k);
            }
        }
    }
}

