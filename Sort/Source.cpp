#include <iostream>



using namespace std;








int main() 
{
	int arr[6];
	cout << "Заполните массив" << endl;
	

	for (int i = 0; i < sizeof(arr); i++)
	{
		cin >> arr[i];
	}

	return 0;
}