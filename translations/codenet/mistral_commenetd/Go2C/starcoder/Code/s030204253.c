#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// Function to sort the array
void sort(float *a, int n) {
	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			if (a[i] > a[j]) {
				float temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

// Function to calculate the average of the first two elements of the array
float average(float *a) {
	return (a[0] + a[1]) / 2;
}

// Function to calculate the median of the array
float median(float *a, int n) {
	if (n % 2 == 0) {
		return (a[n/2] + a[n/2-1]) / 2;
	} else {
		return a[n/2];
	}
}

// Function to calculate the mode of the array
float mode(float *a, int n) {
	float max = 0;
	int max_count = 0;
	for (int i = 0; i < n; i++) {
		int count = 0;
		for (int j = 0; j < n; j++) {
			if (a[i] == a[j]) {
				count++;
			}
		}
		if (count > max_count) {
			max_count = count;
			max = a[i];
		}
	}
	return max;
}

// Function to calculate the standard deviation of the array
float std_dev(float *a, int n) {
	float mean = 0;
	for (int i = 0; i < n; i++) {
		mean += a[i];
	}
	mean /= n;
	float std_dev = 0;
	for (int i = 0; i < n; i++) {
		std_dev += (a[i] - mean) * (a[i] - mean);
	}
	std_dev /= n;
	return sqrt(std_dev);
}

// Function to calculate the variance of the array
float variance(float *a, int n) {
	float mean = 0;
	for (int i = 0; i < n; i++) {
		mean += a[i];
	}
	mean /= n;
	float variance = 0;
	for (int i = 0; i < n; i++) {
		variance += (a[i] - mean) * (a[i] - mean);
	}
	variance /= n;
	return variance;
}

// Function to calculate the skewness of the array
float skewness(float *a, int n) {
	float mean = 0;
	for (int i = 0; i < n; i++) {
		mean += a[i];
	}
	mean /= n;
	float skewness = 0;
	for (int i = 0; i < n; i++) {
		skewness += (a[i] - mean) * (a[i] - mean) * (a[i] - mean);
	}
	skewness /= n;
	return skewness;
}

// Function to calculate the kurtosis of the array
float kurtosis(float *a, int n) {
	float mean = 0;
	for (int i = 0; i < n; i++) {
		mean += a[i];
	}
	mean /= n;
	float kurtosis = 0;
	for (int i = 0; i < n; i++) {
		kurtosis += (a[i] - mean) * (a[i] - mean) * (a[i] - mean) * (a[i] - mean);
	}
	kurtosis /= n;
	return kurtosis;
}

// Function to calculate the sum of the array
float sum(float *a, int n) {
	float sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
	}
	return sum;
}

// Function to calculate the product of the array
float product(float *a, int n) {
	float product = 1;
	for (int i = 0; i < n; i++) {
		product *= a[i];
	}
	return product;
}

// Function to calculate the geometric mean of the array
float geometric_mean(float *a, int n) {
	float geometric_mean = 1;
	for (int i = 0; i < n; i++) {
		geometric_mean *= a[i];
	}
	geometric_mean = pow(geometric_mean, 1.0/n);
	return geometric_mean;
}

// Function to calculate the harmonic mean of the array
float harmonic_mean(float *a, int n) {
	float harmonic_mean = 0;
	for (int i = 0; i < n; i++) {
		harmonic_mean += 1.0/a[i];
	}
	harmonic_mean /= n;
	return harmonic_mean;
}

// Function to calculate the median of the array
float median(float *a, int n) {
	if (n % 2 == 0) {
		return (a[n/2] + a[n/2-1]) / 2;
	} else {
		return a[n/2];
	}
}

// Function to calculate the minimum of the array
float minimum(float *a, int n) {
	float minimum = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] < minimum) {
			minimum = a[i];
		}
	}
	return minimum;
}

// Function to calculate the maximum of the array
float maximum(float *a, int n) {
	float maximum = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > maximum) {
			maximum = a[i];
		}
	}
	return maximum;
}

// Function to calculate the range of the array
float range(float *a, int n) {
	return maximum(a, n) - minimum(a, n);
}

// Function to calculate the midrange of the array
float midrange(float *a, int n) {
	return (maximum(a, n) + minimum(a, n)) / 2;
}

// Function to calculate the mean of the array
float mean(float *a, int n) {
	float mean = 0;
	for (int i = 0; i < n; i++) {
		mean += a[i];
	}
	mean /= n;
	return mean;
}

// Function to calculate the median of the array
float median(float *a, int n) {
	if (n % 2 == 0) {
		return (a[n/2] + a[n/2-1]) / 2;
	} else {
		return a[n/2];
	}
}

// Function to calculate the mode of the array
float mode(float *a, int n) {
	float max = 0;
	int max_count = 0;
	for (int i = 0; i < n; i++) {
		int count = 0;
		for (int j = 0; j < n; j++) {
			if (a[i] == a[j]) {
				count++;
			}
		}
		if (count > max_count) {
			max_count = count;
			max = a[i];
		}
	}
	return max;
}

// Function to calculate the standard deviation of the array
float std_dev(float *a, int n) {
	float mean = 0;
	for (int i = 0; i < n; i++) {
		mean += a[i];
	}
	mean /= n;
	float std_dev = 0;
	for (int i = 0; i < n; i++) {
		std_dev += (a[i] - mean) * (a[i] - mean);
	}
	std_dev /= n;
	return sqrt(std_dev);
}

// Function to calculate the variance of the array
float variance(float *a, int n) {
	float mean = 0;
	for (int i = 0; i < n; i++) {
		mean += a[i];
	}
	mean /= n;
	float variance = 0;
	for (int i = 0; i < n; i++) {
		variance += (a[i] - mean) * (a[i] - mean);
	}
	variance /= n;
	return variance;
}

// Function to calculate the skewness of the array
float skewness(float *a, int n) {
	float mean = 0;
	for (int i = 0; i < n; i++) {
		mean += a[i];
	}
	mean /= n;
	float skewness = 0;
	for (int i = 0; i < n; i++) {
		skewness += (a[i] - mean) * (a[i] - mean) * (a[i] - mean);
	}
	skewness /= n;
	return skewness;
}

// Function to calculate the kurtosis of the array
float kurtosis(float *a, int n) {
	float mean = 0;
	for (int i = 0; i < n; i++) {
		mean += a[i];
	}
	mean /= n;
	float kurtosis = 0;
	for (int i = 0; i < n; i++) {
		kurtosis += (a[i] - mean) * (a[i] - mean) * (a[i] - mean) * (a[i] - mean);
	}
	kurtosis /= n;
	return kurtosis;
}

// Function to calculate the sum of the array
float sum(float *a, int n) {
	float sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
	}
	return sum;
}

// Function to calculate the product of the array
float product(float *a, int n) {
	float product = 1;
	for (int i = 0; i < n; i++) {
		product *= a[i];
	}
	return product;
}

// Function to calculate the geometric mean of the array
float geometric_mean(float *a, int n) {
	float geometric_mean = 1;
	for (int i = 0; i < n; i++) {
		geometric_mean *= a[i];
	}
	geometric_mean = pow(geometric_mean, 1.0/n);
	return geometric_mean;
}

// Function to calculate the harmonic mean of the array
float harmonic_mean(float *a, int n) {
	float harmonic_mean = 0;
	for (int i = 0; i < n; i++) {
		harmonic_mean += 1.0/a[i];
	}
	harmonic_mean /= n;
	return harmonic_mean;
}

// Function to calculate the median of the array
float median(float *a, int n) {
	if (n % 2 == 0) {
		return (a[n/2] + a[n/2-1]) / 2;
	} else {
		return a[n/2];
	}
}

// Function to calculate the minimum of the array
float minimum(float *a, int n) {
	float minimum = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] < minimum) {
			minimum = a[i];
		}
	}
	return minimum;
}

// Function to calculate the maximum of the array
float maximum(float *a, int n) {
	float maximum = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > maximum) {
			maximum = a[i];
		}
	}
	return maximum;
}

// Function to calculate the range of the array
float range(float *a, int n) {
	return maximum(a, n) - minimum(a, n);
}

// Function to calculate the midrange of the array
float midrange(float *a, int n) {
	return (maximum(a, n) + minimum(a, n)) / 2;
}

// Function to calculate the mean of the array
float mean(float *a, int n) {
	float mean = 0;
	for (int i = 0; i < n; i++) {
		mean += a[i];
	}
	mean /= n;
	return mean;
}

// Function to calculate the median of the array
float median(float *a, int n) {
	if (n % 2 == 0) {
		return (a[n/2] + a[n/2-1]) / 2;
	} else {
		return a[n/2];
	}
}

// Function to calculate the mode of the array
float mode(float *a, int n) {
	float max = 0;
	int max_count = 0;
	for (int i = 0; i < n; i++) {
		int count = 0;
		for (int j = 0; j < n; j++) {
			if (a[i] == a[j]) {
				count++;
			}
		}
		if (count > max_count) {
			max_count = count;
			max = a[i];
		}
	}
	return max;
}

// Function to calculate the standard deviation of the array
float std_dev(float *a, int n) {
	float mean = 0;
	for (int i = 0; i < n; i++) {
		mean += a[i];
	}
	mean /= n;
	float std_dev = 0;
	for (int i = 0; i < n; i++) {
		std_dev += (a[i] - mean) * (a[i] - mean);
	}
	std_dev /= n;
	return sqrt(std_dev);
}

// Function to calculate the variance of the array
float variance(float *a, int n) {
	float mean = 0;
	for (int i = 0; i < n; i++) {
		mean += a[i];
	}
	mean /= n;
	float variance = 0;
	for (int i = 0; i < n; i++) {
		variance += (a[i] - mean) * (a[i] - mean);
	}
	variance /= n;
	return variance;
}

// Function to calculate the skewness of the array
float skewness(float *a, int n) {
	float mean = 0;
	for (int i = 0; i < n; i++) {
		mean += a[i];
	}
	mean /= n;
	float skewness = 0;
	for (int i = 0; i < n; i++) {
		skewness += (a[i] - mean) * (a[i] - mean) * (a[i] - mean);
	}
	skewness /= n;
	return skewness;
}

// Function to calculate the kurtosis of the array
float kurtosis(float *a, int n) {
	float mean = 0;
	for (int i = 0; i < n; i++) {
		mean += a[i];
	}
	mean /= n;
	float kurtosis = 0;
	for (int i = 0; i < n; i++) {
		kurtosis += (a[i] - mean) * (a[i] - mean) * (a[i] - mean) * (a[i] - mean);
	}
	kurtosis /= n;
	return kurtosis;
}

// Function to calculate the sum of the array
float sum(float *a, int n) {
	float sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
	}
	return sum;
}

// Function to calculate the product of the array
float product(float *a, int n) {
	float product = 1;
	for (int i = 0; i < n; i++) {
		product *= a[i];
	}
	return product;
}

// Function to calculate the geometric mean of the array
float geometric_mean(float *a, int n) {
	float geometric_mean = 1;
	for (int i = 0; i < n; i++) {
		geometric_mean *= a[i];
	}
	geometric_mean = pow(geometric_mean, 1.0/n);
	return geometric_mean;
}

// Function to calculate the harmonic m