#include <iostream>

using namespace std;

int main()
{
	int nums[50];
	for(int i = 1; i <= 50; i++)
	{
		nums[i -1] = i;
	}

	for(int i = 0; i < 50; i++)
	{
		if (nums[i] % 2 == 0 && nums[i] % 5 == 0)
			cout << "CSUSB ";
		else if(nums[i] % 2 == 0)
			cout << "CSU ";
		else if(nums[i] % 5 == 0)
			cout << "SB ";
		else
			cout <<  nums[i] << " ";
	}
	cout << "\nend" << endl;
	return 0;
}
