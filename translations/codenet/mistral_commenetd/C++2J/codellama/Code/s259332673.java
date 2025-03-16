
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int h1, h2, m1, m2, k;

        System.out.print("Enter hours and minutes for the first time: ");
        h1 = sc.nextInt();
        m1 = sc.nextInt();

        System.out.print("Enter hours and minutes for the second time: ");
        h2 = sc.nextInt();
        m2 = sc.nextInt();

        int ans = h2 * 60 + m2;
        System.out.println("The total minutes of the second time are: " + ans);

        ans -= (h1 * 60 + m1);
        System.out.println("The difference in minutes is: " + ans);

        ans -= k;
        System.out.println("The difference in minutes after subtracting " + k + " is: " + ans);

        int hours = ans / 60;
        int minutes = ans % 60;

        System.out.println(hours + " hours and " + minutes + " minutes");

        sc.close();
    }
}

