import java.util.Scanner;

public class LeastCommonMultiple {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long long A = sc.nextLong();
        long long B = sc.nextLong();
        long long GCD = Euclid(A, B);
        long long LCM = (A * B) / GCD;
        System.out.println(LCM);
    }

    public static long long Euclid(long long x, long long y) {
        long long tmp;

        // Ensure x is the larger number
        if (x < y) {
            tmp = x; // Store the smaller number in tmp
            x = y;   // Assign the larger number to x
            y = tmp; // Assign the smaller number to y
        }

        // If y divides x evenly, y is the GCD
        if (!(x % y)) return y;

        // Recursively call Euclid with y and the remainder of x divided by y
        return Euclid(y, x % y);
    }
}

