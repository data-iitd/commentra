import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int x = 1;
        while (Math.log(n) % 1 != 0) {
            x += 1;
            n -= (int) Math.pow(2, (int) Math.log(n));
        }
        System.out.println(x);
    }
}
