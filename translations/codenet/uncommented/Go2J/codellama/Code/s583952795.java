
package main

import java.util.Scanner;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        PrintWriter writer = new PrintWriter(System.out);

        int N = scanner.nextInt();
        int K = scanner.nextInt();
        String s = TenToN(N, K);
        writer.println(s.length());
        writer.flush();
    }

    public static String TenToN(int number, int n) {
        String s = "";
        int tmp = number;
        while (true) {
            s = i2s(tmp % n) + s;
            if (tmp < n) {
                break;
            }
            tmp /= n;
        }
        return s;
    }

    public static String i2s(int i) {
        return String.valueOf(i);
    }

    public static int s2i(String s) {
        return Integer.parseInt(s);
    }

    public static int sum(int[] i) {
        int sum = 0;
        for (int val : i) {
            sum += val;
        }
        return sum;
    }

    public static String[] split(String s) {
        return s.split(" ");
    }

    public static int[] strAry2intAry(String[] strs) {
        int[] ret = new int[strs.length];
        for (int i = 0; i < strs.length; i++) {
            ret[i] = s2i(strs[i]);
        }
        return ret;
    }

    public static String[] intAry2strAry(int[] nums) {
        String[] ret = new String[nums.length];
        for (int i = 0; i < nums.length; i++) {
            ret[i] = i2s(nums[i]);
        }
        return ret;
    }

    public static String ary2str(String[] strs) {
        return String.join(" ", strs);
    }

    public static int[] reverse(int[] res) {
        for (int i = 0, j = res.length - 1; i < j; i++, j--) {
            int tmp = res[i];
            res[i] = res[j];
            res[j] = tmp;
        }
        return res;
    }

    public static void initalize(int[] res, int init) {
        if (res.length == 0) {
            return;
        }
        res[0] = init;
        for (int i = 0; i < res.length; i++) {
            System.arraycopy(res, 0, res, i, i);
        }
    }

    // public static void regexpExample() {
    //     // Your code here!
    //     String str = "13:20";
    //     Pattern r = Pattern.compile("(\\d+):(\\d+)");
    //     Matcher m = r.matcher(str);
    //     System.out.println(m.find());
    // }

    // public static Country[] stableSortExample() {
    //     Country[] country = {
    //         new Country(1, 2, 3),
    //         new Country(1, 2, 3),
    //         new Country(1, 3, 2),
    //         new Country(1, 3, 3),
    //     };
    //     Arrays.sort(country, (a, b) -> a.blonze - b.blonze);
    //     Arrays.sort(country, (a, b) -> a.silver - b.silver);
    //     Arrays.sort(country, (a, b) -> a.gold - b.gold);
    //     return country;
    // }

    // public static class Country {
    //     int gold;
    //     int silver;
    //     int blonze;

    //     public Country(int gold, int silver, int blonze) {
    //         this.gold = gold;
    //         this.silver = silver;
    //         this.blonze = blonze;
    //     }
    // }
}

