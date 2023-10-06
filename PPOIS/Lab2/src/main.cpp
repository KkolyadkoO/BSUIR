#include <iostream>
#include "../inc/postal_office.h"
#include <vector>
using namespace std;

int main()
{       
    PostalOffice off("address","10 am","delivery");
    off.loadDate("date.txt");
    off.showClients();
    off.showPostmans();
    off.sortPackage();
    return 0;

}