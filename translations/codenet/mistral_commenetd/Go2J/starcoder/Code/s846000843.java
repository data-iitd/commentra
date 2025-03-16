package main;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] aa = new int[n];
		for (int i = 0; i < n; i++) {
			aa[i] = sc.nextInt();
		}
		int[] cumsum = CumSum(aa);
		int ans = 2020202020;
		for (int i = 1; i < cumsum.length-1; i++) {
			int diff1 = Math.abs(cumsum[cumsum.length-1] - cumsum[i]);
			int diff2 = cumsum[i] - cumsum[0];
			ans = Math.min(ans, Math.min(diff1, diff2));
		}
		System.out.println(ans);
	}

	public static int[] CumSum(int[] aa) {
		int[] cumsum = new int[aa.length+1];
		cumsum[0] = 0;
		for (int i = 0; i < aa.length; i++) {
			cumsum[i+1] = cumsum[i] + aa[i];
		}
		return cumsum;
	}
}

// The CumSum function computes the cumulative sum of an integer slice.
public static int[] CumSum(int[] aa) {
	int[] cumsum = new int[aa.length+1];
	cumsum[0] = 0;
	for (int i = 0; i < aa.length; i++) {
		cumsum[i+1] = cumsum[i] + aa[i];
	}
	return cumsum;
}

// The BisectLeft function returns the index where x should be inserted into a sorted slice to maintain the sort order.
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

// The Permutations function returns all permutations of a slice.
public static List<List<Integer>> Permutations(int[] nums) {
	int size = nums.length;
	List<List<Integer>> result = new ArrayList<List<Integer>>();
	for (int n : nums) {
		List<Integer> rest = remove(nums, n);
		List<List<Integer>> lists = Permutations(rest);
		for (List<Integer> list : lists) {
			for (int i = 0; i < list.size(); i++) {
				list.add(i, n);
			}
			result.add(list);
		}
	}
	return result;
}

// The remove function removes the first occurrence of x from a slice.
public static List<Integer> remove(int[] nums, int x) {
	List<Integer> result = new ArrayList<Integer>();
	for (int n : nums) {
		if (n!= x) {
			result.add(n);
		}
	}
	return result;
}

// The PowerSet function returns all subsets of a slice.
public static List<List<Integer>> PowerSet(int[] nums) {
	int size = nums.length;
	List<List<Integer>> result = new ArrayList<List<Integer>>();
	result.add(new ArrayList<Integer>());
	int idx = 0;
	for (int n : nums) {
		int max = idx;
		for (int i = 0; i < max; i++) {
			List<Integer> dst = copyAndAppend(result.get(i), n);
			result.add(dst);
			idx++;
		}
	}
	return result;
}

// The copyAndAppend function returns a copy of x with y appended to it.
public static List<Integer> copyAndAppend(List<Integer> x, int y) {
	List<Integer> dst = new ArrayList<Integer>(x.size()+1);
	dst.addAll(x);
	dst.add(y);
	return dst;
}

// The Combination function returns all combinations of size r from a slice.
public static List<List<Integer>> Combination(int[] nums, int r) {
	int size = nums.length;
	List<List<Integer>> result = new ArrayList<List<Integer>>();
	int bi = (1 << r) - 1;
	int max = 1 << size;
	int idx = 0;
	for (int i = 0; i < size; i++) {
		if (bi%2!= 0) {
			result.add(new ArrayList<Integer>());
		}
		bi /= 2;
	}
	for (int i = 0; i < size; i++) {
		if (bi%2!= 0) {
			result.get(idx).add(nums[i]);
		}
		bi /= 2;
		idx++;
	}
	for (int i = 0; i < size; i++) {
		if (bi%2!= 0) {
			result.get(idx).add(nums[i]);
		}
		bi /= 2;
		idx++;
	}
	for (int i = 0; i < size; i++) {
		if (bi%2!= 0) {
			result.get(idx).add(nums[i]);
		}
		bi /= 2;
		idx++;
	}
	for (int i = 0; i < size; i++) {
		if (bi%2!= 0) {
			result.get(idx).add(nums[i]);
		}
		bi /= 2;
		idx++;
	}
	for (int i = 0; i < size; i++) {
		if (bi%2!= 0) {
			result.get(idx).add(nums[i]);
		}
		bi /= 2;
		idx++;
	}
	for (int i = 0; i < size; i++) {
		if (bi%2!= 0) {
			result.get(idx).add(nums[i]);
		}
		bi /= 2;
		idx++;
	}
	for (int i = 0; i < size; i++) {
		if (bi%2!= 0) {
			result.get(idx).add(nums[i]);
		}
		bi /= 2;
		idx++;
	}
	for (int i = 0; i < size; i++) {
		if (bi%2!= 0) {
			result.get(idx).add(nums[i]);
		}
		bi /= 2;
		idx++;
	}
	for (int i = 0; i < size; i++) {
		if (bi%2!= 0) {
			result.get(idx).add(nums[i]);
		}
		bi /= 2;
		idx++;
	}
	for (int i = 0; i < size; i++) {
		if (bi%2!= 0) {
			result.get(idx).add(nums[i]);
		}
		bi /= 2;
		idx++;
	}
	for (int i = 0; i < size; i++) {
		if (bi%2!= 0) {
			result.get(idx).add(nums[i]);
		}
		bi /= 2;
		idx++;
	}
	for (int i = 0; i < size; i++) {
		if (bi%2!= 0) {
			result.get(idx).add(nums[i]);
		}
		bi /= 2;
		idx++;
	}
	for (int i = 0; i < size; i++) {
		if (bi%2!= 0) {
			result.get(idx).add(nums[i]);
		}
		bi /= 2;
		idx++;
	}
	for (int i = 0; i < size; i++) {
		if (bi%2!= 0) {
			result.get(idx).add(nums[i]);
		}
		bi /= 2;
		idx++;
	}
	for (int i = 0; i < size; i++) {
		if (bi%2!= 0) {
			result.get(idx).add(nums[i]);
		}
		bi /= 2;
		idx++;
	}
	for (int i = 0; i < size; i++) {
		if (bi%2!= 0) {
			result.get(idx).add(nums[i]);
		}
		bi /= 2;
		idx++;
	}
	for (int i = 0; i < size; i++) {
		if (bi%2!= 0) {
			result.get(idx).add(nums[i]);
		}
		bi /= 2;
		idx++;
	}
	for (int i = 0; i < size; i++) {
		if (bi%2!= 0) {
			result.get(idx).add(nums[i]);
		}
		bi /= 2;
		idx++;
	}
	for (int i = 0; i < size; i++) {
		if (bi%2!= 0) {
			result.get(idx).add(nums[i]);
		}
		bi /= 2;
		idx++;
	}
	for (int i = 0; i < size; i++) {
		if (bi%2!= 0) {
			result.get(idx).add(nums[i]);
		}
		bi /= 2;
		idx++;
	}
	for (int i = 0; i < size; i++) {
		if (bi%2!= 0) {
			result.get(idx).add(nums[i]);
		}
		bi /= 2;
		idx++;
	}
	for (int i = 0; i < size; i++) {
		if (bi%2!= 0) {
			result.get(idx).add(nums[i]);
		}
		bi /= 2;
		idx++;
	}
	for (int i = 0; i < size; i++) {
		if (bi%2!= 0) {
			result.get(idx).add(nums[i]);
		}
		bi /= 2;
		idx++;
	}
	for (int i = 0; i < size; i++) {
		if (bi%2!= 0) {
			result.get(idx).add(nums[i]);
		}
		bi /= 2;
		idx++;
	}
	for (int i = 0; i < size; i++) {
		if (bi%2!= 0) {
			result.get(idx).add(nums[i]);
		}
		bi /= 2;
		idx++;
	}
	for (int i = 0; i < size; i++) {
		if (bi%2!= 0) {
			result.get(idx).add(nums[i]);
		}
		bi /= 2;
		idx++;
	}
	for (int i = 0; i < size; i++) {
		if (bi%2!= 0) {
			result.get(idx).add(nums[i]);
		}
		bi /= 2;
		idx++;
	}
	for (int i = 0; i < size; i++) {
		if (bi%2!= 0) {
			result.get(idx).add(nums[i]);
		}
		bi /= 2;
		idx++;
	}
	for (int i = 0; i < size; i++) {
		if (bi%2!= 0) {
			result.get(idx).add(nums[i]);
		}
		bi /= 2;
		idx++;
	}
	for (int i = 0; i < size; i++) {
		if (bi%2!= 0) {
			result.get(idx).add(nums[i]);
		}
		bi /= 2;
		idx++;
	}
	for (int i = 0; i < size; i++) {
		if (bi%2!= 0) {
			result.get(idx).add(nums[i]);
		}
		bi /= 2;
		idx++;
	}
	for (int i = 0; i < size; i++) {
		if (bi%2!= 0) {
			result.get(idx).add(nums[i]);
		}
		bi /= 2;
		idx++;
	}
	for (int i = 0; i < size; i++) {
		if (bi%2!= 0) {
			result.get(idx).add(nums[i]);
		}
		bi /= 2;
		idx++;
	}
	for (int i = 0; i < size; i++) {
		if (bi%2!= 0) {
			result.get(idx).add(nums[i]);
		}
		bi /= 2;
		idx++;
	}
	for (int i = 0; i < size; i++) {
		if (bi%2!= 0) {
			result.get(idx).add(nums[i]);
		}
		bi /= 2;
		idx++;
	}
	for (int i = 0; i < size; i++) {
		if (bi%2!= 0) {
			result.get(idx).add(nums[i]);
		}
		bi /= 2;
		idx++;
	}
	for (int i = 0; i < size; i++) {
		if (bi%2!= 0) {
			result.get(idx).add(nums[i]);
		}
		bi /= 2;
		idx++;
	}
	for (int i = 0; i < size; i++) {
		if (bi%2!= 0) {
			result.get(idx).add(nums[i]);
		}
		bi /= 2;
		idx++;
	}
	for (int i = 0; i < size; i++) {
		if (bi%2!= 0) {
			result.get(idx).add(nums[i]);
		}
		bi /= 2;
		idx++;
	}
	for (int i = 0; i < size; i++) {
		if (bi%2!= 0) {
			result.get(idx).add(nums[i]);
		}
		bi /= 2;
		idx++;
	}
	for (int i = 0; i < size; i++) {
		if (bi%2!= 0) {
			result.get(idx).add(nums[i]);
		}
		bi /= 2;
		idx++;
	}
	for (int i = 0; i < size; i++) {
		if (bi%2!= 0) {
			result.get(idx).add(nums[i]);
		}
		bi /= 2;
		idx++;
	}
	for (int i = 0; i < size; i++) {
		if (bi%2!= 0) {
			result.get(idx).add(nums[i]);
		}
		bi /= 2;
		idx++;
	}
	for (int i = 0; i < size; i++) {
		if (bi%2!= 0) {
			result.get(idx).add(nums[i]);
		}
		bi /= 2;
		idx++;
	}
	for (int i = 0; i < size; i++) {
		if (bi%2!= 0) {
			result.get(idx).add(nums[i]);
		}
		bi /= 2;
		idx++;
	}
	for (int i = 0; i < size; i++) {
		if (bi%2!= 0) {
			result.get(idx).add(nums[i]);
		}
		bi /= 2;
		idx++;
	}
	for (int i = 0; i < size; i++) {
		if (bi%2!= 0) {
			result.get(idx).add(nums[i]);
		}
		bi /= 2;
		idx++;
	}
	for (int i = 0; i < size; i++) {
		if (bi%2!= 0) {
			result.get(idx).add(nums[i]);
		}
		bi /= 2;
		idx++;
	}
	for (int i = 0; i < size; i++) {
		if (bi%2!= 0) {
			result.get(idx).add(nums[i]);
		}
		bi /= 2;
		idx++;
	}
	for (int i = 0; i < size; i++) {
		if (bi%2!= 0) {
			result.get(idx).add(nums[i]);
		}
		bi /= 2;
		idx++;
	}
	for (int i = 0; i < size; i++) {
		if (bi%2!= 0) {
			result.get(idx).add(nums[i]);
		}
		bi /= 2;
		idx++;
	}
	for (int i = 0; i < size; i++) {
		if (bi%2!= 0) {
			result.get(idx).add(nums[i]);
		}
		bi /= 2;
		idx++;
	}
	for (int i = 0; i < size; i++) {
		if (bi%2!= 0) {
			result.get(idx).add(nums[i]);
		}
		bi /= 2;
		idx++;
	}
	for (int i = 0; i < size; i++) {
		if (bi%2!= 0) {
			result.get(idx).add(nums[i]);
		}
		bi /= 2;
		idx++;
	}
	for (int i = 0; i < size; i++) {
		if (bi%2!= 0) {
			result.get(idx).add(nums[i]);
		}
		bi /= 2;
		idx++;
	}
	for (int i = 0; i < size; i++) {
		if (bi%2!= 0) {
			result.get(idx).add(nums[i]);
		}
		bi /= 2;
		idx++;
	}
	for (int i = 0; i < size; i++) {
		if (bi%2!= 0) {
			result.get(idx).add(nums[i]);
		}
		bi /= 2;
		idx++;
	}
	for (int i = 0; i < size; i++) {
		if (bi%2!= 0) {
			result.get(idx).add(nums[i]);
		}
		bi /= 2;
		idx++;
	}
	for (int i = 0; i < size; i++) 