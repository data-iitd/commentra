

import java.util.Scanner;

public class atcoder_ABC143_A{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int A = scanner.nextInt();  // Taking an integer input A
        int B = scanner.nextInt();  // Taking an integer input B
        int ans = A - 2 * B;  // Calculating the value of ans as A minus two times B
        if (ans < 0) {  // Checking if ans is less than 0
            ans = 0;  // Setting ans to 0 if it is less than 0
        }
        System.out.println(ans);  // Printing the value of ans
    }
}
