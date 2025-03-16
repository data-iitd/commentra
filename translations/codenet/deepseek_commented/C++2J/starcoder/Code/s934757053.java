
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int A = in.nextInt();
        int B = in.nextInt();
        int ans = 0;
        int out = 1; // Initialize out to 1

        while(out<B){ // Continue the loop as long as out is less than B
            out--; // Decrement out by 1
            out += A; // Increment out by A
            ans++; // Increment ans by 1
        }
        System.out.println(ans); // Print the value of ans to the standard output
    }
}

