 #include "customer.h"
 #include<set>
 #include <iostream>
 #include <ctime>
using namespace std;
#define Rooms ShowRooms::Rooms
#define DisplayShowRooms ShowRooms::DisplayShowRooms
#define DisplayGarage garage::DisplayGarage
#define Garages garage::Garages
set <pair <string , string> > customer::user;
set <string>customer::username;
string customer::currentcustomer;
string name , pw ;
template <typename T>
void Erase(vector<T> &X, int idx){
    swap(X[idx], X.back());

    if(!X.empty()) X.pop_back();
}
void customer::registration (){
        cout <<"Enter User Name :";
        cin >>name ;
        cout <<"Enter Password:";
        cin >>pw;
        if(username.count(name))
        {
            cout<<"Username already exists!"<<endl;
            registration();
        }
        else
        {
            user.insert({name, pw});
            username.insert(name);
            cout << "Registration Is Successfull! "<<endl;
            system("cls");
            login();
        }
}
  void customer::login(){
        cout <<"Enter User Name :";
        cin >>name;
        cout <<"Enter Password:";
        cin >>pw;
        if(user.count({name, pw})){
            system("cls");
             cout <<  "Your Login Is Successfull!"<<endl;
             customer::currentcustomer=name;
        }
        else
        {
              system("cls");
              cout << "Login Error..Check Your Username and Password!" << endl;
              cout<<endl;
              login();
        }

}
void ShowRoomReceipt(ShowRoom_receipt receipt){
    cout<<"Process ID: "<<receipt.Process_ID<<endl;
    cout<<"Customer ID: "<<receipt.Customer_ID<<endl;
    cout<<"Process Date: "<<receipt.date.day<<"/"<<receipt.date.month<<"/"<<receipt.date.year<<endl;
    cout<<"Price: "<<receipt.Amount_of_money<<" LE\n";
    cout<<"Car Model: "<<receipt.Chosen_car.model<<endl;
}
void customer::page(){
    Login:
    int c , plaa2;
    int  x ;
    cout <<"|-------------------------------------------|" <<endl;
    cout <<"|         Welcome To The Login Page         |"<<endl;
    cout <<"|-------------------------------------------|" <<endl<<endl;
    cout <<"If You Are Admin Press 1" <<endl;
    cout <<"If You Are Customer Press 2"<<endl;
    cin >> x ;
    if (x==2){
    cout <<"Press 1 To Login"<<endl;
    cout <<"Press 2 To Registration"<<endl;
    cin >> c;
    switch (c)
    {
    case 1:
        login();
        break;
    case 2:
        registration();
       break;

    default:
    system ("cls");
       cout << "Please Select From Options Given Above!" << endl;
       page();
    }
    cout <<"Press 1 to Display "<<endl;
    cout <<"Press 2 to Search "<<endl;
    cin >> plaa2;
    switch (plaa2)
    {
    case 1:
    displayAll();
        break;
    case 2:
    search();

    default:
        break;
    }

    }

    else if (x==1){
        Admin admin;
        string name, pass;
        cout <<"Enter Username: " << endl;
        cin >> name;
        cout <<"Enter Password: " << endl;
        cin >> pass;
        if (name == admin.admainName && pass == admin.password)
            Admin::Administration();
        else{
            cout << "\nLogin Error..Check Your Username and Password!" << endl;
            cout<<endl;
            goto Login;
        }


    }
    else {
    cout << "Please Select From Options Given Above " << endl ;
    page();}
}
void customer::displayAll(){
        time_t now = time(0);
        tm *ltm = localtime(&now);
        int year = 1900 + ltm->tm_year;
        int month = 1 + ltm->tm_mon;
        int today = ltm->tm_mday;
        int plaa;
        Display:
        cout << "1: Buy/Rent Car "<< endl;
        cout << "2: Services "<< endl;
        cout<<"3: Logout "<<endl;
        cout <<"Enter Your Choice :"<<endl;
        cin>>plaa;
        if(plaa==1){
         system("cls");
            int idx1, idx2;
            DisplayShowRooms(1);
            cout << "-------------------------------------" << endl;
            cout << "Enter index of both showroom and car." << endl;
            cout << "Showroom index : " << endl; cin >> idx1;
            cout << "Car index : " << endl; cin >> idx2;
            system("cls");
            cout << "1: Buy"<< endl;
            cout << "2: Rent"<< endl;
            int choose; cin >> choose;
            if(choose == 1){
                cout<<"Do you want to book it for a specific time? (y/n)"<<endl;
                char c;cin>>c;
                if(c=='y'){
                    ShowRoom_receipt receipt;
                    receipt.Process_ID++;
                    receipt.Customer_ID=name;
                    receipt.date.day=today;
                    receipt.date.month=month;
                    receipt.date.year=year;
                    receipt.Amount_of_money+=Rooms[idx1].car[idx2].price;
                    receipt.Chosen_car.model=Rooms[idx1].car[idx2].model;
                    cout<<"For How Many Days?"<<endl;
                    int days;cin>>days;
                    cout << "Your car has been booked until "<<today+days<<"/"<<month<<"/"<<year<< endl;
                    cout<<"Do You Want Show Your Receipt? (y/n)"<<endl;
                    cin>>c;
                    if(c=='y'){
                        ShowRoomReceipt(receipt);
                        cout<<"Congrats, Purchase Completed!"<<endl;
                        Erase(Rooms[idx1].car, idx2);
                        return;
                    }
                    else{
                        cout<<"Congrats, Purchase Completed!"<<endl;
                        Erase(Rooms[idx1].car, idx2);
                        return;
                    }

                }
                else{
                    ShowRoom_receipt receipt;
                    receipt.Process_ID++;
                    receipt.Customer_ID=name;
                    receipt.date.day=today;
                    receipt.date.month=month;
                    receipt.date.year=year;
                    receipt.Amount_of_money+=Rooms[idx1].car[idx2].price;
                    receipt.Chosen_car.model=Rooms[idx1].car[idx2].model;
                    cout<<"Do You Want Show Your Receipt? (y/n)"<<endl;
                    cin>>c;
                    if(c=='y'){
                        ShowRoomReceipt(receipt);
                        cout<<"Congrats, Purchase Completed!"<<endl;
                        Erase(Rooms[idx1].car, idx2);
                        return;
                    }
                    else{
                        cout<<"Congrats, Purchase Completed!"<<endl;
                        Erase(Rooms[idx1].car, idx2);
                        return;
                    }

                }
            } if(choose == 2){
                cout<<"How Many Days?\n"<<"One Day Is Equal To 0.1% Of The Total Value Of The Car"<<endl;
                int days;cin>>days;
                ShowRoom_receipt receipt;
                receipt.Process_ID++;
                receipt.Customer_ID=name;
                receipt.date.day=today;
                receipt.date.month=month;
                receipt.date.year=year;
                receipt.Amount_of_money+=days*(Rooms[idx1].car[idx2].price*0.01);
                receipt.Chosen_car.model=Rooms[idx1].car[idx2].model;
                Rooms[idx1].car[idx2].deadline=today+days;
                if(Rooms[idx1].car[idx2].deadline>30)
                    Rooms[idx1].car[idx2].deadline-=30;
                cout<<"Do You Want Show Your Receipt? (y/n)"<<endl;
                char c;cin>>c;
                if(c=='y'){
                    ShowRoomReceipt(receipt);
                    cout<<"Enjoy Your Time!"<<endl;
                    return;
                }
                else{
                    cout<<"Enjoy Your Time!"<<endl;
                    return;
                }

            }

        }

        else if (plaa==2)
        {
            system("cls");
            DisplayGarage(1,name);

        }
        else if(plaa==3){
            system("cls");
            page();
        }
        else {
            system("cls");
            cout << "Please Enter From Options Given Above";
            goto Display;
        }
}

void customer::search(){
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int today = ltm->tm_mday;
    int yournum;
        cout <<"1:Car "<< endl;
        cout <<"2:ShowRooms "<< endl;
        cout <<"3:Garages "<< endl;
        cout <<"4:Services "<< endl;
        cout <<"Enter Your Choice :"<<endl;
        cin >> yournum;
        string name , model;
        bool found;
        switch (yournum)
        {
        case 1:
                cout<< "Please..Enter Car Name And Model . "<< endl;
                cout <<"Car Name : " <<endl;
                cin >> name;
                cout <<"Car Model :"<<endl ;
                cin >> model;
            for (auto u : Rooms)
                for (auto v : u.car)
                    if (v.model == name && v.year == model) {
                        cout << "Showroom name : " << u.name << endl;
                        cout << "Showroom location : " << u.location << endl;
                        cout << "Car price : " << v.price << endl;
                        cout << "Installment state : " << v.installment << endl;
                        if(today<v.deadline&&v.deadline!=0)
                            cout << "Car state : Not Available"<< endl;
                        else
                            cout << "Car state : Available"<< endl;
                        found = true;
                    }

            if (!found)
                cout << "Car not found!" << endl;

            break;

       case 2:
          cout << "Enter showroom name : " << endl;
            cin >> name;
            for (auto u : Rooms) {
                if (u.name == name) {
                    cout << "Showroom location : " << u.location << endl;
                    cout << "Showroom phone number : " << u.phone << endl;
                    u.Display();
                    found = true;
                }
            }

            if (!found) cout << "Showroom not found!" << endl;

            break;
        case 3:
            cout << "Enter garage name : " << endl;
            cin >> name;
            for(auto u : Garages){
                if(u.name == name){
                    cout << "Garage location : " << u.location << endl;
                    cout << "Garage phone number : " << u.phone << endl;
                    u.Display_garage();
                    found = true;
                }
            }
                if(!found) cout << "Garage not found!" << endl;

            break;
        case 4:
        cout << "Enter service name : " << endl;
            cin >> name;
            for(auto u : Garages){
                for(auto v : u.service){
                    if(v.name == name){
                        cout << "Garage name : " << u.name << endl;
                        cout << "Garage location : " << u.location << endl;
                        cout << "Service price : " << v.price << endl;
                        found = true;
                    }
                }
            }

            if(!found) cout << "Service not found!" << endl;
            break;


        default:
            break;
            }
}
