#include <iostream>
#include <string>
#include <vector>
class Solution {
public:
	int countMovetimes(std::vector<int> v)
	{
		int Movetimes = 0;
		int sum = 0;
		int average = 0;
		int move = 0;
		bool NoaverFlag = true;
		for (auto vit : v)
		{
			sum += vit;
		}
		average = sum / v.size();
		if (average*v.size() != sum)
			return Movetimes;
		for (auto it : v)
		{
			if (it != average)
			{
				NoaverFlag = false;
				break;
			}
		}
		while (!NoaverFlag)
		{
			for (int i = 0; i < v.size(); i++)
			{
				if (i == 0 && v[i]>average)
				{
					move = v[i] - average;
					Movetimes += move;
					v[i + 1] += move;
					v[i] = average;
				}
				else if (i == v.size() - 1 && v[i] > average)
				{
					move = v[i] - average;
					Movetimes += move;
					v[i - 1] += move;
					v[i] = average;
				}
				else if (v[i] > average)
				{
					int lj = i - 1;
					int rj = i + 1;
					while (lj >= 0)
					{
						if (v[lj] < average)
							break;
						lj--;
					}
					while (rj <= v.size() - 1)
					{
						if (v[rj] < average)
							break;
						rj++;
					}
					if (lj<0 && rj>v.size() - 1)
						break;
					if ((lj - i <= rj - i&&lj >= 0) | rj > v.size() - 1)
					{
						move = average - v[lj];
						Movetimes += move;
						v[i - 1] += move;
						v[i] = v[i] - move;
					}
					else if ((lj - i > rj - i&& rj <= v.size() - 1) | lj < 0)
					{
						move = average - v[rj];
						Movetimes += move;
						v[i + 1] += move;
						v[i] = v[i] - move;
					}
				}
			}
			NoaverFlag = true;
			for (auto it : v)
			{
				if (it != average)
				{
					NoaverFlag = false;
					break;
				}
			}
		}
		return Movetimes;
	}
	int inputs() {
		int n = 0;
		std::cin >> n;
		std::vector<int> vectorn;
		while (n--)
		{
			int input;
			std::cin >> input;
			vectorn.push_back(input);
		}
		std::cout << countMovetimes(vectorn) << std::endl;
		return 0;
	}
};