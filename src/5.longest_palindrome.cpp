//
// Created by andrew on 2021/3/7.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
//     官方使用动态规划
    static string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        string ans;
        for (int l = 0; l < n; ++l) {
            for (int i = 0; i + l < n; ++i) {
                int j = i + l;
                if (l == 0) {
                    dp[i][j] = 1;
                } else if (l == 1) {
                    dp[i][j] = (s[i] == s[j]);
                } else {
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                }
                cout <<"i = " << i << "   j = " << j << " l = " << l << endl;
                if (dp[i][j] && l + 1 > ans.size()) {
                    ans = s.substr(i, l + 1);
                }
            }
            cout << "======================" << endl;
        }

        return ans;
    }
    static pair<int, int> expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
           --left;
           ++right;
        }

        return {left + 1, right - 1};
    }
    // 暴力破解
    static string longestPalindrome2(string s) {
        int start = 0, end = 0;
        pair<int, int> point1, point2;
        for (int i =0; i < s.size(); i ++) {
            // aba 型
            point1 = expandAroundCenter(s, i, i);
            // abba 型
            point2 = expandAroundCenter(s, i, i + 1);

            if(point1.second - point1.first > end - start) {
                start = point1.first;
                end = point1.second;
            }
            if (point2.second - point2.first > end - start) {
                start = point2.first;
                end = point2.second;
            }
        }

        return s.substr(start, end - start + 1);
    }


};


int main(int argc, char*argv[]) {

    cout << Solution::longestPalindrome("abba") << endl;

    cout << Solution::longestPalindrome2("abba") << endl;

    return 0;
}