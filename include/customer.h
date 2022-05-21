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
    int Amount_of_money = 0;
    Car Chosen_car;
};

class customer {
public:
    static string currentcustomer;
    static set<pair<string, string> > user;
    static set<string> username;
    vector<Service> HistoricSrevice;

    void registration();

    void login();

    void displayAll();

    void search();

    void page();
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
