//
// Created by andrew on 2021/3/7.
//
#include <iostream>
#include <unordered_set>


using namespace std;



class Solution {
public:
    static int lengthOfLongestSubstring(string s) {
//        使用hash集合，记录每个字符是否出现过
        unordered_set<char> occ;
        int n = s.size(); // 求出字符串长度
        // 右下标初始化为 -1 相当于我们在字符串的左边界的左侧，还没有开始移动
        int rk = -1, ans = 0;
        for (int i = 0; i < n; i ++) {
            if(i != 0) {
                // 要是上次的长度的for循环退出，说明需要清除 i-1对应的元素
                occ.erase(s[i - 1]);
            }
            while (rk + 1 < n && !occ.count(s[rk + 1])) {
                // 不断向右移动指针
                occ.insert(s[rk + 1]);
                rk ++;
            }
            ans = max(ans, rk + 1 - i);
        }
        return ans;
    };

};


int main(int argc, char *argv[]) {

    cout << Solution::lengthOfLongestSubstring("") << endl;
    return 0;
}
