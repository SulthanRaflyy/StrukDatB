#include <iostream>
using namespace std;

class MHS
{
    //Access specifier
    public:

    //Data Member
    string StudName;

    //Member Functions
    void printname()
    {
        cout << ">>> Student Name :" << StudName;
    }
};

int main(){
    //Declare an object of class geeks
    MHS mhs1;

    //accessing data member
    mhs1.StudName="Salten Ikmal";

    //accessing member function
    mhs1.printname();
    return 0;
}