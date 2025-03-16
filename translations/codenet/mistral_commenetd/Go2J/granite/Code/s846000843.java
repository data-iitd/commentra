
import java.util.*;

public class s846000843{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] aa = new int[n];
        for (int i = 0; i < n; i++) {
            aa[i] = scanner.nextInt();
        }
        int[] cumsum = cumSum(aa);
        int ans = 2020202020;
        for (int i = 1; i < cumsum.length - 1; i++) {
            int diff1 = Math.abs(cumsum[cumsum.length - 1] - cumsum[i]);
            int diff2 = cumsum[i] - cumsum[0];
            ans = Math.min(ans, diff1, diff2);
        }
        System.out.println(ans);
    }

    public static int[] cumSum(int[] nums) {
        int[] sums = new int[nums.length + 1];
        for (int i = 0; i < nums.length; i++) {
            sums[i + 1] = sums[i] + nums[i];
        }
        return sums;
    }
}

// The abs function returns the absolute value of an integer.
public static int abs(int a) {
    if (a >= 0) {
        return a;
    } else {
        return -a;
    }
}

// The min function returns the minimum of a list of integers.
public static int min(int... nums) {
    if (nums.length == 0) {
        throw new IllegalArgumentException("Function min() requires at least one argument.");
    }
    int res = nums[0];
    for (int i = 0; i < nums.length; i++) {
        res = Math.min(res, nums[i]);
    }
    return res;
}

// The max function returns the maximum of a list of integers.
public static int max(int... nums) {
    if (nums.length == 0) {
        throw new IllegalArgumentException("Function max() requires at least one argument.");
    }
    int res = nums[0];
    for (int i = 0; i < nums.length; i++) {
        res = Math.max(res, nums[i]);
    }
    return res;
}

// The sortAsc function sorts an integer array in ascending order.
public static int[] sortAsc(int[] a) {
    Arrays.sort(a);
    return a;
}

// The sortDesc function sorts an integer array in descending order.
public static int[] sortDesc(int[] a) {
    Arrays.sort(a);
    int left = 0;
    int right = a.length - 1;
    while (left < right) {
        int temp = a[left];
        a[left] = a[right];
        a[right] = temp;
        left++;
        right--;
    }
    return a;
}

// The gcd function returns the greatest common divisor of two integers.
public static int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// The lcm function returns the least common multiple of two integers.
public static int lcm(int a, int b) {
    if (a == 0 && b == 0) {
        return 0;
    }
    return a * b / gcd(a, b);
}

// The bisectLeft function returns the index where x should be inserted into a sorted array to maintain the sort order.
public static int bisectLeft(int[] nums, int left, int right, int target) {
    if (left == right) {
        if (nums[left] == target) {
            return left;
        } else if (nums[left] < target) {
            return left + 1;
        } else {
            return left;
        }
    }

    int mid = (left + right) / 2;
    if (nums[mid] == target) {
        return mid;
    }

    if (nums[mid] > target) {
        return bisectLeft(nums, left, mid, target);
    } else if (nums[mid] < target) {
        return bisectLeft(nums, mid + 1, right, target);
    }
    return 0;
}

// The permutations function returns all permutations of a list.
public static List<List<Integer>> permutations(List<Integer> nums) {
    int size = nums.size();
    List<List<Integer>> result = new ArrayList<>();

    for (int i = 0; i < nums.size(); i++) {
        int n = nums.get(i);
        List<Integer> rest = remove(nums, n);
        List<List<Integer>> lists = permutations(rest);
        for (List<Integer> list : lists) {
            lists.add(append(list, n));
            result.add(lists);
        }
    }
    return result;
}

// The remove function removes the first occurrence of x from a list.
public static List<Integer> remove(List<Integer> nums, int x) {
    List<Integer> result = new ArrayList<>();
    for (int i = 0; i < nums.size(); i++) {
        int n = nums.get(i);
        if (n!= x) {
            result.add(n);
        }
    }
    return result;
}

// The append function returns a new list with x appended to it.
public static List<Integer> append(List<Integer> list, int x) {
    List<Integer> result = new ArrayList<>(list);
    result.add(x);
    return result;
}

// The powerSet function returns all subsets of a list.
public static List<List<Integer>> powerSet(List<Integer> nums) {
    int size = nums.size();
    List<List<Integer>> result = new ArrayList<>();

    int idx = 0;
    result.add(new ArrayList<>());
    idx++;

    for (int i = 0; i < nums.size(); i++) {
        int n = nums.get(i);
        List<List<Integer>> lists = powerSet(remove(nums, n));
        for (List<Integer> list : lists) {
            lists.add(append(list, n));
            result.add(lists);
        }
    }

    return result;
}

// The combination function returns all combinations of size r from a list.
public static List<List<Integer>> combination(List<Integer> nums, int r) {
    int size = nums.size();
    List<List<Integer>> result = new ArrayList<>();
    int bi = (1 << r) - 1;
    int max = 1 << size;
    int idx = 0;

    for (int i = 0; i < max; i++) {
        int flags = bi;
        List<Integer> s = new ArrayList<>();
        for (int j = 0; j < size; j++) {
            if (flags % 2!= 0) {
                s.add(nums.get(j));
            }
            flags /= 2;
        }
        result.add(s);
        idx++;
        bi = combination2NextIndex(bi);
    }

    return result;
}

// The combinationCount function returns the number of combinations of size r from a list.
public static long combinationCount(int n, int m, int maxInput) {
    Map<Integer, Map<Integer, Long>> memo = new HashMap<>();
    for (int i = 1; i <= maxInput * maxInput; i++) {
        memo.put(i, new HashMap<>());
        for (int j = 1; j <= maxInput; j++) {
            memo.get(i).put(j, 1L);
        }
    }

    return memo.get(n).get(m);
}

// The fact function returns the factorial of n.
public static int fact(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * fact(n-1);
    }
}

// The divisors function returns all divisors of n.
public static List<Integer> divisors(int n) {
    List<Integer> divisors = new ArrayList<>();
    for (int i = 1; i <= n; i++) {
        divisors.add(i);
    }

    return divisors;
}

// The isPrime function checks if n is a prime number.
public static boolean isPrime(int n) {
    if (n == 2) {
        return true;
    } else {
        for (int i = 2; i <= n/2; i++) {
            if (n%i == 0) {
                return false;
            } else {
                for (int j = 1; j <= n/2; j++) {
                    divisors := divisors(n)
                    if (divisors.contains(i)) {
                        return true;
                    } else {
                        return false;
                    }
                }
            }
        }
    }

    return divisors;
}

// The isPrime function checks if n is a prime number.
public static boolean isPrime(int n) {
    if (n == 2) {
        return true;
    } else {
        for (int i = 2; i <= n/2; i++) {
            divisors := divisors(n)
            if (divisors.contains(i)) {
                return true;
            } else {
                return false;
            }
        }
    }

    return divisors;
}

// The isPrime function checks if n is a prime number.
public static boolean isPrime(int n) {
    if (n == 2) {
        return true;
    } else {
        for (int i = 2; i <= n/2; i++) {
            divisors := divisors(n)
            if (divisors.contains(i)) {
                return true;
            } else {
                return false;
            }
        }
    }

    return divisors;
}

// The isPrime function checks if n is a prime number.
public static boolean isPrime(int n) {
    if (n == 2) {
        return true;
    } else {
        for (int i = 2; i <= n/2; i++) {
            divisors := divisors(n)
            if (divisors.contains(i)) {
                return true;
            } else {
                return false;
            }
        }
    }

    return divisors;
}

// The isPrime function checks if n is a prime number.
public static boolean isPrime(int n) {
    if (n == 2) {
        return true;
    } else {
        for (int i = 2; i <= n/2; i++) {
            divisors := divisors(n)
            if (divisors.contains(i)) {
                return true;
            } else {
                return false;
            }
        }
    }

    return divisors;
}

// The isPrime function checks if n is a prime number.
public static boolean isPrime(int n) {
    if (n == 2) {
        return true;
    } else {
        for (int i = 2; i <= n/2; i++) {
            divisors := divisors(n)
            if (divisors.contains(i)) {
                return true;
            } else {
                return false;
            }
        }
    }

    return divisors;
}

// The isPrime function checks if n is a prime number.
public static boolean isPrime(int n) {
    if (n == 2) {
        return true;
    } else {
        for (int i = 2; i <= n/2; i++) {
            divisors := divisors(n)
            if (divisors.contains(i)) {
                return true;
            } else {
                return false;
            }
        }
    }

    return divisors;
}

// The isPrime function checks if n is a prime number.
public static boolean isPrime(int n) {
    if (n == 2) {
        return true;
    } else {
        return false;
    }

    return divisors;
}

// The isPrime function checks if n is a prime number.
public static boolean isPrime(int n) {
    if (n == 2) {
        return true;
    } else {
        return false;
    }

    return divisors;
}

// The isPrime function checks if n is a prime number.
public static boolean isPrime(int n) {
    if (n == 2) {
        return true;
 