#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;

int part(int p[], int in[], int start, int _end)
{
    int pivot = p[_end];
    int pIndex = start;
    for (int i = start; i < _end; i++)
    {
        if (p[i] <= pivot)
        {
            swap(p[i], p[pIndex]);
            swap(in[i], in[pIndex]);
            pIndex++;
        }
    }
    swap (p[pIndex], p[_end]);
    swap (in[pIndex], in[_end]);
    return pIndex;
}
void quicksort(int p[], int in[], int start, int _end)
{
    if (start >= _end) {
        return;
    }
    int pivot = part(p, in, start, _end);
    quicksort(p, in, start, pivot - 1);
    quicksort(p, in, pivot + 1, _end);
}

int main()
{
	setlocale(0, "");
	srand(time(NULL));
	int n = 10, m = 10, i, j, in, k, candidate1, candidate2, winner, localpower = 0,
	fights = n, splitter, globali, number_of_repeats = 10;
	float mutation, p = 1./m;



	int** A1 = new int* [n];
	for (i = 0; i < n; i++)
		A1[i] = new int[m];
    int** A2 = new int* [n];
	for (i = 0; i < n; i++)
		A2[i] = new int[m];
    int *power = new int[n + fights];
    int** parents = new int*[fights];
	for (i = 0; i < fights; i++)
		parents[i] = new int[m];
    int** children = new int* [fights];
	for (i = 0; i < fights; i++)
		children[i] = new int[m];
    int *index = new int[n + fights];


    for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			A1[i][j] = rand() % 2;
	cout << "Population0" << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cout.width(4);
			cout << A1[i][j];
		}
		cout << endl;
	}
	//тут наверное глобальный цикл
	for (globali = 1; globali < number_of_repeats; globali+=2)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                localpower += A1[i][j];
            }
            power[i] = localpower;
            localpower = 0;
        }

        for (int fight = 0; fight < fights; fight++)
        {
            candidate1 = rand() % n;
            candidate2 = rand() % n;
            if (power[candidate1] > power[candidate2])
            {
                for (i = 0; i < m; i++)
                    parents[fight][i] = A1[candidate1][i];
            }
            if (power[candidate1] < power[candidate2])
            {
                for (i = 0; i < m; i++)
                    parents[fight][i] = A1[candidate2][i];
            }
            if (power[candidate1] == power[candidate2])
            {
                winner = rand() % 2;
                if (winner == 0)
                    for (i = 0; i < m; i++)
                        parents[fight][i] = A1[candidate1][i];
                if (winner == 1)
                    for (i = 0; i < m; i++)
                        parents[fight][i] = A1[candidate2][i];

            }
        }
        for (i = 0; i < fights; i+=2)
        {
            splitter = 1 + rand() % 9;
            for (j = 0; j < splitter; j++)
            {
                children[i][j] = parents[i][j];
                children[i+1][j] = parents[i+1][j];
            }
            for (j = splitter; j < m; j++)
            {
                children[i][j] = parents[i + 1][j];
                children[i+1][j] = parents[i][j];
            }
        }
        for (i = 0;i< fights;i++)
        {
            for (j = 0; j<m;j++)
            {
                 mutation = ((double) rand() / (RAND_MAX));
                if (mutation <= p)
                {
                    if (children[i][j] == 0)
                        children[i][j] = 1;
                    if (children[i][j] == 1)
                        children[i][j] = 0;
                }
            }
        }
        for (i = 0; i < fights; i++)
        {
            for (j = 0; j < m; j++)
            {
                localpower += children[i][j];
            }
            power[i+n] = localpower;
            localpower = 0;
        }
        for (i = 0; i < fights + n; i++)
            index[i] = i;
        quicksort(power, index, 0, n + fights - 1);
        for (i = 0, k = fights + n-1; i < n; i++,k--)
        {
            in = index[k];
            if (in <= 9)
            {
                for (j = 0; j < m; j++)
                    A2[i][j] = A1[in][j];
            }
            if (in >= 10)
            {
                in -= 10;
                 for (j = 0; j < m; j++)
                    A2[i][j] = children [in][j];
            }
        }
        cout << "Population" << globali << endl;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                cout.width(4);
                cout << A2[i][j];
            }
            cout << endl;
        }
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                localpower += A2[i][j];
            }
            power[i] = localpower;
            localpower = 0;
        }

        for (int fight = 0; fight < fights; fight++)
        {
            candidate1 = rand() % n;
            candidate2 = rand() % n;
            if (power[candidate1] > power[candidate2])
            {
                for (i = 0; i < m; i++)
                    parents[fight][i] = A2[candidate1][i];
            }
            if (power[candidate1] < power[candidate2])
            {
                for (i = 0; i < m; i++)
                    parents[fight][i] = A2[candidate2][i];
            }
            if (power[candidate1] == power[candidate2])
            {
                winner = rand() % 2;
                if (winner == 0)
                    for (i = 0; i < m; i++)
                        parents[fight][i] = A2[candidate1][i];
                if (winner == 1)
                    for (i = 0; i < m; i++)
                        parents[fight][i] = A2[candidate2][i];

            }
        }
        for (i = 0; i < fights; i+=2)
        {
            splitter = 1 + rand() % 9;
            for (j = 0; j < splitter; j++)
            {
                children[i][j] = parents[i][j];
                children[i+1][j] = parents[i+1][j];
            }
            for (j = splitter; j < m; j++)
            {
                children[i][j] = parents[i + 1][j];
                children[i+1][j] = parents[i][j];
            }
        }
        for (i = 0;i< fights;i++)
        {
            for (j = 0; j<m;j++)
            {
                 mutation = ((double) rand() / (RAND_MAX));
                if (mutation <= p)
                {
                    if (children[i][j] == 0)
                        children[i][j] = 1;
                    if (children[i][j] == 1)
                        children[i][j] = 0;
                }
            }
        }
        for (i = 0; i < fights; i++)
        {
            for (j = 0; j < m; j++)
            {
                localpower += children[i][j];
            }
            power[i+n] = localpower;
            localpower = 0;
        }
        for (i = 0; i < fights + n; i++)
            index[i] = i;
        quicksort(power, index, 0, n + fights - 1);
        for (i = 0, k = fights + n-1; i < n; i++,k--)
        {
            in = index[k];
            if (in <= 9)
            {
                for (j = 0; j < m; j++)
                    A1[i][j] = A2[in][j];
            }
            if (in >= 10)
            {
                in -= 10;
                 for (j = 0; j < m; j++)
                    A1[i][j] = children [in][j];
            }
        }
        cout << "Population" << globali+1 << endl;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                cout.width(4);
                cout << A1[i][j];
            }
            cout << endl;
        }
    }


    for (i = 0; i < n; i++)
		delete [] A2[i];
	delete[] A2;
	for (i = 0; i < fights; i++)
		delete[] children[i];
	delete[] children;
	for (i = 0; i < fights; i++)
		delete[] parents[i];
	delete[] parents;
	delete[] index;
	delete[] power;
	for (i = 0; i < n; i++)
		delete [] A1[i];
	delete[] A1;

}
