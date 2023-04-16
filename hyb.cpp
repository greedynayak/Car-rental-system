#include <iostream>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include <stdlib.h>
#include <sstream>
#include <dos.h>
#include <unistd.h>
using namespace std;

class car
{

protected:
  char customname[50];
  string carmodel;
  string carnumber;
  int id;
  int days;
  int advanceamt;
  char data;

  void get_id()
  {
    cout << "enter the id of the car you want to rent" << endl;
    cin >> id;
    cout << " car id is :" << id << endl;
  }
};

class rental_details : public car
{

  string customer_id;
  string licence;
  char address[50];
  int phone;
  string vehicle_id;
  string rent_date;

public:int days = 0, advanceamt = 0, rentalfee = 0;
 
  void data()
  {
   
    cout << "\t\t\t Please enter your name" << endl;
    cin.getline(customname,50);
    cout << endl;
    do
    {
      cout << "\t\t\t Please select a car" << endl;
      cout << "\t\t\t 'A' for Tesla ." << endl;
      cout << "\t\t\t 'B' for Hyundai ." << endl;
      cout << "\t\t\t 'C' for ford." << endl;
      cout << "\t\t\t 'D' for Maruti ." << endl;
      cout << "\t\t\t 'E' for Honda ." << endl;
      cout << endl;
      cout << "\t\t\t Choose a car from the above options " << endl;
      cin >> carmodel;
      cout << endl;
      cout << " ----------------------------------------------" << endl;
      if (carmodel == "A")
      {
        system("CLS");
        cout << "You have chosen Tesla model" << endl;
        ifstream inA("A.txt");
        char str[200];
        while (inA)
        {
          inA.getline(str, 200);
          if (inA)cout << str << endl;
        }
        sleep(2);
      }
      if (carmodel == "B")
      {
        system("CLS");
        cout << "You have chosen Hyundai model" << endl;
        ifstream inB("B.txt");
        char str[200];
        while (inB)
        {
          inB.getline(str, 200);
          if (inB) cout << str << endl;
        }
        sleep(2);
      }
      if (carmodel == "C")
      {
        system("CLS");
        cout << "You have chosen ford model" << endl;
        ifstream inC("C.txt");
        char str[200];
        while (inC)
        {
          inC.getline(str, 200);
          if (inC)cout << str << endl;
        }
        sleep(2);
      }
      if (carmodel == "D")
      {
        system("CLS");
        cout << "You have chosen Maruti model" << endl;
        ifstream inD("D.txt");
        char str[200];
        while (inD)
        {
          inD.getline(str, 200);
          if (inD) cout << str << endl;
        }
        sleep(2);
      }
      if (carmodel == "E")
      {
        system("CLS");
        cout << "You have chosen Honda model" << endl;
        ifstream inE("E.txt");
        char str[200];
        while (inE)
        {
          inE.getline(str, 200);
          if (inE) cout << str << endl;
        }
        sleep(2);
      }
       if (carmodel != "A" && carmodel != "B" && carmodel != "C" && carmodel != "D" && carmodel != "E")

      cout << "invalid car model. please try again!" << endl;
    }
     while (carmodel != "A" && carmodel != "B" && carmodel != "C" && carmodel != "D" && carmodel != "E");
    cout << "-----------------------------------------------------------------------------" << endl;
    cout << "Please provide following information:" << endl;
    cout << "Please select a Car No. :";
    cin >> carnumber;
    cout << " Number of days you wish to rent the car";
    cin >> days;
    cout << "enter advance amount";
    cin >> advanceamt;
    cout << endl;
  }
  

  void calculaterent()
  {
    sleep(1);
    system("CLS");
    cout << "Calculating rent.please wait......" << endl;
    sleep(2);
    if (carmodel == "A" || carmodel == "a")
      rentalfee = days * 2000;

    if (carmodel == "B" || carmodel == "b")
      rentalfee = days * 600;

    if (carmodel == "C" || carmodel == "c")
      rentalfee = days * 750;

    if (carmodel == "D" || carmodel == "d")
      rentalfee = days * 400;

    if (carmodel == "E" || carmodel == "e")
      rentalfee = days * 800;
  }
  void showrent()
  {
    cout << "\n\t\t                   Car Rental-Customer Invoice               " << endl;
    cout << "\t\t /////////////////////////////////////////////////////////////" << endl;
    cout << "\t\t  | Invoice no. :"
         << "--------------------------|" << setw(10) << "#Cnb8153"
         << " |" << endl;
    cout << "\t\t  | Customer Name. :"
         << "--------------------------|" << setw(10) <<customname
         << " |" << endl;
    cout << "\t\t  | Car Model. :"
         << "--------------------------|" << setw(10) << carmodel
         << " |" << endl;
    cout << "\t\t  | Car number . :"
         << "--------------------------|" << setw(10) << carnumber
         << " |" << endl;
    cout << "\t\t  |  no of days. :"
         << "--------------------------|" << setw(10) << days
         << " |" << endl;
    cout << "\t\t  | Your Rental Amount is. :"
         << "--------------------------|" << setw(10) << rentalfee
         << " |" << endl;
    cout << "\t\t  |advanced Amount is. :"
         << "--------------------------|" << setw(10) << advanceamt
         << " |" << endl;
   cout << "\t\t ______________________________________ "
        << " |" << endl;
        cout<<endl;
   cout << "\t\t  |total Rental Amount is. :"
         << "----------|" << setw(10) << rentalfee-advanceamt
         << " |" << endl;

    int f;
    system("PAUSE");
    system("CLS");
    ifstream inf("thanks.txt");

    char str[300];
    while(inf)
    {
      inf.getline(str,300);
      if(inf)cout<< str << endl;
    }
    inf.close();
  }
  
};
class payments
{
  int card_number;
  string card_type;

public:
  rental_details rent;
  string vehicle_id;
  int amount;
  int car_payment_detail()
  {

    char st;
    ofstream datas;
    datas.open("car_payment_detail.dat", ios::binary | ios::app);
    if (!datas)
    {
      cout << "error in opening the file";
    }
    else
    {
      cout << "enter vehicle_id ";
      cin >> vehicle_id;
      cout << "enter card_number ";
      cin >> card_number;
      cout << "enter card_type (debit/card) ";
      cin >> card_type;
      cout << "enter amount :" << amount << endl;
      datas.write((char *)&st, sizeof(st));
      datas << vehicle_id << "\t" << card_number << "\t" << card_type << "\t" << amount << endl;
      datas.close();
    }
    return amount;
  }
  void payment_detail()
  {
    char st;
    ifstream adatas;
    adatas.open("car_payment_detail.dat", ios::out);
    cout << "vehicle_id is\t"<<vehicle_id<<endl
         << "card_number\t"<<card_number<<endl
         << "card_type\t"<<card_type<<endl
         << "amount" <<amount<< endl;
    string line;
    while (getline(adatas, line))
    {
      cout << line << endl;
    }

    adatas.close();
  }
};

class past_rental_record : public payments, public rental_details
{
  string vehicle_id;
  int rent_on;
  int additional_charge;
  double rent_amount;

public:
  payments p;
  void get_id()
  {
    cout<<" enter the id of the car";
    cin>>id;
  }
  void rental_date()
  {
    string line;
    char st;
    ifstream datasl;
    datasl.open("rental.dat", ios::binary | ios::in);
    if (!datasl)
    {
      cout << "error in opening the file";
    }
    else
    {
      cout << "customer_id"
           << "\tlicence"
           << "\taddress"
           << "\tphone"
           << "\trent_date" << endl;

      string line;
      while (getline(datasl, line))
      {
        cout << line << endl;
      }
      datasl.close();
    }
  }
  int get_add_charge()
  {

    char yes;
    cout << "" << endl;
    cout << "property damage and/or vehicle damage in the event of an accident(y/n): " << endl;
    cin >> yes;
    if (yes == 'y')
    {
      int ren = 6050;
      rent_amount = p.car_payment_detail() + ren;
      cout << "add_charge amount is :" << rent_amount << endl;
      char st;
      ofstream datas1;
      datas1.open("add_payment_charge.dat", ios::binary | ios::app);
      if (!datas1)
      {
        cout << "error in opening the file";
      }
      else
      {
        datas1.write((char *)&st, sizeof(st));
        datas1 << p.vehicle_id << "\t" << rent_amount << endl;
      }
      datas1.close();
    }
    else
    {
      rent_amount = p.car_payment_detail();
      cout << "amount: " << rent_amount << endl;
    }
    return rent_amount;
  }
  void get_amount()
  {

    cout << "payment details";
    p.payment_detail();
    string line;
    char st;
    ifstream datas2;
    datas2.open("add_payment_charge.dat", ios::binary | ios::app);
    if (!datas2)
    {
      cout << "error in opening the file";
    }
    else
    {
      cout << "additon charge payment" << endl;
      cout << "vehicle_id\t"
           << "amount" << endl;
      while (getline(datas2, line))
      {
        cout << line << endl;
      }
      datas2.close();
    }
  }
};

int main()
{
  rental_details r;
  r.data();
  r.calculaterent();
  r.showrent();

_getch();
  return 0;
}

