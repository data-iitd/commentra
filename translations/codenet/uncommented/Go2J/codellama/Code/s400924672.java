
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int r = sc.nextInt();
        int D = sc.nextInt();
        int x = sc.nextInt();

        for (int i = 1; i <= 10; i++) {
            System.out.println(r*x - D);
            x = r*x - D;
        }
    }
}

