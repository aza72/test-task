#include <iostream>
#include <string>
#include <fstream>

using namespace std;












int main()
{
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

	
	







	fileout_polys.close();
	fileout_lines.close();

	return 0;
}

























