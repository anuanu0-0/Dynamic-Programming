// Time Complexity: O(n)
#include<iostream>
#include<climits>

using namespace std;

// Top Down DP
int minStepsTD(int n, int dp[]) {
	// Base Case
	if(n==1)
		return 0;
	// If the value is already computed 
	// Dont recompute it.
	if(dp[n]!=0)
		return dp[n];
	int op1, op2, op3;
	op1=op2=op3=INT_MAX;
	if(n%3==0){
		op1=minStepsTD(n/3, dp)+1;
	}
        if(n%2==0){
		op2=minStepsTD(n/2, dp)+1;
	}
	op3=minStepsTD(n-1, dp)+1;

	// Return min of all possible values
	int res = min(min(op1, op2), op3);
	return dp[n]=res;
}

// Bottom Up DP
int minStepsBU(int n){
	int dp[100]={0};
	dp[1]=0;
	for(int i=2; i<=n; i++){
		int op1, op2, op3;
		op1=op2=op3=INT_MAX;
		if(n%3==0){
			op1=dp[i/3];
		}
		if(n%2==0){
			op2=dp[i/2];
		}
		op3=dp[i-1];

		dp[i] = min(min(op1, op2), op3)+1;
	}
	return dp[n];
}

// Driver
int main() { 
	int n;
	cin >> n;
	int dp[100]={0};
	cout << minStepsTD(n, dp)<<endl;
	cout << minStepsBU(n);
}


