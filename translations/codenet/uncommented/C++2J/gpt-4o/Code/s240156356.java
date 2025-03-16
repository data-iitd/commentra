import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String str1 = scanner.next();
        String str2 = scanner.next();

        char[] arr1 = str1.toCharArray();
        char[] arr2 = str2.toCharArray();

        Arrays.sort(arr1);
        Arrays.sort(arr2);
        reverse(arr2);

        int loop = Math.min(arr1.length, arr2.length);
        boolean flag = false;

        for (int i = 0; i < loop; i++) {
            char ch1 = arr1[i];
            char ch2 = arr2[i];

            if (ch1 == ch2) {
                if (loop == i + 1 && arr1.length < arr2.length) {
                    flag = true;
                    break;
                } else {
                    continue;
                }
            } else {
                if (ch2 > ch1) {
                    flag = true;
                    break;
                } else {
                    break;
                }
            }
        }

        if (flag) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }

    private static void reverse(char[] array) {
        int left = 0, right = array.length - 1;
        while (left < right) {
            char temp = array[left];
            array[left] = array[right];
            array[right] = temp;
            left++;
            right--;
        }
    }
}
// <END-OF-CODE>
