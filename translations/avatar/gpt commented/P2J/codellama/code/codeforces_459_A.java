
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] input = sc.nextLine().split(" ");
        int x1 = Integer.parseInt(input[0]);
        int y1 = Integer.parseInt(input[1]);
        int x2 = Integer.parseInt(input[2]);
        int y2 = Integer.parseInt(input[3]);
        int denominator = x2 - x1;
        int numerator = y2 - y1;
        if (denominator != 0) {
            double quotient = (double) numerator / denominator;
            if (quotient == 1) {
                int d = (int) Math.sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
                int x3 = x1;
                int y3 = y1 + d;
                int x4 = x2;
                int y4 = y2 + d;
                System.out.println(x3 + " " + y3 + " " + x4 + " " + y4);
            } else if (quotient == -1) {
                int d = (int) Math.sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
                int x3 = x2;
                int y3 = y2 + d;
                int x4 = x1;
                int y4 = y1 + d;
                System.out.println(x3 + " " + y3 + " " + x4 + " " + y4);
            } else {
                System.out.println("-1");
            }
        } else if (numerator == 0) {
            int d = (int) Math.sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
            int x3 = x1;
            int y3 = y1 + d;
            int x4 = x2;
            int y4 = y2 + d;
            System.out.println(x3 + " " + y3 + " " + x4 + " " + y4);
        } else {
            System.out.println("-1");
        }
    }
}

