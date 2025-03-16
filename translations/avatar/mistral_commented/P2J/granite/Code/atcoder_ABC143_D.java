
import java.io.*;
import java.util.*;

class atcoder_ABC143_D {
    public static void main(String[] args) throws Exception {
        // Read the number of elements 'n' and a list 'l' of 'n' integers from standard input
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] input = br.readLine().split(" ");
        List<Integer> l = new ArrayList<>();
        for (String s : input) {
            l.add(Integer.parseInt(s));
        }

        // Sort the list 'l' in ascending order
        Collections.sort(l);

        // Initialize an answer variable 'ans' to zero
        long ans = 0;

        // Iterate through each pair of indices 'i' and 'j' in the list 'l'
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // Assign the elements at indices 'i' and 'j' to variables 'a' and 'b' respectively
                int a = l.get(i);
                int b = l.get(j);

                // Use Collections.binarySearch to find the index 'right' where an element greater than 'a+b' is present
                int right = Collections.binarySearch(l, a + b);
                if (right < 0) right = -right - 1;

                // Use Collections.binarySearch to find the index 'left' where the smallest element greater than'max(a-b, b-a)' is present
                int left = Collections.binarySearch(l, Math.max(a - b, b - a));
                if (left < 0) left = -left - 1;

                // Calculate the temporary answer 'tmp' based on the indices 'left' and 'right'
                long tmp = Math.max(0, right - left);

                // Subtract one from the temporary answer 'tmp' if both 'i' and 'j' lie between 'left' and 'right'
                if (left <= i && i < right) tmp--;
                if (left <= j && j < right) tmp--;

                // Add the temporary answer 'tmp' to the final answer 'ans'
                ans += tmp;
            }
        }

        // Print the final answer 'ans' divided by three
        System.out.println(ans / 3);
    }
}
