package main;

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int n = Integer.parseInt(br.readLine());

		int[] aa = new int[n];

		for (int i = 0; i < n; i++) {
			aa[i] = Integer.parseInt(br.readLine());
		}

		int[] cumsum = CumSum(aa);

		//System.out.println(Arrays.toString(cumsum));
		int ans = 2020202020;
		for (int i = 1; i < cumsum.length-1; i++) {
			ans = Math.min(ans, Math.abs(cumsum[cumsum.length-1]-cumsum[i]-(cumsum[i]-cumsum[0])));
		}

		bw.write(Integer.toString(ans) + "\n");

		bw.flush();
		bw.close();
	}

	public static int[] CumSum(int[] nums) {
		int[] sums = new int[nums.length+1];
		sums[0] = 0;
		for (int i = 0; i < nums.length; i++) {
			sums[i+1] = sums[i] + nums[i];
		}
		return sums;
	}

	public static int Abs(int a) {
		if (a >= 0) {
			return a;
		} else {
			return -a;
		}
	}

	public static int Pow(int p, int q) {
		return (int) Math.pow(p, q);
	}

	public static int Min(int... nums) {
		if (nums.length == 0) {
			throw new IllegalArgumentException("function min() requires at least one argument.");
		}
		int res = nums[0];
		for (int i = 0; i < nums.length; i++) {
			res = Math.min(res, nums[i]);
		}
		return res;
	}

	public static int Max(int... nums) {
		if (nums.length == 0) {
			throw new IllegalArgumentException("function max() requires at least one argument.");
		}
		int res = nums[0];
		for (int i = 0; i < nums.length; i++) {
			res = Math.max(res, nums[i]);
		}
		return res;
	}

	public static int[] SortAsc(int[] a) {
		Arrays.sort(a);
		return a;
	}

	public static int[] SortDesc(int[] a) {
		Arrays.sort(a);
		Arrays.sort(a, Collections.reverseOrder());
		return a;
	}

	public static int GCD(int a, int b) {
		if (b == 0) {
			return a;
		}
		return GCD(b, a%b);
	}

	public static int LCM(int a, int b) {
		if (a == 0 && b == 0) {
			return 0;
		}
		return a * b / GCD(a, b);
	}

	public static int BisectLeft(int[] nums, int left, int right, int target) {
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
			return BisectLeft(nums, left, mid, target);
		} else if (nums[mid] < target) {
			return BisectLeft(nums, mid+1, right, target);
		}
		return 0;
	}

	public static List<List<Integer>> Permutations(int[] nums) {
		int n = nums.length;
		if (n == 0) {
			return new ArrayList<>();
		}
		List<List<Integer>> ans = new ArrayList<>();

		for (int i = 0; i < n; i++) {
			int[] rest = remove(nums, nums[i]);
			List<List<Integer>> lists = Permutations(rest);
			if (lists.size() == 0) {
				lists = new ArrayList<>();
				lists.add(new ArrayList<>());
			}

			for (List<Integer> list : lists) {
				list.add(nums[i]);
				ans.add(list);
			}
		}
		return ans;
	}

	public static int[] remove(int[] nums, int target) {
		int[] result = new int[nums.length-1];
		int idx = 0;
		for (int i = 0; i < nums.length; i++) {
			if (nums[i]!= target) {
				result[idx] = nums[i];
				idx++;
			}
		}
		return result;
	}

	public static List<List<Integer>> PowerSet(int[] nums) {
		int size = (int) Math.pow(2, nums.length);
		List<List<Integer>> result = new ArrayList<>(size);

		result.add(new ArrayList<>());
		int idx = 1;

		for (int i = 0; i < nums.length; i++) {
			int max = idx;
			for (int j = 0; j < max; j++) {
				List<Integer> dst = new ArrayList<>(result.get(j));
				dst.add(nums[i]);
				result.add(dst);
			}
			idx *= 2;
		}

		return result;
	}

	public static List<List<Integer>> Combination(int[] nums, int k) {
		int size = nums.length;
		List<List<Integer>> result = new ArrayList<>(CombinationCount(size, k));
		int bi = (1 << k) - 1;
		int max = 1 << size;
		int idx = 0;

		for (int i = 0; i < max; i++) {
			if (bi < max) {
				List<Integer> s = new ArrayList<>();
				for (int j = 0; j < size; j++) {
					if (bi%2!= 0) {
						s.add(nums[j]);
					}
					bi /= 2;
				}
				result.add(s);
				idx++;
			}
		}
		return result;
	}

	// CombinationCount はnCmを計算する関数。メモ化を使って計算量を削減する。
	public static int CombinationCount(int n, int m, int maxInput) {
		Map<Integer, Map<Integer, Integer>> memo = new HashMap<>();
		for (int i = 1; i <= maxInput*maxInput; i++) {
			memo.put(i, new HashMap<>());
		}
		return combinationCount(n, m, memo);
	}
	public static int combinationCount(int n, int m, Map<Integer, Map<Integer, Integer>> memo) {
		if (n == m || m == 0) {
			return 1;
		}

		Integer left = memo.get(n-1).get(m-1);
		Integer right = memo.get(n-1).get(m);

		if (left!= null && right!= null) {
			return left + right;
		}

		if (left!= null) {
			right = combinationCount(n-1, m, memo);
			memo.get(n-1).put(m, right);
			return left + right;
		}

		if (right!= null) {
			left = combinationCount(n-1, m-1, memo);
			memo.get(n-1).put(m-1, left);
			return left + right;
		}

		left = combinationCount(n-1, m-1, memo);
		right = combinationCount(n-1, m, memo);
		memo.get(n-1).put(m-1, left);
		memo.get(n-1).put(m, right);
		return left + right;
	}

	public static int Fact(int n) {
		if (n == 0) {
			return 1;
		} else {
			return n * Fact(n-1);
		}
	}

	public static int[] Divisors(int n) {
		Map<Integer, Boolean> divisors = new HashMap<>();
		for (int i = 1; i < (int) Math.sqrt(n)+1; i++) {
			if (n%i == 0) {
				divisors.put(i, true);
				if (i!= n) {
					divisors.put(n/i, true);
				}
			}

		}
		int[] ans = new int[divisors.size()];
		int idx = 0;
		for (int k : divisors.keySet()) {
			ans[idx] = k;
			idx++;
		}
		return ans;
	}
}

