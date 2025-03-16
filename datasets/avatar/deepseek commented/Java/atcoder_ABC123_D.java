
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x[] = new int[3];
        int max = 0;

        // Step 1: Read input values for the array x and find the maximum value in x.
        for (int i = 0; i < 3; ++i) {
            x[i] = sc.nextInt();
            max = Math.max(max, x[i]);
        }

        int k = sc.nextInt();
        List<Long> a[][] = new List[3][];

        // Step 2: Initialize a list of lists to store the input values for each sub-array.
        for (int i = 0; i < 3; ++i) {
            a[i] = new ArrayList<>();
        }

        // Step 3: Read input values for each sub-array, sort them, and store them in the list of lists.
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < x[i]; ++j) {
                a[i].add(sc.nextLong());
            }
            Collections.sort(a[i]);
        }

        sc.close();

        List<Long> ans = new ArrayList<>();

        // Step 5: Initialize an empty list to store the results.
        // Step 6: Use nested loops to iterate through all possible combinations of elements from the three sub-arrays,
        // and add the sum of the selected elements to the result list if the product of their indices is less than or equal to k.
        for (int i = 0; i < x[0]; ++i) {
            for (int j = 0; j < x[1]; ++j) {
                for (int m = 0; m < x[2]; ++m) {
                    if ((i + 1) * (j + 1) * (m + 1) <= k) {
                        long tmp = a[0].get(x[0] - i - 1) + a[1].get(x[1] - j - 1) + a[2].get(x[2] - m - 1);
                        ans.add(tmp);
                    }
                }
            }
        }

        // Step 7: Sort the result list in ascending order.
        Collections.sort(ans);

        int n = ans.size();

        // Step 8: Print the top k values from the result list in descending order.
        for (int i = 0; i < k; ++i) {
            System.out.println(ans.get(n - i - 1));
        }
    }
}
