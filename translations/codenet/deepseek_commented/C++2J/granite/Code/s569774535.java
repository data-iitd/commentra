
import java.util.*;  // Import the Scanner class from the java.util package

public class s569774535{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);  // Create a Scanner object to read input
        int n = sc.nextInt();  // Read the integer n
        int[] a = new int[n];  // Create an array of size n to store the integers
        for(int i=0;i<n;i++){
            a[i] = sc.nextInt();  // Read n integers into the array a
        }

        int ans = 0;  // Initialize ans to 0
        boolean ok = true;  // Initialize ok to true
        while(ok){  // Start the main loop
            for(int i=0;i<n;i++){  // Iterate over each element in the array a
                if(a[i]%2 == 1){  // Check if the element is odd
                    System.out.println(ans);  // Print the current value of ans and exit
                    return;
                }
                else{  // If the element is even
                    a[i] /= 2;  // Divide the element by 2
                }
            }
            ans++;  // Increment ans after processing all elements
        }

        System.out.println(ans);  // Print the final value of ans
    }
}
