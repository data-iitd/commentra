import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        B();
    }

    public static void B() {
        Scanner scanner = new Scanner(System.in);
        long x, sum;
        x = scanner.nextLong();
        int i;
        sum = 100;
        for (i = 0; sum < x; ++i) {
            sum += sum / 100;
        }
        System.out.println(i);
        scanner.close();
    }
}

// <END-OF-CODE>
