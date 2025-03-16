// Ask the user for the number of elements in the sequence
Scanner scanner = new Scanner(System.in);
int n = scanner.nextInt();

// Initialize the indices of the left and right pointers
int l = 1;
int r = n;

// Binary search algorithm
while (l < r) {
    // Calculate the middle index
    int mid = l + (r - l) / 2;

    // Calculate the number of elements on the left side of the middle index
    int idxcnt = mid * (mid + 1) / 2;

    // If the number of elements on the left side is less than the target number,
    // move the left pointer to the right of the middle index
    if (idxcnt < n) {
        l = mid + 1;
    }

    // Otherwise, the target number is either at the middle index or on the right side,
    // so move the right pointer to the left of the middle index
    else {
        r = mid;
    }
}

// The target number is at the index l-1, so we need to subtract the number of elements
// on the left side of index l-1 from the total number of elements to get the target number
l -= 1;

// Calculate the number of elements on the left side of index l
idxcnt = l * (l + 1) / 2;

// Print the target number
System.out.println(n - idxcnt);

