
package main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());

		int[] aa = new int[n];

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) {
			aa[i] = Integer.parseInt(st.nextToken());
		}

		int[] cumsum = cumsum(aa);

		//System.out.println(Arrays.toString(cumsum));
		int ans = 2020202020;
		for (int i = 1; i < cumsum.length - 1; i++) {
			ans = Math.min(ans, Math.abs(cumsum[cumsum.length - 1] - cumsum[i] - (cumsum[i] - cumsum[0])));
		}

		System.out.println(ans);

	}

	public static int[] cumsum(int[] a) {
		int[] sums = new int[a.length + 1];
		sums[0] = 0;
		for (int i = 0; i < a.length; i++) {
			sums[i + 1] = sums[i] + a[i];
		}
		return sums;
	}

	public static int min(int... nums) {
		int min = nums[0];
		for (int i = 1; i < nums.length; i++) {
			if (nums[i] < min) {
				min = nums[i];
			}
		}
		return min;
	}

	public static int max(int... nums) {
		int max = nums[0];
		for (int i = 1; i < nums.length; i++) {
			if (nums[i] > max) {
				max = nums[i];
			}
		}
		return max;
	}

	public static int[] sortAsc(int[] a) {
		Arrays.sort(a);
		return a;
	}

	public static int[] sortDesc(int[] a) {
		Arrays.sort(a);
		return a;
	}

	public static int gcd(int a, int b) {
		if (b == 0) {
			return a;
		}
		return gcd(b, a % b);
	}

	public static int lcm(int a, int b) {
		if (a == 0 && b == 0) {
			return 0;
		}
		return a * b / gcd(a, b);
	}

	public static int[] permutations(int[] nums) {
		int n = nums.length;
		if (n == 0) {
			return new int[] {};
		}
		List<int[]> ans = new ArrayList<>();

		for (int i = 0; i < nums.length; i++) {
			int[] rest = remove(nums, nums[i]);
			int[][] lists = permutations(rest);
			if (lists.length == 0) {
				lists = new int[][] { new int[] {} };
			}

			for (int j = 0; j < lists.length; j++) {
				int[] list = lists[j];
				list = Arrays.copyOf(list, list.length + 1);
				list[list.length - 1] = nums[i];
				ans.add(list);
			}
		}
		return ans.toArray(new int[ans.size()][]);
	}

	public static int[] remove(int[] nums, int target) {
		List<Integer> result = new ArrayList<>();
		for (int i = 0; i < nums.length; i++) {
			if (nums[i] != target) {
				result.add(nums[i]);
			}
		}
		return result.stream().mapToInt(Integer::intValue).toArray();
	}

	public static int[][] powerSet(int[] nums) {
		int n = nums.length;
		int size = (int) Math.pow(2, n);
		int[][] result = new int[size][];

		int idx = 0;
		result[idx] = new int[] {};
		idx++;

		for (int i = 0; i < nums.length; i++) {
			int max = idx;
			for (int j = 0; j < max; j++) {
				result[idx] = copyAndAppend(result[j], nums[i]);
				idx++;
			}
		}

		return result;
	}

	public static int[] copyAndAppend(int[] nums, int n) {
		int[] dst = new int[nums.length + 1];
		System.arraycopy(nums, 0, dst, 0, nums.length);
		dst[nums.length] = n;
		return dst;
	}

	public static int[][] combination(int[] nums, int k) {
		int n = nums.length;
		int size = (int) Math.pow(2, n);
		int[][] result = new int[combinationCount(n, k, 1000000000)][];

		int idx = 0;
		result[idx] = new int[] {};
		idx++;

		for (int i = 0; i < nums.length; i++) {
			int max = idx;
			for (int j = 0; j < max; j++) {
				result[idx] = copyAndAppend(result[j], nums[i]);
				idx++;
			}
		}

		return result;
	}

	public static int combinationCount(int n, int k, int maxInput) {
		Map<Integer, Map<Integer, Integer>> memo = new HashMap<>();
		for (int i = 1; i <= maxInput * maxInput; i++) {
			memo.put(i, new HashMap<>());
		}
		return combinationCount(n, k, memo);
	}

	public static int combinationCount(int n, int k, Map<Integer, Map<Integer, Integer>> memo) {
		if (n == k || k == 0) {
			return 1;
		}

		Integer left = memo.get(n - 1).get(k - 1);
		Integer right = memo.get(n - 1).get(k);

		if (left != null && right != null) {
			return left + right;
		}

		if (left != null) {
			right = combinationCount(n - 1, k, memo);
			memo.get(n - 1).put(k, right);
			return left + right;
		}

		if (right != null) {
			left = combinationCount(n - 1, k - 1, memo);
			memo.get(n - 1).put(k - 1, left);
			return left + right;
		}

		left = combinationCount(n - 1, k - 1, memo);
		right = combinationCount(n - 1, k, memo);
		memo.get(n - 1).put(k - 1, left);
		memo.get(n - 1).put(k, right);
		return left + right;
	}

	public static int fact(int n) {
		if (n == 0) {
			return 1;
		} else {
			return n * fact(n - 1);
		}
	}

	public static int[] divisors(int n) {
		Map<Integer, Boolean> divisors = new HashMap<>();
		for (int i = 1; i <= (int) Math.sqrt(n) + 1; i++) {
			if (n % i == 0) {
				divisors.put(i, true);
				if (i != n) {
					divisors.put(n / i, true);
				}
			}
		}
		return divisors.keySet().stream().mapToInt(Integer::intValue).toArray();
	}

	// 