
#####
# Code
#####

# Read input: two integers n and k
int n, k;
std::cin >> n >> k;

// Initialize variable x to 0
int x = 0;

// Check if k is valid based on the condition
if (k <= std::max(n * n / 2, n * n - (n * n / 2))) {
    // If k is valid, print 'YES'
    std::cout << "YES" << std::endl;

    // Iterate through rows and columns of the grid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            // Check if current position (i, j) is valid based on the condition
            if (i % 2 == j % 2 && x < k) {

                // If valid, print 'L' and increment x
                std::cout << "L";
                x++;

            // If not valid, print 'S'
            } else {
                std::cout << "S";
            }
        }

        // Move to the next line after completing a row
        std::cout << std::endl;
    }

// If k is not valid, print 'NO'
} else {
    std::cout << "NO" << std::endl;
}

