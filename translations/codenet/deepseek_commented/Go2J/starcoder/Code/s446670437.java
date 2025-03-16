
package main;

import java.util.Scanner;

/*
展開図の展開の仕方を固定して、回転動作によってどのように展開図の数字が移るかを記録する。
展開図は次の通り。手前の目2番を中心に据える展開の仕方。
         ___
    ____|_1_|_______
    |_4_|_2_|_3_|_5_|
        |_6_|

サイコロの状態は上面と前面を指定することで一意に決定される。それぞれを指定された目に揃えて、
展開図の3番を記録。
入力された二つのサイコロについて上面前面を揃えた上で右側面の値を比較することで判定。
で、できるかと思ったが、サイコロの各面の数字がすべて異なるという制約は今回の問題にはないので、
この判定方法は不完全。

よって、力ずくで全通り調べる。
*/

// Dice represents a die with six faces
class Dice {
	int[] nums; // Slice of integers representing the faces of the die

	// Constructor
	public Dice() {
		nums = new int[6];
	}

	// rotate rotates the die in a specified direction a given number of times
	public void rotate(String direction, int times) {
		times %= 4; // Normalize the number of rotations to 4 or less
		switch (direction) {
		case "W":
			for (int i = 0; i < times; i++) {
				int tmp = nums[0];
				nums[0] = nums[2];
				nums[2] = nums[5];
				nums[5] = nums[3];
				nums[3] = tmp;
			}
			break;
		case "E":
			for (int i = 0; i < times; i++) {
				int tmp = nums[0];
				nums[0] = nums[3];
				nums[3] = nums[5];
				nums[5] = nums[2];
				nums[2] = tmp;
			}
			break;
		case "N":
			for (int i = 0; i < times; i++) {
				int tmp = nums[0];
				nums[0] = nums[4];
				nums[4] = nums[5];
				nums[5] = nums[1];
				nums[1] = tmp;
			}
			break;
		case "S":
			for (int i = 0; i < times; i++) {
				int tmp = nums[5];
				nums[5] = nums[1];
				nums[1] = nums[0];
				nums[0] = nums[4];
				nums[4] = tmp;
			}
			break;
		}
	}

	// roll rolls the die in a specified direction a given number of times
	public void roll(String direction, int times) {
		times %= 4; // Normalize the number of rolls to 4 or less
		switch (direction) {
		case "R":
			for (int i = 0; i < times; i++) {
				int tmp = nums[3];
				nums[3] = nums[1];
				nums[1] = nums[2];
				nums[2] = nums[4];
				nums[4] = tmp;
			}
			break;
		case "L":
			for (int i = 0; i < times; i++) {
				int tmp = nums[3];
				nums[3] = nums[4];
				nums[4] = nums[2];
				nums[2] = nums[1];
				nums[1] = tmp;
			}
			break;
		}
	}

	// printStatus prints the current status of the die in a formatted string
	public void printStatus() {
		System.out.println("	　　　 _ _ _ _");
		System.out.println("     _ _ _|_%3d_|_ _ _ _ _ _");
		System.out.println("    |_%3d_|_%3d_|_%3d_|_%3d_|");
		System.out.println(" 　       |_%3d_|");
	}

	// getIndex returns the index of the target number in the slice
	public int getIndex(int target) {
		for (int i = 0; i < nums.length; i++) {
			if (target == nums[i]) {
				return i;
			}
		}
		return -1;
	}

	// isEqual checks if two Dice objects have the same faces
	public boolean isEqual(Dice other) {
		for (int i = 0; i < nums.length; i++) {
			if (nums[i]!= other.nums[i]) {
				return false;
			}
		}
		return true;
	}
}

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Dice dice1 = new Dice();
		Dice dice2 = new Dice();
		for (int i = 0; i < 6; i++) {
			dice1.nums[i] = sc.nextInt();
		}
		for (int i = 0; i < 6; i++) {
			dice2.nums[i] = sc.nextInt();
		}

		String[] directionOrder = {"N", "S", "W", "E"};
		String[] rollOrder = {"R", "L"};
		boolean flag = false;

		for (int i = 0; i <= 2; i++) {
			for (int j = 0; j <= 2; j++) {
				for (String direction : directionOrder) {
					for (String roll : rollOrder) {
						Dice tmp = new Dice();
						tmp.nums = dice2.nums.clone();
						tmp.rotate(direction, i);
						tmp.roll(roll, j);
						if (tmp.isEqual(dice1)) {
							flag = true;
							break;
						}
					}
				}
			}
		}
		if (flag) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
	}
}

