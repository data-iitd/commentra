import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] l = sc.nextLine().split(" ");
        int x = Integer.parseInt(l[0]);
        int y = Integer.parseInt(l[1]);
        int a = Integer.parseInt(l[2]);
        int b = Integer.parseInt(l[3]);
        int lcm = lcm(x, y);
        System.out.println(b / lcm - (a - 1) / lcm);
    }
    public static int lcm(int a, int b) {
        while (a % b != 0) {
            a = b;
            b = a % b;
        }
        return b;
    }
}
