#include<iostream>
using namespace std;
class Seuraaja
{
    private:
    string nimi;
    public:
    Seuraaja* next = nullptr;
    Seuraaja(string n) : nimi(n) {}
    void paivitus(string s)
    {
        cout << nimi << " sai ilmoituksen: " << s << endl;
    }
    string getNimi()
    {
        return nimi;
    }
};
class Notifikaattori 
{
    private:
    Seuraaja* seuraaja = nullptr;
    public:
    Notifikaattori() {}
    void listaa(Seuraaja* s)
    {
        if (seuraaja != nullptr)
        {
            s->next = seuraaja;
        }
        seuraaja = s;
    }
    void poista(Seuraaja* s)
    {
        if (seuraaja == s)
        {
            seuraaja = seuraaja->next;
            return;
        }
        Seuraaja* current = seuraaja;
        while(current != nullptr && current->next != s)
        {
            current = current->next;
        }
        if (current != nullptr)
        {
            current->next = s->next;
        }
    }
    void tulosta()
    {
        Seuraaja* current = seuraaja;
        while(current != nullptr)
        {
            cout << current->getNimi() << endl;
            current = current->next;
        }
    }
    void postita(string s)
    {
        Seuraaja* current = seuraaja;
        while(current != nullptr)
        {
            current->paivitus(s);
            current = current->next;
        }
    }
};
int main ()
{
    Notifikaattori n;
    Seuraaja a("A");
    Seuraaja b("B");
    Seuraaja c("C");
    n.listaa(&a);
    n.listaa(&b);
    n.listaa(&c);
    n.tulosta();
    n.postita("Tämä on viesti");
    n.poista(&b);
    n.postita("Tämä on viesti 2");

    return 0;
}