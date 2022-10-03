#include <bits/stdc++.h>
using namespace std;
bool detectCapitalUse(string word) {
    int n = word.length();
    int countLOW=0,countUP=0;
    int i;
    for(i=0;i<n;i++)
    {
        if(word[i] >='A' && word[i] <= 'Z') countUP++;
        else if(word[i] >='a' && word[i] <= 'z') countLOW++;
    }
    if(countUP==n || countLOW==n) return  true;
    else if(word[0] >='A' && word[0] <= 'Z') 
    {
        for(int j=1;j<n;j++)
        {
            if(word[j] >='a' && word[j] <= 'z') continue;
            else return false;
        }
        return true;
    }
    return false;
}
int main()
{
	string s = "Leetcode";
	if(detectCapitalUse(s)) cout<<"true \n";
	else cout<<"false \n";
}
