#include<iostream>
#include<set>
#include<fstream>
#include"customer.h"

using namespace std;
#define Rooms ShowRooms::Rooms
#define DisplayShowRooms ShowRooms::DisplayShowRooms
#define DisplayGarage garage::DisplayGarage
#define Garages garage::Garages

void GoodMorning() {
    ifstream input;
    input.open("Showrooms.txt");
    int n;
    input >> n;
    for (int i = 0; i < n; i++) {
        ShowRooms X;
        input >> X.cnt >> X.name >> X.location >> X.phone;
        int m;
        input >> m;
        for (int j = 0; j < m; j++) {
            Car Y;
            input >> Y.price >> Y.year >> Y.make >> Y.model >> Y.installment >> Y.deadline;
            X.car.push_back(Y);
        }
        Rooms.push_back(X);
    }
    input.close();

    input.open("Garages.txt");
    input >> n;
    for (int i = 0; i < n; i++) {
        garage X;
        input >> X.name >> X.location >> X.phone;
        int m;
        input >> m;
        for (int j = 0; j < m; j++) {
            Service Y;
            input >> Y.name >> Y.price;
            X.service.push_back(Y);
        }
        input >> m;
        for (int j = 0; j < m; j++) {
            string x;
            input >> x;
            X.cnt.insert(x);
        }
        Garages.push_back(X);
    }
    input.close();

    input.open("Users.txt");
    input >> n;
    for (int i = 0; i < n; i++) {
        string name, pass;
        input >> name >> pass;
        customer::user.insert({name, pass});
        customer::username.insert(name);
    }
    input.close();
}

void GoodBye() {
    ofstream output;
    output.open("Showrooms.txt");
    output << Rooms.size() << endl;
    for (auto u : Rooms) {
        output << ' ' << u.cnt << ' ' << u.name << ' ' << u.location << ' ' << u.phone << endl;
        output << u.car.size() << endl;
        for (auto v : u.car) {
            output << ' ' << v.price << ' ' << v.year << ' ' << v.make << ' ' << v.model << ' ' << v.installment << ' '
                   << v.deadline << endl;
        }
    }
    output.close();

    output.open("Garages.txt");
    output << Garages.size() << endl;
    for (auto u : Garages) {
        output << u.name << ' ' << u.location << ' ' << u.phone << endl;
        output << u.service.size() << endl;
        for (auto v : u.service)
            output << v.name << ' ' << v.price << endl;

        output << u.cnt.size() << endl;
        for (auto v : u.cnt)
            cout << v << endl;
    }
    output.close();

    output.open("Users.txt");
    output << customer::user.size() << endl;
    for (auto u : customer::user)
        output << u.first << ' ' << u.second << endl;

    output.close();
}

int main() {
    customer c;
    GoodMorning();
    c.page();
    GoodBye();

}
