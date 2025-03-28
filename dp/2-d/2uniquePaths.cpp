// Question Link - https://leetcode.com/problems/unique-paths/description/

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int memoization(int m, int n, int r, int d, vector<vector<int>> &dp) {
    if(r==m && d==n) {
        return 1;
    }

    if(r>m || d>n)  return 0;
    if(dp[r][d]!=-1)    return dp[r][d];

    int right = memoization(m, n, r + 1, d, dp);
    int down = memoization(m, n, r, d + 1, dp);

    return dp[r][d] = right+down;
}

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return memoization(m-1, n-1, 0, 0, dp);
}

int tabulation(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, -1));

    for(int i = 0; i < m; i++) dp[i][0] = 1; 
    for(int j = 0; j < n; j++) dp[0][j] = 1; 

    for(int i=1; i<m; i++) {
        for(int j=1; j<n; j++) {
            int up = dp[i-1][j];
            int left = dp[i][j-1];

            dp[i][j]=up+left;
        }
    }

    return dp[m-1][n-1];
}