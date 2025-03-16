import java.util.ArrayDeque; // Importing the ArrayDeque class for using deque
import java.util.Scanner; // Importing the Scanner class for reading input

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in); // Creating a Scanner object to read input
        int N = scan.nextInt(); // Reading the number of elements N
        int[] a = new int[N]; // Initializing the array a with size N
        
        // Reading N elements and storing them in the array a
        for (int i = 0; i < N; ++i) {
            a[i] = scan.nextInt();
        }
        
        // Initializing arrays to store the distances to the nearest smaller elements
        int[] leftl = new int[N];
        int[] rightl = new int[N];
        
        // Using a deque to find the nearest smaller element to the right
        ArrayDeque<Integer> que = new ArrayDeque<>();
        int index = 0;
        while (index < N) {
            while (!que.isEmpty() && a[que.peek()] > a[index]) {
                int ind = que.poll();
                rightl[ind] = index - ind - 1; // Calculating the distance
            }
            que.push(index++); // Adding the current index to the deque
        }
        while (!que.isEmpty()) {
            int ind = que.poll();
            rightl[ind] = N - ind - 1; // Calculating the distance for remaining elements
        }
        
        // Using a deque to find the nearest smaller element to the left
        index = N - 1;
        while (index >= 0) {
            while (!que.isEmpty() && a[que.peek()] > a[index]) {
                int ind = que.poll();
                leftl[ind] = ind - index - 1; // Calculating the distance
            }
            que.push(index--); // Adding the current index to the deque
        }
        while (!que.isEmpty()) {
            int ind = que.poll();
            leftl[ind] = ind - index - 1; // Calculating the distance for remaining elements
        }
        
        // Calculating the result by summing up the products
        long ans = 0;
        for (int i = 0; i < N; ++i) {
            ans += (long) a[i] * (leftl[i] + 1) * (rightl[i] + 1);
        }
        
        // Printing the result
        System.out.println(ans);
    }
}
