import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        int a = sc.nextInt();
        System.out.println(comp(x,a));
    }

    public static int comp(int x, int a) {
        if (x < a) {
            return 0;
        }
        return 10;
    }
}
