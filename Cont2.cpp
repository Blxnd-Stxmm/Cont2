#include <iostream>
#include <math.h>
using namespace std;
class Poligon
{
private:
    int n;
    double** mass;
    void array()
    {
        mass = new double* [2];
        for (int i = 0; i < 2; i++)
        {
            mass[i] = new double[n];
        }
    }
public:
    Poligon(int _n, double** _arr)
    {
        n = _n;
        array();
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < n; j++)
            {
                mass[i][j] = _arr[i][j];
            }
        }
    }
    void print()
    {
        double* arr1 = new double[n];
        double* arr2 = new double[n];
        arr1 = translate_abscissa();
        arr2 = translate_ordinata();
        cout << "abscissa ";
        for (int i = 0; i < n; i++)
        {
            cout << arr1[i] << " ";
        }
        cout << " ";
        cout << "ordinata ";
        for (int i = 0; i < n; i++)
        {
            cout << arr2[i] << " ";
        }
        cout << " ";
        cout << "Perimetr= ";
        P();
        cout << " Ploshad= ";
        S();
        cout << endl;
    }
    double* translate_abscissa()
    {
        double* arr1 = new double[n];
        for (int i = 0; i < n; i++)
        {
            arr1[i] = mass[0][i];//абцисса
        }
        return arr1;
    }
    double* translate_ordinata()
    {
        double* arr2 = new double[n];
        for (int i = 0; i < n; i++)
        {
            arr2[i] = mass[1][i];//ордината
        }
        return arr2;
    }
    void S()
    {
        double* arr1 = new double[n];
        double* arr2 = new double[n];
        double S = 0;
        arr1 = translate_abscissa();
        arr2 = translate_ordinata();
        for (int i = 0; i < n - 1; i++)
        {
            S += ((arr1[i] - arr1[i + 1]) * (arr2[i + 1] + arr2[i]) / 2);
        }
        S += ((arr1[n - 1] - arr1[0]) * (arr2[n - 1] + arr2[0]) / 2);
        S = abs(S);
        cout << S;
    }
    void P()
    {
        double* arr1 = new double[n];
        double* arr2 = new double[n];
        double P = 0;
        arr1 = translate_abscissa();
        arr2 = translate_ordinata();
        for (int i = 0; i < n - 1; i++)
        {
            P += sqrt(pow((abs(arr1[i] - arr1[i + 1])), 2) + pow((abs(arr2[i] - arr2[i + 1])), 2));
        }
        P += sqrt(pow((abs(arr1[n - 1] - arr1[0])), 2) + pow((abs(arr2[n - 1] - arr2[0])), 2));
        cout << P;
    }
    friend bool operator^(Poligon Pol1, Poligon Pol2)
    {
        bool Left = false, Right = false, Up = false, Down = false;
        bool Peresech = false;
        int n = Pol1.n;
        int m = Pol2.n;
        double* abcissa1 = new double[n];
        double* ordinata1 = new double[n];
        double* abcissa2 = new double[m];
        double* ordinata2 = new double[m];
        abcissa1 = Pol1.translate_abscissa();
        abcissa2 = Pol2.translate_abscissa();
        ordinata1 = Pol1.translate_ordinata();
        ordinata2 = Pol2.translate_ordinata();
        for (int i = 0; i < Pol1.n; i++)
        {
            for (int j = 0; j < Pol2.n; j++)
            {
                if (abcissa1[i] < abcissa2[j])
                    Left = true;
                if (abcissa1[i] > abcissa2[j])
                    Right = true;
                if (ordinata1[i] > ordinata2[j])
                    Up = true;
                if (ordinata1[i] < ordinata2[j])
                    Down = true;
            }
            if (Left && Right && Down && Up)
                Peresech = true;
            Left = false;
            Right = false;
            Up = false;
            Down = false;
        }
        return Peresech;
    }
};

int main()
{
    int n, m;
    cin >> n;
    double x_pol1, x_pol2;
    double y_pol1, y_pol2;
    double** matr1 = new double* [2];
    for (int i = 0; i < 2; i++)
    {
        matr1[i] = new double[n];
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matr1[i][j];
        }
    }
    Poligon figure1(n, matr1);
    cin >> m;
    double** matr2 = new double* [2];
    for (int i = 0; i < 2; i++)
    {
        matr2[i] = new double[m];
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matr2[i][j];
        }
    }
    Poligon figure2(m, matr2);
    cout << "Poligon1= ";
    figure1.print();
    cout << "Poligon2= ";
    figure2.print();
    bool tof = figure1 ^ figure2;
    if (tof == true)
    {
        cout << "Poligon1 peresekaet Poligon2" << endl;
    }
    else
    {
        cout << "Poligon1 ne peresekaet Poligon2" << endl;
    }
    for (int i = 0; i < 2; i++)
    {
        delete[] matr1[i];
    }
    delete matr1;
    for (int i = 0; i < 2; i++)
    {
        delete[] matr2[i];
    }
    delete matr2;
}