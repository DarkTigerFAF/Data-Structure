#include"showrooms.h"
#include<iostream>
#include<ctime>
#include<vector>
using namespace std;
time_t now = time(0);
tm *ltm = localtime(&now);
int day= ltm->tm_mday;
vector<ShowRooms> ShowRooms::Rooms;
void ShowRooms::Display() {
    int idx = 0;
    for (auto u :car) {
        if (day<u.deadline&&u.deadline!=0) continue;
        cout << "Car Model : " << u.model << endl;
        cout << "Car Make : " << u.make << endl;
        cout << "Car Price : " << u.price << endl;
        cout << "Car Index : " << idx++ << endl;
        cout << "-------------------------------- " << endl;
    }

}
void ShowRooms::DisplayShowRooms(int turn) {
    int idx = 0;
    for (auto u : Rooms) {
        cout << "Showroom Name : " << u.name << endl;
        cout << "Showroom Location : " << u.location << endl;
        cout << "Showroom Phone Number : " << u.phone << endl;
        cout << "Showroom Index : " << idx++ << endl << endl;
        if (turn) {
            cout << "Cars : " << endl;
            u.Display();
            cout << endl;
        }
    }

}
