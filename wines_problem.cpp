#include<iostream>
#include<climits>
using namespace std;

// Top Down DP
int winesProfitTD(int wines[], int i, int j, int y , int dp[][100]) {
	// Base Case
	if(i>j)
		return 0;
	// Lookup
	if(dp[i][j]!=0)
		return dp[i][j];
	// Recursive Case
	int op1 = wines[i]*y + winesProfitTD(wines, i+1, j, y+1, dp);
	int op2 = wines[j]*y + winesProfitTD(wines, i, j-1, y+1, dp);

	return dp[i][j] = max(op1, op2);
} 
int main(){
	int n;
	cin >> n;
	int wines[n];
	for(int i=0; i<n; i++)
		cin >> wines[i];
	int dp[100][100]={0};
	// Initial Year = 1
	cout << winesProfitTD(wines, 0, n-1, 1, dp);
}
