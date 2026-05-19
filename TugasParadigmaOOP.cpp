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

class rekeningPremium : public rekeningBank
{
public:
    rekeningPremium(string pNama, int pSaldo) :
        rekeningBank(pNama, pSaldo)
    {
        cout << "Rekening premium dibuat\n" << endl;
    }

    void potonganAdmin() 
    override 
    {
        if (saldo > 10000000)
        {
            cout << " [premium]" << namaPemilik << " bebas biaya admin (Saldo > 10 Juta)" << endl;
        }
        else
        {
            saldo -= 50000;
            cout << " [premium]" << namaPemilik << " dipotong 50000 (Saldo <= 10 Juta)" << endl;
        }
    }
};

int main()
{
    rekeningSyariah syariah("Andi", 5000000);
    rekeningKonvensional konvensional("Budi", 3000000);
    rekeningPremium premium("Citra", 15000000);

    cout << "\nInformasi rekening sebelum potongan admin:\n" << endl;
    syariah.tampilInfo();
    konvensional.tampilInfo();
    premium.tampilInfo();

    cout << "\nProses potongan admin:\n" << endl;
    syariah.potonganAdmin();
    konvensional.potonganAdmin();
    premium.potonganAdmin();

    cout << "\nInformasi rekening setelah potongan admin:\n" << endl;
    syariah.tampilInfo();
    konvensional.tampilInfo();
    premium.tampilInfo();

    return 0;
}