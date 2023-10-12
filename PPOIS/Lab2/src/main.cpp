#include <iostream>
#include "../inc/customer.h"
#include "../inc/postman.h"
#include "../inc/delivery_address.h"
#include "../inc/packege.h"
#include "../inc/letter.h"
#include "../inc/parcel.h"
#include "../inc/sorter.h"
#include "../inc/deliveryman.h"
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