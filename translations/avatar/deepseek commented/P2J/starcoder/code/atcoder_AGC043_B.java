import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Read an integer n and a list of integers from the input
        int n = sc.nextInt();
        List<Integer> nums = new ArrayList<Integer>();
        for (int i = 0; i < n; i++) {
            nums.add(sc.nextInt() - 1);
        }
        
        // If the list does not contain the number 1, halve each number in the list and set no_one to True
        boolean no_one = false;
        if (!nums.contains(1)) {
            for (int i = 0; i < nums.size(); i++) {
                nums.set(i, nums.get(i) / 2);
            }
            no_one = true;
        }
        
        // Initialize is_odd to False
        boolean is_odd = false;
        
        // Iterate over the list nums, checking the parity of nCr for each element and the corresponding index
        for (int i = 0; i < nums.size(); i++) {
            if (!parity_of_nCr(n - 1, i) && (nums.get(i) & 1) == 1) {
                is_odd ^= true;
            }
        }
        
        // If is_odd is False, print 0; otherwise, print 1 << no_one (which is equivalent to 2 ** no_one)
        if (!is_odd) {
            System.out.println(0);
        } else {
            System.out.println(1 << no_one);
        }
    }
    
    // Calculate the number of factors of 2 in the factorial of n
    public static int twos_in_factorial(int n) {
        String s = Integer.toBinaryString(n);
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '1') {
                count++;
            }
        }
        return n - count;
    }
    
    // Determine the parity (odd or even) of the binomial coefficient nCr
    public static boolean parity_of_nCr(int n, int i) {
        int f = twos_in_factorial(n);
        return f - f(n - i) - f(i) > 0;
    }
}

