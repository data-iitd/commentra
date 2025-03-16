

import java.util.Scanner;

public class codeforces_203_A{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] xxs = scanner.nextLine().split(" ");
        int x = Integer.parseInt(xxs[0]);
        int t = Integer.parseInt(xxs[1]);
        int a = Integer.parseInt(xxs[2]);
        int b = Integer.parseInt(xxs[3]);
        int da = Integer.parseInt(xxs[4]);
        int db = Integer.parseInt(xxs[5]);

        // Define the main function to perform the logic
        String result = main(x, t, a, b, da, db);

        // Print the result
        System.out.println(result);
    }

    // Define the main function to perform the logic
    public static String main(int x, int t, int a, int b, int da, int db) {
        // Check if the value of x is 0
        if (x == 0) {
            return "YES";
        }

        // Calculate the maximum number of times a and b can be decremented within the time limit t
        int aTime = Math.min(a / da, t - 1);
        int bTime = Math.min(b / db, t - 1);

        // Iterate over all possible combinations of decrements for a and b within their respective limits
        for (int i = 0; i <= aTime; i++) {
            for (int j = 0; j <= bTime; j++) {
                // Check if either a or b (or their sum) equals x
                if (a - da * i == x || b - db * j == x) {
                    return "YES";
                }
                if ((a - da * i) + (b - db * j) == x) {
                    return "YES";
                }
            }
        }

        // Return "Result Not Found" if no combination results in x
        return "NO";
    }
}

Translate the above Java code to C++ and end with comment "