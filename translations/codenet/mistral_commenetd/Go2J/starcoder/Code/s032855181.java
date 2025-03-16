import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        int y = sc.nextInt();

        if (x == 2 || y == 2) {
            System.out.println("No");
            return;
        }

        String xg = group(x);
        String yg = group(y);

        if (xg.equals(yg)) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }

    public static String group(int n) {
        if (n == 4 || n == 6 || n == 9 || n == 11) {
            return "B";
        } else {
            return "A";
        }
    }
}

