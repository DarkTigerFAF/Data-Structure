#include<vector>
#include <iostream>
#include<ctime>
#include "garage.h"
using namespace std ;
#define DisplayGarage garage::DisplayGarage
#define Garages garage::Garages
vector<garage> garage::Garages;

void garage::Display_garage() {
    int idx=0;
    for (auto u : service) {
        cout << "Service Name : " << u.name << endl;
        cout << "Service Price : " << u.price << endl;
        cout << "Service Index : " << idx++ << endl;
    }
}
void GarageReceipt(Garage_receipt receipt){
    cout<<"Process ID: "<<receipt.Process_ID<<endl;
    cout<<"Customer ID: "<<receipt.Customer_ID<<endl;
    cout<<"Process Date: "<<receipt.date.day<<"/"<<receipt.date.month<<"/"<<receipt.date.year<<endl;
    cout<<"Price: "<<receipt.Amount_of_money<<" LE\n";
    cout<<"Service Name: "<<receipt.Chosen_Service.name<<endl;
}
void DisplayGarage(int turn,string currentcustomer) {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int year = 1900 + ltm->tm_year;
    int month = 1 + ltm->tm_mon;
    int today = ltm->tm_mday;
    int idx = 0;
    for (auto u : Garages) {
        cout << "Garage Name : " << u.name << endl;
        cout << "Garage Location : " << u.location << endl;
        cout << "Garage Phone Number : " << u.phone << endl;
        cout << "Garage Queue Line : " << u.cnt.size() << endl;
        cout << "Garage Index : " << idx++ << endl << endl;
        if (turn > -1)
            cout << "Services :" << endl;
        u.Display_garage();
    }
    if (turn > -1) {
        cout << "Do you want to make an appointment in a certain garage ? (y/n)" << endl;
        char x;
        cin >> x;
        if (x == 'y') {
            cout << "Enter The Index Of The Garage: " << endl;
            int ans1,ans2;
            cin >> ans1;
            cout << "Enter The Index Of The Service: " << endl;
            cin >> ans2;
            Garage_receipt receipt;
            receipt.Process_ID++;
            receipt.Customer_ID=currentcustomer;
            receipt.date.day=today;
            receipt.date.month=month;
            receipt.date.year=year;
            receipt.Amount_of_money+=Garages[ans1].service[ans2].price;
            receipt.Chosen_Service.name=Garages[ans1].service[ans2].name;
            cout<<"Do You Want Show Your Receipt? (y/n)"<<endl;
            char c; cin>>c;
            if(c=='y'){
                GarageReceipt(receipt);
                cout<<endl;

            }
            Garages[ans1].cnt.insert(currentcustomer);
            cout<<Garages[ans1].cnt.size()<<" In The Queue"<<endl;
            return;
        } else {
            cout << "Ok!" << endl;
        }
    }
}
