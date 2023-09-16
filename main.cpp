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
void cross(int fights, int m, int cross_switch, int **children, int **parents)
{
    int i, j, k, p, splitter, splitter2;
    if (cross_switch == 1)
        {
            for (i = 0, k = 0; k < fights; i++, k += 2)
            {
                splitter = 1 + rand() % 9;
                for (j = 0; j < splitter; j++)
                {
                    children[i][j] = parents[k][j];
                }
                for (j = splitter; j < m; j++)
                {
                    children[i][j] = parents[k + 1][j];
                }
            }
        }
        if (cross_switch == 2)
        {
            for (i = 0, k = 0; k < fights; i++, k+=2)
            {
                splitter = 1 + rand() % 9;
                splitter2 = 1 + rand() % 9;
                if (splitter < splitter2)
                {
                     for (j = 0; j < splitter; j++)
                    {
                        children[i][j] = parents[k][j];
                    }
                    for (j = splitter; j < splitter2; j++)
                    {
                        children[i][j] = parents[k + 1][j];
                    }
                    for (j = splitter2; j < m; j++)
                    {
                        children[i][j] = parents[k][j];
                    }
                }
                if (splitter2 < splitter)
                {
                     for (j = 0; j < splitter2; j++)
                    {
                        children[i][j] = parents[k][j];
                    }
                    for (j = splitter2; j < splitter; j++)
                    {
                        children[i][j] = parents[k + 1][j];
                    }
                    for (j = splitter; j < m; j++)
                    {
                        children[i][j] = parents[k][j];
                    }
                }
               if (splitter == splitter2)
               {
                   k-=2;
                   i--;
                   continue;
               }
            }
        }
        if (cross_switch == 3)
        {
            for (i = 0, k = 0; k < fights; i++, k+=2)
            {
                for (j = 0; j < m; j++)
                {
                    p = rand()%2;
                    children[i][j] = parents[k+p][j];
                }
            }
        }
}
void mutation(string mut_switch, int fights, int m, int **children)
{
    float mut, p_weak = 1./3.*m, p_average = 1./m, p_strong = 3./m;
    int i, j;
    if(mut_switch == "weak"){

            for (i = 0;i< fights;i++)
            {
                for (j = 0; j<m;j++)
                {
                     mut = ((double) rand() / (double)(RAND_MAX));
                    if (mut <= p_weak)
                    {
                        if (children[i][j] == 0)
                            children[i][j] = 1;
                        if (children[i][j] == 1)
                            children[i][j] = 0;
                    }
                }
            }
        }
        if(mut_switch == "average"){

            for (i = 0;i< fights;i++)
            {
                for (j = 0; j<m;j++)
                {
                     mut = ((double) rand() / (RAND_MAX));
                    if (mut <= p_average)
                    {
                        if (children[i][j] == 0)
                            children[i][j] = 1;
                        if (children[i][j] == 1)
                            children[i][j] = 0;
                    }
                }
            }
        }
        if(mut_switch == "strong"){

            for (i = 0;i< fights;i++)
            {
                for (j = 0; j<m;j++)
                {
                     mut = ((double) rand() / (RAND_MAX));
                    if (mut <= p_strong)
                    {
                        if (children[i][j] == 0)
                            children[i][j] = 1;
                        if (children[i][j] == 1)
                            children[i][j] = 0;
                    }
                }
            }
        }
}
void cout_popul(int globali, int **A, int n, int m)
{
    int i, j;
     cout << "Population" << globali << endl;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                cout.width(4);
                cout << A[i][j];
            }
            cout << endl;
        }
}

int main()
{
	setlocale(0, "");
	srand(time(NULL));
	int cross_switch = 3;//2, 3
	string mut_switch = "weak";//average, strong
	int n = 6, m = 10, i, j, in, k, candidate1, candidate2, winner, localpower = 0,
	fights = n*2, splitter, splitter2, globali, number_of_repeats = 10, p;




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
    //инициализация
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
	//глобальный цикл
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
        //турнирные бои
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
        //скрещивание
        cross(fights, m, cross_switch, children, parents);
        //мутация
        mutation(mut_switch, fights, m, children);
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
        //создание новой популяции
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
       cout_popul(globali, A2, n, m);
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                localpower += A2[i][j];
            }
            power[i] = localpower;
            localpower = 0;
        }
        //турнирные бои
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
        //скрещивание
        cross(fights, m, cross_switch, children, parents);
        //мутации
        mutation(mut_switch, fights, m, children);
        //определение силы
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
        //создание новой популяции
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
        cout_popul(globali, A1, n, m)
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
