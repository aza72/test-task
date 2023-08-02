#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>


using namespace std;



int chekk(class rectangle& A, rectangle& B, rectangle& C, rectangle& D, class segments& Aseg, segments& Bseg);
int intersectionOfproctions(int xarec, int yarec, int xbrec, int ybrec, int xaseg, int yaseg, int xbseg, int ybseg);
int intersectionOFsegments(int ax, int ay, int bx, int by, int axseg, int ayseg, int bxseg, int byseg);
int pointAffiliation(int ax, int ay, int bx, int by, int cx, int cy, int axseg, int ayseg);

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
	friend int chekk(class rectangle& A, rectangle& B, rectangle& C, rectangle& D, class segments & Aseg, segments & Bseg);



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


		if (i == 2 )
		{
			if (j!=0)
			{
				swap(mass[startindex][0], mass[j][0]);
				swap(mass[startindex][1], mass[j][1]);
				
			}
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
	friend int chekk(class rectangle& A, rectangle& B, rectangle& C, rectangle& D, class segments& Aseg, segments& Bseg);

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
	ifstream in(polys),in1(lines);
	fileout_polys.open(polys);
	fileout_lines.open(lines);

	if (!fileout_polys.is_open())
	{
		cout << "File opening error" << endl;
	}

	//заполнение
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
	//запись в файл
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
	//считывание
	      while (!in.eof())
	       {
		    getline(in, str);
		     cout << str;//удалить
	       }
		  cout << endl;//удалить
	in.close();

	int rowcount = 0;
	int columcount = 0;
	string res="";
	int r= 0;
	

	//извлечение точек из файла
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

	//cout
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 2; j++)
		{
			cout << mass[i][j] << endl;
		}
	}




	
    rectangle A, B, C, D, E;
	E.sortPoint(mass);
	A.set_x_y(mass[0][0], mass[0][1]);
	B.set_x_y(mass[1][0], mass[1][1]);
	C.set_x_y(mass[2][0], mass[2][1]);
	D.set_x_y(mass[3][0], mass[3][1]);

	if (!fileout_lines.is_open())
	{
		cout << "File opening error" << endl;
	}

	//запись в файл отрезки
	int temp;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (j == 0)
			{
				cout << i << " Enter X=";
				cin >> temp;
				fileout_lines << "X=" << temp << ",";
			}
			if (j == 1)
			{
				cout << i << " Enter Y=";
				cin >> temp;
				fileout_lines << "Y=" << temp << "\t";
			}
		}
		fileout_lines << "\n" ;
	}
	fileout_lines.close();
	//считывание отрезки
	 rowcount = 0;
	 columcount = 0;
	 res = "";
	 r = 0;
	int arrseg[8][2];
	//str = "";
	while (!in1.eof())
	{
		getline(in1, str);
		cout << str;//удалить
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '=')
			{
				res = str.substr(i + 1);
				r = stoi(res);

				if (columcount == 0 || columcount % 2 == 0)
				{
					arrseg[rowcount][columcount] = r;
					columcount++;
				}
				else
				{
arrseg[rowcount][columcount] = r;
rowcount++;
columcount--;
				}
			}

		}

	}

	in1.close();
	segments Aseg, Bseg, A2seg, B2seg, A3seg, B3seg, A4seg, B4seg;
	Aseg.setXsegYseg(arrseg[0][0], arrseg[0][1]);
	Bseg.setXsegYseg(arrseg[1][0], arrseg[1][1]);
	A2seg.setXsegYseg(arrseg[2][0], arrseg[2][1]);
	B2seg.setXsegYseg(arrseg[3][0], arrseg[3][1]);
	A3seg.setXsegYseg(arrseg[4][0], arrseg[4][1]);
	B3seg.setXsegYseg(arrseg[5][0], arrseg[5][1]);
	A4seg.setXsegYseg(arrseg[6][0], arrseg[6][1]);
	B4seg.setXsegYseg(arrseg[7][0], arrseg[7][1]);

	//test


	A.set_x_y(mass[0][0], mass[0][1]);
	B.set_x_y(mass[1][0], mass[1][1]);

	int f = B.getX();


	Aseg.setXsegYseg(12, 2);
	int g = Aseg.getYseg();

	int fr = intersectionOfproctions(4, 5, 3, 7, 4, 4, 5, 2);

	//int dd=intersectionOFsegments(1, 1, 1, 4, 2, 1, 3, 2);

	pointAffiliation(2, 1, 2, 4, 2,2,3,2);

	//end test








	return 0;
}

int chekk(class rectangle& A, rectangle& B, rectangle& C, rectangle& D, class segments& Aseg, segments& Bseg)
{
	int xa = A.getX();
	int ya = A.getY();
	int xb = B.getX();
	int yb = B.getY();
	int xc = C.getX();
	int yc = C.getY();
	int xd = D.getX();
	int yd = D.getY();
	int Xaseg = Aseg.getXseg();
	int Yaseg = Aseg.getYseg();
	int Xbseg = Bseg.getXseg();
	int Ybseg = Bseg.getYseg();

	int Ap,Ap1;
	//проверка принадлежности точки
	Ap=pointAffiliation(xa, ya, xb, yb, xc, yc, Xaseg, Yaseg);
	if (Ap==0)
	{
		Ap = pointAffiliation(xc, yc, xd, yd, xa, ya, Xaseg, Yaseg);
	}
    
	Ap1= pointAffiliation(xa, ya, xb, yb, xc, yc, Xbseg, Ybseg);
	if (Ap1 == 0)
	{
		Ap1 = pointAffiliation(xc, yc, xd, yd, xa, ya, Xbseg, Ybseg);
	}
	if (Ap==1&&Ap1==1)
	{
		return 0;
	}
	if (Ap==1||Ap1==1)
	{
		return 2;
	}
	
	// конец проверка принадлежности точки

	//Пересечение проекций
	int abp, bcp, cdp, dap;

	abp=intersectionOfproctions(xa,ya,xb,yb,Xaseg,Yaseg,Xbseg,Ybseg);
	bcp = intersectionOfproctions(xb, yb, xc, yc, Xaseg, Yaseg, Xbseg, Ybseg);
	cdp = intersectionOfproctions(xc, yc, xd, yd, Xaseg, Yaseg, Xbseg, Ybseg);
	dap = intersectionOfproctions(xd, yd, xa, ya, Xaseg, Yaseg, Xbseg, Ybseg);

	if (abp==0&&bcp==0&&cdp==0&&dap==0)
	{
		return 3;
	}
	//Конец пересечение проекций

	//пересечение отрезков
	int abs, bcs, cds, das;

	abs = intersectionOFsegments(xa, ya, xb, yb, Xaseg, Yaseg, Xbseg, Ybseg);
	if (abs==1)
	{
		return 1;
	}
	bcs = intersectionOFsegments(xb, yb, xc, yc, Xaseg, Yaseg, Xbseg, Ybseg);
	if (bcs == 1)
	{
		return 1;
	}
	cds = intersectionOFsegments(xc, yc, xd, yd, Xaseg, Yaseg, Xbseg, Ybseg);
	if (cds == 1)
	{
		return 1;
	}
	das = intersectionOFsegments(xd, yd, xa, ya, Xaseg, Yaseg, Xbseg, Ybseg);
	if (das == 1)
	{
		return 1;
	}

	


	//конец пересечение отрезков


	return 3;
}
//принадлежность точки
int pointAffiliation(int ax, int ay, int bx, int by, int cx, int cy, int axseg, int ayseg)
{
	int avec, bvec, cvec,AX,AY,BX,BY,count=0;

	AX = axseg - ax;
	AY = ayseg - ay;
	BX = bx - ax;
	BY = by - ay;
	avec = AX * BY - AY * BX;
	if (avec>0)
	{
		count++;
	}
	else
	{
		count--;
	}
	AX = axseg-bx;
	AY = ayseg-by;
	BX = cx-bx;
	BY = cy-by;
	bvec= AX * BY - AY * BX;
	if (bvec > 0)
	{
		count++;
	}
	else
	{
		count--;
	}

	AX = axseg - cx;
	AY = ayseg - cy;
	BX = ax - cx;
	BY = ay - cy;

	cvec= AX * BY - AY * BX;
	if (cvec > 0)
	{
		count++;
	}
	else
	{
		count--;
	}

	if (avec==0||bvec==0||cvec==0)
	{
		return 1;

	}

	if (count==3||count==-3)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	

}
//пересечение отрезков
int intersectionOFsegments(int ax, int ay, int bx, int by, int axseg, int ayseg, int bxseg, int byseg)
{
	int AX, AY,BX,BY,res,res2;
	bool result, result2;
	AX = bx - ax;
	AY = by - ay;

	BX = axseg - ax;
	BY = ayseg - ay;

	res=AX* BY - AY * BX;

	BX = bxseg - ax;
	BY = byseg - ay;

	res2 = AX * BY - AY * BX;

	if (res==0||res2==0)
	{
		return 2;
	}

	if (res>0&&res2<0||res<0&&res2>0)
	{
		result = 1;
	}
	else
	{
		result = 0;
	}

	AX = bxseg-axseg;
    AY = byseg - ayseg;

	BX = ax-axseg;
	BY = ay - ayseg;

	res = AX * BY - AY * BX;

	BX = bx - axseg;
	BY = by - ayseg;

	res2 = AX * BY - AY * BX;

	if (res==0||res2==0)
	{
		return 2;
	}

	if (res > 0 && res2 < 0 || res < 0 && res2>0)
	{
		result2 = 1;
	}
	else
	{
		result2 = 0;
	}

	if (result&&result2)
	{
		return 1;
	}
	if (!result&&!result2)
	{
		return 0;
	}
	
	
}
//пересечение проекций
int intersectionOfproctions(int xarec, int yarec, int xbrec, int ybrec, int xaseg, int yaseg, int xbseg, int ybseg)
{
	bool chekX=false, chekY=false;
	int minXrec, maxXrec, minXseg, maxXseg, resminX, resmaxX;
	int minYrec, maxYrec, minYseg, maxYseg, resminY, resmaxY;
	if (xarec==xaseg||xarec==xbseg||xbrec==xaseg||xbrec==xbseg|| yarec==yaseg||yarec==ybseg||ybrec==yaseg||ybrec==ybseg)
	{
		return 1;
	}

	if (xarec <= xbrec)
	{
		minXrec = xarec;
		maxXrec = xbrec;
	}
	else {
		minXrec = xbrec;
		maxXrec = xarec;
	}

	if (xaseg <= xbseg)
	{
		minXseg = xaseg;
		maxXseg = xbseg;
	}
	else
	{
		minXseg = xbseg;
		maxXseg = xaseg;
	}

	if (minXrec > minXseg)
	{
		resminX = minXrec;
	}
	else
	{
		resminX = minXseg;
	}

	if (maxXrec < maxXseg)
    {
		resmaxX = maxXrec;
    }
	else
	{
		resmaxX=maxXseg;
	}
	//пересечение по х
	if (resminX<resmaxX)
	{
		chekX=true;
	}
	
	//пересечение по х

	if (yarec <= ybrec)
	{
		minYrec = yarec;
		maxYrec = ybrec;
	}
	else {
		minYrec = ybrec;
		maxYrec = yarec;
	}

	if (yaseg <= ybseg)
	{
		minYseg = yaseg;
		maxYseg = ybseg;
	}
	else
	{
		minYseg = ybseg;
		maxYseg = yaseg;
	}

	if (minYrec > minYseg)
	{
		resminY = minYrec;
	}
	else
	{
		resminY = minYseg;
	}

	if (maxYrec < maxYseg)
	{
		resmaxY = maxYrec;
	}
	else
	{
		resmaxY = maxYseg;
	}
	//пересечение по y
	if (resminY < resmaxY)
	{
		chekY=true;
	}
	
	//пересечение по y

	if (chekX||chekY)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}




















