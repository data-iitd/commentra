#include <iostream> // Including the iostream library for input and output operations
#include <vector>   // Including the vector library for using dynamic arrays

using namespace std; // Using the standard namespace

bool dfs(int currpos, const vector<int>& arr, int target) { // Defining the recursive depth-first search function
    if (currpos == target) { // Base case: if the current position is the target position, return true
        return true;
    }
    if (currpos > arr.size()) { // Base case: if the current position is out of the array bounds, return false
        return false;
    }
    bool teleport = dfs(currpos + arr[currpos - 1], arr, target); // Recursive call: try to teleport to the next position
    if (teleport) { // If teleportation was successful, return true
        return true;
    }
    return false; // If teleportation was not successful, return false
}

int main() { // Defining the main function
    int n, goal; // Declaring variables for the number of positions and the target position
    cin >> n >> goal; // Reading the number of positions and the target position from the standard input
    vector<int> arr(n - 1); // Creating a vector of size n-1 to store the positions of the teleportals
    for (int i = 0; i < n - 1; i++) { // Reading the positions of the teleportals from the standard input and storing them in the vector
        cin >> arr[i];
    }
    bool isFound = dfs(1, arr, goal); // Calling the depth-first search function with the initial position and the target position
    if (isFound) { // If the target position was found, print "YES" to the standard output
        cout << "YES" << endl;
    } else { // If the target position was not found, print "NO" to the standard output
        cout << "NO" << endl;
    }
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
