
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] input = sc.nextLine().split(" ");
        int x1 = Integer.parseInt(input[0]);
        int y1 = Integer.parseInt(input[1]);
        int x2 = Integer.parseInt(input[2]);
        int y2 = Integer.parseInt(input[3]);

        if (x2 - x1!= 0) {
            double quotient = (y2 - y1) / (x2 - x1);
            if (quotient == 1 || quotient == -1) {
                System.out.println(x1 + " " + y1 + " " + x2 + " " + y2);
            } else {
                System.out.println("-1");
            }
        } else if (y2 - y1!= 0) {
            int d = (int) Math.sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
            System.out.println(x1 + " " + (y1 + d) + " " + (x2 + d) + " " + y2);
        } else {
            System.out.println("-1");
        }
    }
}

