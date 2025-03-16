
import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in); // Initialize a Scanner object'sc' to read input from the standard input

        int n = sc.nextInt(); // Read the number of elements 'n' from the standard input
        int k = sc.nextInt(); // Read the number of frequencies to consider 'k' from the standard input

        int[] cnt = new int[1000001]; // Initialize an array 'cnt' of size '1000001' to store the frequency count of each element

        for(int i = 0; i < n; ++i){ // Loop through the input elements
            int x = sc.nextInt(); // Read an element 'x' from the standard input

            cnt[x]++; // Increment the frequency count of the element 'x' in the array 'cnt'
        }

        int ans = 0; // Initialize an integer 'ans' to store the sum of the first 'k' frequency counts

        for(int i = 0; i < 1000001; ++i){ // Loop through all elements in the array 'cnt'
            if(cnt[i] > 0) // If the frequency count of an element is greater than zero
                ans += cnt[i]; // Add the frequency count to the variable 'ans'
        }

        ans -= k; // Subtract the number of frequencies to be ignored from the variable 'ans'

        System.out.println(ans); // Print the result 'ans' to the standard output
    }
}

