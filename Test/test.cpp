//10��, 6��, 5��,4��
#include <iostream>
#include <map>
#include <limits>
int capacity[] = { 10, 6, 5, 4 };
class state
{
public:
	state(int _b10, int _b6, int _b5, int _b4)
		:count(0), value(_b10 * 1000 + _b6 * 100 + _b5 * 10 + _b4)
	{
	}
	bool operator<(state rhs)const
	{
		return value < rhs.value;
	}
	int getvalue()const
	{
		return value;
	}
	short count;
protected:
	short value;
};
std::map<int,state> open, close;
//һ������Ϊ4����
void int2array(int content[], state s)
{
	int svalue = s.getvalue();
	content[0] = svalue / 1000;
	content[1] = svalue % 1000 / 100;
	content[2] = svalue % 100 / 10;
	content[3] = svalue % 10;
}
int array2int(int content[])
{
	return content[0] * 1000 + content[1] * 100
		+ content[2] * 10 + content[3];
}
//һ��ת��״̬
void derive(std::pair<int, state> sp)
{
	int c[4], t[4];
	int2array(c, sp.second);
	for (int i = 0; i < 4; ++i) // the bottle to pour from
	{
		if (c[i] == 0)
			continue; // no action on empty bottle
		for (int j = 0; j < 4; ++j) // the bottle to pour to
		{
			if (j == i || c[j] == capacity[j]) // don't pour to self or full bottle
				continue;
			//now we can derive a new state
			//state s=*this;
			//++s.count;
			int balance = capacity[j] - c[j];
			t[0] = c[0];
			t[1] = c[1];
			t[2] = c[2];
			t[3] = c[3];
			if (c[i] > balance) // source has more than target can hold
				t[i] -= balance, t[j] = capacity[j];
			else // target can hold everything currently in source
				t[j] += t[i], t[i] = 0;
			state si(t[0], t[1], t[2], t[3]);
			si.count = sp.second.count + 1;
			auto p = open.find(array2int(t));
			auto q = close.find(array2int(t));
			if (p != open.end()) // might encounter a better state
			{
				if (p->second.count > si.count)
					p->second.count = si.count;
			}
			else if (q == close.end())
			{
				open.insert(std::pair<int, state>(array2int(t),si));
			}
		}
	}
}
int main() {
	int n = 4;
	int input;
	int min = INT_MAX;
	int initvalue = 1;
	//�����ʼ״̬
	open.insert(std::pair<int, state>(10000, state(10, 0, 0, 0)));
	//������ĸ�����Ϊһ����
	for (int i = 0; i < n; i++)
	{
		std::cin >> input;
		if (i == 0)
			initvalue = input;
		else
			initvalue = initvalue * 10 + input;
	}
	//���������ռ�,ȡ��open״̬����close����״̬����open
	while (!open.empty())
	{
		auto p = open.begin();
		auto s = *p;
		close.insert(s);
		open.erase(p);
		derive(s);
	}
	//printf 
	for (auto i = close.begin(); i != close.end(); ++i)
	{
		std::cout << i->first << " " << i->second.count << std::endl;
	}
	auto i = close.find(initvalue);
	if(i != close.end())
		if (min > i->second.count)
			min = i->second.count;
	if (min == INT_MAX)
		std::cout << -1 << std::endl;
	std::cout << min << std::endl;
	return 0;
}