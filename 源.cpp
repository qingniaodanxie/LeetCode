#include <iostream>
//#include <regex>
using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		int lens = s.length();
		int lenp = p.length();
		if (lenp == 0)
			return lens == 0;
		if (lens==1)
		{
			if (lens == 0)
				return false;
			if (s.length() != 0 || (p[0] == s[0]) || p[0] == '.')
				return isMatch(s.substr(1), p.substr(1));
		}
		if(lens >= 2)
		{
			if (p[1] != '*')
			{
				if (s.length() != 0 && (p[0] == s[0] || p[0] == '.'))
					return isMatch(s.substr(1), p.substr(1));
			
				else
						return false;
			
			}
			else
				while(s.length()!=0 &&(p[0] == s[0]||p[0] == '.'))
				{
					if (isMatch(s, p.substr(2)))
						return true;
					else
					{
						s = s.substr(1);
					}
				}
			return isMatch(s, p.substr(2));
		}
	}
	
};

int main(int args , char *argv[])
{
	Solution solution;
	string str = "aaaaaa";
	string p = "c*a*b";
	cout <<	solution.isMatch(str, p) << endl;

	system("pause");
	return 0;
}