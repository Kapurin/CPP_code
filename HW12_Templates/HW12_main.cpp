/* Программа реализует шаблонную функцию "sum_all" 
*/


#include <iostream>
#include <conio.h>
#include <vector>

using namespace std;


template <typename T>
T sum_all(T Name)
{
	T RetN = Name;

	return RetN;
}


template <typename T>
T sum_all(vector<T> VName)
{

	auto Sum = VName[0];
	//if (sizeof(char) != sizeof(T))
	//{
		for (size_t i = 1; i < VName.size(); i++)
		{
			Sum = Sum + VName[i];
		}
		return Sum;
	//}
	//else if (sizeof(char) == sizeof(T))
	//{
	//	//int N = VName.size();
	//	char Arr1[];
	//	for (size_t i = 0; i < VName.size(); i++)
	//	{
	//		Arr1[i] = VName[i];
	//	}

	//	return Arr1[VName.size()];
	//}
}



int main()
{
	vector<int> v1 = { 1, 2, 3 };
	vector<double> v2 = { 1.0, 2.0, 3.0 };
	vector<string> v3 = { "a", "bc", "def" };
	vector<char> v4 = { 'a', 'b', 'c' };


	cout << sum_all(5) << endl;
	cout << sum_all(3.0) << endl;
	cout << sum_all(v1) << endl;
	cout << sum_all(v2) << endl;
	cout << sum_all(v3) << endl;
//	cout << static_cast <string>(sum_all(v4)) << endl;
	cout << sum_all(v4) << endl;

	_getch();
	return 0;
}