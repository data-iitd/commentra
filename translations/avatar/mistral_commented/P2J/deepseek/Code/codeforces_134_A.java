import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Reading the first line of input which contains the number of elements 'n' in the list 'w'
        int n = Integer.parseInt(scanner.nextLine());
        
        // Initializing an empty list 'w' to store the elements
        List<Integer> w = new ArrayList<>();
        
        // Reading the elements of the list 'w'
        String[] input = scanner.nextLine().split(" ");
        for (String s : input) {
            w.add(Integer.parseInt(s));
        }
        
        // Initializing an empty list 'd' to store the indices of the elements that satisfy the condition
        List<Integer> d = new ArrayList<>();
        
        // Iterating through each element 'i' in the list 'w'
        for (int i = 0; i < n; i++) {
            // Calculating the average of the remaining sum of elements after removing the current element 'w[i]'
            // and checking if it's equal to the current element 'w[i]'
            if ((w.stream().mapToInt(Integer::intValue).sum() - w.get(i)) % (n - 1) == 0 && (w.stream().mapToInt(Integer::intValue).sum() - w.get(i)) / (n - 1) == w.get(i)) {
                // If the condition is true, add the index 'i+1' to the list 'd'
                d.add(i + 1);
            }
        }
        
        // Printing the length of the list 'd'
        System.out.println(d.size());
        
        // Printing the elements of the list 'd' separated by a space
        for (int i = 0; i < d.size(); i++) {
            if (i > 0) {
                System.out.print(" ");
            }
            System.out.print(d.get(i));
        }
        System.out.println();
    }
}

