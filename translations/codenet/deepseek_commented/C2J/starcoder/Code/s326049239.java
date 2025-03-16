import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a, c, k, b;
        while (sc.hasNextInt()) {
            a = sc.nextInt();
            c = 0;
            k = 0;
            if (a < 3) {
                System.out.println("0");
            } else {
                b = a;
                while (a > 0) {
                    b--;
                    c++;
                    if (c == 3) {
                        k++;
                        c = 0;
                    }
                    a--;
                }
                System.out.println(k);
            }
        }
    }
}
