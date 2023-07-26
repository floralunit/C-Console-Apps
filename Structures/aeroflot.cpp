#include <iostream>
#include <cstring>
#define M 15
using namespace std;

struct AEROFLOT {
    char kuda[M];
    int num;
    char type[M];
};

int main() {
    static int N = 3;
    AEROFLOT fly[N];
    int i;
    for (i = 0; i < N; i++) {
        cout << "\nВведите номер рейса: "; cin >> fly[i].num;
        cout << "\nВведите тип самолёта: "; cin >> fly[i].type;
        cout << "\nВведите пункт назначения: "; cin >> fly[i].kuda;
    }

    cout << "\n ________________________________________________________\n";
    for (i = 0; i < N; i++) {
        cout << fly[i].kuda << "    " << fly[i].num << "    " << fly[i].type << endl;

    }
    cout << "\n ________________________________________________________\n";
    char temp[M];
    int count;

    cout << "\nВведите желаемый пункт назначения: ";
    cin >> temp;
    count = 0;
    for (i = 0; i < N; i++)
    {
        if (strcmp(fly[i].kuda, temp) == 0)
        {
            cout << endl
                 << fly[i].kuda << "    " << fly[i].num << endl;
            count++;
        }
    }
    if (count == 0)
        cout << endl
             << " Нет таких рейсов\n";

    cout << "\nВведите желаемый тип самолёта: ";
    cin >> temp;
    count = 0;
    for (i = 0; i < N; i++)
    {
        if (strcmp(fly[i].type, temp) == 0)
        {
            cout << endl
                 << fly[i].kuda << "    " << fly[i].num << endl;
            count++;
        }
    }
    if (count == 0)
        cout << endl
             << " Нет таких рейсов\n";
}


