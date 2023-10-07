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
int part(int p[], float in[], int start, int _end)
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
void quicksort(int p[], float in[], int start, int _end)
{
    if (start >= _end) {
        return;
    }
    int pivot = part(p, in, start, _end);
    quicksort(p, in, start, pivot - 1);
    quicksort(p, in, pivot + 1, _end);
}
void cout_popul(int globali, int **A, int n, int m)
{
    int i, j;
     cout << "Population" << globali << endl;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                //cout.width(4);
                cout << A[i][j];
            }
            cout << endl;
        }
}
void cout_one(int globali, int **A, int n, int m)
{
    int i, j, localpower = 0;
    cout << "Population" << globali << endl;
    for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                localpower += A[i][j];
            }
            cout << localpower << endl;
            localpower = 0;
        }
}
void cross(int fights, int m, int cross_switch, int **children, int **parents)
{
    int i, j, k, p, splitter, splitter2;
    if (cross_switch == 1)
        {
            for (i = 0, k = 0; k < fights; i++, k += 2)
            {
                splitter = 1 + (rand() % (m-1));
                //cout << splitter<<endl;
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
                splitter = 1 + (rand() % (m-1));
                splitter2 = 1 + (rand() % (m-1));
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
void mutation(string mut_switch, int n, int m, int **children)
{
    float mut, p_weak = 1./3.*m, p_average = 1./m, p_strong = 3./m;
    int i, j;
    if(mut_switch == "weak"){

            for (i = 0;i< n;i++)
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

            for (i = 0;i< n;i++)
            {
                for (j = 0; j<m;j++)
                {
                     mut = ((double) rand() / (double)(RAND_MAX));
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
        if(mut_switch == "strong")
        {
            for (i = 0;i< n;i++)
            {
                for (j = 0; j<m;j++)
                {
                     mut = ((double) rand() / double(RAND_MAX));
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

void selection (string sel_switch, int *power, int fights, int n, int **parents, int **A, int m)
{
    int *temp_power = new int[n];
    int *marks = new int[n];
    int *index = new int[n];
    int fight, i, sumpower = 0, j, candidate1, candidate2, winner, cont = 0, k, sumrang = 0;
    float *rang = new float[n];
    float *p = new float[n];
    float temp = 0, randp;
    if (sel_switch == "prop")
    {
        for (i = 0; i < n; i++)
        {
            sumpower += power[i];
        }
        for (i = 0; i < n; i++)
        {
            p[i] = temp + (float)power[i]/((float)sumpower);
            //cout << p[i] << endl;
            temp += (float)power[i]/((float)sumpower);
        }
        for (fight = 0; fight < fights; fight++)
        {
            randp = ((double) rand() / (RAND_MAX));
            if (0 <= randp < p[0])
            {
                for (i = 0; i < m; i++)
                    parents[fight][i] = A[0][i];
                continue;
            }
            for (j = 0; j < n-1; j++)
            {
                if (p[j] <= randp < p[j+1])
                {
                    for (i = 0; i < m; i++)
                        parents[fight][i] = A[j+1][i];
                    break;
                }
            }
        }

    }
    if (sel_switch == "rang")
    {
        for (i = 0; i < n; i++)
        {
            temp_power[i] = power[i];
            index[i] = i;//индекс должен начинаться с нуля для функции сортировки
            rang[i] = i + 1;//ранг должен начинаться с одного для пропорций
            marks[i] = 0;
        }
        quicksort(temp_power, index, 0, n - 1);
        /*for (i = 0; i < n; i++)
        {
            cout << temp_power [i] << " " << index[i]  << " " << rang[i] << endl;
        }*/
        //если пригодности одинаковые
        for (i = 0; i < n-1; i++)
        {
            if (marks[i] == 2)
                continue;
            sumrang = i+1;
            for (j = i + 1; j < n; j++)
            {
                if (temp_power[i] == temp_power[j])
                {
                    cont +=1;
                    marks[i] = 1;
                    marks[j] = 1;
                    sumrang += j+1;
                }
            }
            if (cont > 0)
            {
                cont += 1;
                for (k = 0; k < n; k++)
                {
                    if (marks[k] == 1)
                    {
                        rang[k] = (float)sumrang/((float) cont);
                        marks[k] = 2;
                    }
                }
            }
            cont = 0;
            sumrang = 0;
        }

        quicksort(index, rang, 0, n-1);
        /*for (i = 0; i < n; i++)
        {
           cout  << index[i]  << " " << rang[i] << endl;
        }
        for (i = 0; i < n; i++)
        {
            cout << power [i] << " " << index[i]  << " " << rang[i] << endl;
        }*/

        for (i = 0; i < n; i++)
        {
            sumpower += rang[i];
        }
        for (i = 0; i < n; i++)
        {
            p[i] = temp + (float)rang[i]/((float)sumpower);
            //cout << p[i] << endl;
            temp += (float)rang[i]/((float)sumpower);
        }

        for (fight = 0; fight < fights; fight++)
        {
            randp = ((double) rand() / (RAND_MAX));
            if (0 <= randp < p[0])
            {
                for (i = 0; i < m; i++)
                    parents[fight][i] = A[0][i];
                continue;
            }
            for (j = 0; j < n-1; j++)
            {
                if (p[j] <= randp < p[j+1])
                {
                    for (i = 0; i < m; i++)
                        parents[fight][i] = A[j+1][i];
                    break;
                }
            }
        }

    }
    if (sel_switch == "tour")
    {
         for (int fight = 0; fight < fights; fight++)
        {
            candidate1 = rand() % n;
            candidate2 = rand() % n;
            if (power[candidate1] > power[candidate2])
            {
                for (i = 0; i < m; i++)
                    parents[fight][i] = A[candidate1][i];
            }
            if (power[candidate1] < power[candidate2])
            {
                for (i = 0; i < m; i++)
                    parents[fight][i] = A[candidate2][i];
            }
            if (power[candidate1] == power[candidate2])
            {
                winner = rand() % 2;
                if (winner == 0)
                    for (i = 0; i < m; i++)
                        parents[fight][i] = A[candidate1][i];
                if (winner == 1)
                    for (i = 0; i < m; i++)
                        parents[fight][i] = A[candidate2][i];

            }
        }
    }
    delete[] marks;
    delete[] temp_power;
    delete[] index;
    delete[] rang;
    delete[] p;
}


void count_power1 (int n, int m, int *power, int **A)
{
    int i, j, localpower = 0;
    for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                localpower += A[i][j];
            }
            power[i] = localpower;
            localpower = 0;
        }
}

void count_power2 (int n, int fights, int m, int *power, int **children)
{
    int i, j, localpower = 0;
    for (i = 0; i < fights; i++)
        {
            for (j = 0; j < m; j++)
            {
                localpower += children[i][j];
            }
            power[i+n] = localpower;
            localpower = 0;
        }
}

int main()
{
	setlocale(0, "");
	srand(time(NULL));
	string sel_switch = "rang";// prop, rang, tour
	int cross_switch = 1;//1, 2, 3
	string mut_switch = "average";//weak, average, strong
	int n = 250, m = 100, i, j, in, k, fights = n*2, globali, number_of_repeats = 500;
	//candidate1, candidate2, winner, localpower = 0,
	//splitter, splitter2, , p;




	int** A1 = new int* [n];
	for (i = 0; i < n; i++)
		A1[i] = new int[m];
    int** A2 = new int* [n];
	for (i = 0; i < n; i++)
		A2[i] = new int[m];
    int *power1 = new int[n + fights];
    int *power2 = new int[n];
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
	/*cout << "Population0" << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			//cout.width(4);
			cout << A1[i][j];
		}
		cout << endl;
	}*/
	//глобальный цикл
	for (globali = 1; globali < number_of_repeats; globali++)
    {
        count_power1(n, m, power1, A1);
        //for (i = 0; i < n; i++){
           // cout << power[i]<<endl;
        //}

        //селекция
        selection (sel_switch, power1, fights, n, parents, A1, m);
        //cout_popul(100, parents, fights, m);
        //скрещивание
        cross(fights, m, cross_switch, children, parents);
        //cout_popul(200, children, n, m);
        //мутация
        mutation(mut_switch, n, m, children);
        //cout_popul(300, children, n, m);
        count_power2(n, fights, m, power1, children);
        //for (i = 0; i < fights; i++){
            //cout << power[i]<<endl;
        //}
        for (i = 0; i < fights; i++)
            index[i] = i;
        quicksort(power1, index, 0, fights - 1);
        //for (i = 0; i < fights; i++){
            //cout << power[i]<<" "<<index[i]<<endl;
        //}
        //создание новой популяции
        for (i = 0, k = fights-1; i < n; i++,k--)
        {
            in = index[k];
            if (in < n)
            {
                for (j = 0; j < m; j++)
                    A2[i][j] = A1[in][j];
                    power2[i] = power1[in];
            }
            if (in >= n)
            {
                in -= n;
                 for (j = 0; j < m; j++)
                    A2[i][j] = children [in][j];
                    power2[i] = power1[in];
            }
        }
       for (i = 0; i < n; i++)
       {
           for (j=0; j < m; j++)
           {
               A1[i][j]=A2[i][j];
           }
       }
       for (i = 0; i<n;i++)
       {
           power1[i] = power2[i];
       }
       cout_one(globali, A1, n, m);
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
	delete[] power2;
	delete[] power1;
	for (i = 0; i < n; i++)
		delete [] A1[i];
	delete[] A1;

}
