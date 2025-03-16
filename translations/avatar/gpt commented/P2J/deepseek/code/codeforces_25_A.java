import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read an integer input which represents the number of elements
        int n = scanner.nextInt();
        
        // Read a line of input, split it into individual elements, convert them to integers,
        // and create a list that contains 1 for odd numbers and 0 for even numbers
        int[] list = new int[n];
        String[] elements = scanner.next().split("");
        
        for (int i = 0; i < n; i++) {
            list[i] = Integer.parseInt(elements[i]) % 2;
        }
        
        // Check if there is exactly one odd number in the list
        int oddCount = 0;
        int evenIndex = -1;
        
        for (int i = 0; i < n; i++) {
            if (list[i] == 1) {
                oddCount++;
            } else {
                evenIndex = i;
            }
        }
        
        if (oddCount == 1) {
            // If there is one odd number, print its position (1-based index)
            System.out.println(list.indexOf(1) + 1);
        } else {
            // If there are no odd numbers, print the position of the first even number (1-based index)
            System.out.println(evenIndex + 1);
        }
    }
}
