import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int x = in.nextInt();
        int y = in.nextInt();
        int a = in.nextInt();
        int b = in.nextInt();

        int lcm = x * y / GCD(x, y);

        System.out.println(b / lcm - (a - 1) / lcm);
    }

    public static int GCD(int a, int b) {
        // Calculate the greatest common divisor (GCD) of a and b using the Euclidean algorithm
        while (a % b!= 0) {
            int temp = a;
            a = b;
            b = temp % b;
        }
        return b;
    }
}

