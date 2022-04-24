#include <iostream>
#include <istream>
#include <fstream>
#include <set>
#include <vector>
#include <ctime>

using namespace std;

#define Delete system("cls");

int choice;
set<pair<string, string>> user;
/*struct Date{
    int year,day,month;
};*/
struct Car {
    string price, year;
    string make, model;
    int installment;
    bool rent = false;
};

struct Service {
    string price;
    string name;
};

template<typename T>
void Erase(vector<T> &X, int idx) {
    swap(X[idx], X.back());

    if (!X.empty()) X.pop_back();
}

class garage {
public:
    int cnt = 0;
    string name;
    string location;
    string phone;
    vector<Service> service;

    void Display_garage() {
        for (auto u : service) {
            cout << "Service Name : " << u.name << endl;
            cout << "Service Price : " << u.price << endl;
        }
    }
};

vector<garage> Garages;

void DisplayGarage(int turn) {
    int idx = 0;
    for (auto u : Garages) {
        cout << "Garage Name : " << u.name << endl;
        cout << "Garage Location : " << u.location << endl;
        cout << "Garage Phone Number : " << u.phone << endl;
        cout << "Garage Tabor Line : " << u.cnt << endl;
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
            cout << "Please enter the ID of the garage" << endl;
            int ans;
            cin >> ans;
            Garages[ans - 1].cnt++;
        } else {
            cout << "ok!" << endl;
        }
    }
}

class ShowRooms {
public:
    int cnt;
    string name;
    string location;
    string phone;
    vector<Car> car;

    void Display() {
        int idx = 0;
        for (auto u : car) {
            if (u.rent) continue;
            cout << "Car Model : " << u.model << endl;
            cout << "Car Make : " << u.make << endl;
            cout << "Car Price : " << u.price << endl;
            cout << "Car Index : " << idx++ << endl;
            cout << "--------------------------------------------" << endl;
        }
    }
};

class process {
public:
    int process_id, customer_id;
    long long price = 0;
    Car chosen_car;
    time_t curr_time;
    char *tm = ctime(&curr_time);

    void displayreceipt() {
        cout << "---------------------------------------------" << endl;
        cout << "|               Your Receipt                |" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "Process id: " << process_id << endl;
        cout << "Customer id:" << customer_id << endl;
        cout << "Price: " << price << endl;
        cout << "Chosen Car: " << chosen_car.model << endl;
        cout << "---------------------------------------------" << endl;
    }
};

vector<ShowRooms> Rooms;

void DisplayShowRooms(int turn) {
    int idx = 0;
    for (auto u : Rooms) {
        cout << "Showroom name : " << u.name << endl;
        cout << "Showroom location : " << u.location << endl;
        cout << "Showroom Phone Number : " << u.phone << endl;
        cout << "Showroom Index : " << idx++ << endl << endl;
        if (turn) {
            cout << "Cars : " << endl;
            u.Display();
            cout << endl;
        }
    }
}

class customer {
public:
    set<int> id;
    int cnt = 0;
    string name, pw, idd;

    void registration() {
        cout << "Enter your username and password." << endl;
        cout << "Enter username : ";
        cin >> name;
        cout << "Enter password : ";
        cin >> pw;
        user.insert({name, pw});

        id.insert(cnt++);
        cout << "Registration is successful ! " << endl;
    }

    int login() {
        cout << "Enter your username and password." << endl;
        cout << "Username : ";
        cin >> name;
        cout << "Password : ";
        cin >> pw;
        if (user.count({name, pw})) {
            Delete
            cout << " Login Successful !" << endl;
        } else {
            Delete
            cout << "Please check your username and password." << endl;
            return 0;
        }
        return 1;
    }

    void displayAll() {
        process process;
        customer customer;
        int counter = 0;
        string plaa;
        Display:
        cout << "if you want to buy or rent ..please enter showrooms ! " << endl;
        cout << "if you want to repair ..please enter garages ! " << endl;
        cin >> plaa;
        if (plaa == "showrooms") {
            Delete
            int idx1, idx2;
            DisplayShowRooms(1);
            cout << "-------------------------------------" << endl;
            cout << "Enter index of both showroom and car." << endl;
            cout << "Showroom index : " << endl;
            cin >> idx1;
            cout << "Car index : " << endl;
            cin >> idx2;
            Delete

            cout << "Type Rent or Buy" << endl;
            string choose;
            cin >> choose;
            if (choose == "Buy") {
                counter++;
                cout << "Congratulations, purchase completed!" << endl;
                process.process_id = counter;
                //process.customer_id=customer.idd;
                long long p = stoll(Rooms[idx1].car[idx2].price);
                process.price += p;
                process.chosen_car = Rooms[idx1].car[idx2];
                /*-------------------------------------
                       time_t now = time(0);
                       tm *ltm = localtime(&now);
                       Date date;
                       date.year = 1900 + ltm->tm_year;
                       date.month = 1 + ltm->tm_mon;
                       date.day = ltm->tm_mday;
                */
                cout << "Do You Want to Show the receipt?(y/n)";
                char c;
                cin >> c;
                if (c == 'y') {
                    process.displayreceipt();
                }
                Erase(Rooms[idx1].car, idx2);
            }
            if (choose == "Rent") {
                Rooms[idx1].car[idx2].rent = true;
            }
            // display all showrooms (display دخلوا فانكشن من نوع كلاس المعارض  اسمه )
        } else if (plaa == "garages") {
            Delete
            DisplayGarage(1);
            // display all garages ( display دخلوا فانكشن من نوع كلاس جراج  اسمه )
        } else {
            Delete
            cout << "Please enter from options given above";
            goto Display;
        }
    }

    void search() {
        int yournum;
        cout << "1 : Search for a car : " << endl
             << endl;
        cout << "2 : Search for a showroom : " << endl
             << endl;
        cout << "3 : Search for a garage : " << endl
             << endl;
        cout << "4 : Search for a service : " << endl
             << endl;
        cout << "Enter your choice : ";
        cin >> yournum;
        Delete

        if (yournum == 1) {
            cout << "Enter car name and model." << endl;
            cout << "Car name : " << endl;
            cin >> name;
            cout << "Car model : " << endl;
            string model;
            cin >> model;
            bool found = false;

            for (auto u : Rooms)
                for (auto v : u.car)
                    if (v.model == name && v.year == model) {
                        cout << "Showroom name : " << u.name << endl;
                        cout << "Showroom location : " << u.location << endl;
                        cout << "Car price : " << v.price << endl;
                        cout << "Installment state : " << v.installment << endl;
                        found = true;
                    }

            if (!found)
                cout << "Car not found!" << endl;
        }
        if (yournum == 2) {
            cout << "Enter showroom name : " << endl;
            cin >> name;
            bool found = false;
            for (auto u : Rooms) {
                if (u.name == name) {
                    cout << "Showroom location : " << u.location << endl;
                    cout << "Showroom phone number : " << u.phone << endl;
                    u.Display();
                    found = true;
                }
            }

            if (!found) cout << "Showroom not found!" << endl;
        }
        if (yournum == 3) {
            cout << "Enter garage name : " << endl;
            cin >> name;
            bool found = false;
            for (auto u : Garages) {
                if (u.name == name) {
                    cout << "Garage location : " << u.location << endl;
                    cout << "Garage phone number : " << u.phone << endl;
                    u.Display_garage();
                    found = true;
                }
            }

            if (!found) cout << "Garage not found!" << endl;
        }
        if (yournum == 4) {
            cout << "Enter service name : " << endl;
            cin >> name;
            bool found = false;
            for (auto u : Garages) {
                for (auto v : u.service) {
                    if (v.name == name) {
                        cout << "Garage name : " << u.name << endl;
                        cout << "Garage location : " << u.location << endl;
                        cout << "Service price : " << v.price << endl;
                        found = true;
                    }
                }
            }

            if (!found) cout << "Service not found!" << endl;
        }
    }
};



int main() {
    GoodMorning();
    int c, plaa2;
    string x;
    customer cui;
    Login:
    cout << "____________________________________________________" << endl;
    cout << "              Welcome to the login page        " << endl;
    cout << "____________________________________________________" << endl;
    cout << " If you're an admin please write admin          |" << endl;
    cout << " If you're a customer please write customer     |" << endl;
    cin >> x;

    if (x == "customer") {
        cout << "  1 : Login                         |" << endl;
        cout << "  2 : Registration                     |" << endl;
        cout << "  Please enter your choice : ";
        cin >> c;
        cout << endl;
        Delete
        switch (c) {
            case 1:
                Delete
                if (!cui.login())
                    goto Login;
                break;
            case 2:
                Delete
                cui.registration();
                goto Login;

            default:
                Delete
                cout << " Please select from options given above " << endl;
                main();
        }
        Delete
        cout << "  1 : Display                       |" << endl;
        cout << "  2 : Search                        |" << endl;
        cout << "  Please enter your choice: ";
        cin >> plaa2;
        switch (plaa2) {
            case 1:
                cui.displayAll();
                break;
            case 2:
                cui.search();
            default:
                break;
        }
    } else if (x == "admin") {
        string name, pass;
        cout << "Enter username : " << endl;
        cin >> name;
        cout << "Enter password : " << endl;
        cin >> pass;
        if (name == "admin" && pass == "admin123")
            Admin::Administration();
        else goto Login;

    } else {
        cout << " Please select from the options given above. " << endl;
        goto Login;
    }
    GoodBye();
}
