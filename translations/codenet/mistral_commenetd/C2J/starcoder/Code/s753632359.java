
import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Declare variables N and D of integer type
        // N and D should be positive integers less than or equal to 20
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int D = sc.nextInt();

        // Calculate the quotient of N by (D*2+1) and store it in variable ans
        int ans = N / (D*2+1);

        // Calculate the remainder of N by (D*2+1) and store it in variable rem
        int rem = N % (D*2+1);

        // Check if the remainder is zero or not
        if(rem!= 0){
            // If the remainder is not zero, increment the value of ans by 1
            ans = ans + 1;
        }

        // Print the value of ans using printf function
        System.out.println(ans);
    }
}

