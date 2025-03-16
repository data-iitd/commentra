
#include <iostream> 
#include <string> 
#include <cctype> 

using namespace std; 

int main() { 
    // Create a Scanner object to read input from the console
    string word1, word2, word3; 
    int students; 
    string testCase; 
    string perm1, perm2, perm3, perm4, perm5, perm6; 
    
    // Read three words from the input, remove non-alphabetic characters, and convert them to lowercase
    cin >> word1 >> word2 >> word3; 
    for (int i = 0; i < word1.length(); i++) { 
        if (!isalpha(word1[i])) { 
            word1.erase(i, 1); 
            i--; 
        } 
    } 
    for (int i = 0; i < word2.length(); i++) { 
        if (!isalpha(word2[i])) { 
            word2.erase(i, 1); 
            i--; 
        } 
    } 
    for (int i = 0; i < word3.length(); i++) { 
        if (!isalpha(word3[i])) { 
            word3.erase(i, 1); 
            i--; 
        } 
    } 
    word1 = word1.lowercase(); 
    word2 = word2.lowercase(); 
    word3 = word3.lowercase(); 
    
    // Generate all possible permutations of the three words
    perm1 = word1 + word2 + word3; 
    perm2 = word1 + word3 + word2; 
    perm3 = word2 + word1 + word3; 
    perm4 = word2 + word3 + word1; 
    perm5 = word3 + word2 + word1; 
    perm6 = word3 + word1 + word2; 
    
    // Read the number of students (test cases)
    cin >> students; 
    
    // Loop through each student's test case
    for (int i = 0; i < students; i++) { 
        // Read the test case input, remove non-alphabetic characters, and convert to lowercase
        cin >> testCase; 
        for (int i = 0; i < testCase.length(); i++) { 
            if (!isalpha(testCase[i])) { 
                testCase.erase(i, 1); 
                i--; 
            } 
        } 
        testCase = testCase.lowercase(); 
        
        // Check if the test case matches any of the generated permutations
        if (testCase.equals(perm1) || testCase.equals(perm2) || 
            testCase.equals(perm3) || testCase.equals(perm4) || 
            testCase.equals(perm5) || testCase.equals(perm6)) { 
            // If it matches, print "ACC" (Accepted)
            cout << "ACC" << endl; 
        } else { 
            // If it doesn't match, print "WA" (Wrong Answer)
            cout << "WA" << endl; 
        } 
    } 
    return 0; 
} 

