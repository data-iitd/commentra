
import java.util.*;

public class Main {

    public static void main(String[] args) {
        // Declare variables
        int N;                  // Number of elements in the array
        int i;                 // Loop counter
        long sum = 0;      // Sum of all elements in the array
        long wa = 0;       // Sum of all indices from 1 to N
        int[] A = new int[N];              // Array to store input elements
        int[] sa = new int[N];       // Array to store differences between adjacent elements
        int ans;               // Answer flag
        int shou;              // Quotient of sum and wa

        // Read input
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        // Read N integers into the array A
        for( i = 0; i < N; i++ ){
            A[i] = sc.nextInt();
            // Add current element to sum
            sum += A[i];
            // Add current index to wa
            wa += i+1;
        }

        // Check if sum is divisible by wa
        if( sum % wa ) ans = 0;
        else{
            // Calculate quotient of sum and wa
            shou = sum/wa;
            // Calculate differences between adjacent elements and store in array sa
            for( i = 0; i < N; i++ ){
                sa[i] = A[(i+1)%N] - A[i]-shou;
            }

            // Check if any difference is less than or equal to 0 and divisible by N
            for( i = 0; i < N-1; i++ ){
                if( sa[i] <= 0 &&!(sa[i] % N))
                    ans = 1;
                else{
                    ans = 0;
                    break;
                }
            }
        }

        // Print answer
        if( ans ) System.out.println("YES");
        else{     System.out.println("NO");}
    }
}

