
package main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] line = reader.readLine().split(" ");
        int N = Integer.parseInt(line[0]);
        int K = Integer.parseInt(line[1]);

        // Convert N to base K and print the length of the resulting string
        String s = TenToN(N, K);
        System.out.println(s.length());
    }

    // TenToN converts a decimal number to a base N string
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

    // s2i converts a string to an integer
    public static int s2i(String s) {
        int intVal = Integer.parseInt(s);
        return intVal;
    }

    // i2s converts an integer to a string
    public static String i2s(int i) {
        String strVal = Integer.toString(i);
        return strVal;
    }

    // s2f converts a string to a float
    public static float s2f(String s) {
        float floatVal = Float.parseFloat(s);
        return floatVal;
    }

    // sum calculates the sum of integers in a slice
    public static int sum(int[] i) {
        int sum = 0;
        for (int val : i) {
            sum += val;
        }
        return sum;
    }

    // split splits a string into a slice of words
    public static String[] split(String s) {
        return s.split(" ");
    }

    // strAry2intAry converts a slice of strings to a slice of integers
    public static int[] strAry2intAry(String[] strs) {
        int[] ret = new int[strs.length];
        for (int i = 0; i < strs.length; i++) {
            int intVal = Integer.parseInt(strs[i]);
            ret[i] = intVal;
        }
        return ret;
    }

    // intAry2strAry converts a slice of integers to a slice of strings
    public static String[] intAry2strAry(int[] nums) {
        String[] ret = new String[nums.length];
        for (int i = 0; i < nums.length; i++) {
            String strVal = Integer.toString(nums[i]);
            ret[i] = strVal;
        }
        return ret;
    }

    // ary2str joins a slice of strings into a single string with spaces
    public static String ary2str(String[] strs) {
        return String.join(" ", strs);
    }

    // reverse reverses a slice of integers
    public static int[] reverse(int[] res) {
        for (int i = 0, j = res.length - 1; i < j; i++, j--) {
            int tmp = res[i];
            res[i] = res[j];
            res[j] = tmp;
        }
        return res;
    }

    // initalize initializes a slice with a given value
    public static void initalize(int[] res, int init) {
        if (res.length == 0) {
            return;
        }
        res[0] = init;
        for (int i = 0; i < res.length; i++) {
            System.arraycopy(res, 0, res, i, i);
        }
    }

    // func regexpExample() {
    //     // Your code here!
    //     var str = "13:20"
    //     r := regexp.MustCompile(`(\d+):(\d+)`)
    //     fmt.Println(r.FindStringSubmatch(str))
    // }

    // type Country struct {
    //     gold int
    //     silver int
    //     blonze int
    // }

    // // 複数ソートのサンプル
    // func stableSortExample() []Country{
    //     var country = []Country {
    //         {gold:1, silver:2, blonze:3},
    //         {gold:1, silver:2, blonze:3},
    //         {gold:1, silver:3, blonze:2},
    //         {gold:1, silver:3, blonze:3},
    //     }
    //     sort.SliceStable(country, func(i, j int) bool { return country[i].blonze > country[j].blonze })
    //     sort.SliceStable(country, func(i, j int) bool { return country[i].silver > country[j].silver })
    //     sort.SliceStable(country, func(i, j int) bool { return country[i].gold > country[j].gold })
    //     return country
    // }

    // 正規表現のサンプル
    public static void regexpExample() {
        // Your code here!
        String str = "13:20";
        Pattern r = Pattern.compile("(\\d+):(\\d+)");
        Matcher m = r.matcher(str);
        if (m.find()) {
            System.out.println(m.group(1));
            System.out.println(m.group(2));
        }
    }

    // 複数ソートのサンプル
    public static List<Country> stableSortExample() {
        List<Country> country = new ArrayList<>();
        country.add(new Country(1, 2, 3));
        country.add(new Country(1, 2, 3));
        country.add(new Country(1, 3, 2));
        country.add(new Country(1, 3, 3));

        country.sort((c1, c2) -> c1.blonze - c2.blonze);
        country.sort((c1, c2) -> c1.silver - c2.silver);
        country.sort((c1, c2) -> c1.gold - c2.gold);
        return country;
    }

    public static class Country {
        int gold;
        int silver;
        int blonze;

        public Country(int gold, int silver, int blonze) {
            this.gold = gold;
            this.silver = silver;
            this.blonze = blonze;
        }
    }
}

