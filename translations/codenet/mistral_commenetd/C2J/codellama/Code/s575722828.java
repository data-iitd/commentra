
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int S = sc.nextInt();
        System.out.println(S / 3600 + ":" + (S % 3600) / 60 + ":" + S % 60);
    }
}

