#include <iostream>
#include <string>
class Solution {
public:
	int Fib2(int n)
	{
		int f1, f2, f3;
		f1 = f2 = f3 = 1;

		if ((n == 1) || (n == 2))
			return f1;

		for (int i = 3; i <= n; i++)
		{
			f1 = f2 + f3;
			f3 = f2;
			f2 = f1;
		}

		return f1;
	}
	int puts() {
		int n = 0;
		std::string inputs;
		std::cin >> n;
		bool AlloneFlag = true;
		while (n--)
		{
			AlloneFlag = true;
			inputs.clear();
			std::cin >> inputs;
			for (auto c : inputs)
			{
				if (c != '1')
				{
					AlloneFlag = false;
					break;
				}
			}
			if (AlloneFlag)
				std::cout << Fib2(inputs.size() + 1) << std::endl;
		}
		return 0;
	}
};