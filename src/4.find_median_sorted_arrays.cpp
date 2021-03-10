//
// Created by andrew on 2021/3/7.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        size_t len1 = 0, len2 = 0;

        len1 = nums1.size();
        len2 = nums2.size();

        size_t sumLen = len1 + len2;
        int i = 0, j = 0;
        bool dataStatus = false;
        int data1 = 0, data2 = 0, data3 = 0;

        if (sumLen % 2 == 0) {
            dataStatus = true;
        }

        for (i = 0, j = 0; i + j <= sumLen / 2;) {

            if (i >= len1) {
                data3 = data2;
                data2 = data1;
                data1 = nums2[j];
                j++;
                continue;
            }
            if (j >= len2) {
                data3 = data2;
                data2 = data1;
                data1 = nums1[i];
                i++;
                continue;
            }

            if (nums1[i] >= nums2[j]) {
                data3 = data2;
                data2 = data1;
                data1 = nums2[j];
                j++;
            } else {
                data3 = data2;
                data2 = data1;
                data1 = nums1[i];
                i++;

            }

        }

        if (dataStatus) {
            return ((double) data2 + (double) data1) / 2;
        } else
            return (double) data1;


    }
};

// 官方答案
class Solution2 {
public:
    int getKthElement(const vector<int>& nums1, const vector<int>& nums2, int k) {
        /* 主要思路：要找到第 k (k>1) 小的元素，那么就取 pivot1 = nums1[k/2-1] 和 pivot2 = nums2[k/2-1] 进行比较
         * 这里的 "/" 表示整除
         * nums1 中小于等于 pivot1 的元素有 nums1[0 .. k/2-2] 共计 k/2-1 个
         * nums2 中小于等于 pivot2 的元素有 nums2[0 .. k/2-2] 共计 k/2-1 个
         * 取 pivot = min(pivot1, pivot2)，两个数组中小于等于 pivot 的元素共计不会超过 (k/2-1) + (k/2-1) <= k-2 个
         * 这样 pivot 本身最大也只能是第 k-1 小的元素
         * 如果 pivot = pivot1，那么 nums1[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums1 数组
         * 如果 pivot = pivot2，那么 nums2[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums2 数组
         * 由于我们 "删除" 了一些元素（这些元素都比第 k 小的元素要小），因此需要修改 k 的值，减去删除的数的个数
         */

        int m = nums1.size();
        int n = nums2.size();
        int index1 = 0, index2 = 0;

        while (true) {
            // 边界情况
            if (index1 == m) {
                return nums2[index2 + k - 1];
            }
            if (index2 == n) {
                return nums1[index1 + k - 1];
            }
            if (k == 1) {
                return min(nums1[index1], nums2[index2]);
            }

            // 正常情况
            int newIndex1 = min(index1 + k / 2 - 1, m - 1);
            int newIndex2 = min(index2 + k / 2 - 1, n - 1);
            int pivot1 = nums1[newIndex1];
            int pivot2 = nums2[newIndex2];
            if (pivot1 <= pivot2) {
                k -= newIndex1 - index1 + 1;
                index1 = newIndex1 + 1;
            }
            else {
                k -= newIndex2 - index2 + 1;
                index2 = newIndex2 + 1;
            }
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totalLength = nums1.size() + nums2.size();
        if (totalLength % 2 == 1) {
            return getKthElement(nums1, nums2, (totalLength + 1) / 2);
        }
        else {
            return (getKthElement(nums1, nums2, totalLength / 2) + getKthElement(nums1, nums2, totalLength / 2 + 1)) / 2.0;
        }
    }
};


int main(int argc, char *argv[]) {
    vector<int> nums1 = {1};
    vector<int> nums2 = {2,3, 4};

    cout << Solution::findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}
