// Time Complexity : O(n^2)
// Problem Statement: Given n wines in a row, with integers denoting the cost of each wine respectively. 
    //   Each year you can sale the first or the last wine in the row. However, the price of wines increases over time.
    //   Let the initial profits from the wines be P1, P2, P3…Pn. On the Yth year, the profit from the ith wine will be Y*Pi. 
    //   Calculate the maximum profit from all the wines.

#include <iostream>
#include <climits>
using namespace std;

// TOP DOWN DP
int winesProfit(int wines[], int i, int j, int y, int dp[][100]) {
    //  Base Case
        if(i>j)
            return 0;

    //Look Up
        if(dp[i][j]!=0)
            return dp[i][j];
    //  Recursive Case
        int op1 = wines[i]*y + winesProfit(wines, i+1, j, y+1, dp);
        int op2 = wines[j]*y + winesProfit(wines, i, j-1, y+1, dp);

        return dp[i][j]=max(op1, op2);
}

// Driver Function
int main()
{
    int n;
    cin >> n;
    int wines[n], y=1;
    int dp[100][100] = {0}; 
    for(int i=0; i<n; i++)
        cin >> wines[i];
    cout << winesProfit(wines, 0, n-1, y, dp);
    return 0;
}