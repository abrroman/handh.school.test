#include <vector>
#include <iostream>
#include <ctime>

static int R = 20;
using namespace std;

void link_swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void selectionsort(vector<int>* arr, bool reverse) {
	int n = (*arr).size();
	for (int i = 0; i < n - 1; ++i)
	{
		int smallestIndex = i;

		if (reverse)
		{
			for (int currentIndex = i + 1; currentIndex < n; ++currentIndex)
			{
				if ((*arr)[currentIndex] > (*arr)[smallestIndex])
					smallestIndex = currentIndex;
			}
		}
		else
		{
			for (int currentIndex = i + 1; currentIndex < n; ++currentIndex)
			{
				if ((*arr)[currentIndex] < (*arr)[smallestIndex])
					smallestIndex = currentIndex;
			}
		}
		link_swap(&(*arr)[i], &(*arr)[smallestIndex]);
	}
}

void sorting(vector<vector<int>>* arr, int n)
{
	for (int i = 0; i < n; i++)
		(i + 1) % 2 ? selectionsort(&((*arr)[i]),true) : selectionsort(&((*arr)[i]),false);

}

bool IsNotInVector(vector<int>* arr, int n, int x)
{
	for (int i = 0; i < n; i++)
		if (x == (*arr)[i]) { return false; }

	return true;
}

void gensizes(int n, vector<int>* arr)
{
	int i = 0;
	while (i != n)
	{
		int size = rand() % R + 1;
		if (IsNotInVector(arr, n, size))
		{
			(*arr)[i] = size;
			i++;
		}
	}
}

void arrgen(vector<int>* sizes, int n, vector<vector<int>>* result)
{
	vector<int> arr;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < (*sizes)[i]; j++)
			arr.push_back(rand() % R + 1);

		(*result).push_back(arr);
		arr.clear();
	}
}

void Out(vector<vector<int>>* result, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < (*result)[i].size(); j++)
			cout << (*result)[i][j] << ' ';
		cout << endl;
	}

}

int main()
{
	srand(time(0));
	int n;
	cout << "Enter parameter n: ";
	cin >> n;
	if (R < n) { R = n + 1; }
	vector<vector<int>> result;
	vector<int> sizes(n, 0);
	gensizes(n, &sizes);
	arrgen(&sizes, n, &result);
	sorting(&result, n);
	Out(&result, n);
}
