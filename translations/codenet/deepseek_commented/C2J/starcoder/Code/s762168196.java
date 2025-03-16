import java.util.*;

public class Main {

    public static void main(String[] args) {
        // Step 1: Declare necessary variables
        int[] a = new int[10000];
        int min, max, n, i;
        long sum = 0;

        // Step 2: Read the number of elements (n) from the user
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();

        // Step 3: Read the elements of the array from the user and calculate the sum
        for(i = 0; i < n; i++){
            a[i] = sc.nextInt();
            sum += a[i];
        }

        // Step 4: Find the minimum and maximum values in the array
        max = min = a[0];
        for(i = 1; i < n; i++){
            if(a[i] > max) max = a[i];
            if(a[i] < min) min = a[i];
        }

        // Step 5: Print the minimum, maximum, and sum of the elements
        System.out.println(min + " " + max + " " + sum);
    }
}
