
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Take the number of test cases as input
        int n = sc.nextInt();

        // Initialize a list 't' with 0 as the first element and followed by the given input list
        List<Integer> t = new ArrayList<>();
        t.add(0);
        for (int i = 0; i < n; i++) {
            t.add(sc.nextInt());
        }

        // Initialize a list 'a' with 0 as the first element and followed by the given input list
        List<Integer> a = new ArrayList<>();
        a.add(0);
        for (int i = 0; i < n; i++) {
            a.add(sc.nextInt());
        }

        // Initialize empty lists 'ans' and 'cnt'
        List<Integer> ans = new ArrayList<>();
        List<Integer> cnt = new ArrayList<>();
        for (int i = 0; i < n + 1; i++) {
            cnt.add(0);
        }

        // Iterate through each element in list 'a' and increment the count of its corresponding index in list 'cnt'
        for (int i = 1; i < n + 1; i++) {
            cnt.set(a.get(i), cnt.get(a.get(i)) + 1);
        }

        // Iterate through each index from 1 to n
        for (int i = 1; i < n + 1; i++) {
            // If the current index in list 't' is 1
            if (t.get(i) == 1) {
                // Initialize an empty list 'crt' to store the current sequence
                List<Integer> crt = new ArrayList<>();
                // Get the current element in list 'a'
                int x = a.get(i);
                // Continue adding elements to 'crt' as long as the corresponding index in 'cnt' has a count of 1
                while (cnt.get(x) == 1) {
                    crt.add(x);
                    x = a.get(x);
                }
                // If the length of the current sequence is greater than the length of the current answer sequence
                if (crt.size() > ans.size()) {
                    // Update the answer sequence with the current sequence
                    ans = crt;
                }
            }
        }

        // Print the length of the answer sequence
        System.out.println(ans.size());
        // Print the answer sequence with each element separated by a space
        for (int i = 0; i < ans.size(); i++) {
            System.out.print(ans.get(i) + " ");
        }
    }
}

