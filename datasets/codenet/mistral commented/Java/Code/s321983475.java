import java.util.*;

public class Main {
    public static void main(String[] args){
        // Create a new Scanner object to read input from the standard input stream
        Scanner sc = new Scanner(System.in);

        // Read three integers `w`, `a`, and `b` from the user
        int w = sc.nextInt();
        int a = sc.nextInt();
        int b = sc.nextInt();

        // Calculate the difference between the larger and smaller of `a` and `b`, and subtract `w`. This is the answer to the problem
        int answer = Math.max(a, b) - Math.min(a, b) - w;

        // Check if the answer is negative. If it is, we print `0` instead
        if(answer < 0){
            System.out.println(0);
        }else{
            // Otherwise, we print the answer
            System.out.println(answer);
        }

        // Close the Scanner to free up system resources
        sc.close();
    }
}