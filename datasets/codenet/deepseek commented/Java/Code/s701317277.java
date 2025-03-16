import java.util.*; // Importing the Scanner class for input

public class Main {
    
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in); // Initializing a Scanner object to read input

        int N = sc.nextInt(); // Reading the number of elements N
        int[] A = new int[N]; // Initializing an array A of size N
        int min = Integer.MAX_VALUE; // Initializing min to the maximum possible value
        int count = 0; // Initializing count to 0 to count negative numbers
        long sum = 0; // Initializing sum to 0 to store the sum of absolute values
        for(int i = 0; i < N; i++){
            A[i] = sc.nextInt(); // Reading each element of the array A
            if(A[i] < 0) // Checking if the element is negative
                count++; // Incrementing the count if the element is negative
            min = Math.min(min, Math.abs(A[i])); // Updating the min value with the absolute value of the element
            sum += Math.abs(A[i]); // Adding the absolute value of the element to the sum
        }
        sc.close(); // Closing the Scanner object

        if(count%2 == 0) // Checking if the count of negative numbers is even
            System.out.println(sum); // Printing the sum if the count is even
        else {
            System.out.println(sum-min*2); // Printing the sum minus twice the min value if the count is odd
        }
    }
}
