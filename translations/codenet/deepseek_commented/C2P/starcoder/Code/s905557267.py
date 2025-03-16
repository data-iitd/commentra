#include <stdio.h>

# Function to return the smaller of two integers
def min(a, b):
	if (a <= b):
		return (a);
	return (b);

# Function to remove chains of four or more consecutive identical elements
def Chain(b, n):
	i = 0
	j = 0
	count = 0 # To count the length of the chain
	color = 0 # To store the color of the chain
	a = [0] * 10000 # Temporary array to hold the modified sequence
	
	# Copy the original array to a temporary array
	for (i = 0; i < n; i++){
		a[i] = b[i];
	}
	
	# Iterate through the array to find and remove chains of four or more elements
	for (i = 0; i < n - 4; i++){
		if (a[i]!= 0 and a[i] == a[i + 1] and a[i] == a[i + 2] and a[i] == a[i + 3]){
			# Debugging output to show the array before removal
			#if 0
			print("-----")
			for (j = 0; j < n; j++){
				print(a[j])
			}
			print("-----")
			#endif
			
			count = 0;
			color = a[i];
			
			# Remove the chain by setting all elements to 0
			for (j = i; a[j] == color; j++){
				a[j] = 0;
				count++;
			}
			
			# Shift the remaining elements to fill the gap left by the removed chain
			for (j = 0; i + j + count < 10000; j++){
				a[i + j] = a[i + j + count];
				a[i + j + count] = 0;
			}
			
			# Debugging output to show the array after removal
			#if 0
			print("-----")
			for (j = 0; j < n; j++){
				print(a[j])
			}
			print("-----")
			#endif
			
			# Reset the index to start checking from the beginning
			i = 0;
		}
		
	}
	
	count = 0;
	while (a[count]!= 0):
		count++;
	}
	
	# Check if the remaining sequence is a chain of four or more elements
	if (count == 4 and a[0] == a[1] and a[0] == a[2] and a[0] == a[3]):
		return (0);
	}
	
	return (count);
}

# Main function to read input, process it, and print the result
def main():
	n = 0
	i = 0
	j = 0
	count = 0 # To count the length of the chain
	color = 0 # To store the color of the chain
	a = [0] * 10000 # Temporary array to hold the modified sequence
	ans = 0
	
	while (1):
		# Initialize the array with zeros
		for (i = 0; i < 10000; i++){
			a[i] = 0;
		}
		
		# Read the number of elements
		scanf("%d", &n);
		if (n == 0):
			break;
		ans = n;
		
		# Read the elements themselves
		for (i = 0; i < n; i++){
			scanf("%d", &a[i]);
		}
		
		# Iterate over possible starting points for chains of four or more elements
		for (i = 0; i < n - 4; i++){
			count = [0, 0, 0]; # To count occurrences of each color
			for (j = i; j < i + 4; j++){
				if (a[j] - 1 >= 0):
					count[a[j] - 1]++;
				}
			}
			
			color = 0;
			for (j = 0; j < 3; j++){
				if (count[j] >= 3):
					color = j + 1;
					break;
				}
			}
			
			if (color!= 0):
				for (j = i; j < i + 4; j++){
					int buf;
					buf = a[j];
					a[j] = color;
					ans = min(ans, Chain(a, n));
					a[j] = buf;
				}
			}
		}
		
		# Print the minimum length after processing
		printf("%d\n", ans);
	}
	
	return (0);
}

# 