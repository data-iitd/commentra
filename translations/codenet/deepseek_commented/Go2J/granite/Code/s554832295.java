

import java.util.Scanner;

public class s554832295{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int x1 = scanner.nextInt();
        int y1 = scanner.nextInt();
        int x2 = scanner.nextInt();
        int y2 = scanner.nextInt();
        int a = x2 - x1;
        int b = y2 - y1;
        int x3 = x2 - b;
        int y3 = y2 + a;
        int x4 = x1 - b;
        int y4 = y1 + a;
        System.out.println(x3 + " " + y3 + " " + x4 + " " + y4);
    }
}

