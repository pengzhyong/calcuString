/*
This is a tiny program for study, the function is to calculate the 
result of the string expression.
It's a good demo for how to use string
pengzhyong, 2018/3/7
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
double calcu(string equation);
int main()
{
	string test_str1 = "-1+3*4 -4";
	calcu(test_str1);
	system("pause");
}
double calcu(string equation)
{
	string shortEq;
	double ret = 0;
	const string c = "65535";
	for (auto ch : equation)
	{
		if (ch != ' ')
			shortEq.push_back(ch);
	}

	string retEq(shortEq);
	cout << retEq << endl;
	string::size_type pos = 0;
	//先处理乘除法
	while ((pos = shortEq.find_first_of("*/")) != string::npos)//, pos))
	{
		string::size_type prePos = pos - 1;
		string::size_type lastPos = pos + 1;
		for (auto iter = shortEq.begin() + pos - 1; iter != shortEq.begin(); --iter)
		{
			if (*iter == '+' || *iter == '-' || *iter == '*' || *iter == '/')
			{
				prePos++;
				break;
			}
			prePos--;
		}
		for (auto iter = shortEq.begin() + pos + 1; iter != shortEq.end(); ++iter)
		{
			if (*iter == '+' || *iter == '-' || *iter == '*' || *iter == '/')
			{
				break;
			}
			lastPos++;
		}
		double preNumber = stod(shortEq.substr(prePos, pos - prePos));
		double lastNumber = stod(shortEq.substr(pos + 1, lastPos - pos - 1));
		//cout << preNumber << " " << lastNumber << endl;
		if (shortEq.at(pos) == '*')
			shortEq.replace(prePos, lastPos - prePos, to_string(preNumber*lastNumber));
		else if (shortEq.at(pos) == '/')
			shortEq.replace(prePos, lastPos - prePos, to_string(preNumber / lastNumber));
		cout << shortEq << endl;
	}


	//再处理加减
	bool isNeg = false;
	//对于第一个数是负数的处理，把所有符号都反号，使其变为正数
	if (shortEq.at(0) == '-')
	{
		isNeg = !isNeg;
		shortEq.erase(0, 1);
		for (auto& ch : shortEq)
		{
			if (ch == '+')
				ch = '-';
			else if (ch == '-')
				ch = '+';
		}
	}
	while ((pos = shortEq.find_first_of("+-")) != string::npos)//, pos))
	{
		string::size_type prePos = pos - 1;
		string::size_type lastPos = pos + 1;
		for (auto iter = shortEq.begin() + pos - 1; iter != shortEq.begin(); --iter)
		{
			if (*iter == '+' || *iter == '-')
			{
				prePos++;
				break;
			}
			prePos--;
		}
		for (auto iter = shortEq.begin() + pos + 1; iter != shortEq.end(); ++iter)
		{
			if (*iter == '+' || *iter == '-')
			{
				break;
			}
			lastPos++;
		}
		double preNumber = stod(shortEq.substr(prePos, pos - prePos));
		double lastNumber = stod(shortEq.substr(pos + 1, lastPos - pos - 1));
		//cout << preNumber << " " << lastNumber << endl;
		if (shortEq.at(pos) == '+')
			shortEq.replace(prePos, lastPos - prePos, to_string(preNumber + lastNumber));
		else if (shortEq.at(pos) == '-')
			shortEq.replace(prePos, lastPos - prePos, to_string(preNumber - lastNumber));
		cout << shortEq << endl;

		if (shortEq.at(0) == '-')
		{
			isNeg = !isNeg;
			shortEq.erase(0, 1);
			for (auto& ch : shortEq)
			{
				if (ch == '+')
					ch = '-';
				else if (ch == '-')
					ch = '+';
			}
		}
	}
	if (isNeg)
		shortEq.insert(0, "-");
	cout << retEq << "=" << shortEq << endl;
	return ret;
}