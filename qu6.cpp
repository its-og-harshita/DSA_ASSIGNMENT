#include <iostream>
#include <string>
using namespace std;

string longestPalindromicSubstring(string s)
{
    int n = s.size();
    if (n == 0)
        return "";

    int start = 0, maxLength = 1;
    bool **dp = new bool *[n];
    for (int i = 0; i < n; i++)
    {
        dp[i] = new bool[n]();
    }

    for (int i = 0; i < n; i++)
    {
        dp[i][i] = true;
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            dp[i][i + 1] = true;
            start = i;
            maxLength = 2;
        }
    }

    for (int len = 3; len <= n; len++)
    {
        for (int i = 0; i < n - len + 1; i++)
        {
            int j = i + len - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1])
            {
                dp[i][j] = true;
                start = i;
                maxLength = len;
            }
            string result = s.substr(start, maxLength);

            for (int i = 0; i < n; i++)
            {
                delete[] dp[i];
            }
            delete[] dp;

            return result;
        }

        return s.substr(start, maxLength);
    }
}

    int main()
    {
        string input;
        cout << "Enter a string: ";
        cin >> input;

        string result = longestPalindromicSubstring(input);
        cout << "Longest Palindromic Substring: " << result << endl;

        return 0;
    }
