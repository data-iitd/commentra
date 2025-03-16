
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int S = sc.nextInt();

        if (S < 60) {
            System.out.println("0:0:" + S);
        } else if (S < 3600) {
            System.out.println("0:" + S / 60 + ":" + S % 60);
        } else {
            System.out.println(S / 3600 + ":" + (S % 3600) / 60 + ":" + (S % 60) % 60);
        }
    }
}

