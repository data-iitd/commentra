
import java.util.*;  // Importing the Scanner class for input

public class codeforces_637_A{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);  // Creating a Scanner object to read input
        int n = scanner.nextInt();  // Reading the number of elements
        String[] s = new String[n];  // Creating an array to store the elements
        for (int i = 0; i < n; i++) {
            s[i] = scanner.next();  // Reading each element and storing it in the array
        }
        Map<String, Integer> w = new HashMap<>();  // Creating a HashMap to count occurrences of elements
        for (String element : s) {
            w.put(element, w.getOrDefault(element, 0) + 1);  // Incrementing the count of each element
        }
        Arrays.sort(s, (a, b) -> w.get(b) - w.get(a));  // Sorting the elements based on their count in descending order
        String a = "";  // Initializing the most frequent element
        for (String element : s) {
            if (w.get(element).equals(w.get(s[0]))) {  // Checking if the current element has the same count as the most frequent element
                a = element;  // Updating the most frequent element
                break;  // Exiting the loop once the most frequent element is found
            }
        }
        System.out.println(a);  // Printing the most frequent element
    }
}

Translate the above Java code to C++ and end with comment "