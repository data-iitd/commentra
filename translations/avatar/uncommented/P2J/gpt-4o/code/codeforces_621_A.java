import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = Integer.parseInt(scanner.nextLine());
        int[] lst = new int[n];
        
        String[] input = scanner.nextLine().split(" ");
        for (int i = 0; i < n; i++) {
            lst[i] = Integer.parseInt(input[i]);
        }
        
        Arrays.sort(lst);
        // Reverse the array
        for (int i = 0; i < n / 2; i++) {
            int temp = lst[i];
            lst[i] = lst[n - 1 - i];
            lst[n - 1 - i] = temp;
        }
        
        int od = 0;
        for (int i : lst) {
            if ((i & 1) != 0) {
                od++;
            }
        }
        
        int sum = 0;
        boolean ok = false;
        for (int i = 0; i < n; i++) {
            if (lst[i] % 2 == 0) {
                sum += lst[i];
            } else {
                if (ok || od > 1) {
                    sum += lst[i];
                    od--;
                    ok = !ok;
                }
            }
        }
        
        System.out.println(sum);
    }
}
// <END-OF-CODE>
