import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        StringBuilder s = new StringBuilder();

        // If `n` is 0, it immediately outputs '0' and terminates. Otherwise, it proceeds to convert the integer `n` to a base -2 representation.
        if (n == 0) {
            System.out.println("0");
            return;
        }

        while (n != 0) {
            if (n % 2 == 0) {
                s.append('0');
            } else {
                s.append('1');
            }

            n -= Math.abs(n % 2);
            n /= -2;
        }

        s.reverse();
        System.out.println(s.toString());

        /*
        Inside the `main` function, a StringBuilder `s` is initialized as an empty string. The function then enters a loop that continues until `n` becomes 0. Inside the loop, it checks if `n` is even or odd. If `n` is even, it appends '0' to the StringBuilder `s`; if `n` is odd, it appends '1' to the StringBuilder `s`. The function then adjusts `n` by subtracting its remainder when divided by 2 (which is 0 for even numbers and 1 for odd numbers) and dividing `n` by -2.

        After the loop, the StringBuilder `s` is reversed to correct the order of the digits in the base -2 representation. Finally, the function outputs the resulting string.
        */
    }
}

//<END-OF-CODE>
