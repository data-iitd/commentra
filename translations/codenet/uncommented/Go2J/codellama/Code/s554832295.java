
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x1 = sc.nextInt();
        int y1 = sc.nextInt();
        int x2 = sc.nextInt();
        int y2 = sc.nextInt();

        int a = x2 - x1;
        int b = y2 - y1;

        int x3 = x2 - b;
        int y3 = y2 + a;
        int x4 = x1 - b;
        int y4 = y1 + a;

        System.out.println(x3 + " " + y3 + " " + x4 + " " + y4);
    }
}

