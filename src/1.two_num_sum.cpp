//
// Created by andrew on 2021/3/5.
//
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

// 暴力求解
class Solution {
public:
    vector<int> twoSum1(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; i++){
            for (int j = i+1;j < n; j ++){
                if (nums[i] + nums[j] == target)
                    return {i, j};
            }
        }
        return {};
    }

    vector<int> twoSum2(vector<int>& nums, int target) {
        unordered_map<int, int> hashTable;
        for (int i = 0;i < nums.size(); i++) {
            auto it = hashTable.find(target - nums[i]);
            if(it != hashTable.end())
                return {it->second, i};
            hashTable[nums[i]] = i;
        }
        return {};
    }

};

int main(int argc, char *argv[])
{

    vector<int> nums = {2,7,11,15};
    vector<int> retVal = {};
    int target = 9;
    Solution solution;
    retVal = solution.twoSum1(nums, target);
    int n = retVal.size();
    for (int i = 0; i < n; i ++) {
        cout << retVal[i] << endl;
    }
    cout << "+++++++++++++++++++++++++++++++" << endl;
    retVal = solution.twoSum2(nums, target);
    n = retVal.size();
    for (int i = 0; i < n; i ++) {
        cout << retVal[i] << endl;
    }

    return 0;
}