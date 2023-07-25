#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>


using namespace std;









int main()
{
	int point=0;
	int size = 4;
	int arr[4][2];
	string str;
	string polys = "polys.txt";
	string lines = "lines.txt";
	ofstream fileout_polys, fileout_lines;
	ifstream in(polys);
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
			if (j == 0)
			{
				fileout_polys << "X=" << arr[i][j] << ",";
			}
			if (j == 1)
			{
				fileout_polys << "Y=" << arr[i][j] << "\t";
			}
		}
	}
	fileout_polys.close();

	      while (!in.eof())
	       {
		    getline(in, str);
		     cout << str;
	       }
		  cout << endl;
	in.close();

	int rowcount = 0;
	int columcount = 0;
	string res="";
	//res.push_back(str[2]);
	int r= 0/*stoi(res)*/;
	/*istringstream(res) >> r;*/
	//cout <<r << endl;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i]=='=')
		{
			res = str.substr(i+1)   ;
			
		}

		
		//cout << str[i] << endl;
	}
	r = stoi(res);
	cout << r;
	
	
	fileout_lines.close();

	return 0;
}

























