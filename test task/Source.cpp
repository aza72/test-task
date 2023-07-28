#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>


using namespace std;

//class methods
class methods
{
public:


	methods();
	~methods();
	/*int trw(rectangle A, rectangle B, segments Aseg, segments Bseg);
	{


	}*/

private:

};

methods::methods()
{
}

methods::~methods()
{
}
// end class methods

//class rectangle
class rectangle
{
public:
	rectangle();
	~rectangle();

	void set_x_y(int x, int y);
	int getX();
	int getY();

	void sortPoint(int mass[][2]);




private:
	int x;
	int y;
};

rectangle::rectangle()
{
	this->x = 0;
	this->y = 0;
}

rectangle::~rectangle()
{
}

void rectangle::set_x_y(int x, int y)
{
	this->x = x;
	this->y = y;
}

int rectangle::getX()
{
	return x;
}

int rectangle::getY()
{
	return y;
}
void rectangle::sortPoint(int mass[][2])
{

	int startindex = 0;
	int j = 0;
	int count = 0;
	for (int i = 0; count < 3; i++)
	{

		if (mass[startindex][0] > mass[i + 1][0])
		{
			if (mass[j][0] > mass[i + 1][0])
			{
				j = i + 1;
			}

		}

		if (i == 2)
		{
			swap(mass[startindex][0], mass[j][0]);
			swap(mass[startindex][1], mass[j][1]);
			startindex++;
			count++;
			i = count - 1;
		}
	}
	 
	if (mass[0][1]>mass[1][1])
	{
		swap(mass[0][1], mass[1][1]);
		swap(mass[0][0], mass[1][0]);

	}

	if (mass[2][1] < mass[3][1])
	{
		swap(mass[2][1], mass[3][1]);
		swap(mass[2][0], mass[3][0]);

	}

	
	
}

// end class rectangle

// class segments
class segments
{
public:
	segments();
	~segments();
	void setXsegYseg(int xseg, int yseg);
	int getXseg();
	int getYseg();

private:
	int xseg;
	int yseg;
};

segments::segments()
{
	this->xseg = 0;
	this->yseg = 0;
}

segments::~segments()
{
}

void segments::setXsegYseg(int xseg, int yseg)
{
	this->xseg = xseg;
	this->yseg = yseg;
}

int segments::getXseg()
{
	return xseg;;
}

int segments::getYseg()
{
	return yseg;
}

// end class segments


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
	int mass[4][2];
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i]=='=')
		{
			res = str.substr(i+1)   ;
			r = stoi(res);
		
		    if (columcount == 0 || columcount % 2 == 0)
		    {
			mass[rowcount][columcount] = r;
			columcount++;
		     }
		     else
		      {
			mass[rowcount][columcount] = r;
			rowcount++;
			columcount--;
		      }
		}
		
	}



	/*r = stoi(res);
	cout << r;*/
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 2; j++)
		{
			cout << mass[i][j] << endl;
		}
	}

	fileout_lines.close();
	rectangle A, B, C, D, E;
	E.sortPoint(mass);


	//test
	
	
	A.set_x_y(mass[0][0], mass[0][1]);
	B.set_x_y(mass[1][0], mass[1][1]);

	int f= B.getX();

	segments Aseg;
	Aseg.setXsegYseg(12, 2);
	int g = Aseg.getYseg();

	

 //end test
	
	
   





	return 0;
}

























