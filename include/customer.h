#include<iostream>
#include<string.h>
#include"garage.h"
#include "showrooms.h"
#include<set>
#include<vector>

using namespace std;
struct ShowRoom_receipt {
    int Process_ID = 0;
    string Customer_ID;
    Date date;
    double Amount_of_money = 0;
    Car Chosen_car;
};

class customer {
public:
    static string currentcustomer;
    static set<pair<string, string> > user;
    string name, pass;
    vector<Service> HistoricService;
    static vector<customer> Customers;

    static void registration();

    static int login();

    static void displayAll(customer *Cust);

    static void search();

    static void page();
};

class Admin {
public:
    const string admainName = "admin", id, password = "admin";

    static Car GetCar(ShowRooms &X);

    static Service GetService(garage &X);

    static void AddShow();

    static void AddGarage();

    static void Administration();
};
