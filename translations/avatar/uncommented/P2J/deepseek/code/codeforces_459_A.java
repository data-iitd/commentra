import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        String[] parts = input.split(" ");
        int[] l1 = new int[4];
        for (int i = 0; i < 4; i++) {
            l1[i] = Integer.parseInt(parts[i]);
        }
        int x1 = l1[0];
        int y1 = l1[1];
        int x2 = l1[2];
        int y2 = l1[3];
        int denominator = x2 - x1;
        int numerator = y2 - y1;
        if (denominator != 0) {
            double quotient = (double) numerator / denominator;
            if (quotient == 1) {
                int x4 = x2;
                int x3 = x1;
                int y4 = y1;
                int y3 = y2;
                System.out.println(x3 + " " + y3 + " " + x4 + " " + y4);
            } else if (quotient == -1) {
                int x4 = x1;
                int x3 = x2;
                int y4 = y2;
                int y3 = y1;
                System.out.println(x3 + " " + y3 + " " + x4 + " " + y4);
            }
        } else {
            int d = (int) Math.sqrt(Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2));
            int x4 = x1;
            int x3 = x2;
            int y3 = y2 + d;
            int y4 = y1 + d;
            System.out.println(x3 + " " + y3 + " " + x4 + " " + y4);
        }
        if (numerator == 0) {
            int d = (int) Math.sqrt(Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2));
            int x4 = x1;
            int x3 = x2;
            int y3 = y2 + d;
            int y4 = y1 + d;
            System.out.println(x3 + " " + y3 + " " + x4 + " " + y4);
        } else if (denominator == 0) {
            int d = (int) Math.sqrt(Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2));
            int x4 = x1 + d;
            int x3 = x2 + d;
            int y3 = y2;
            int y4 = y1;
            System.out.println(x3 + " " + y3 + " " + x4 + " " + y4);
        } else if (quotient == 1) {
            int x4 = x2;
            int x3 = x1;
            int y4 = y1;
            int y3 = y2;
            System.out.println(x3 + " " + y3 + " " + x4 + " " + y4);
        } else if (quotient == -1) {
            int x4 = x1;
            int x3 = x2;
            int y4 = y2;
            int y3 = y1;
            System.out.println(x3 + " " + y3 + " " + x4 + " " + y4);
        } else {
            System.out.println("-1");
        }
    }
}
