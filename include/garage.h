#include<vector>
#include<iostream>
#include<string>
#include<set>
using namespace std;
struct Service {
    int price;
    string name;
};
struct Datee{
    int day,month,year;
};
struct Garage_receipt{
    int Process_ID=0;
    string Customer_ID;
    Datee date;
    int Amount_of_money=0;
    Service Chosen_Service;
};
class garage {
    public:
    set<string>cnt;
    string name;
    string location;
    string phone;
    vector<Service> service;
    void Display_garage();
   static void DisplayGarage(int turn,string currentcustomer);
   static vector<garage> Garages;
};
