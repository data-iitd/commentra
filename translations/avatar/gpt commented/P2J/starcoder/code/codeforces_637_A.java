import java.util.*;  // Importing the Scanner class
import java.util.stream.*;  // Importing the Stream class

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);  // Creating a Scanner object

        // Reading the number of elements
        int n = sc.nextInt();

        // Reading the input string, removing the last character (newline), and splitting it into a list
        List<String> s = Arrays.asList(sc.nextLine().substring(0, n - 1).split(" "));

        // Counting the occurrences of each element in the list
        Map<String, Long> w = s.stream().collect(Collectors.groupingBy(e -> e, Collectors.counting()));

        // Reversing the list to process elements in reverse order
        Collections.reverse(s);

        // Initializing variables to track the index of the most frequent element and its value
        int c = -1, a = 0;

        // Iterating through each unique element in the count dictionary
        for (String i : w.keySet()) {
            // Checking if the current element's count is equal to the maximum count
            if (w.get(i).equals(w.values().stream().max(Comparator.naturalOrder()).get())) {
                // If the index of the current element in the reversed list is greater than the current index
                if (s.indexOf(i) > c) {
                    // Updating the most frequent element and its index
                    a = i.charAt(0);
                    c = s.indexOf(i);
                }
            }
        }

        // Printing the most frequent element that appears last in the original order
        System.out.println(a);
    }
}

