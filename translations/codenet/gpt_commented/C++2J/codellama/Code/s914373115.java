
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Call function B to execute its logic
        B();
    }

    public static void B() {
        Scanner sc = new Scanner(System.in);
        long long x = sc.nextLong();
        int i = 0;
        long long sum = 100;

        while (sum < x) {
            sum += sum / 100;
            i++;
        }

        System.out.println(i);
    }
}

