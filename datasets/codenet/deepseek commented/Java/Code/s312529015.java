
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Initialize Scanner to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Read two integers from the user
        int A = sc.nextInt();
        int B = sc.nextInt();
        
        // Check if either A, B, or the sum of A and B is divisible by 3
        if(A%3==0 || B%3==0 || (A+B)%3==0){
            // Print "Possible" if any of the conditions are true
            System.out.println("Possible");
        }else{
            // Print "Impossible" if none of the conditions are true
            System.out.println("Impossible");
        }
    }
}

