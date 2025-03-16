
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = (b-1)+(a-2);
        int d = a-1;
        int e = c/d;
        System.out.println(e);
    }
}

