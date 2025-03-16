
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int m1, d1, m2, d2;

        m1 = sc.nextInt();
        d1 = sc.nextInt();
        m2 = sc.nextInt();
        d2 = sc.nextInt();

        if (m1!= m2) {
            System.out.println("1");
        } else {
            System.out.println("0");
        }
    }
}

