// Importing random module for generating random numbers if required
import java.util.Random;

// Taking input from user and converting it into a list of integers
String input = in.readLine();
int[] A = new int[input.split(" ").length];
for (int i = 0; i < A.length; i++) {
    A[i] = Integer.parseInt(input.split(" ")[i]);
}

// Adding the first element of the list to the beginning of the list
// to make the first index 0 based instead of 1 based
A = new int[A.length + 1];
A[0] = A[A.length - 1];
for (int i = 0; i < A.length - 1; i++) {
    A[i + 1] = A[i];
}
A[0] = A[A.length - 1];
A = Arrays.copyOfRange(A, 1, A.length);

// Assigning the length of the list to a variable for easier reference
int N = A.length;

// Defining a helper function to find the index of the last occurrence of an element
// in a list, and the index and value of the previous occurrence
public List<Integer> cut(int[] array, int index) {
    // Base case: if index is less than 1, return an empty list
    if (index < 1) {
        return new ArrayList<>();
    }

    // Base case: if index is less than or equal to the first element in the array
    if (index <= array[0]) {
        return new ArrayList<>(Arrays.asList(index, array[0]));
    }

    // Iterating through the array from the end to the beginning
    for (int i = array.length - 1; i >= 0; i--) {
        // If the previous element is smaller than the index, return the sublist up to that index
        if (array[i - 1] < index) {
            List<Integer> list = new ArrayList<>();
            for (int j = i; j < array.length; j++) {
                list.add(array[j]);
            }
            list.add(index);
            list.add(array[i]);
            return list;
        }
    }
}

// Defining a helper function to check if it's possible to add a certain number of elements
// to the list while maintaining the condition that the previous element is smaller than the current one
public boolean isPossible(int K) {
    // Initializing an empty list to store the indices and values of the elements in the list
    List<Integer> dp = new ArrayList<>(Arrays.asList(A[0], 0));

    // Iterating through the list starting from the second element
    for (int a : A) {
        // If the current element is smaller than the last element in the dp list,
        // we need to cut the list at the previous index and add the current element
        if (a <= dp.get(dp.size() - 1)) {
            dp = cut(dp.stream().mapToInt(Integer::intValue).toArray(), a);
        }

        // Adding the current element to the dp list
        dp.add(a);
        dp.add(0);

        // Initializing a flag to check if we need to add an element to the dp list
        boolean isAdded = false;

        // Iterating through the dp list from the end to the beginning
        for (int j = dp.size() - 1; j >= 0; j--) {
            // If the previous element has a smaller value and enough space to add the current element,
            // we need to cut the list at the previous index and add the current element
            if (dp.get(j) < K - 1) {
                dp = cut(dp.stream().mapToInt(Integer::intValue).toArray(), dp.get(j) - 1);
                dp.add(dp.get(j));
                dp.add(dp.get(j) + 1);

                // Checking if the last element in the dp list is smaller than the current element
                if (dp.get(dp.size() - 1) < a) {
                    dp.add(a);
                    dp.add(0);
                    isAdded = true;
                    break;
                }
            }
        }

        // If we didn't add an element to the dp list, the current number can't be added
        if (!isAdded) {
            return false;
        }
    }

    return true;
}

// Defining a helper function to find the binary index of a number in the list
public int bis(int x, int y) {
    // Base case: if y is one more than x, return y
    if (y == x + 1) {
        return y;
    }

    // Recursively finding the binary index of x and y using the is_possible function
    if (isPossible((x + y) / 2)) {
        return bis(x, (x + y) / 2);
    }

    // If is_possible returns False for (x + y) // 2 and y, return the binary index of y
    else {
        return bis((x + y) / 2, y);
    }
}

// Printing the result of the binary index function
System.out.println(bis(0, N));

