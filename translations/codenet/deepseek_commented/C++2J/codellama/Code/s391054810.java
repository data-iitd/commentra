import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int h = sc.nextInt();
        int w = sc.nextInt();
        int hh = sc.nextInt();
        int ww = sc.nextInt();
        int area = (h-hh) * (w-ww);
        System.out.println(area);
    }
}

