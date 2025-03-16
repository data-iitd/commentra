
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int x = 1;
        while (true) {
            if (Math.log(n) / Math.log(2) % 1 == 0) {
                break;
            }
            x++;
            n -= (int) Math.pow(2, Math.log(n) / Math.log(2));
        }
        System.out.println(x);
    }
}

