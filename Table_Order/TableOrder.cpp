#include<iostream>
#include<string>
#include<iomanip> 
#include<fstream> 
#define MAX_TABLE 50 
using namespace std;
class Table {
	private : 
	    string tableStatus;
		int numberCustomer,tableID; 
	public : 
		Table(); 
		int getTableID();
		void setTableID(int tableID);
		string getTableStatus();
		void setTableStatus(string tableStatus);
		int getNumberCustomer();
		void setNumberCustomer(int numberCustomer);	
		void inPut();
		void outPut();	 
}; 
Table::Table() {
	tableStatus = "";
	numberCustomer = 0;tableID = 0;
}
int Table::getTableID() {
	return tableID;
}
void Table::setTableID(int tableID) {
	this->tableID = tableID;
}
string Table::getTableStatus() {
	return tableStatus;
}
void Table::setTableStatus(string tableStatus) {
	this->tableStatus = tableStatus;
}
int Table::getNumberCustomer() {
	return numberCustomer; 
}
void Table::setNumberCustomer(int numberCustomer) {
	this->numberCustomer = numberCustomer; 
}
void Table::inPut() {
	cout << "|------------------------------------------------------|" << endl; 
	cout << "Nhap so ban : "; cin >> tableID; 
	cout << "Nhap so luong nguoi :"; cin >> numberCustomer; cin.ignore(); 
	cout << "Nhap trang thai cua ban :"; getline(cin,tableStatus);
}
void Table::outPut() { 
	cout << tableID << setw(10) <<  numberCustomer << setw(20) << tableStatus << endl; 
}

//****************************************************************************

class tableOrder {
	private : 
		Table tables[MAX_TABLE];
		int numberTable; 
	public : 
		int getNumberTable();
		void setNumberTable(int numberTable); 
		void initTable();
		void tableList();
		void bookTable(int id,int customer);
		void freeTable(int id); 
		void writeFile();
		void readFile(); 
}; 
int tableOrder::getNumberTable() {
	return numberTable; 
}
void tableOrder::setNumberTable(int numberTable) {
	this->numberTable = numberTable; 
}
void tableOrder::initTable() { 
		for(int i = 0; i < 20; i++) { 
			tables[i].setTableID(i+1);
			tables[i].setNumberCustomer(0);
			tables[i].setTableStatus("off");  
		} 
	cout << "Khoi tao ban thanh cong." << endl; 
	cout << "|------------------------------------------------------|" << endl; 
}
void tableOrder::tableList() {
	cout << " BAN " << setw(10) << " SO KHACH " << setw(20) << " TRANG THAI "  << endl;
	cout << "|------------------------------------------------------|" << endl;  
	for(int i = 0; i < 20; i++) {
		tables[i].outPut(); 
	} 
} 
void tableOrder::bookTable(int id,int customer) {
    for(int i = 0; i < 20; i++) {
        if (tables[i].getTableID() == id) {
            if (tables[i].getTableStatus() == "off") {
                tables[i].setNumberCustomer(customer);
                tables[i].setTableStatus("on");
                cout << "Dat ban thanh cong." << endl; 
                writeFile();
                tableList();
            } else {
                cout << "Ban da co nguoi dat." << endl; 
        	}
        return;
   		}
    }
}
void tableOrder::freeTable(int id) {
    for(int i = 0; i < 20; i++) {
        if (tables[i].getTableID() == id) {
            if (tables[i].getTableStatus() == "on") {
                tables[i].setTableStatus("off");
                tables[i].setNumberCustomer(0);
                cout << "Ban da trong." << endl; 
                writeFile();
                tableList();
            } else {
                cout << "Ban hien tai chua duoc dat." << endl; 
            }
            return;
  	 	}
	}
}
void tableOrder::writeFile() {
	ofstream f("TableData.txt");
		if(!f.is_open()) {
			cout << "Chua co file TableData.txt." << endl;
			return; 
		} 
		for(int i = 0; i < 20; i++) { 
			f << tables[i].getTableID() << setw(10) <<  tables[i].getNumberCustomer() << setw(20) << tables[i].getTableStatus() << endl;   
		} 
	f.close();
} 
void tableOrder::readFile() {
	ifstream f("TableData.txt");
		if(!f.is_open()) {
			cout << "Loi khi mo file de doc." << endl;
			initTable(); 
			return; 
		} 
	numberTable = 0; int id, num;
	string status;
    while (f >> id >> num >> status) {
        tables[numberTable].setTableID(id);
        tables[numberTable].setNumberCustomer(num);
        tables[numberTable].setTableStatus(status);
       	numberTable++;
    }
    f.close();
} 
int main() {
	tableOrder tb;
	tb.readFile(); 
	int choice,id,customer;
    do {
    	cout << "----------------------------DAT BAN----------------------------" << endl;
		cout << "1.Danh sach ban." << endl;
		cout << "2.Dat ban." << endl;
		cout << "3.Giai phong ban." << endl;
		cout << "4.Thoat." << endl; 
		cout << "Chon chuc nang : "; cin >> choice;
			switch(choice) {
				case 1 : 
					tb.tableList(); 
					break; 
				case 2 :
					cout << "Nhap ban muon dat : "; cin >> id;
					cout << "Nhap so luong nguoi : "; cin >> customer;
					tb.bookTable(id,customer);
					break;
			
				case 3 : 
					cout << "Nhap ban muon giai phong : "; cin >> id;
					tb.freeTable(id);	
					break;
				case 4 : 
					tb.writeFile();
					cout << "Cam on quy khach !" << endl;
					break;
				default : cout << "Lua chon khong hop le !" << endl; 
			} 
		} while(choice != 4); 
	return 0; 
} 

