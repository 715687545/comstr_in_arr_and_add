#include "iostream"
#include "cstring"
#include "stdio.h"
#include "vector"

using namespace std;

//将一串字符串按某符号切割
//将其转为数组
//然后将另一串字符串与之比对
//看是否被包含

int compare(string s1, string s2);//单个字符串中字符比较
vector<string> split(const string& str, const string& delim);//数组分割
static string compstr_in_arr_and_add(string a, string b, string c);
int main()
{
	string a = "efrg,eregvs,efwef,wefew";
	string b = "efrd";
	string c = ",";
	cout << "the old:"<<a.c_str();
	string d = compstr_in_arr_and_add(a, b, c);
	cout << a.c_str();
	
	system("pause");
	return 0;
}
static string compstr_in_arr_and_add(string a, string b, string c)
{

	vector<string> res = split(a, c);
	int j = 0;
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i].c_str() << endl;
		int p = compare(res[i].c_str(), b);
		j = j + p;

	}
	////////如果不匹配j=0000，加上新加的串
	if (j == 0)
	{
		a = a + c + b;
		cout << a.c_str() << endl << endl;
	}
	else
	{
	}
	return a;
}
vector<string> split(const string& str, const string& delim)
{
	vector<string> res;
	if ("" == str) return res;
	//先将要切割的字符串从string类型转换为char*类型
	char * strs = new char[str.length() + 1]; //不要忘了
	strcpy(strs, str.c_str());

	char * d = new char[delim.length() + 1];
	strcpy(d, delim.c_str());

	char *p = strtok(strs, d);
	while (p) {
		string s = p; //分割得到的字符串转换为string类型
		res.push_back(s); //存入结果数组
		p = strtok(NULL, d);
	}

	return res;
}
int compare(string s1, string s2)//比较字符串是否相等
{
	int len1 = s1.length();//第一个字符串长度
	int len2 = s2.length();//第二个字符串长度
	int n = 0;
	if (len1 == len2)
	{
		for (int i = 0; i < len1; i++)
		{

			if (s2[i] != s1[i])
			{
				cout << "不匹配" << endl;
				return 0;
			}
			else
			{
			}
		}
		cout << "不匹配" << endl;
		return 1;
	}
	else
	{
		cout << "不匹配" << endl;
		return 0;
	}
}