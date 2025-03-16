
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int day = sc.nextInt();

        switch (day) {
            case 25:
                System.out.println("Christmas");
                break;
            case 24:
                System.out.println("Christmas Eve");
                break;
            case 23:
                System.out.println("Christmas Eve Eve");
                break;
            case 22:
                System.out.println("Christmas Eve Eve Eve");
                break;
        }
    }
}

