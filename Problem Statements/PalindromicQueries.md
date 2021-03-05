## Given a string s and m queries . Each query consists of (l,r) where 1 <= l <= r <= n(size of string). You need to print whether l to r is a palindromic string or not.A string can be called palindrome if its reverse is same as itself . Ex - "aba" .

### Input Format

First line contains n Second lines contains a string of length n. Next line contains m where m is the number of queries . Next m lines contains two integers l,r as described in the question.

Constraints <pre>
n <= 1000
m <= 100000

</pre>

Output Format

<pre>
for every query from l to r print "YES" if s[l…..r] is palindrome else print "NO" without quotes in a new line.
</pre>

Sample Input

<pre>5
abbac
2
1 4
2 4
</pre>

Sample Output

<pre>YES
NO
</pre>

Explanation

<pre>
s[1….4]="abba", it is a palindrome.
</pre>
