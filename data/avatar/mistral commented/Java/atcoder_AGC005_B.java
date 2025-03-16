
import java.util.ArrayDeque; // Importing the ArrayDeque class for implementing a double ended queue
import java.util.Scanner; // Importing the Scanner class for reading input from the console
import java.util.stream.IntStream; // Importing the IntStream class for creating an IntStream from an array

public class Main {

 // Main method to start the execution of the program
  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in); // Creating a new Scanner object to read input from the console
    int N = scan.nextInt(); // Reading the number of elements in the array from the console
    int[] a = new int[N]; // Creating an integer array of size N

    // Reading the elements of the array from the console and storing them in the array
    for (int i = 0; i < N; ++i) {
      a[i] = scan.nextInt();
    }

    int[] leftl = new int[N]; // Creating an integer array of size N to store the length of the left segment for each element
    int[] rightl = new int[N]; // Creating an integer array of size N to store the length of the right segment for each element
    ArrayDeque<Integer> que = new ArrayDeque<>(); // Creating an ArrayDeque object to implement a double ended queue
    int index = 0; // Initializing the index variable to traverse the array

    // Finding the length of the left and right segments for each element using two stacks
    while (index < N) {
      while (!que.isEmpty() && a[que.peek()] > a[index]) { // Popping the elements from the queue whose right segment length is to be calculated
        int ind = que.poll(); // Storing the index of the popped element
        rightl[ind] = index - ind - 1; // Calculating the length of the right segment for the popped element
      }
      que.push(index++); // Pushing the current index into the queue
    }

    // Calculating the length of the right segment for the last element
    while (!que.isEmpty()) {
      int ind = que.poll();
      rightl[ind] = N - ind - 1;
    }

    index = N - 1; // Initializing the index variable to traverse the array in reverse order

    // Finding the length of the left segments for each element using two stacks in reverse order
    while (index >= 0) {
      while (!que.isEmpty() && a[que.peek()] > a[index]) { // Popping the elements from the queue whose left segment length is to be calculated
        int ind = que.poll();
        leftl[ind] = ind - index - 1; // Calculating the length of the left segment for the popped element
      }
      que.push(index--); // Pushing the current index into the queue
    }

    // Calculating the length of the left segment for the first element
    while (!que.isEmpty()) {
      int ind = que.poll();
      leftl[ind] = ind - index - 1;
    }

    long ans = 0; // Initializing the variable to store the final answer

    // Calculating the answer by multiplying the element, left segment length, and right segment length for each element
    for (int i = 0; i < N; ++i) {
      ans += (long) a[i] * (leftl[i] + 1) * (rightl[i] + 1);
    }

    // Printing the final answer
    System.out.println(ans);
  }
}