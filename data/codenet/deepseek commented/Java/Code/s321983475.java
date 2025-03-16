
import java.util.*;

public class Main {
    public static void main(String[] args){
        // Create a Scanner object to read input from the standard input stream
        Scanner sc = new Scanner(System.in);
        
        // Read three integers from the input
        int w = sc.nextInt();
        int a = sc.nextInt();
        int b = sc.nextInt();
        
        // Calculate the difference between the maximum and minimum of a and b, then subtract the width w
        int answer = Math.max(a,b) - Math.min(a,b) - w;
        
        // If the result is less than 0, print 0; otherwise, print the calculated difference
        if(answer < 0){
            System.out.println(0);
        }else{
            System.out.println(answer);
        }
    }
}
