import java.util.*;
import java.util.stream.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read an integer input
        IntFunction<Integer> numInp = () -> Integer.parseInt(scanner.nextLine());
        
        // Read a list of integers from input
        IntFunction<List<Integer>> arrInp = () -> 
            Arrays.asList(scanner.nextLine().split(" "))
                  .stream()
                  .mapToInt(Integer::parseInt)
                  .boxed()
                  .collect(Collectors.toList());
        
        // Read a space-separated list of integers as a list of integers
        IntFunction<List<Integer>> spInp = () -> 
            Arrays.asList(scanner.nextLine().split(" "))
                  .stream()
                  .mapToInt(Integer::parseInt)
                  .boxed()
                  .collect(Collectors.toList());
        
        // Read the input from the first line of the standard input, sort it, and convert it to a list of integers
        List<Integer> a = arrInp.apply();
        Collections.sort(a);
        
        // Check if any element in the list 'a' is not divisible by the first element of 'a'
        // If all elements are divisible, print the first element; otherwise, print -1
        int firstElement = a.get(0);
        boolean divisible = a.stream().allMatch(x -> x % firstElement == 0);
        
        System.out.println(divisible ? firstElement : -1);
    }
}
