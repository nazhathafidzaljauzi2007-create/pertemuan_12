#include <iostream>
using namespace std;

class rekeningBank
{
protected:
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

class rekeningSyariah : public rekeningBank
{
public:
    rekeningSyariah(string pNama, int pSaldo) :
        rekeningBank(pNama, pSaldo)
    {
        cout << "Rekening syariah dibuat\n" << endl;
    }

    void potonganAdmin() 
    override 
    {
        cout << "[Syariah] " << namaPemilik << " bebas biaya admin." << endl;
    }
};

class rekeningKonvensional : public rekeningBank
{
public:
    rekeningKonvensional(string pNama, int pSaldo) :
        rekeningBank(pNama, pSaldo)
    {
        cout << "Rekening konvensional dibuat\n" << endl;
    }

    void potonganAdmin() 
    override 
    {
        saldo -= 15000;
        cout << "Potongan admin rekening konvensional sebesar 15000\n" << endl;
    }
};