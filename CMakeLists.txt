cmake_minimum_required(VERSION 3.2)

project(Achou-leetcode)


#1. 求两数之和
add_executable(1-twoNumberSum src/1.two_num_sum.cpp)
#2.求两数之相加
add_executable(2-addTwoSum src/2.add_two_sum.cpp)
#3.求字符串最长子串
add_executable(3-longs_sub_string src/3.longs_sub_string.cpp)
#4.求两个数组中位数
add_executable(4-find_median_sorted_arrays src/4.find_median_sorted_arrays.cpp)
#5.求最长回文字符串
add_executable(5-longest_palindrome src/5.longest_palindrome.cpp)
#6.求Z型字符串
add_executable(6-z_shape_change src/6.z_shape_change.cpp)
#6.测试
add_executable(test src/test.cpp)