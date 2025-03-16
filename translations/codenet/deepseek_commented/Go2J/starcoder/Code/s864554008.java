package main;

import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		// Create a new data instance
		Data d = new Data();
		
		// Check if the smaller image exists within the larger image and print the result
		System.out.println(d.exist()? "Yes" : "No");
	}
}

// Class to hold the data for the images
class Data {
	int n, m; // Dimensions of the images and their slices
	String[] nImg, mImg; // Slices to hold the image data
	
	// Function to initialize a new data instance by reading image dimensions and data from standard input
	Data() {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		m = sc.nextInt();
		nImg = load(n);
		mImg = load(m);
	}
	
	// Function to read a specified number of strings from standard input and return them as a slice of strings
	String[] load(int cnt) {
		String[] ret = new String[cnt];
		for (int i = 0; i < cnt; i++) {
			ret[i] = sc.next();
		}
		return ret;
	}
	
	// Method to check if the smaller image exists within the larger image
	boolean exist() {
		// Iterate over all possible positions where the smaller image could fit within the larger image
		for (int i = 0; i <= n-m; i++) {
			for (int j = 0; j <= n-m; j++) {
				if (match(i, j)) { // Check if the smaller image matches the corresponding part of the larger image at the current position
					return true;
				}
			}
		}
		return false;
	}
	
	// Method to check if the smaller image matches the corresponding part of the larger image at a given position
	boolean match(int x, int y) {
		// Iterate over each pixel in the smaller image and compare it with the corresponding pixel in the larger image
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				if (nImg[x+i].charAt(y+j)!= mImg[i].charAt(j)) { // If any pixel does not match, return false
					return false;
				}
			}
		}
		return true; // If all pixels match, return true
	}
}

