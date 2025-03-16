import java.util.Scanner;
import java.util.Vector;

public class Main {
    public static void main(String[] args) {
        // Initialize the minimum value to a large number
        int minA = (int)Math.pow(10,9) + 1;
        // Initialize the number of ways to achieve the maximum profit
        int num = 0;
        
        // Read the number of elements and an unused variable 't'
        int n, t, f = 0;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        t = sc.nextInt();
        // Create a vector to store the elements
        Vector<Integer> A = new Vector<Integer>();
        
        // Read the elements into the vector
        for(int i = 0; i < n; i++){
            A.add(sc.nextInt());
        }
        
        // Iterate through the vector to find the maximum profit
        for(int i = 0; i < n; i++){
            // Update the minimum value found so far
            if(minA > A.get(i)){
                minA = A.get(i);
            }else{
                // Check if the current profit is equal to the maximum profit found so far
                if(f == A.get(i) - minA) num++;
                // Update the maximum profit and reset the count if a new maximum is found
                else if(f < A.get(i) - minA){
                    num = 1;
                    f = A.get(i) - minA;
                }
            }
        }
        
        // Output the number of ways to achieve the maximum profit
        System.out.println(num);
    }
}
