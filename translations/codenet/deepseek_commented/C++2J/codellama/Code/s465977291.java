import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int d = sc.nextInt();
        double a = d * 2 + 1;
        System.out.println((int) Math.ceil(n / a));
    }
}
