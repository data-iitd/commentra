import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String a = sc.nextLine();
        int count = 0;
        for (int i = 0; i < a.length(); i++) {
            if (a.charAt(i) == '1') {
                count++;
            }
        }
        if (count == 0) {
            System.out.println(0);
        } else {
            int[] arr = new int[count];
            int index = 0;
            for (int i = 0; i < a.length(); i++) {
                if (a.charAt(i) == '1') {
                    int start = i + 1;
                    while (a.charAt(start) == '0') {
                        start++;
                    }
                    int end = start;
                    while (a.charAt(end) == '1') {
                        end++;
                    }
                    arr[index++] = end - start;
                    i = end;
                }
            }
            int result = 1;
            for (int i = 0; i < arr.length; i++) {
                result *= arr[i] + 1;
            }
            System.out.println(result);
        }
    }
}

