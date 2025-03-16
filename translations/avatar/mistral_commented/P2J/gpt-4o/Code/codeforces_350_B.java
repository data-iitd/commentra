import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Take the number of test cases as input
        int n = scanner.nextInt();
        
        // Initialize a list 't' with 0 as the first element and followed by the given input list
        int[] t = new int[n + 1];
        t[0] = 0;
        for (int i = 1; i <= n; i++) {
            t[i] = scanner.nextInt();
        }
        
        // Initialize a list 'a' with 0 as the first element and followed by the given input list
        int[] a = new int[n + 1];
        a[0] = 0;
        for (int i = 1; i <= n; i++) {
            a[i] = scanner.nextInt();
        }
        
        // Initialize empty lists 'ans' and 'cnt'
        List<Integer> ans = new ArrayList<>();
        int[] cnt = new int[n + 1];
        
        // Iterate through each element in list 'a' and increment the count of its corresponding index in list 'cnt'
        for (int i = 1; i <= n; i++) {
            cnt[a[i]]++;
        }
        
        // Iterate through each index from 1 to n
        for (int i = 1; i <= n; i++) {
            // If the current index in list 't' is 1
            if (t[i] == 1) {
                // Initialize an empty list 'crt' to store the current sequence
                List<Integer> crt = new ArrayList<>();
                crt.add(i);
                // Get the current element in list 'a'
                int x = a[i];
                // Continue adding elements to 'crt' as long as the corresponding index in 'cnt' has a count of 1
                while (cnt[x] == 1) {
                    crt.add(x);
                    x = a[x];
                }
                // If the length of the current sequence is greater than the length of the current answer sequence
                if (crt.size() > ans.size()) {
                    // Update the answer sequence with the current sequence
                    ans = new ArrayList<>(crt);
                }
            }
        }
        
        // Reverse the order of elements in the answer sequence
        List<Integer> reversedAns = new ArrayList<>();
        for (int j = ans.size() - 1; j >= 0; j--) {
            reversedAns.add(ans.get(j));
        }
        
        // Print the length of the answer sequence
        System.out.println(reversedAns.size());
        // Print the answer sequence with each element separated by a space
        for (int i = 0; i < reversedAns.size(); i++) {
            System.out.print(reversedAns.get(i));
            if (i < reversedAns.size() - 1) {
                System.out.print(" ");
            }
        }
        System.out.println();
        
        scanner.close();
    }
}
// <END-OF-CODE>
