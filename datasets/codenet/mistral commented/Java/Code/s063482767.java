import java.util.*; // We import the utility class Scanner and the PriorityQueue from the java.util package

public class Main { // This is the main class

    public static void main(String[] args) { // This is the main method where the program starts execution
        Scanner sc = new Scanner(System.in); // We create a new Scanner object to read input from the standard input
        int n = sc.nextInt(); // We read the first integer from the standard input and assign it to the variable n

        PriorityQueue<Integer> queue = new PriorityQueue<>(); // We create an empty PriorityQueue of Integers

        for(int i = 0; i < n; i++) { // We use a for loop to read and add n integers to the queue
            queue.add(sc.nextInt());
        }

        int sum = 0; // We initialize the sum variable to 0
        for(int i = 0; i < n - 1; i++) { // We use another for loop to sum up the first n-1 elements in the queue
            sum += queue.poll(); // We remove and add the polled element to the sum
        }

        // 出力
        System.out.println(queue.poll() < sum ? "Yes" : "No"); // We print "Yes" if the last element in the queue is smaller than the sum of the first n-1 elements, otherwise we print "No"
    }
}
