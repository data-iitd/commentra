
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int r = sc.nextInt();
        int D = sc.nextInt();
        int x = sc.nextInt();

        for (int i = 2; i < 12; i++) {
            System.out.println(Math.round((Math.pow(r, i - 1)) * (x + D / (1 - r)) - D / (1 - r)));
        }
    }
}

