
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        int a = sc.nextInt();
        System.out.println(comp(x, a));
    }

    // comp takes two integers x and a as input and returns an integer.
    // It returns 0 if x is less than a, otherwise it returns 10.
    public static int comp(int x, int a) {
        if (x < a) { // Check if x is less than a
            return 0;
        }
        return 10; // Return 10 if x is not less than a
    }
}

