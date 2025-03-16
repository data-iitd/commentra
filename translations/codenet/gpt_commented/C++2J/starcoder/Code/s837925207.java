import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        int ans = 0;
        ans = x + x*x + x*x*x;
        System.out.println(ans);
    }
}
