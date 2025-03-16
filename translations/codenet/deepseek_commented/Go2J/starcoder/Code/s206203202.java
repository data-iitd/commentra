
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();

        int x = N % K;
        x = Math.min(Math.abs(x - K), x);
        System.out.println(x);
    }
}

