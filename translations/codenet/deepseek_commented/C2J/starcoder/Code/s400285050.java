import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        int y = sc.nextInt();
        int z;
        if (x >= y)
            z = you(x, y);
        else
            z = you(y, x);
        System.out.println(z);
    }

    public static int you(int x, int y) {
        int z;
        while (true) {
            z = x % y;
            x = y;
            y = z;
            if (y <= 0)
                break;
        }
        return x;
    }
}

