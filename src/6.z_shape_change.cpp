//
// Created by andrew on 2021/3/9.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static string convert(string s, int numRows) {
//         vector定义的时候，要是不使用insert需要指定要创建多少个vector 如：vector<string> subStr(numRows);
        vector<string> subStr(numRows);

        bool goDown = false;
        int len = s.size();
        int rowsCount = 0;

        for(int i = 0; i < len; i ++) {
            cout << i << s.at(i) << "   rowsCount  "<< rowsCount <<  endl;
            subStr[rowsCount] += s.at(i);
            if (rowsCount == 0 || rowsCount == numRows - 1) goDown = !goDown;
            rowsCount += goDown ? 1:-1;
        }

        string retStr;
        iterator<string>::


        return "";
    }
};

int main(int argc, char*argv[]) {

    Solution::convert("", 3);



    return 0;
}