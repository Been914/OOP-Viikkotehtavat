#include <iostream>
using namespace std;
class Pankkitili
{
    protected:
    string omistaja;
    double saldo = 0;
    public:
    Pankkitili(string nimi) : omistaja(nimi){
        cout << "Pankkitili luotu omistajalle: " << omistaja << endl;
    }
    double getBalance()
    {
        return saldo;
    }
    virtual bool deposit(double amount)
    {
        if (amount > 0)
        {
            saldo += amount;
            cout << "Tilille " << omistaja << " talletettu: " << amount << " euroa." << endl;
            return true;
        }
        else
        {
            cout << "Talletus epäonnistui: summa negatiivinen." << endl;
            return false;
        }
    }
    virtual bool withdraw(double amount)
    {
        if (amount > 0 && amount <= saldo)
        {
            saldo -= amount;
            cout << "Tililtä " << omistaja << " nostettu: " << amount << " euroa." << endl;
            return true;
        }
        else
        {
            cout << "Nosto epäonnistui: tarkista summa ja saldo." << endl;
            return false;
        }
    }
};
class Luottotili : public Pankkitili
{
    protected:
    double luottoraja = 0;
    public:
    Luottotili(string nimi, double raja) : Pankkitili(nimi), luottoraja(raja) {
        cout << "Luottotili luotu omistajalle: " << omistaja << " luottorajalla: " << luottoraja << " euroa." << endl;
    }
    bool withdraw(double amount) override
    {
        if (amount > 0 && amount <= (saldo + luottoraja))
        {
            saldo -= amount;
            cout << "Tililtä " << omistaja << " nostettu: " << amount << " euroa." << endl;
            return true;
        }
        else
        {
            cout << "Nosto epäonnistui: tarkista summa ja luottoraja." << endl;
            return false;
        }
    }
    bool deposit(double amount) override
    {
        if (amount > 0)
        {
            saldo += amount;
            cout << "Tilille " << omistaja << " talletettu: " << amount << " euroa." << endl;
            return true;
        }
        else
        {
            cout << "Talletus epäonnistui: summa negatiivinen." << endl;
            return false;
        }
    }
};
class Asiakas
{
    private:
    string nimi;
    Pankkitili kayttotili;
    Luottotili luottotili;
    public:
    Asiakas(string n, double luottoraja) : nimi(n), kayttotili(n), luottotili(n, luottoraja) {
        cout << "Asiakas " << nimi << " luotu." << endl;
    }
    string getNimi()
    {
        return nimi;
    }
    void showSaldot()
    {
        cout << "Asiakas: " << nimi << endl;
        cout << "Käyttötilin saldo: " << kayttotili.getBalance() << " euroa." << endl;
        cout << "Luottotilin saldo: " << luottotili.getBalance() << " euroa." << endl;
    }
    bool talletus(double amount)
    {
        return kayttotili.deposit(amount);
    }
    bool nosto(double amount)
    {
        if (kayttotili.withdraw(amount))
        {
            return true;
        }
    }
    bool luottoNosto(double amount)
    {
        return luottotili.withdraw(amount);
    }
    bool luottoMaksu(double amount)
    {
        return luottotili.deposit(amount);
    }
    bool tiliSiirto(double amount, Asiakas &toinen)
    {
        if (kayttotili.withdraw(amount))
        {
            return toinen.talletus(amount);
        }
        return false;
    }
};
int main()
{
    Asiakas asiakas1("Aapeli", 1000);
    
    asiakas1.talletus(250);
    asiakas1.luottoNosto(150);
    asiakas1.showSaldot();

    Asiakas asiakas2("Bertta", 1000);

    asiakas2.showSaldot();
    
    asiakas1.tiliSiirto(50, asiakas2);

    asiakas1.showSaldot();

    asiakas2.showSaldot();
    
    return 0;
}