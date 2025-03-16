
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>

using namespace std;

//  長い入力を読む
vector<string> ReadLongLines(int times) {
    vector<string> result(times);
    char buf[100000];
    for (int i = 0; i < times; i++) {
        gets(buf);
        result[i] = buf;
    }
    return result;
}

//  長い入力を reading から読んで、result に格納する
void ReadLongLines(vector<string> &result, istream &reading) {
    char buf[100000];
    for (int i = 0; i < result.size(); i++) {
        gets(buf);
        result[i] = buf;
    }
}

//  長い入力を reading から読んで、result に格納する
void ReadLongLines(vector<string> &result, FILE *reading) {
    char buf[100000];
    for (int i = 0; i < result.size(); i++) {
        fgets(buf, 100000, reading);
        result[i] = buf;
    }
}

//  長い入力を reading から読んで、result に格納する
void ReadLongLines(vector<string> &result, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        throw runtime_error("file open error");
    }
    ReadLongLines(result, fp);
    fclose(fp);
}

//  長い入力を reading から読んで、result に格納する
void ReadLongLines(vector<string> &result, const string &filename) {
    ReadLongLines(result, filename.c_str());
}

//  長い入力を読んで、result に格納する
void ReadLongLines(vector<string> &result) {
    ReadLongLines(result, cin);
}

//  長い入力を読んで、result に格納する
vector<string> ReadLongLines() {
    vector<string> result;
    ReadLongLines(result);
    return result;
}

//  長い入力を reading から読んで、result に格納する
void ReadLongLines(vector<string> &result, istream &reading) {
    char buf[100000];
    for (int i = 0; i < result.size(); i++) {
        gets(buf);
        result[i] = buf;
    }
}

//  長い入力を reading から読んで、result に格納する
void ReadLongLines(vector<string> &result, FILE *reading) {
    char buf[100000];
    for (int i = 0; i < result.size(); i++) {
        fgets(buf, 100000, reading);
        result[i] = buf;
    }
}

//  長い入力を reading から読んで、result に格納する
void ReadLongLines(vector<string> &result, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        throw runtime_error("file open error");
    }
    ReadLongLines(result, fp);
    fclose(fp);
}

//  長い入力を reading から読んで、result に格納する
void ReadLongLines(vector<string> &result, const string &filename) {
    ReadLongLines(result, filename.c_str());
}

//  長い入力を read から読んで、result に格納する
void ReadLongLines(vector<string> &result, FILE *read) {
    char buf[100000];
    for (int i = 0; i < result.size(); i++) {
        fgets(buf, 100000, read);
        result[i] = buf;
    }
}

//  長い入力を read から読んで、result に格納する
void ReadLongLines(vector<string> &result, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        throw runtime_error("file open error");
    }
    ReadLongLines(result, fp);
    fclose(fp);
}

//  長い入力を read から読んで、result に格納する
void ReadLongLines(vector<string> &result, const string &filename) {
    ReadLongLines(result, filename.c_str());
}

//  長い入力を read から読んで、result に格納する
void ReadLongLines(vector<string> &result, FILE *read) {
    char buf[100000];
    for (int i = 0; i < result.size(); i++) {
        fgets(buf, 100000, read);
        result[i] = buf;
    }
}

//  長い入力を read から読んで、result に格納する
void ReadLongLines(vector<string> &result, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        throw runtime_error("file open error");
    }
    ReadLongLines(result, fp);
    fclose(fp);
}

//  長い入力を read から読んで、result に格納する
void ReadLongLines(vector<string> &result, const string &filename) {
    ReadLongLines(result, filename.c_str());
}

//  長い入力を read から読んで、result に格納する
void ReadLongLines(vector<string> &result, FILE *read) {
    char buf[100000];
    for (int i = 0; i < result.size(); i++) {
        fgets(buf, 100000, read);
        result[i] = buf;
    }
}

//  長い入力を read から読んで、result に格納する
void ReadLongLines(vector<string> &result, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        throw runtime_error("file open error");
    }
    ReadLongLines(result, fp);
    fclose(fp);
}

//  長い入力を read から読んで、result に格納する
void ReadLongLines(vector<string> &result, const string &filename) {
    ReadLongLines(result, filename.c_str());
}

//  長い入力を read から読んで、result に格納する
void ReadLongLines(vector<string> &result, FILE *read) {
    char buf[100000];
    for (int i = 0; i < result.size(); i++) {
        fgets(buf, 100000, read);
        result[i] = buf;
    }
}

//  長い入力を read から読んで、result に格納する
void ReadLongLines(vector<string> &result, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        throw runtime_error("file open error");
    }
    ReadLongLines(result, fp);
    fclose(fp);
}

//  長い入力を read から読んで、result に格納する
void ReadLongLines(vector<string> &result, const string &filename) {
    ReadLongLines(result, filename.c_str());
}

//  長い入力を read から読んで、result に格納する
void ReadLongLines(vector<string> &result, FILE *read) {
    char buf[100000];
    for (int i = 0; i < result.size(); i++) {
        fgets(buf, 100000, read);
        result[i] = buf;
    }
}

//  長い入力を read から読んで、result に格納する
void ReadLongLines(vector<string> &result, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        throw runtime_error("file open error");
    }
    ReadLongLines(result, fp);
    fclose(fp);
}

//  長い入力を read から読んで、result に格納する
void ReadLongLines(vector<string> &result, const string &filename) {
    ReadLongLines(result, filename.c_str());
}

//  長い入力を read から読んで、result に格納する
void ReadLongLines(vector<string> &result, FILE *read) {
    char buf[100000];
    for (int i = 0; i < result.size(); i++) {
        fgets(buf, 100000, read);
        result[i] = buf;
    }
}

//  長い入力を read から読んで、result に格納する
void ReadLongLines(vector<string> &result, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        throw runtime_error("file open error");
    }
    ReadLongLines(result, fp);
    fclose(fp);
}

//  長い入力を read から読んで、result に格納する
void ReadLongLines(vector<string> &result, const string &filename) {
    ReadLongLines(result, filename.c_str());
}

//  長い入力を read から読んで、result に格納する
void ReadLongLines(vector<string> &result, FILE *read) {
    char buf[100000];
    for (int i = 0; i < result.size(); i++) {
        fgets(buf, 100000, read);
        result[i] = buf;
    }
}

//  長い入力を read から読んで、result に格納する
void ReadLongLines(vector<string> &result, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        throw runtime_error("file open error");
    }
    ReadLongLines(result, fp);
    fclose(fp);
}

//  長い入力を read から読んで、result に格納する
void ReadLongLines(vector<string> &result, const string &filename) {
    ReadLongLines(result, filename.c_str());
}

//  長い入力を read から読んで、result に格納する
void ReadLongLines(vector<string> &result, FILE *read) {
    char buf[100000];
    for (int i = 0; i < result.size(); i++) {
        fgets(buf, 100000, read);
        result[i] = buf;
    }
}

//  長い入力を read から読んで、result に格納する
void ReadLongLines(vector<string> &result, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        throw runtime_error("file open error");
    }
    ReadLongLines(result, fp);
    fclose(fp);
}

//  長い入力を read から読んで、result に格納する
void ReadLongLines(vector<string> &result, const string &filename) {
    ReadLongLines(result, filename.c_str());
}

//  長い入力を read から読んで、result に格納する
void ReadLongLines(vector<string> &result, FILE *read) {
    char buf[100000];
    for (int i = 0; i < result.size(); i++) {
        fgets(buf, 100000, read);
        result[i] = buf;
    }
}

//  長い入力を read から読んで、result に格納する
void ReadLongLines(vector<string> &result, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        throw runtime_error("file open error");
    }
    ReadLongLines(result, fp);
    fclose(fp);
}

//  長い入力を read から読んで、result に格納する
void ReadLongLines(vector<string> &result, const string &filename) {
    ReadLongLines(result, filename.c_str());
}

//  長い入力を read から読んで、result に格納する
void ReadLongLines(vector<string> &result, FILE *read) {
    char buf[100000];
    for (int i = 0; i < result.size(); i++) {
        fgets(buf, 100000, read);
        result[i] = buf;
    }
}

//  長い入力を read から読んで、result に格納する
void ReadLongLines(vector<string> &result, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        throw runtime_error("file open error");
    }
    ReadLongLines(result, fp);
    fclose(fp);
}

//  長い入力を read から読んで、result に格納する
void ReadLongLines(vector<string> &result, const string &filename) {
    ReadLongLines(result, filename.c_str());
}

//  長い入力を read から<fim_middle>t i = 0; i < times; i++) {
		if (i == 0) {
			con.Printf("%d", m[i])
		} else {
			con.Printf(" %d", m[i])
		}
	}
	con.Println("")
}

int main() {
	con := NewConsole()
	defer con.Flush()

	m := make(map[int]struct{})
	lines, _ := ReadLongLines(4)
	a := strings.Split(lines[1], " ")
	for i := range a {
		n, _ := strconv.Atoi(a[i])
		m[n] = struct{}{}
	}

	result := make([]int, 0, 200000)
	b := strings.Split(lines[3], " ")
	for i := range b {
		n, _ := strconv.Atoi(b[i])
		if _, ok := m[n]; ok {
			delete(m, n)
		} else {
			m[n] = struct{}{}
		}
	}
	for k, _ := range m {
		result = append(result, k)
	}
	sort.Slice(result, func(lhs, rhs int) bool {
		return result[lhs] < result[rhs]
	})
	for j := range result {
		con.Printf("%d\n", result[j])
	}
}
