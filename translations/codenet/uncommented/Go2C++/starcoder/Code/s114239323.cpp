#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector<int> h(N);
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }

    vector<int> dp(N);
    dp[0] = 0;
    dp[1] = abs(h[0] - h[1]);
    for (int i = 2; i < N; i++) {
        dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
    }

    cout << dp[N - 1] << endl;
}

/* templates */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector<int> h(N);
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }

    vector<int> dp(N);
    dp[0] = 0;
    dp[1] = abs(h[0] - h[1]);
    for (int i = 2; i < N; i++) {
        dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
    }

    cout << dp[N - 1] << endl;
}

/* templates */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector<int> h(N);
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }

    vector<int> dp(N);
    dp[0] = 0;
    dp[1] = abs(h[0] - h[1]);
    for (int i = 2; i < N; i++) {
        dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
    }

    cout << dp[N - 1] << endl;
}

/* templates */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector<int> h(N);
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }

    vector<int> dp(N);
    dp[0] = 0;
    dp[1] = abs(h[0] - h[1]);
    for (int i = 2; i < N; i++) {
        dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
    }

    cout << dp[N - 1] << endl;
}

/* templates */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector<int> h(N);
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }

    vector<int> dp(N);
    dp[0] = 0;
    dp[1] = abs(h[0] - h[1]);
    for (int i = 2; i < N; i++) {
        dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
    }

    cout << dp[N - 1] << endl;
}

/* templates */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector<int> h(N);
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }

    vector<int> dp(N);
    dp[0] = 0;
    dp[1] = abs(h[0] - h[1]);
    for (int i = 2; i < N; i++) {
        dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
    }

    cout << dp[N - 1] << endl;
}

/* templates */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector<int> h(N);
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }

    vector<int> dp(N);
    dp[0] = 0;
    dp[1] = abs(h[0] - h[1]);
    for (int i = 2; i < N; i++) {
        dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
    }

    cout << dp[N - 1] << endl;
}

/* templates */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector<int> h(N);
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }

    vector<int> dp(N);
    dp[0] = 0;
    dp[1] = abs(h[0] - h[1]);
    for (int i = 2; i < N; i++) {
        dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
    }

    cout << dp[N - 1] << endl;
}

/* templates */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector<int> h(N);
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }

    vector<int> dp(N);
    dp[0] = 0;
    dp[1] = abs(h[0] - h[1]);
    for (int i = 2; i < N; i++) {
        dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
    }

    cout << dp[N - 1] << endl;
}

/* templates */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector<int> h(N);
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }

    vector<int> dp(N);
    dp[0] = 0;
    dp[1] = abs(h[0] - h[1]);
    for (int i = 2; i < N; i++) {
        dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
    }

    cout << dp[N - 1] << endl;
}

/* templates */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector<int> h(N);
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }

    vector<int> dp(N);
    dp[0] = 0;
    dp[1] = abs(h[0] - h[1]);
    for (int i = 2; i < N; i++) {
        dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
    }

    cout << dp[N - 1] << endl;
}

/* templates */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector<int> h(N);
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }

    vector<int> dp(N);
    dp[0] = 0;
    dp[1] = abs(h[0] - h[1]);
    for (int i = 2; i < N; i++) {
        dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
    }

    cout << dp[N - 1] << endl;
}

/* templates */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector<int> h(N);
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }

    vector<int> dp(N);
    dp[0] = 0;
    dp[1] = abs(h[0] - h[1]);
    for (int i = 2; i < N; i++) {
        dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
    }

    cout << dp[N - 1] << endl;
}

/* templates */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector<int> h(N);
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }

    vector<int> dp(N);
    dp[0] = 0;
    dp[1] = abs(h[0] - h[1]);
    for (int i = 2; i < N; i++) {
        dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
    }

    cout << dp[N - 1] << endl;
}

/* templates */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector<int> h(N);
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }

    vector<int> dp(N);
    dp[0] = 0;
    dp[1] = abs(h[0] - h[1]);
    for (int i = 2; i < N; i++) {
        dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
    }

    cout << dp[N - 1] << endl;
}

/* templates */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector<int> h(N);
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }

    vector<int> dp(N);
    dp[0] = 0;
    dp[1] = abs(h[0] - h[1]);
    for (int i = 2; i < N; i++) {
        dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
    }

    cout << dp[N - 1] << endl;
}

/* templates */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector<int> h(N);
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }

    vector<int> dp(N);
    dp[0] = 0;
    dp[1] = abs(h[0] - h[1]);
    for (int i = 2; i < N; i++) {
        dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
    }

    cout << dp[N - 1] << endl;
}

/* templates */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector<int> h(N);
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }

    vector<int> dp(N);
    dp[0] = 0;
    dp[1] = abs(h[0] - h[1]);
    for (int i = 2; i < N; i++) {
        dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
    }

    cout << dp[N - 1] << endl;
}

/* templates */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector<int> h(N);
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }

    vector<int> dp(N);
    dp[0] = 0;
    dp[1] = abs(h[0] - h[1]);
    for (int i = 2; i < N; i++) {
        dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
    }

    cout << dp[N - 1] << endl;
}

/* templates */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector<int> h(N);
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }

    vector<int> dp(N);
    dp[0] = 0;
    dp[1] = abs(h[0] - h[1]);
    for (int i = 2; i < N; i++) {
        dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
    }

    cout << dp[N - 1] << endl;
}

/* templates */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector<int> h(N);
    for (int i = 0; i