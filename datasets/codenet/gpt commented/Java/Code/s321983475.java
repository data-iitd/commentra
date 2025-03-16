import java.util.*;

public class Main {
    public static void main(String[] args){
        // Create a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in);
        
        // Read the width (w) from the input
        int w = sc.nextInt();
        
        // Read the first position (a) from the input
        int a = sc.nextInt();
        
        // Read the second position (b) from the input
        int b = sc.nextInt();
        
        // Calculate the difference between the maximum and minimum of a and b, then subtract w
        int answer = Math.max(a,b) - Math.min(a,b) - w;
        
        // Check if the calculated answer is less than 0
        if(answer < 0){
            // If the answer is negative, print 0
            System.out.println(0);
        } else {
            // If the answer is non-negative, print the answer
            System.out.println(answer);
        }
    }
}
