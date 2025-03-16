#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> input_array(n);
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        stringstream ss(s);
        string temp;
        vector<int> temp_array;
        while (getline(ss, temp, ' '))
        {
            temp_array.push_back(stoi(temp));
        }
        input_array[i] = temp_array;
    }
    vector<vector<int>> outdated;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (input_array[i][0] < input_array[j][0] && input_array[i][1] < input_array[j][1] && input_array[i][2] < input_array[j][2])
            {
                outdated.push_back(input_array[i]);
            }
        }
    }
    outdated = vector<vector<int>>(outdated.begin(), unique(outdated.begin(), outdated.end()));
    int minimum_cost = 100000;
    int input_number = 0;
    for (int i = 0; i < n; i++)
    {
        vector<int> current_item = input_array[i];
        int cost = current_item[3];
        if (find(outdated.begin(), outdated.end(), current_item) == outdated.end() && cost < minimum_cost)
        {
            minimum_cost = cost;
            input_number = i + 1;
        }
    }
    cout << input_number << endl;
    return 0;
}