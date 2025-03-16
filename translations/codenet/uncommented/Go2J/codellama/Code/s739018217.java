
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int x = m*1900 + (n-m)*100;
        System.out.println(x * (int)Math.pow(2.0, m));
    }
}

