
import java.util.Scanner;
import java.util.HashMap;

public class atcoder_ABC109_B{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        HashMap<String, Integer> map = new HashMap<>();
        String[] arr = new String[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.next();
            map.put(arr[i], map.getOrDefault(arr[i], 0) + 1);
        }
        boolean flag = true;
        for (int i = 0; i < n; i++) {
            if (map.get(arr[i]) >= 2) {
                flag = false;
                break;
            }
            if (i > 0 && arr[i - 1].charAt(arr[i - 1].length() - 1)!= arr[i].charAt(0)) {
                flag = false;
                break;
            }
        }
        System.out.println(flag? "Yes" : "No");
    }
}
