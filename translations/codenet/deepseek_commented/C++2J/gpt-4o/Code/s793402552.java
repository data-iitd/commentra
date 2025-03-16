import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        /*
        This section of the code reads two integers, a and b, from the standard input.
        */
        int a = scanner.nextInt();
        int b = scanner.nextInt();

        /*
        This section converts the integer b to a string to determine its length.
        */
        String bstr = Integer.toString(b);

        /*
        This section calculates a new number, num, by multiplying a with 10 raised to the power of the length of b (in string form), and then adding b to it.
        */
        long num = a * Math.pow(10, bstr.length()) + b;

        int i;
        for (i = 1; i <= 100100; i++) {
            if (i * i == num) break;
        }

        /*
        This section checks if the loop has finished due to finding a perfect square root of num. If not, it prints "No". Otherwise, it prints "Yes".
        */
        if (i > 100100) {
            System.out.println("No");
        } else {
            System.out.println("Yes");
        }

        scanner.close();
    }
}

/* <END-OF-CODE> */
