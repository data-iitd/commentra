import java.util.Arrays;
import java.util.Scanner;

public class RibbonCutter {
    public static void cutRibbon() {
        Scanner scanner = new Scanner(System.in);
        String[] input = scanner.nextLine().split(" ");
        int length = Integer.parseInt(input[0]);
        int[] arr = new int[3];
        for (int i = 1; i <= 3; i++) {
            arr[i - 1] = Integer.parseInt(input[i]);
        }
        Arrays.sort(arr);
        
        if (length % arr[2] == 0) {
            System.out.println(length / arr[2]);
            return;
        }
        
        int ans = 0;
        if (arr[1] == arr[2]) {
            for (int i = 0; i <= length / arr[1]; i++) {
                int check = length - i * arr[1];
                if (check >= 0 && check % arr[0] == 0) {
                    int k = check / arr[0];
                    ans = Math.max(ans, k + i);
                }
            }
        } else {
            for (int i = 0; i <= length / arr[2]; i++) {
                for (int j = 0; j <= length / arr[1]; j++) {
                    int check = length - i * arr[2] - j * arr[1];
                    if (check >= 0 && check % arr[0] == 0) {
                        int k = check / arr[0];
                        ans = Math.max(ans, k + i + j);
                    }
                }
            }
        }
        System.out.println(ans);
    }

    public static void main(String[] args) {
        cutRibbon();
    }
}

// <END-OF-CODE>
