#include <algorithm>
#include <iomanip>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'plusMinus' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 * 
 * Given an array of integers, calculate the ratios of
 * its elements that are positive, negative, and zero.
 * Print the decimal value of each fraction on a new
 * line with places after the decimal.
 */

void plusMinus(vector<int> arr)
{
    float plus = 0, minus = 0, zero = 0;
    for (int x : arr) {
        if(x > 0) plus++;
        else if(x < 0) minus++;
        else zero++;
    }
    cout << fixed << setprecision(6) << plus/arr.size() << endl;
    cout << fixed << setprecision(6) << minus/arr.size() << endl;
    cout << fixed << setprecision(6) << zero/arr.size() << endl;
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    plusMinus(arr);

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), [](unsigned char c) { return !ispunct(c); }));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), [](unsigned char c) { return !ispunct(c); }).base(),
        s.end());

    return s;
}

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
