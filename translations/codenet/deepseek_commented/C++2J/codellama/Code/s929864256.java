import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long a = sc.nextLong();
        long b = sc.nextLong();
        long max = Math.max(a+b, Math.max(a-b, a*b));
        System.out.println(max);
    }
}

