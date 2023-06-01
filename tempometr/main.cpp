#include <iostream>
#include <iomanip>
#include <fstream>
#include <limits>
using namespace std;

float CelToKel(float st_Cel)
{
    return st_Cel + 273.15;
}

float CelToFahr(float st_Cel)
{
    return (9.0 / 5.0) * st_Cel + 32;
}

int main()
{
    int min, max, krok;
    string plik;

    cout << "\n\t\tPodaj zakres temperatur:\n";
    cout << "\n\tMinimalna temperatura: ";
    while (!(cin >> min))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\n\tBłędna wartość. Podaj ponownie minimalną temperaturę: ";
    }

    cout << "\n\tMaksymalna temperatura: ";
    while (!(cin >> max) || max <= min)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\n\tBłędna wartość. Podaj ponownie maksymalną temperaturę (większą od minimalnej): ";
    }

    cout << "\n\tKrok: ";
    while (!(cin >> krok) || krok <= 0 || krok > (max - min) / 2)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\n\tBłędna wartość. Podaj ponownie krok (dodatnią wartość, nie większą niż połowa zakresu): ";
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\n\tPodaj nazwę pliku do zapisu wyników: ";
    getline(cin, plik);

    ofstream outputFile(plik);
    if (!outputFile)
    {
        cout << "\n\tNie można otworzyć pliku " << plik << " do zapisu." << endl;
        return 1;
    }

    cout << "\n\tT[st.C]\t\tT[K]\t\tT[st.F]" << endl;
    cout.setf(ios::fixed | ios::right);
    cout.precision(2);

    outputFile << "\tT[st.C]\tT[K]\t\tT[st.F]" << endl;
    outputFile.setf(ios::fixed | ios::right);
    outputFile.precision(2);

    for (int T = min; T <= max; T += krok)
    {
        cout << "\t" << setw(3) << T << "\t"
             << "\t" << setw(8) << CelToKel(T) << "\t"
             << "\t" << setw(6) << CelToFahr(T) << endl;

        outputFile << "\t" << setw(3) << T << "\t"
                   << setw(8) << CelToKel(T) << "\t"
                   << setw(6) << CelToFahr(T) << endl;
    }

    outputFile.close();

    cout << endl; return 0;
}
