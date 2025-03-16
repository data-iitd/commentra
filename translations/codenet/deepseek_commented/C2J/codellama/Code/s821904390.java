
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int in = sc.nextInt();
        int h = in / 3600;
        in %= 3600;
        int m = in / 60;
        in %= 60;
        int s = in;
        System.out.println(h + ":" + m + ":" + s);
    }
}

