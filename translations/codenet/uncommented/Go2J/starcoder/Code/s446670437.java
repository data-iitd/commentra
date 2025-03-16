package main;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] nums1 = new int[6];
        int[] nums2 = new int[6];
        for (int i = 0; i < 6; i++) {
            nums1[i] = sc.nextInt();
        }
        for (int i = 0; i < 6; i++) {
            nums2[i] = sc.nextInt();
        }
        boolean flag = false;
        for (int i = 0; i <= 2; i++) {
            for (int j = 0; j <= 2; j++) {
                for (int k = 0; k < 4; k++) {
                    for (int l = 0; l < 2; l++) {
                        int[] nums3 = new int[6];
                        for (int m = 0; m < 6; m++) {
                            nums3[m] = nums2[m];
                        }
                        rotate(nums3, k, i);
                        roll(nums3, l, j);
                        if (isEqual(nums1, nums3)) {
                            flag = true;
                            break;
                        }
                    }
                    if (flag) {
                        break;
                    }
                }
                if (flag) {
                    break;
                }
            }
            if (flag) {
                break;
            }
        }
        if (flag) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }

    private static void rotate(int[] nums, int direction, int times) {
        times %= 4;
        switch (direction) {
            case 0:
                for (int i = 0; i < times; i++) {
                    int tmp = nums[0];
                    nums[0] = nums[2];
                    nums[2] = nums[5];
                    nums[5] = nums[3];
                    nums[3] = tmp;
                }
                break;
            case 1:
                for (int i = 0; i < times; i++) {
                    int tmp = nums[0];
                    nums[0] = nums[3];
                    nums[3] = nums[5];
                    nums[5] = nums[2];
                    nums[2] = tmp;
                }
                break;
            case 2:
                for (int i = 0; i < times; i++) {
                    int tmp = nums[0];
                    nums[0] = nums[1];
                    nums[1] = nums[5];
                    nums[5] = nums[4];
                    nums[4] = tmp;
                }
                break;
            case 3:
                for (int i = 0; i < times; i++) {
                    int tmp = nums[0];
                    nums[0] = nums[4];
                    nums[4] = nums[5];
                    nums[5] = nums[1];
                    nums[1] = tmp;
                }
                break;
        }
    }

    private static void roll(int[] nums, int direction, int times) {
        times %= 4;
        switch (direction) {
            case 0:
                for (int i = 0; i < times; i++) {
                    int tmp = nums[3];
                    nums[3] = nums[1];
                    nums[1] = nums[2];
                    nums[2] = nums[4];
                    nums[4] = tmp;
                }
                break;
            case 1:
                for (int i = 0; i < times; i++) {
                    int tmp = nums[3];
                    nums[3] = nums[4];
                    nums[4] = nums[1];
                    nums[1] = nums[2];
                    nums[2] = tmp;
                }
                break;
        }
    }

    private static boolean isEqual(int[] nums1, int[] nums2) {
        for (int i = 0; i < 6; i++) {
            if (nums1[i]!= nums2[i]) {
                return false;
            }
        }
        return true;
    }
}

