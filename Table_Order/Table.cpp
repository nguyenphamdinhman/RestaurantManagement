#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#define MAX_TABLE 50
#define MAX_DISH 100
using namespace std;

class Dish {
private:
    string dishName;
    double price;
    int quantity;
public:
    void inPut() {
        cout << "Nhap ten mon: ";
        cin.ignore();
        getline(cin, dishName);
        cout << "Nhap gia: ";
        cin >> price;
        cout << "Nhap so luong: ";
        cin >> quantity;
    }
    void outPut() {
        cout << setw(20) << left << dishName
             << setw(10) << price
             << setw(10) << quantity
             << setw(10) << price * quantity << endl;
    }
    double getPrice() { return price; }
    int getQuantity() { return quantity; }
};

//****************************************************************************

class Customer {
private:
    string name;
    string phone;
public:
    void inPut() {
        cout << "Nhap ten khach hang: ";
        getline(cin, name);
        cout << "Nhap SDT: ";
        getline(cin, phone);
    }
    void outPut() {
        cout << "Khach hang: " << name << " | SDT: " << phone << endl;
    }
};

//------------------ CLASS TABLE ------------------//
class Table {
private:
    string tableStatus;
    int numberCustomer, tableID;
public:
    Table() {
        tableStatus = "off";
        numberCustomer = 0;
        tableID = 0;
    }
    int getTableID() { return tableID; }
    void setTableID(int id) { tableID = id; }
    string getTableStatus() { return tableStatus; }
    void setTableStatus(string s) { tableStatus = s; }
    int getNumberCustomer() { return numberCustomer; }
    void setNumberCustomer(int n) { numberCustomer = n; }

    void outPut() {
        cout << tableID << setw(10) << numberCustomer << setw(20) << tableStatus << endl;
    }
};

//------------------ CLASS TABLE ORDER ------------------//
class tableOrder {
private:
    Table tables[MAX_TABLE];
public:
    void initTable();
    void tableList();
    bool bookTable(int id, int customer);
    bool freeTable(int id);
    void writeFile();
    void readFile();
};

void tableOrder::initTable() {
    for (int i = 0; i < 20; i++) {
        tables[i].setTableID(i + 1);
        tables[i].setTableStatus("off");
        tables[i].setNumberCustomer(0);
    }
    writeFile();
}

void tableOrder::tableList() {
    cout << " BAN " << setw(10) << " SO KHACH " << setw(20) << " TRANG THAI " << endl;
    for (int i = 0; i < 20; i++) {
        tables[i].outPut();
    }
}

bool tableOrder::bookTable(int id, int customer) {
    if (id < 1 || id > 20) return false;
    if (tables[id - 1].getTableStatus() == "on") {
        cout << "Ban da co nguoi dat!\n";
        return false;
    }
    tables[id - 1].setNumberCustomer(customer);
    tables[id - 1].setTableStatus("on");
    writeFile();
    return true;
}

bool tableOrder::freeTable(int id) {
    if (id < 1 || id > 20) return false;
    if (tables[id - 1].getTableStatus() == "off") {
        cout << "Ban hien dang trong!\n";
        return false;
    }
    tables[id - 1].setTableStatus("off");
    tables[id - 1].setNumberCustomer(0);
    writeFile();
    return true;
}

void tableOrder::writeFile() {
    ofstream f("tables.txt");
    for (int i = 0; i < 20; i++) {
        f << tables[i].getTableID() << " "
          << tables[i].getNumberCustomer() << " "
          << tables[i].getTableStatus() << endl;
    }
    f.close();
}

void tableOrder::readFile() {
    ifstream f("tables.txt");
    if (!f.is_open()) {
        cout << "Chua co file -> Tao moi danh sach 20 ban.\n";
        initTable();
        return;
    }
    int id, num;
    string status;
    int i = 0;
    while (f >> id >> num >> status) {
        tables[i].setTableID(id);
        tables[i].setNumberCustomer(num);
        tables[i].setTableStatus(status);
        i++;
    }
    f.close();
}

//------------------ CLASS ORDER ------------------//
class Order {
private:
    string orderID, dishStatus;
    int Quantity;
    Customer cus;
    Dish dishes[MAX_DISH];
    Table tab;
    static int idCount;
public:
    Order() {
        orderID = "ORD" + to_string(++idCount);
        dishStatus = "DANG LAM";
        Quantity = 0;
    }
    void inPut(tableOrder &tb);
    void outPut();
    double addUp();
};
int Order::idCount = 1000;

void Order::inPut(tableOrder &tb) {
    cout << "\nNhap thong tin khach hang:\n";
    cin.ignore();
    cus.inPut();
    cout << "Nhap so ban muon dat (1-20): ";
    int id, num;
    cin >> id;
    cout << "Nhap so luong khach: ";
    cin >> num;
    if (tb.bookTable(id, num)) {
        tab.setTableID(id);
        tab.setTableStatus("on");
    } else {
        cout << "Khong the dat ban nay.\n";
        return;
    }

    cout << "Nhap so luong mon an: ";
    cin >> Quantity;
    for (int i = 0; i < Quantity; i++) {
        cout << "\n--- Mon an " << i + 1 << " ---\n";
        dishes[i].inPut();
    }
    cout << "Dat don hang thanh cong!\n";
}

void Order::outPut() {
    cout << "\n========== THONG TIN DON HANG ==========\n";
    cout << "Ma don hang: " << orderID << endl;
    cus.outPut();
    tab.outPut();
    cout << setw(20) << left << "Mon an" << setw(10) << "Gia" << setw(10) << "SL" << setw(10) << "Tien" << endl;
    for (int i = 0; i < Quantity; i++) dishes[i].outPut();
    cout << "Tong cong: " << addUp() << " VND\n";
}

double Order::addUp() {
    double sum = 0;
    for (int i = 0; i < Quantity; i++)
        sum += dishes[i].getPrice() * dishes[i].getQuantity();
    return sum;
}

//****************************************************************************
int main() {
    tableOrder tb;
    tb.readFile();
    int choice;
    do {
        cout << "\n========= QUAN LY QUAN AN =========\n";
        cout << "1. Xem danh sach ban\n";
        cout << "2. Dat ban va tao don\n";
        cout << "3. Giai phong ban\n";
        cout << "0. Thoat\n";
        cout << "Chon: ";
        cin >> choice;
        if (choice == 1)
            tb.tableList();
        else if (choice == 2) {
            Order o;
            o.inPut(tb);
            o.outPut();
        } else if (choice == 3) {
            int id;
            cout << "Nhap so ban muon giai phong: ";
            cin >> id;
            tb.freeTable(id);
        }
    } while (choice != 0);

    cout << "Tam biet!\n";
    return 0;
}

