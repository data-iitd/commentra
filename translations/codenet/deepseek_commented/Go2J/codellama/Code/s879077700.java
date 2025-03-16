
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String a = sc.nextLine();
        String ans = "Good";
        for (int i = 0; i < 3; i++) {
            if (a.charAt(i) == a.charAt(i+1)) {
                ans = "Bad";
            }
        }
        System.out.println(ans);
    }
}

