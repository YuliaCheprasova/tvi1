#include <iostream>
#include <ctime>
#include <algorithm>
#include <cmath>


using namespace std;
const double pi = 3.141592653589793;

int part(float p[], int in[], int start, int _end)
{
    float pivot = p[_end];
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
void quicksort(float p[], int in[], int start, int _end)
{
    if (start >= _end) {
        return;
    }
    int pivot = part(p, in, start, _end);
    quicksort(p, in, start, pivot - 1);
    quicksort(p, in, pivot + 1, _end);
}
int part(float p[], float in[], int start, int _end)
{
    float pivot = p[_end];
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
void quicksort(float p[], float in[], int start, int _end)
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
    float mut, p_weak = 1./(3.*m), p_average = 1./m, p_strong = 3./m;
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

void selection (string sel_switch, float *power, int fights, int n, int **parents, int **A, int m)
{
    float *temp_power = new float[n];
    float sumpower = 0;
    int *marks = new int[n];
    int *index = new int[n];
    int fight, i, j, candidate1, candidate2, winner, cont = 0, k, sumrang = 0;
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
            if (randp >= 0&&randp < p[0])
            {
                for (i = 0; i < m; i++)
                    parents[fight][i] = A[0][i];
                continue;
            }
            for (j = 0; j < n-1; j++)
            {
                if (randp < p[j+1]&&randp >=p[j])
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

void count_x(int **A, int n, int m, float h, int left, float *x1, float *x2, bool parents = false)
{
    int temp = 0, i, j, k;
    for (i = 0; i < n; i++)
    {
        for (j = 0, k = m/2-1; j < m/2; j++, k--)
        {
            if (A[i][j] == 1)
            {
                temp += pow(2,k);
            }
        }
        if (parents)
            x1[i] = h*temp + left;
        else
            x1[i+n] = h*temp + left;
        temp = 0;
        for (j = m/2, k = m/2-1; j < m; j++, k--)
        {
            if (A[i][j] == 1)
            {
                temp += pow(2,k);
            }
        }
        if (parents)
            x2[i] = h*temp + left;
        else
            x2[i+n] = h*temp + left;
        temp = 0;
    }
}

void func(float *x1, float *x2, float *power, int n, int kind_of_func, bool parents = false)
{
    int i, j = 0, k;
    float ax, bx, zx1, zx2, sum;
    int *a {new int[25]{ -32, -16, 0, 16, 32, -32, -16, 0, 16, 32, -32, -16, 0, 16, 32, -32, -16, 0, 16, 32, -32, -16, 0, 16, 32}};
    int *b {new int[25]{ -32, -32, -32, -32, -32, -16, -16, -16, -16, -16, 0, 0, 0, 0, 0, 16, 16, 16, 16, 16, 32, 32, 32, 32, 32}};
    if (parents == false)
    {
        j = n;
        n = n*2;
    }
    if (kind_of_func == 1)
        for (i = j; i < n; i++)
            power[i] = -(0.1*x1[i]*x1[i]+0.1*x2[i]*x2[i]-4*cos(0.8*x1[i])-4*cos(0.8*x2[i])+8);
    if (kind_of_func == 2)
        for (i = j; i < n; i++)
        {
            ax = x1[i]*cos(pi/4.)-x2[i]*sin(pi/4.);
            bx = x1[i]*sin(pi/4.)+x2[i]*cos(pi/4.);
            power[i] = -(0.1*1.5*ax*ax+0.1*0.8*bx*bx-4*cos(0.8*1.5*ax)-4*cos(0.8*0.8*bx)+8);
        }
    if (kind_of_func == 3)
        for (i = j; i < n; i++)
            power[i] = -(100*(x2[i]-x1[i]*x1[i])*(x2[i]-x1[i]*x1[i])+(1-x1[i])*(1-x1[i]));
    if (kind_of_func == 4)
        for (i = j; i < n; i++)
            power[i] = -((-10./(0.005*(x1[i]*x1[i]+x2[i]*x2[i])-cos(x1[i])*cos(x2[i]/sqrt(2))+2))+10);
    if (kind_of_func == 5)
        for (i = j; i < n; i++)
            power[i] = -((-100./(100*(x1[i]*x1[i]-x2[i])*(x1[i]*x1[i]-x2[i])+(1-x1[i]*x1[i])*(1-x1[i]*x1[i])+1))+100);
    if (kind_of_func == 6)
        for (i = j; i < n; i++)
            power[i] = -((-1+sin(sqrt(x1[i]*x1[i]+x2[i]*x2[i]))*sin(sqrt(x1[i]*x1[i]+x2[i]*x2[i])))/(1+0.001*(x1[i]*x1[i]+x2[i]*x2[i])));
    if (kind_of_func == 7||kind_of_func == 8)
        for (i = j; i < n; i++)
            power[i] = -(0.5*(x1[i]*x1[i]+x2[i]*x2[i])*(1.6+0.8*cos(1.5*x1[i])*cos(3.14*x2[i])+0.8*cos(sqrt(5)*x1[i])*cos(3.5*x2[i])));
    if (kind_of_func == 9)
        for (i = j; i < n; i++)
            power[i] = -(x1[i]*x1[i]*abs(sin(2*x1[i]))+x2[i]*x2[i]*abs(sin(2*x2[i]))-1/(5*x1[i]*x1[i]+5*x2[i]*x2[i]+0.2)+5);
    if (kind_of_func == 10)
        for (i = j; i < n; i++)
            power[i] = -(0.5*(x1[i]*x1[i]+x1[i]*x2[i]+x2[i]*x2[i])*(1+0.5*cos(1.5*x1[i])*cos(3.2*x1[i]*x2[i])*cos(3.14*x2[i])+0.5*cos(2.2*x1[i])*cos(4.8*x1[i]*x2[i])*cos(3.5*x2[i])));
    if (kind_of_func == 11)
        for (i = j; i < n; i++)
        {
            zx1 = (1./((x1[i]-1)*(x1[i]-1)+0.2))+(1./(2*(x1[i]-2)*(x1[i]-2)+0.15))+(1./(3*(x1[i]-3)*(x1[i]-3)+0.3));
            zx2 = (1./((x2[i]-1)*(x2[i]-1)+0.2))+(1./(2*(x2[i]-2)*(x2[i]-2)+0.15))+(1./(3*(x2[i]-3)*(x2[i]-3)+0.3));
            power[i] = -(-zx1*zx2);
        }
    if (kind_of_func == 12)
        for (i = j; i < n; i++)
        {
            zx1 = (1./((x1[i]-1)*(x1[i]-1)+0.2))+(1./(2*(x1[i]-2)*(x1[i]-2)+0.15))+(1./(3*(x1[i]-3)*(x1[i]-3)+0.3));
            zx2 = (1./((x2[i]-1)*(x2[i]-1)+0.2))+(1./(2*(x2[i]-2)*(x2[i]-2)+0.15))+(1./(3*(x2[i]-3)*(x2[i]-3)+0.3));
            power[i] = -(-(zx1+zx2));
        }
    if (kind_of_func == 13)
    {
        for (i = j; i < n; i++)
        {
            //x1[i]=-32;
            //x2[i]=-32;
            sum = 0;
            for(k = 0; k < 25; k++)
            {
                sum += 1./((k+1)+(x1[i]-a[k])*(x1[i]-a[k])*(x1[i]-a[k])*(x1[i]-a[k])+(x2[i]-b[k])*(x2[i]-b[k])*(x2[i]-b[k])*(x2[i]-b[k]));
            }
            power[i] = -(1./(1./500.+sum));
        }
    }
    delete[] a;
    delete[] b;
}


void limits(float*left, float *right, int kind_of_func, float* opt1, float* opt2)
{
    if (kind_of_func == 1||kind_of_func == 2||kind_of_func == 4)
    {
        *left = -16;
        *right = 16;
        *opt1 = 0;
        *opt2 = 0;
    }
    if (kind_of_func == 3)
    {
        *left = -2;
        *right = 2;
        *opt1 = 1;
        *opt2 = 1;
    }
    if (kind_of_func == 5)
    {
        *left = -10;
        *right = 10;
        *opt1 = 1;
        *opt2 = 1;
    }
    if (kind_of_func == 6)
    {
        *left = -10;
        *right = 10;
        *opt1 = 0;
        *opt2 = 0;
    }
    if (kind_of_func == 7)
    {
        *left = -2.5;
        *right = 2.5;
        *opt1 = 0;
        *opt2 = 0;
    }
    if (kind_of_func == 8)
    {
        *left = -5;
        *right = 5;
        *opt1 = 0;
        *opt2 = 0;
    }
    if (kind_of_func == 9)
    {
        *left = -4;
        *right = 4;
        *opt1 = 0;
        *opt2 = 0;
    }
    if (kind_of_func == 10)
    {
        *left = 0;
        *right = 4;
        *opt1 = 0;
        *opt2 = 0;
    }
    if (kind_of_func == 11||kind_of_func == 12)
    {
        *left = 0;
        *right = 4;
        *opt1 = 1.99516;
        *opt2 = 1.99516;
    }
    if (kind_of_func == 13)
    {
        *left = -65;
        *right = 65;
        *opt1 = -32;
        *opt2 = -32;
    }
}

int main()
{
	setlocale(0, "");
	srand(time(NULL));
	string sel_switch = "rang";// prop, rang, tour
	int cross_switch = 3;//1, 2, 3
	string mut_switch = "strong";//weak, average, strong
	//плохо 6
	int kind_of_func = 6;//1 - Растригина, 2 - Растригина овражная, 3 - Розенброка, 4 - Гриванка, 5 - Де Йонга, 6 - Сомбреро,
	//7 - Катникова1, 8 - Катникова2, 9 - функция9, 10 - функция10, 11 - мультипликативная, 12 - аддитивная, 13 - лисьи норы
	int n = 100, m = 0, s = 1, i, j, in, k, fights = n*2, globali, i_launch, number_of_popul = 100, gener;
	float left, right, e = 0.01, nparts, h, opt1, opt2, number = 0, reability, number_of_launch = 100, min_diff1, min_diff2, x1min,
	x2min, powermin, sum_gener = 0, average_gener;
	bool flag;

    limits(&left, &right, kind_of_func, &opt1, &opt2);
    nparts = (right - left)/e;
    while (s < nparts + 1)
    {
        s *= 2;
        m++;
    }
    h = (right - left)/(pow(2,m)-1);
    //cout << h << endl;
    m *= 2;



	int** A1 = new int* [n];
	for (i = 0; i < n; i++)
		A1[i] = new int[m];
    int** A2 = new int* [n];
	for (i = 0; i < n; i++)
		A2[i] = new int[m];
    float *power1 = new float[n*2];
    float *power2 = new float[n];
    int** parents = new int*[fights];
	for (i = 0; i < fights; i++)
		parents[i] = new int[m];
    int** children = new int* [fights];
	for (i = 0; i < fights; i++)
		children[i] = new int[m];
    int *index = new int[n + fights];
    float *x1 = new float[n*2];
    float *x2 = new float[n*2];
    float *x12 = new float[n];
    float *x22 = new float[n];

    //цикл запусков
    for (i_launch = 0; i_launch < number_of_launch; i_launch++)
    {
        flag = false;

        //инициализация
        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++)
                A1[i][j] = rand() % 2;

        count_x(A1, n, m, h, left, x1, x2, true);
        func(x1, x2, power1, n, kind_of_func, true);
        cout << "Launch " << i_launch+1 << endl;
        /*for (i = 0; i < n; i++)
        {
            cout << x1[i] <<" "<< x2[i] <<" "<< power1[i] << endl;
        }*/
        //цикл поколений
        for (globali = 1; globali < number_of_popul; globali++)
        {
            //селекция
            selection (sel_switch, power1, fights, n, parents, A1, m);
            //скрещивание
            cross(fights, m, cross_switch, children, parents);
            //мутация
            mutation(mut_switch, n, m, children);
            count_x(children, n, m, h, left, x1, x2);
            func(x1, x2, power1, n, kind_of_func);
            for (i = 0; i < n*2; i++)
                index[i] = i;
            quicksort(power1, index, 0, fights - 1);
            //создание новой популяции
            for (i = 0, k = fights-1; i < n; i++,k--)
            {
                in = index[k];
                if (in < n)
                {
                    for (j = 0; j < m; j++)
                        A2[i][j] = A1[in][j];
                    power2[i] = power1[k];
                    x12[i] = x1[in];
                    x22[i] = x2[in];
                }
                if (in >= n)
                {
                     for (j = 0; j < m; j++)
                        A2[i][j] = children [in-n][j];
                    power2[i] = power1[k];
                    x12[i] = x1[in];
                    x22[i] = x2[in];
                }
            }
           for (i = 0; i < n; i++)
           {
               power1[i] = power2[i];
               x1[i] = x12[i];
               x2[i] = x22[i];
               for (j=0; j < m; j++)
               {
                   A1[i][j]=A2[i][j];
               }
           }

            min_diff1 = abs(x1[0]-opt1);
            min_diff2 = abs(x2[0]-opt2);
            for (i = 0; i < n; i++)
            {
                if(abs(x1[i]-opt1) <= e&&abs(x2[i]-opt2) <= e)
                {
                    number+=1;
                    cout << x1[i] <<" "<< x2[i] <<" "<< power1[i] << endl;
                    flag = true;
                    gener = globali;
                    cout << gener << endl;
                    sum_gener += gener;
                    break;
                }
                if (abs(x1[i]-opt1)<= min_diff1&&abs(x2[i]-opt2)<= min_diff2)
                {
                    min_diff1 = abs(x1[i]-opt1);
                    min_diff2 = abs(x2[i]-opt2);
                    x1min = x1[i];
                    x2min = x2[i];
                    powermin = power1[i];

                }
            }
            if (flag)
                break;
        }
        if (flag == false)
            cout << x1min <<" "<< x2min <<" "<< powermin << endl;
    }
    reability = number/number_of_launch;
    cout << "Надежность = " << reability << endl;
    average_gener = sum_gener/number_of_launch;
    cout << "В среднем решение находится на  " << average_gener << " поколении" << endl;

    delete[] x1;
    delete[] x2;
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
