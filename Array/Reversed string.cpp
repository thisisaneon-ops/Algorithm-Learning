#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
// 逆序字符串
string s = "Helloworld";
const int length = s.size();
void reverse_string()
{
	int i = 0;
	int j = length - 1;
	while (i < j)
	{
		swap(s[i], s[j]);
		i++;
		j--;
	}
}
int main()
{
	cout << s << endl;
	reverse_string();
	cout << s;
	return 0;
}
