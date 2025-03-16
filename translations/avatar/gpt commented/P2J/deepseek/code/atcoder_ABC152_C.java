import java.util.Scanner;  // Importing the Scanner class for taking input

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);  // Creating a Scanner object

        // Taking input for the number of elements
        int N = Integer.parseInt(scanner.nextLine());  

        // Taking input for the elements and converting them into an array of integers
        String[] input = scanner.nextLine().split(" ");
        int[] n = new int[N];
        for (int i = 0; i < N; i++) {
            n[i] = Integer.parseInt(input[i]);
        }

        // Initializing a counter 'a' to count the number of elements that are less than the current element
        int a = 1;  

        // Initializing 'pos' to keep track of the position of the last element that was smaller
        int pos = 0;  

        // Looping through the array starting from the second element
        for (int i = 1; i < N; i++) {  
            // Checking if the current element is smaller than the element at 'pos'
            if (n[pos] > n[i]) {  
                a += 1;  // Incrementing the counter if the condition is met
                pos = i;  // Updating 'pos' to the current index
            }
        }

        // Printing the final count of elements that were smaller than the previous ones
        System.out.println(a);  
    }
}
