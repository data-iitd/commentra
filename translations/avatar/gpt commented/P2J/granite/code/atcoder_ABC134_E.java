
import java.util.*;

class atcoder_ABC134_E {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        List<List<Integer>> ans = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            int A = sc.nextInt();
            int idx = binarySearch(ans, A);
            if (idx == ans.size()) {
                ans.add(new ArrayList<>(Arrays.asList(A)));
            } else {
                ans.get(idx).add(A);
            }
        }
        System.out.println(ans.size());
    }

    public static int binarySearch(List<List<Integer>> ans, int key) {
        int bad = -1, good = ans.size();
        while (good - bad > 1) {
            int mid = (bad + good) / 2;
            if (ans.get(mid).get(ans.get(mid).size() - 1) < key) {
                good = mid;
            } else {
                bad = mid;
            }
        }
        return good;
    }
}

// Read the number of elements
int N = sc.nextInt();

// Initialize an empty list to hold the subsequences
List<List<Integer>> ans = new ArrayList<>();

// Iterate over the range of N to read each element
for (int i = 0; i < N; i++) {
    int A = sc.nextInt();  // Read the current element
    int idx = binarySearch(ans, A);  // Find the position to insert the element
    
    // If the index is equal to the length of ans, it means A is greater than all elements
    if (idx == ans.size()) {
        ans.add(new ArrayList<>(Arrays.asList(A)));  // Start a new subsequence with A
    } else {
        // Otherwise, append A to the existing subsequence at index idx
        ans.get(idx).add(A);
    }
}

// Print the number of subsequences formed
System.out.println(ans.size());

