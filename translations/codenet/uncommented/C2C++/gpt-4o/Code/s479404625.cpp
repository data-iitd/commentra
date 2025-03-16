#include <iostream>
#include <cstring>

int main()
{
    char A[20], B[20], C[20];

    std::cin >> A >> B >> C;

    int la = strlen(A), lb = strlen(B);

    if (A[la - 1] == B[0] && B[lb - 1] == C[0])
    {
        std::cout << "YES" << std::endl;
    }
    else
    {
        std::cout << "NO" << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
