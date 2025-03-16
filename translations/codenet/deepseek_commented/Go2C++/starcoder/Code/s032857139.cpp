
#include <bits/stdc++.h>

using namespace std;

// Utility functions for input/output, mathematical operations, and sorting.
template <typename T>
void Read(T &x) {
    cin >> x;
}

template <typename T, typename... Ts>
void Read(T &x, Ts &... xs) {
    cin >> x;
    Read(xs...);
}

template <typename T>
void Write(const T &x) {
    cout << x;
}

template <typename T, typename... Ts>
void Write(const T &x, const Ts &... xs) {
    cout << x << " ";
    Write(xs...);
}

template <typename T>
void WriteLine(const T &x) {
    Write(x);
    Write("\n");
}

template <typename T, typename... Ts>
void WriteLine(const T &x, const Ts &... xs) {
    Write(x, xs...);
    WriteLine();
}

template <typename T>
void ReadContainer(T &x) {
    for (auto &a : x) {
        Read(a);
    }
}

template <typename T>
void WriteContainer(const T &x) {
    for (const auto &a : x) {
        Write(a, " ");
    }
    WriteLine();
}

template <typename T>
void WriteContainer(const T &x, int start, int end) {
    for (int i = start; i < end; i++) {
        Write(x[i], " ");
    }
    WriteLine();
}

template <typename T>
void ReadContainer(T &x, int n) {
    x.resize(n);
    ReadContainer(x);
}

template <typename T>
void WriteContainer(const T &x, int n) {
    WriteContainer(x, 0, n);
}

template <typename T>
void WriteContainer(const T &x, int start, int end, int d) {
    for (int i = start; i < end; i += d) {
        Write(x[i], " ");
    }
    WriteLine();
}

template <typename T>
void ReadContainer(T &x, int n, int m) {
    x.resize(n, m);
    ReadContainer(x);
}

template <typename T>
void WriteContainer(const T &x, int n, int m) {
    WriteContainer(x, 0, n, m);
}

template <typename T>
void WriteContainer(const T &x, int start, int end, int d, int m) {
    for (int i = start; i < end; i += d) {
        WriteContainer(x[i], m);
    }
    WriteLine();
}

template <typename T>
void ReadContainer2D(T &x) {
    int n, m;
    Read(n, m);
    x.resize(n, m);
    ReadContainer(x);
}

template <typename T>
void WriteContainer2D(const T &x) {
    WriteContainer2D(x, 0, 0, x.size(), x[0].size());
}

template <typename T>
void WriteContainer2D(const T &x, int start, int end, int d, int m) {
    for (int i = start; i < end; i += d) {
        WriteContainer(x[i], m);
    }
    WriteLine();
}

template <typename T>
void ReadContainer2D(T &x, int n) {
    x.resize(n);
    ReadContainer2D(x);
}

template <typename T>
void WriteContainer2D(const T &x, int n) {
    WriteContainer2D(x, 0, n, 1, x[0].size());
}

template <typename T>
void ReadContainer2D(T &x, int n, int m) {
    x.resize(n, m);
    ReadContainer2D(x);
}

template <typename T>
void WriteContainer2D(const T &x, int n, int m) {
    WriteContainer2D(x, 0, n, 1, m);
}

template <typename T>
void ReadContainer3D(T &x) {
    int n, m, l;
    Read(n, m, l);
    x.resize(n, m, l);
    ReadContainer(x);
}

template <typename T>
void WriteContainer3D(const T &x) {
    WriteContainer3D(x, 0, 0, 0, x.size(), x[0].size(), x[0][0].size());
}

template <typename T>
void WriteContainer3D(const T &x, int start, int end, int d, int m, int l) {
    for (int i = start; i < end; i += d) {
        WriteContainer2D(x[i], m, l);
    }
    WriteLine();
}

template <typename T>
void ReadContainer3D(T &x, int n) {
    x.resize(n);
    ReadContainer3D(x);
}

template <typename T>
void WriteContainer3D(const T &x, int n) {
    WriteContainer3D(x, 0, n, 1, x[0].size(), x[0][0].size());
}

template <typename T>
void ReadContainer3D(T &x, int n, int m) {
    x.resize(n, m);
    ReadContainer3D(x);
}

template <typename T>
void WriteContainer3D(const T &x, int n, int m) {
    WriteContainer3D(x, 0, n, 1, m, x[0][0].size());
}

template <typename T>
void ReadContainer3D(T &x, int n, int m, int l) {
    x.resize(n, m, l);
    ReadContainer3D(x);
}

template <typename T>
void WriteContainer3D(const T &x, int n, int m, int l) {
    WriteContainer3D(x, 0, n, 1, m, l);
}

template <typename T>
void ReadContainer4D(T &x) {
    int n, m, l, o;
    Read(n, m, l, o);
    x.resize(n, m, l, o);
    ReadContainer(x);
}

template <typename T>
void WriteContainer4D(const T &x) {
    WriteContainer4D(x, 0, 0, 0, 0, x.size(), x[0].size(), x[0][0].size(), x[0][0][0].size());
}

template <typename T>
void WriteContainer4D(const T &x, int start, int end, int d, int m, int l, int o) {
    for (int i = start; i < end; i += d) {
        WriteContainer3D(x[i], m, l, o);
    }
    WriteLine();
}

template <typename T>
void ReadContainer4D(T &x, int n) {
    x.resize(n);
    ReadContainer4D(x);
}

template <typename T>
void WriteContainer4D(const T &x, int n) {
    WriteContainer4D(x, 0, n, 1, x[0].size(), x[0][0].size(), x[0][0][0].size());
}

template <typename T>
void ReadContainer4D(T &x, int n, int m) {
    x.resize(n, m);
    ReadContainer4D(x);
}

template <typename T>
void WriteContainer4D(const T &x, int n, int m) {
    WriteContainer4D(x, 0, n, 1, m, x[0][0].size(), x[0][0][0].size());
}

template <typename T>
void ReadContainer4D(T &x, int n, int m, int l) {
    x.resize(n, m, l);
    ReadContainer4D(x);
}

template <typename T>
void WriteContainer4D(const T &x, int n, int m, int l) {
    WriteContainer4D(x, 0, n, 1, m, l, x[0][0][0].size());
}

template <typename T>
void ReadContainer4D(T &x, int n, int m, int l, int o) {
    x.resize(n, m, l, o);
    ReadContainer4D(x);
}

template <typename T>
void WriteContainer4D(const T &x, int n, int m, int l, int o) {
    WriteContainer4D(x, 0, n, 1, m, l, o);
}

template <typename T>
void ReadContainer5D(T &x) {
    int n, m, l, o, p;
    Read(n, m, l, o, p);
    x.resize(n, m, l, o, p);
    ReadContainer(x);
}

template <typename T>
void WriteContainer5D(const T &x) {
    WriteContainer5D(x, 0, 0, 0, 0, 0, x.size(), x[0].size(), x[0][0].size(), x[0][0][0].size(), x[0][0][0][0].size());
}

template <typename T>
void WriteContainer5D(const T &x, int start, int end, int d, int m, int l, int o, int p) {
    for (int i = start; i < end; i += d) {
        WriteContainer4D(x[i], m, l, o, p);
    }
    WriteLine();
}

template <typename T>
void ReadContainer5D(T &x, int n) {
    x.resize(n);
    ReadContainer5D(x);
}

template <typename T>
void WriteContainer5D(const T &x, int n) {
    WriteContainer5D(x, 0, n, 1, x[0].size(), x[0][0].size(), x[0][0][0].size(), x[0][0][0][0].size());
}

template <typename T>
void ReadContainer5D(T &x, int n, int m) {
    x.resize(n, m);
    ReadContainer5D(x);
}

template <typename T>
void WriteContainer5D(const T &x, int n, int m) {
    WriteContainer5D(x, 0, n, 1, m, x[0][0].size(), x[0][0][0].size(), x[0][0][0][0].size());
}

template <typename T>
void ReadContainer5D(T &x, int n, int m, int l) {
    x.resize(n, m, l);
    ReadContainer5D(x);
}

template <typename T>
void WriteContainer5D(const T &x, int n, int m, int l) {
    WriteContainer5D(x, 0, n, 1, m, l, x[0][0][0].size(), x[0][0][0][0].size());
}

template <typename T>
void ReadContainer5D(T &x, int n, int m, int l, int o) {
    x.resize(n, m, l, o);
    ReadContainer5D(x);
}

template <typename T>
void WriteContainer5D(const T &x, int n, int m, int l, int o) {
    WriteContainer5D(x, 0, n, 1, m, l, o, x[0][0][0][0].size());
}

template <typename T>
void ReadContainer5D(T &x, int n, int m, int l, int o, int p) {
    x.resize(n, m, l, o, p);
    ReadContainer5D(x);
}

template <typename T>
void WriteContainer5D(const T &x, int n, int m, int l, int o, int p) {
    WriteContainer5D(x, 0, n, 1, m, l, o, p);
}

template <typename T>
void ReadContainer6D(T &x) {
    int n, m, l, o, p, q;
    Read(n, m, l, o, p, q);
    x.resize(n, m, l, o, p, q);
    ReadContainer(x);
}

template <typename T>
void WriteContainer6D(const T &x) {
    WriteContainer6D(x, 0, 0, 0, 0, 0, 0, x.size(), x[0].size(), x[0][0].size(), x[0][0][0].size(), x[0][0][0][0].size(), x[0][0][0][0][0].size());
}

template <typename T>
void WriteContainer6D(const T &x, int start, int end, int d, int m, int l, int o, int p, int q) {
    for (int i = start; i < end; i += d) {
        WriteContainer5D(x[i], m, l, o, p, q);
    }
    WriteLine();
}

template <typename T>
void ReadContainer6D(T &x, int n) {
    x.resize(n);
    ReadContainer6D(x);
}

template <typename T>
void WriteContainer6D(const T &x, int n) {
    WriteContainer6D(x, 0, n, 1, x[0].size(), x[0][0].size(), x[0][0][0].size(), x[0][0][0][0].size(), x[0][0][0][0][0].size());
}

template <typename T>
void ReadContainer6D(T &x, int n, int m) {
    x.resize(n, m);
    ReadContainer6D(x);
}

template <typename T>
void WriteContainer6D(const T &x, int n, int m) {
    WriteContainer6D(x, 0, n, 1, m, x[0][0].size(), x[0][0][0].size(), x[0][0][0][0].size(), x[0][0][0][0][0].size());
}

template <typename T>
void ReadContainer6D(T &x, int n, int m, int l) {
    x.resize(n, m, l);
    ReadContainer6D(x);
}

template <typename T>
void WriteContainer6D(const T &x, int n, int m, int l) {
    WriteContainer6D(x, 0, n, 1, m, l, x[0][0][0].size(), x[0][0][0][0].size(), x[0][0][0][0][0].size());
}

template <typename T>
void ReadContainer6D(T &x, int n, int m, int l, int o) {
    x.resize(n, m, l, o);
    ReadContainer6D(x);
}

template <typename T>
void WriteContainer6D(const T &x, int n, int m, int l, int o) {
    WriteContainer6D(x, 0, n, 1, m, l, o, x[0][0][0][0].size(), x[0][0][0][0][0].size());
}

template <typename T>
void ReadContainer6D(T &x, int n, int m, int l, int o, int p) {
    x.resize(n, m, l, o, p);
    ReadContainer6D(x);
}

template <typename T>
void WriteContainer6D(const T &x, int n, int m, int l, int o, int p) {
    WriteContainer6D(x, 0, n, 1, m, l, o, p, x[0][0][0][0][0].size());
}

template <typename T>
void ReadContainer6D(T &x, int n, int m, int l, int o, int p, int q) {
    x.resize(n, m, l, o, p, q);
    ReadContainer6D(x);
}

template <typename T>
void WriteContainer6D(const T &x, int n, int m, int l, int o, int p, int q) {
    WriteContainer6D(x, 0, n, 1, m, l, o, p, q);
}

template <typename T>
void ReadContainer7D(T &x) {
    int n, m, l, o, p, q, r;
    Read(n, m, l, o