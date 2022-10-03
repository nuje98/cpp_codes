class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower); 
        vector<char>v;
        for(int i=0;i<s.length();i++)
        {
        	if( (s[i] >= 'a'&& s[i] <='z') || (s[i] >= 48 && s[i] <= 57) )
        	{
        		v.push_back(s[i]);
			}
		}
		int i = 0, j = v.size()-1;
		while(i<=j)
		{
			if(v[i] != v[j]) return false;
			i++;
			j--;
		}
		return true;
    }
};
