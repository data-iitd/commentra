import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int h = sc.nextInt();
        int a = sc.nextInt();
        int sho = h / a;
        int am = h % a;
        if (am!= 0) {
            sho += 1;
        }
        System.out.println(sho);
    }
}
