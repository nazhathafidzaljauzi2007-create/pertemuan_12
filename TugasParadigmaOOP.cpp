#include <iostream>
using namespace std;

class rekeningBank
{
private:
    string namaPemilik;
    int saldo;
public:
    rekeningBank(string pNama, int pSaldo) :
        namaPemilik(pNama),
        saldo(pSaldo)
    {
        cout << "Rekening bank dibuat " << namaPemilik << " dan saldo " << saldo << "\n" << endl;
    }

    virtual void potonganAdmin() = 0;

    void tampilInfo()
    {
        cout << "Pemilik " << namaPemilik << " adalah " << saldo << "\n" << endl;
    }
};