import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the first line of input and split it into an array of strings
        String[] input = scanner.nextLine().split(" ");
        
        // Convert the input strings to an array of integers
        int[] a = Arrays.stream(input)
                        .mapToInt(Integer::parseInt)
                        .sorted()
                        .toArray();
        
        // Check if any element in the array 'a' is not divisible by the first element of 'a'
        boolean notDivisible = false;
        for (int x : a) {
            if (x % a[0] != 0) {
                notDivisible = true;
                break;
            }
        }
        
        // Print the first element if all are divisible, otherwise print -1
        System.out.println(notDivisible ? -1 : a[0]);
        
        scanner.close();
    }
}

// <END-OF-CODE>
