import java.util.Scanner;
import java.util.Stack;
public final class MaximumMinimumWindow {
    private MaximumMinimumWindow() {
    }
    public static int[] calculateMaxOfMin(int[] arr, int n) {
        Stack<Integer> s = new Stack<>();
        int[] left = new int[n];
        int[] right = new int[n];
        int[] ans = new int[n + 1];
        for (int i = 0; i < n; i++) {
            left[i] = -1;
            right[i] = n;
        }
        for (int i = 0; i < n; i++) {
            while (!s.isEmpty() && arr[s.peek()] >= arr[i]) {
                s.pop();
            }
            if (!s.isEmpty()) {
                left[i] = s.peek();
            }
            s.push(i);
        }
        s.clear(); 
        for (int i = n - 1; i >= 0; i--) {
            while (!s.isEmpty() && arr[s.peek()] >= arr[i]) {
                s.pop();
            }
            if (!s.isEmpty()) {
                right[i] = s.peek();
            }
            s.push(i);
        }
        for (int i = 0; i < n; i++) {
            int len = right[i] - left[i] - 1; 
            ans[len] = Math.max(ans[len], arr[i]);
        }
        for (int i = n - 1; i >= 1; i--) {
            ans[i] = Math.max(ans[i], ans[i + 1]);
        }
        return ans;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        int[] result = calculateMaxOfMin(arr, n);
        for (int i = 1; i <= n; i++) {
            System.out.print(result[i] + " ");
        }
        scanner.close();
    }
}
