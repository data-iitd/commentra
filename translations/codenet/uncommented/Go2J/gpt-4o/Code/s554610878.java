import java.util.Scanner;

public class Main {
    private static final int MOD = 1000000007;

    public static void main(String[] args) {
        String[] week = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();
        int index = -1;

        for (int i = 0; i < week.length; i++) {
            if (s.equals(week[i])) {
                index = i;
                break;
            }
        }

        System.out.println(7 - index);
        scanner.close();
    }

    private static int getInt(Scanner scanner) {
        return scanner.nextInt();
    }

    private static String getString(Scanner scanner) {
        return scanner.next();
    }

    private static int abs(int a) {
        return Math.abs(a);
    }

    private static int pow(int p, int q) {
        return (int) Math.pow(p, q);
    }

    private static int min(int... nums) {
        if (nums.length == 0) {
            throw new IllegalArgumentException("Function min() requires at least one argument.");
        }
        int res = nums[0];
        for (int num : nums) {
            res = Math.min(res, num);
        }
        return res;
    }

    private static int max(int... nums) {
        if (nums.length == 0) {
            throw new IllegalArgumentException("Function max() requires at least one argument.");
        }
        int res = nums[0];
        for (int num : nums) {
            res = Math.max(res, num);
        }
        return res;
    }

    private static boolean strSearch(String[] a, String b) {
        for (String s : a) {
            if (s.equals(b)) {
                return true;
            }
        }
        return false;
    }

    private static void printIntArray(int[] array) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < array.length; i++) {
            sb.append(array[i]);
            if (i < array.length - 1) {
                sb.append(", ");
            }
        }
        System.out.println(sb.toString());
    }

    private static int calcMod(int x) {
        return x % MOD;
    }
}

// <END-OF-CODE>
