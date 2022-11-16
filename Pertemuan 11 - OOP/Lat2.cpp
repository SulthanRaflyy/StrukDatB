#include <iostream>
using namespace std;

class MHS
{

    // Acces Specifier
public:
    // member function()
    void printname()
    {
        cout << ">>> Student Name : " << namemhs;
    }

    string getNama()
    {
        return namemhs;
    }

    MHS(string nama)
    {
        namemhs = nama;
    }

private:
    string namemhs; // data member
};

int main()
{ // declare an object of class geeks
    MHS mhs1("Opet");
    MHS mhs2("Hakim");
    MHS mhs3("Cindo");

    // accesing member function
    mhs2.printname();

    cout << mhs2.getNama();

    return 0;
}