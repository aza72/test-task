#include <iostream>



using namespace std;





void Merge (int A[], int p, int q, int r);


int main() 
{
	setlocale(LC_ALL, "rus");
	
;	int arr[6];
	cout << "Заполните массив" << endl;
	

	for (int i = 0; i < 6; i++)
	{
		cin >> arr[i];

	}


		Merge(arr, 0, 3, 6);

	return 0;
}

void Merge(int A[], int p, int q, int r) 
{
	 int  countarr=p,countleft=0,countright=0;
	 int left = r - q;
	int right = r - left;

	int *l= new int [left];
	int *ri= new int[right];
	 
	for (int i = 0; i < left; i++)
	{
		l[i] = A[p + i];
	}

	for (int i = 0; i < right; i++)
	{
		ri[i] = A[q + i];
	}
	
	while (countleft < left && countright < right)
	{
		if (l[countleft]<=ri[countright])
		{
			A[countarr] = l[countleft];
			countleft++;
		}
		else
		{
			A[countarr] = ri[countright];
			countright++;
		}
		countarr++;
	}


	while (countleft < left)
	{
		A[countarr] = l[countleft];
		countleft++;
		countarr++;
	}

	while (countright < right)
	{
		A[countarr] = ri[countright];
		countright++;
		countarr++;
	}

	
	delete[] l;
	delete[] ri;
	

}