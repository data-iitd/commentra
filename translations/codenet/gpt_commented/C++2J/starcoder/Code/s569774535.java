import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Read the number of elements
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        // Initialize a vector to store the elements
        int[] a = new int[n];
        
        // Input the elements into the vector
        for(int i = 0; i < n; i++){
            a[i] = sc.nextInt();
        }

        // Initialize the answer counter and a flag for the loop
        int ans = 0;
        boolean ok = true;

        // Loop until an odd number is found in the vector
        while(ok){
            // Check each element in the vector
            for(int i = 0; i < n; i++){
                // If the current element is odd, print the answer and exit
                if(a[i] % 2 == 1){
                    System.out.println(ans);
                    return;
                }
                // If the current element is even, divide it by 2
                else{
                    a[i] /= 2;
                }
            }
            // Increment the answer counter for each complete iteration
            ans++;
        }

        // Output the final count of divisions by 2 before encountering an odd number
        System.out.println(ans);
    }
}

