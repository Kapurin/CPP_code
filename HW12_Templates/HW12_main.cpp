/* Программа реализует шаблонную функцию "sum_all" 
*/


#include <iostream>
#include <conio.h>
#include <vector>
#include <sstream> // для stringstream

using namespace std;


template <typename T>
void sum_all(T Name)
{
	cout << Name << endl;
}


template <typename T>
void sum_all(vector<T> VName)
{
	T Sum = VName[0];
	for (size_t i = 1; i < VName.size(); i++)
	{
		Sum = Sum + VName[i];
	}
	cout << Sum << endl;
}


void sum_all(vector<char> VName)
{
	std::stringstream res;
	for (auto i : VName)
		res << i;
	cout << res.str() << endl;
}



int main()
{
	vector<int> v1 = { 1, 2, 3 };
	vector<double> v2 = { 1.0, 2.0, 3.0 };
	vector<string> v3 = { "a", "bc", "def" };
	vector<char> v4 = { 'a', 'b', 'c' };


	sum_all(5);
	sum_all(3.0);
	sum_all(v1);
	sum_all(v2);
	sum_all(v3);
	sum_all(v4);

	_getch();
	return 0;
}