import java.util.*;

public class Main{
    public static void main(String[] args){
        // Read the number of elements from the standard input
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        // Declare and initialize an array of size 100 with zeros
        int a[] = new int[100];

        // Calculate the average of the elements in the array
        double avg = 0;
        for(int i = 0; i < n; i++){
            a[i] = sc.nextInt(); // Read an element from the standard input and store it in the array
            avg += a[i];        // Add the current element to the sum of all elements
        }

        // Calculate the average and divide it by the number of elements
        avg /= n;

        // Initialize the difference between the first element and the average
        double s = Math.abs(a[0] - avg);

        // Initialize the index of the element with the maximum difference from the average
        int ans = 0;

        // Find the index of the element with the maximum difference from the average
        for(int i = 1; i < n; i++){
            if(s > Math.abs(a[i] - avg)){ // If the current difference is greater than the previous difference
                s = Math.abs(a[i] - avg); // Update the difference
                ans = i;                  // Update the index
            }
        }

        // Print the index of the element with the maximum difference from the average
        System.out.println(ans);
    }
}

