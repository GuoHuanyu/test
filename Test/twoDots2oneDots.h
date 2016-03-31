#include <iostream>
#include <string>
class Solution {
public:
	int fs(std::string s){
		int fscount = -1;
		int fscountNew = 0;
		while (fscount != fscountNew)
		{
			fscount = fscountNew;
			for (std::string::iterator iter = s.begin(); iter != s.end(); ++iter)
			{
				if (*iter == '.' && (iter + 1) != s.end() && *(iter + 1) == '.')
				{
					s.erase(iter);
					fscountNew++;
				}
			}
		}
		return fscount;
	}
	int inputs() {
		int m = 0;
		int n = 0;
		int index = 0;
		char c = NULL;
		std::string inputs = "";
		while (std::cin >> m&&std::cin >> n)
		{
			inputs.clear();
			std::cin >> inputs;
			if (inputs.size() != m)
				continue;
			else
			{
				for (int i = 0; i < n; i++)
				{
					std::cin >> index&&std::cin >> c;
					if (index>m - 1 || index < 1)
						continue;
					inputs[index - 1] = c;
					std::cout << fs(inputs) << std::endl;
				}
			}

		}
		return 0;
	}
};