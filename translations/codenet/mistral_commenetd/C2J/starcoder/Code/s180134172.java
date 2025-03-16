import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in); // Create a Scanner object to read from the standard input
        int n,k; // Declare two integer variables n and k
        int p[] = new int[99999]; // Declare an array p of integers with a size of 99999
        int i,j,l,m; // Declare integer variables i, j, l, and m
        int o = 0; // Declare an integer variable o and initialize it to 0

        n = sc.nextInt(); // Read an integer from the standard input and store it in the variable n
        k = sc.nextInt(); // Read an integer from the standard input and store it in the variable k

        for(i=0;i<n;i++){ // Iterate through the array p from index 0 to n-1
            p[i] = sc.nextInt(); // Read an integer from the standard input and store it in the array p at index i
        }

        for(i=0;i<n;i++){ // Iterate through the array p from index 0 to n-1
            l = i; // Initialize variable l to i
            for(j=i+1;j<n;j++){ // Iterate through the array p from index i+1 to n-1
                if(p[j]<p[l]){ // If the element at index j is smaller than the element at index l
                    l = j; // Update the index of the smallest element
                }
            }
            if(l!=i){ // If the index of the smallest element is not equal to i
                m = p[i]; // Swap the elements at indices i and l
                p[i] = p[l];
                p[l] = m;
            }
        }

        for(i=0;i<k;i++){ // Iterate through the array p from index 0 to k-1
            o += p[i]; // Add the element at index i to the variable o
        }

        System.out.println(o); // Print the value of the variable o to the standard output
    }
}
