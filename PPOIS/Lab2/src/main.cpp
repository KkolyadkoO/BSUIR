#include <iostream>
#include "../inc/postal_office.h"
#include <vector>
using namespace std;

int main()
{       
    PostalOffice off("address","10 am","delivery");
    off.loadClients("clients.txt");
    off.loadPostmans("postmans.txt");
    off.loadPackage("letters.txt","parcels.txt");
    off.showPostmans();
    return 0;

}