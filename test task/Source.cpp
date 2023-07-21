#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;




class A 
{
public:
	A(int x, int y) {
		
	}
};







int main()
{
	int point=0;
	int size = 4;
	int arr[4][2];
	string polys = "polys.txt";
	string lines = "lines.txt";
	ofstream fileout_polys, fileout_lines;

	fileout_polys.open(polys);
	fileout_lines.open(lines);

	if (!fileout_polys.is_open())
	{
		cout << "File opening error" << endl;
	}

	if (!fileout_lines.is_open())
	{
		cout << "File opening error" << endl;
	}
	
	
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (j==0)
			{
				cout << "enter X ";
				cin >> point;
			}
			else if (j==1)
			{
				cout << "enter Y ";
				cin >> point;
			}
			arr[i][j] = point;
		}

	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (j==0)
			{
				fileout_polys << "X=" << arr[i][j];
			}
			if (j==1)
			{
				fileout_polys << "Y=" << arr[i][j];
			}
		}

	}





	fileout_polys.close();
	fileout_lines.close();

	return 0;
}

























