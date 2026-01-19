#include <iostream>
using namespace std;
class Chef
{
    protected:
    string chefName;
    public:
    Chef(string name) : chefName(name){
        cout << "Chef " << chefName << " is ready to cook!" << endl;
    }
    ~Chef()
    {
        cout << "Chef " << chefName << " is done for the day." << endl;
    }
    string getName()
    {
        return chefName;
    }
    int makeSalad(int x)
    {
        cout << "Chef " << chefName << " is making " << 5/x << " salads." << endl;
        return 5/x;
    }
    int makeSoup(int x)
    {
        cout << "Chef " << chefName << " is making " << 3/x << " soups." << endl;
        return 3/x;
    }
};
class ItalianChef : public Chef
{
    public:
    ItalianChef(string name) : Chef(name) {
        cout << "Italian Chef " << chefName << " is ready to cook Italian dishes!" << endl;
    }
    ~ItalianChef()
    {
        cout << "Italian Chef " << chefName << " is done for the day." << endl;
    }
    bool askSecret(string s, int x, int y)
    {
        if (s == password)
        {
            flour = x;
            water = y;
            cout << "Chef " << chefName << " received the secret pizza recipe!" << endl;
            makePizza();
            return true;
        }
        else
        {
            cout << "Wrong password! Chef " << chefName << " cannot make pizza." << endl;
            return false;
        }
    }
    private:
    int makePizza()
    {
        int n = 0;
        while (flour > 5 && water > 5)
        {
            flour -= 5;
            water -= 5;
            n++;
        }
            cout << "Chef " << chefName << " making " << n << " pizzas." << endl;
        return n;
    }
    string password = "pizza";
    int flour;
    int water;
};
int main()
{
    Chef chef1("Gordon Ramsay");
    chef1.makeSalad(1);
    chef1.makeSoup(3);

    ItalianChef chef2("Mario Batali");
    chef2.makeSalad(2);
    chef2.askSecret("mammamia", 20, 20);
    chef2.askSecret("pizza", 20, 20);
}