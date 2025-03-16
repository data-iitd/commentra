import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.next();
        int max = 0, cnt = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == 'A' || str.charAt(i) == 'C' || str.charAt(i) == 'G' || str.charAt(i) == 'T') {
                cnt++;
            } else {
                cnt = 0;
            }
            max = max < cnt ? cnt : max;
        }
        System.out.println(max);
    }
}

