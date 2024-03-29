
# Longest Common Prefix

## Problem Description

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string `""`.

**Example 1:**
```
Input: ["flower","flow","flight"]
Output: "fl"
```

**Example 2:**
```
Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
```

**Note:**
All given inputs are in lowercase letters `a-z`.

## Solutions
| Name          | Runtime           | Memory  |  Language |
| :-----------: |:-------------:    | :-----: | :-------: |
| Horizontal Scanning  | 4 ms              | 9 MB  |    cpp    |
| Vertical Scanning    | 4 ms              | 8.6 MB  |    cpp    |
