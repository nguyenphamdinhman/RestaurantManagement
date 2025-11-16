#include<iostream>
#include<string>
#include<iomanip> 
#include<fstream> 

#define MAX_STAFF 50 
#define MAX_CUSTOMER 100 
#define MAX_DISH 50 
#define MAX_TABLE 50 
using namespace std;

//STRUCT DATE 
struct Date {
	int day, month,year; 
};	
void inputDate(Date &d) {
	cout << "Nhap ngay : "; cin >> d.day;
	cout << "Nhap thang : "; cin >> d.month;
	cout << "Nhap nam :"; cin >> d.year;
	cin.ignore(); 
} 
void outputDate(const Date &d) {
	cout << setfill('0') << setw(2) << d.day << "/" << setw(2) << d.month << "/" << setw(2) << d.year;
} 
//PERSON*********************************************************************************
class Person {
 	private : 
 	 	string Name,Gender,birthDate,Phone,Address;
 	public : 
 	    Person();
  		void inPut();
 		void outPut();
 		string getName();
     	void setName(string Name);
 	    string getPhone();
 	    void setPhone(string Phone);
 	    string getGender();
 	    void setGender(string Gender);
 	    string getBirthDate();
 	    void setBirthDate(string birthDate);
 	    string getAddress();
 	    void setAddress(string Address);
 	    void writeFile(ofstream &f);
		bool readFile(ifstream &f);
};
Person::Person() {
	Name = ""; Gender = ""; Address = ""; Phone = ""; birthDate = "";
}
string Person::getName() { 
	return Name;
}
void Person::setName(string Name) { 
	this->Name = Name;
}
string Person::getGender() {
	return Gender;
}
void Person::setGender(string Gender) {
	this->Gender = Gender;
}
string Person::getAddress() {
	return Address;
}
void Person::setAddress(string Address) {
	this->Address = Address;
}
string Person::getBirthDate() {
	return birthDate;
}
void Person::setBirthDate(string birthDate) {
	this->birthDate = birthDate;
}
string Person::getPhone() {
	return Phone;
}
void Person::setPhone(string Phone) {
	this->Phone = Phone;
}
void Person::writeFile(ofstream &f) {
	f << Name << endl;
	f << birthDate << endl;
	f << Gender << endl;
	f << Address << endl;
	f << Phone << endl; 
}
bool Person::readFile(ifstream &f) {
	getline(f,Name); if(Name.empty()) return false;
	getline(f,birthDate);
	getline(f,Gender);
	getline(f,Address);
	getline(f,Phone);
	return true; 
}
void Person::inPut() {
	cout << "Nhap ho va ten : " ; getline(cin,Name);
	cout << "Nhap ngay sinh : "; getline(cin,birthDate);
	cout << "Nhap gioi tinh : " ; getline(cin,Gender);
	cout << "Nhap dia chi  : " ; getline(cin,Address); 
	cout << "Nhap so dien thoai : "; getline(cin,Phone); 
}
void Person::outPut() {	
	cout << "HO VA TEN : " << Name << endl;
	cout << "NGAY SINH : " << birthDate << endl;
	cout << "GIOI TINH : " << Gender << endl;
	cout << "DIA CHI : " << Address << endl; 
	cout << "SO DIEN THOAI : " << Phone << endl; 
}
//STAFF**********************************************************************************
class Staff : public Person {
	private : 
		string staffID,Role,Department,startDate,homeTown; 
		double Salary;
	public :
	    Staff();
		string getStaffID();
		void setStaffID(string staffID);
		string getRole();
		void setRole(string Role);
		string getDepartment();
		void setDepartment(string Department);
		string getStartDate();
		void setStartDate(string startDate);
		string getHomeTown();
		void setHomeTown(string homeTown);
		double getSalary();
		void setSalary(double Salary);	
		void inPut();
		void outPut(); 
		void writeFile(ofstream &f);
		bool readFile(ifstream &f);
}; 
Staff::Staff() {
	Salary = 0;
	Role = ""; staffID = ""; Department = ""; startDate = ""; homeTown = ""; 
}
string Staff::getStaffID() {
	return staffID;
}
void Staff::setStaffID(string staffID) {
	this->staffID = staffID;
}
string Staff::getRole() {
	return Role;
}
void Staff::setRole(string Role) {
	this->Role = Role;
}
string Staff::getDepartment() {
	return Department; 
}
void Staff::setDepartment(string Department) {
	this->Department = Department; 
}
string Staff::getStartDate() {
	return startDate;
}
void Staff::setStartDate(string startDate) {
	this->startDate = startDate; 
}
string Staff::getHomeTown() {
	return homeTown;
}
void Staff::setHomeTown(string homeTown) {
	this->homeTown = homeTown;
}
double Staff::getSalary() {
	return Salary;
}
void Staff::setSalary(double Salary) {
	this->Salary = Salary;
}	
void Staff::inPut() {
    cout << "Nhap ID nhan vien: "; getline(cin, staffID);
    Person::inPut();
    cout << fixed << setprecision(2);
    cout << "Nhap que quan: "; getline(cin, homeTown);
    cout << "Nhap chuc vu: "; getline(cin, Role);
    cout << "Nhap phong ban: "; getline(cin, Department);
    cout << "Nhap ngay bat dau lam viec: "; getline(cin, startDate);
    cout << "Nhap luong: "; cin >> Salary;
    cin.ignore();
}
void Staff::outPut() {
	cout << "ID : " << staffID << endl; 
	Person::outPut();
	cout << "QUE QUAN : " << homeTown << endl; 
	cout << "CHUC VU : " << Role << endl;
	cout << "PHONG BAN : " << Department << endl; 
	cout << "NGAY BAT DAU : " << startDate << endl; 
	cout << "LUONG : " << Salary << endl; 
	cout << "-----------------------------------------------------------" << endl;
}
void Staff::writeFile(ofstream &f) {
	Person::writeFile(f);
        f << staffID << endl;
        f << homeTown << endl;
        f << Role << endl;
        f << Department << endl;
        f << startDate << endl;
        f << Salary << endl;
}
bool Staff::readFile(ifstream &f) {
 	if (!Person::readFile(f)) return false;
 		getline(f, staffID);
        getline(f, homeTown);
        getline(f, Role);
        getline(f, Department);
        getline(f, startDate);
        f >> Salary;
        f.ignore();
        return true;
}
//STAFF_FUCTION**************************************************************************
class SManager {
	private : 
		Staff staffs[MAX_STAFF];
		int nums;
	public :
		SManager();
		void loadFile();
		void saveFile();
		void addStaff();
		void updateStaff();
		void deleteStaff();	
		void SMenu(); 
}; 
SManager::SManager() { 
	nums = 0;
} 
void SManager::loadFile() {
	ifstream fin("StaffData.txt");
        if (!fin.is_open()) return;
        while (nums < MAX_STAFF && staffs[nums].readFile(fin)) nums++;
        fin.close(); 
}
void SManager::saveFile() {
        ofstream fout("StaffData.txt");
        for (int i = 0; i < nums; i++) staffs[i].writeFile(fout);
        fout.close();
        cout << "Da luu vao file." << endl;
}
void SManager::addStaff() {
	cout << "THEM NHAN VIEN" << endl; 
		staffs[nums].inPut();
        nums++;
        cout << "Them thanh cong." << endl;
} 
void SManager::updateStaff() {
	string idUpdate; cout << "Nhap ma nhan vien can sua : "; getline(cin,idUpdate);
	for(int i = 0; i < nums; i++) {
		if(staffs[i].getStaffID() == idUpdate) {
			staffs[i].inPut(); 
		} 
	} 
	cout << "Chinh sua thanh cong." << endl; 
}
void SManager::deleteStaff() {
	string idDelete; cout << "Nhap ma nhan vien can xoa : "; getline(cin,idDelete);
	int vitri = -1;
	for(int i = 0; i < nums; i++) {
		if(staffs[i].getStaffID() == idDelete) {
			vitri = i;
			break; 
		} 
	}
	if (vitri == -1) cout << "Khong thay nhan vien trong danh sach." << endl;
        else {
            for (int i = vitri; i < nums - 1; i++) {
                staffs[i] = staffs[i + 1];
        }
            nums--;
            cout << "Xoa thanh cong." << endl;
    }
}
void SManager::SMenu() {
	int choice ; 
		SManager::loadFile();
	do {
		cout << "--------------------------------------------------------------------------------------------------------" << endl; 
		cout << "MENU NHAN VIEN" << endl;
		cout << "1.Them." << endl;
		cout << "2.Chinh sua." << endl;
		cout << "3.Xoa." << endl;
		cout << "4.Luu file." << endl;
		cout << "5.Thoat." << endl;
		cout << "Chon chuc nang : "; cin >> choice; cin.ignore(); 
		switch(choice) {
			case 1 : SManager::addStaff(); break; 
			case 2 : SManager::updateStaff(); break; 
			case 3 : SManager::deleteStaff(); break; 
			case 4 : SManager::saveFile(); break; 
			case 5 : cout << "Thoat chuong trinh nhan vien." << endl; break;
			default : cout << "Vui long chon chuc nang hop le." << endl; 
		} 
	} while(choice != 5);  
}
//CUSTOMER*******************************************************************************
class Customer: public Person {
	private : 
	    string customerID,email;  
	    bool emailCheck; 
	public :
	 	Customer(); 
		string getCustomerID();
		void setCustomerID(string customerID);
		string getEmail();
		void setEmail(string email);
		void inPut();
		void outPut();
		void writeFile(ofstream &f);
		bool readFile(ifstream &f);
}; 
Customer::Customer() {
	customerID = ""; email = ""; emailCheck = false; 
}
string Customer::getCustomerID() {
	return customerID;
}
void Customer::setCustomerID(string customerID) {
	this->customerID = customerID;
}
string Customer::getEmail() {
	return email;
}
void Customer::setEmail(string email) {
	this->email = email;
}
void Customer::inPut() {
	cout << "Nhap ID khach hang : "; getline(cin,customerID);
	Person::inPut();
	cout <<	"Nhap email khach hang :"; getline(cin,email);
	if(email.empty()) {
		emailCheck = false; 
		email = "X"; 
	} else {
		emailCheck = true; 
	} 
}
void Customer::outPut() {
	cout << "ID khach hang : " << customerID << endl; 
	Person::outPut();
	if(emailCheck) {
		cout << "Email : " << email << endl; 
	} else {
		cout << "Email : X " << endl; 
	} 
}
void Customer::writeFile(ofstream &f) {
	Person::writeFile(f);
	f << customerID << endl;
	f << email << endl; 
}
bool Customer::readFile(ifstream &f) {
	if(!Person::readFile(f)) return false;
	getline(f,customerID);
	getline(f,email);
	return true; 
}
//CUSTOMER_FUNTION************************************************************************
class CManager {
	private : 
		Customer customers[MAX_CUSTOMER]; 
		int nums;
	public : 
		CManager();
		void loadFile();
		void saveFile();
		void addCustomer();
		void deleteCustomer();
		void CMenu(); 
}; 
CManager::CManager() {
	nums = 0; 
}
void CManager::loadFile() {
	ifstream fin("CustomerData.txt");
		if(!fin.is_open()) return; 
		while(nums < MAX_CUSTOMER && customers[nums].readFile(fin)) nums++;
		fin.close(); 
} 
void CManager::saveFile() {
	ofstream fout("CustomerData.txt");
		for (int i = 0; i < nums; i++) {
			customers[i].writeFile(fout); 
		}
		fout.close(); 
		cout << "Da luu vao file." << endl; 
}
void CManager::addCustomer() {
	cout << "THEM KHACH HANG." << endl;
	customers[nums].inPut(); nums++;
	cout << "Them thanh cong." << endl; 
} 
void CManager::deleteCustomer() {
	string idDelete; cout << "Nhap ma khach hang can xoa : "; getline(cin,idDelete);
	int vitri = -1;
	for(int i = 0; i < nums; i++) {
		if(customers[i].getCustomerID() == idDelete) {
			vitri = i;
			break; 
		} 
	}
	if(vitri == -1) {
		cout << "Khong thay khach hang trong danh sach." << endl; 
	} else {
		for(int i = vitri; i < nums; i++) {
			customers[i] = customers[i+1]; 
		}
			nums--;
			cout << "Xoa thanh cong." << endl;
	} 
} 
void CManager::CMenu() {
	int choice ; 
		CManager::loadFile();
	do {
		cout << "--------------------------------------------------------------------------------------------------------" << endl; 
		cout << "MENU KHACH HANG" << endl;
		cout << "1.Them." << endl;
		cout << "2.Xoa." << endl;
		cout << "3.Luu file." << endl;
		cout << "4.Thoat." << endl;
		cout << "Chon chuc nang : "; cin >> choice; cin.ignore(); 
		switch(choice) {
			case 1 : CManager::addCustomer(); break; 
			case 2 : CManager::deleteCustomer(); break; 
			case 3 : CManager::saveFile(); break; 
			case 4 : cout << "Thoat chuong trinh nhan vien." << endl; break;
			default : cout << "Vui long chon chuc nang hop le." << endl; 
		} 
	} while(choice != 4);   
}
//DISH***********************************************************************************
class Dish {
	private : 
	    string dishID,Name,Type;
		int Price; 
	public : 
	 	Dish(); 
		string getDishID();
		void setDishID(string DishID);
		int getPrice();
		void setPrice(int Price);
		string getName();
		void setName(string Name);
		string getType();
		void setType(string Type);
		void inPut();
		void outPut();
		void writeFile(ofstream &f);
		bool readFile(ifstream &f);
};
Dish::Dish() {
	dishID = "", Name = "" , Type = ""; 
	Price = 0;
}
string Dish::getDishID() {
	return dishID;
}
void Dish::setDishID(string dishID) {
	this->dishID = dishID;
}
int Dish::getPrice() {
	return Price;
}
void Dish::setPrice(int Price) {
	this->Price = Price;
} 
string Dish::getName() {
	return Name;
}
void Dish::setName(string Name) {
	this->Name = Name;
}
string Dish::getType() {
	return Type;
}
void Dish::setType(string Type) {
	this->Type = Type;
}
void Dish::inPut() {
	cout << "Nhap ID mon : "; getline(cin,dishID);
	cout << "Nhap ten mon : "; getline(cin,Name);
	cout << "Nhap loai mon an : "; getline(cin,Type);
	cout << "Nhap gia cho mon an : "; cin >> Price; cin.ignore(); 
}
void Dish::outPut() {
	cout << setw(10) << dishID << setw(30) << Name << setw(20) << Type << setw(15) << Price << " VND "<< endl;
}
void Dish::writeFile(ofstream &f) {
	f << dishID << endl;
	f << Name << endl; 
	f << Type << endl;
	f << Price << endl;
}	
bool Dish::readFile(ifstream &f) {
    getline(f,dishID); if(dishID.empty()) return false; 
	getline(f,Name); 
	getline(f,Type); 
	f >> Price; f.ignore(); 
	return true;
}
//MENU_FUNCTION***************************************************************************
class Menu {
	private : 
	    Dish dishes[MAX_DISH];
	    int Quantity; 
	public : 
		Menu(); 
		void loadFile();
		void saveFile(); 
		void showMenu(); 
		void addDish();
		void searchDish();
		void deleteDish(); 
		void updateDish(); 
		void sortDish(); 
		void MMenu(); 
}; 
Menu::Menu() {
	Quantity = 0; 
} 
int typeOrder(const string &type) {
        if(type == "Mon chinh") return 1;
        if(type == "Mon phu") return 2;
        if(type == "Do uong") return 3;
        return 4;
}
void Menu::loadFile() {
	ifstream fin("MenuData.txt");
		if(!fin.is_open()) return;
		while(Quantity < MAX_DISH && dishes[Quantity].readFile(fin)) Quantity++;
		fin.close(); 
}	
void Menu::saveFile() {
	ofstream fout("MenuData.txt");
		for(int i = 0; i < Quantity; i++) {
			dishes[i].writeFile(fout);
		}
		fout.close();
		cout << "Da luu vao file ." << endl; 
}
void Menu::showMenu() {
    cout << setw(10) << "ID" << setw(30) << "MON AN" << setw(20) << "LOAI MON" << setw(15) << "GIA" << endl;
    for(int i = 0; i < Quantity; i++) {
        dishes[i].outPut();
    }
}
void Menu::addDish() {
	if(Quantity >= MAX_DISH) {
		cout << "Dat gioi han." << endl;
		return; 
	} 
	int count; cout << "Nhap so luong mon an muon them : "; cin >> count; cin.ignore();
	cout << endl;
		for(int i = 0; i < count; i++) {
			dishes[Quantity].inPut();
			Quantity++; 
	}
	cout << "Them mon thanh cong" << endl; 
}
void Menu::deleteDish() {
	string dishName; cout << "Nhap ten mon an can xoa : "; getline(cin,dishName);
	bool flag = false; 
	 	for(int i = 0; i < Quantity; i++) {
			if(dishes[i].getName() == dishName) {
				for(int j = i; j < Quantity - 1; j++) {
					dishes[j] = dishes[j+1]; 
			} 
			Quantity--;
			flag = true; 
			cout << "Xoa mon thanh cong." << endl;
			return; 
		}
	}
	if(!flag) cout << "Khong tim thay mon " << dishName << " trong menu."<< endl; 
}
void Menu::searchDish() {
	string dishName; cout << "Nhap ten mon an can tim kiem : "; getline(cin,dishName); 
	bool flag = false; 
		for(int i = 0; i < Quantity; i++) {
			if(dishes[i].getName() == dishName) {
				dishes[i].outPut();
				flag = true; 
				return; 
		} 
	} 
	if(!flag) cout << "Khong tim thay mon " << dishName << " trong menu."<< endl;  
}
void Menu::sortDish() {
	for(int i = 0; i < Quantity; i++) {
		for(int j = i + 1; j < Quantity; j++) {
			int typeI = typeOrder(dishes[i].getType());
            int typeJ = typeOrder(dishes[j].getType());
                if(typeI > typeJ) {
					Dish tmp = dishes[i];
					dishes[i] = dishes[j];
					dishes[j] = tmp; 
			} 
		} 
	}
	cout << "Sap xep menu thanh cong." << endl; 
} 
void Menu::updateDish() {
	string id; cout << "Nhap ma mon can cap nhat : "; getline(cin,id);
		for(int i = 0; i < Quantity; i++) {
            if(dishes[i].getDishID() == id) {
                cout << "Nhap thong tin moi:\n";
                dishes[i].inPut();
                cout << "Cap nhat thanh cong!\n";
                return;
            }
    	}
    cout << "Khong tim thay ma mon an " << id << " trong danh sach." << endl; 
} 
void Menu::MMenu() {
	int choice;  
		Menu::loadFile();
	do {
		cout << "--------------------------------------------------------------------------------------------------------" << endl; 
		cout << "MENU DISH" << endl;
		cout << "1.Hien thi." << endl;
		cout << "2.Them." << endl;
		cout << "3.Chinh sua." << endl;
		cout << "4.Tim kiem." << endl;
		cout << "5.Sap xep." << endl; 
		cout << "6.Xoa." << endl;
		cout << "7.Luu file." << endl; 
		cout << "8.Thoat." << endl; 
		cout << "Chon chuc nang : "; cin >> choice; cin.ignore(); 
		switch(choice) {
			case 1 : Menu::showMenu(); break; 
			case 2 : Menu::addDish(); break; 
			case 3 : Menu::updateDish(); break; 
			case 4 : Menu::searchDish(); break; 
			case 5 : Menu::sortDish(); break; 
			case 6 : Menu::deleteDish(); break; 
			case 7 : Menu::saveFile(); break;  
			case 8 : cout << "Thoat chuong trinh nhan vien." << endl; break; 
			default : cout << "Vui long chon chuc nang hop le." << endl; 
		} 
	} while(choice != 8);  
} 
//TABLE**********************************************************************************
class Table {
	private : 
	    string tableStatus;
		int numberCustomer,tableID; 
		Date date; 
	public : 
		Table(); 
		int getTableID();
		void setTableID(int tableID);
		string getTableStatus();
		void setTableStatus(string tableStatus);
		int getNumberCustomer();
		void setNumberCustomer(int numberCustomer);	
		Date getDate();
		void setDate(Date date); 
		void inPut();
		void outPut();	 
}; 
Table::Table() {
	tableStatus = "off"; 
	numberCustomer = 0;tableID = 0; 
	date.day = 0; date.month = 0; date.year = 0; 
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
Date Table::getDate() {
	return date; 
}
void Table::setDate(Date date) {
	this->date = date; 
}
void Table::inPut() {
	cout << "NHAP THONG TIN BAN" << endl; 
	cout << "Nhap so ban : "; cin >> tableID; 
	cout << "Nhap so luong nguoi :"; cin >> numberCustomer; 
	cout << "Nhap ngay : "; cin >> date.day;
	cout << "Nhap thang : "; cin >> date.month;
	cout << "Nhap nam : "; cin >> date.year; 
	cin.ignore();  
	cout << "Nhap trang thai cua ban :"; getline(cin,tableStatus);
}
void Table::outPut() { 
	cout << setfill('0') << tableID << " " << numberCustomer << " " << date.day << " " << date.month << " " << date.year << " " << tableStatus << endl; 
}
//TABLE_FUNCTION*************************************************************************
class tableOrder {
	private : 
		Table tables[MAX_TABLE];
		int numberTable; 
	public : 
		int getNumberTable();
		void setNumberTable(int numberTable);
		Table getTableId(int id); 
		bool isCheckStatus(int id);
		void tableList();
		void bookTable(int id,int customer);
		void freeTable(int id); 
		void writeFile();
		void readFile(); 
		void TMenu(); 
}; 
int tableOrder::getNumberTable() {
	return numberTable; 
}
void tableOrder::setNumberTable(int numberTable) {
	this->numberTable = numberTable; 
}
Table tableOrder::getTableId(int id) {
	for(int i = 0; i < numberTable; i++) {
		if(tables[i].getTableID() == id) {
			return tables[i]; 
		} 
	} 
	return Table(); 
}
bool tableOrder::isCheckStatus(int id) {
	for (int i = 0; i < numberTable; i++) {
            if (tables[i].getTableID() == id && tables[i].getTableStatus() == "on") {
                return true;
            }
        }
    return false;
}
void tableOrder::tableList() {
	cout << " BAN " << setw(10) << " SO KHACH " << setw(20) << " NGAY " << setw(15) << " TRANG THAI "  << endl;
	for(int i = 0; i < numberTable; i++) {
		tables[i].outPut(); 
	}  
}
void tableOrder::bookTable(int id,int customer) {
    for(int i = 0; i < numberTable; i++) {
        if (tables[i].getTableID() == id) {
            if (tables[i].getTableStatus() == "off") {
                tables[i].setNumberCustomer(customer);
               	Date d;
					cout << "Nhap ngay : "; cin >> d.day;
					cout << "Nhap thang : "; cin >> d.month;
					cout << "Nhap nam : "; cin >> d.year;
					tables[i].setDate(d);
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
    for(int i = 0; i < numberTable; i++) {
        if (tables[i].getTableID() == id) {
            if (tables[i].getTableStatus() == "on") {
                tables[i].setTableStatus("off");
                tables[i].setNumberCustomer(0);
                tables[i].setDate({0,0,0});  
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
void tableOrder::readFile() {
	ifstream f("TableData.txt");
		if(!f.is_open()) {
			cout << "Loi khi mo file de doc." << endl;
			return; 
		} 
	numberTable = 0; 
	int id,num,d,m,y; 
	Date date;
	string status; 
    while (f >> id >> num >> d >> m >> y >> status) { 
        tables[numberTable].setTableID(id);
        tables[numberTable].setNumberCustomer(num);
    	tables[numberTable].setDate({d,m,y});
        tables[numberTable].setTableStatus(status);
       	numberTable++;
    }
    f.close();
}  
void tableOrder::writeFile() {
	ofstream f("TableData.txt");
		if(!f.is_open()) {
			cout << "Chua co file TableData.txt." << endl;
			return; 
		} 
		for(int i = 0; i < numberTable; i++) { 
			Date d = tables[i].getDate(); 
			f << tables[i].getTableID() << " " <<  tables[i].getNumberCustomer() << " " << d.day << " "  << d.month << " " <<  d.year  << " " << tables[i].getTableStatus() << endl;   
		} 
	f.close();
} 
void tableOrder::TMenu() {
	int choice; 
	do {
		cout << "--------------------------------------------------------------------------------------------------------" << endl; 
		cout << "MENU BAN" << endl;
		cout << "1.Hien thi." << endl; 
		cout << "2.Dat ban." << endl;
		cout << "3.Tra ban." << endl;
		cout << "4.Thoat" << endl;
		cout << "Chon chuc nang : "; cin >> choice; cin.ignore();
		switch(choice) {
			case 1 : readFile(); tableList(); break; 
			case 2 : 
				{
					int id, customer;
                		cout << "Nhap so ban : "; cin >> id;
                		cout << "Nhap so khach : "; cin >> customer;
                		cin.ignore(); 
               				 bookTable(id,customer);
               		break; 
              	}
			case 3 : 
				{
					int id; 
						cout << "Nhap so ban can xoa : "; cin >> id; cin.ignore(); 
							freeTable(id); 
					break; 
				}
			case 4 : cout << "Thoat chuong trinh Table." << endl; break; 
			default : cout << "Vui long chon chuc nang hop le." << endl; 
		} 
	} while(choice != 4); 
} 
//ORDER**********************************************************************************
class Order {
	private : 
		Dish dishes[MAX_DISH];
		Table tab; 
	 	int Count; 
	    double Total; 
	    string nameOrder; 
	public:
	    Order();
	    int getCount();
	    void setCount(int Count);
	    double getTotal();
	    void setTotal(double Total);
	    void showMenu();
	    void inPut();
	    void outPut();
	    void writeFile();
	    void readFile();
	    void deleteFile();
	    void OMenu(); 
};
Order::Order() {
	Count = 0;Total = 0; 
} 
int Order::getCount() {
	return Count; 
}
void Order::setCount(int Count) {
	this->Count = Count; 
}
double Order::getTotal() {
	return Total; 
}
void Order::setTotal(double Total) {
	this->Total = Total; 
}
void Order::showMenu() {
	Menu mn; 
	mn.loadFile();
	mn.showMenu(); 
} 
void Order::inPut() {
	int idT; 
	tableOrder to; 
    cout << "Nhap ban so: "; cin >> idT; cin.ignore(); 
    if (!to.isCheckStatus(idT)) {
        cout << "Ban khong hop le." << endl;
        return;
    }
    tab = to.getTableId(idT);
    cout << "Nhap ten mon : "; getline(cin,nameOrder); 
    cout << "Nhap so luong : "; cin >> Count; cin.ignore(); 
    fstream fin("MenuData.txt");
	if(!fin.is_open()) {
		cout << "Loi khi mo file." << endl;
		return; 
	} 
	string idD, dish, type;
    double price = 0;Total = 0;
    bool found = false;
	while (getline(fin, idD)) {
        getline(fin, dish);
        getline(fin, type);
        fin >> price;
        fin.ignore();
        if (dish == nameOrder) {
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Khong tim thay mon nay." << endl;
        return;
    }
    Total = price * Count; 
    cout << "Tong tien : " << Total << " VND" << endl; 
}
void Order::outPut() {
    cout << "Ban so : " << tab.getTableID() << endl;
	cout << "Mon : " << nameOrder << endl;
	cout << "So luong : " << Count << endl; 
    cout << "Tong tien: " << Total << " VND" << endl;
}
void Order::readFile() {
	ifstream fin("OrderData.txt"); 
		if(!fin.is_open()) {
			cout << "Loi ghi mo file de doc." << endl;
			return; 
	} 
	int idT, count;
    string name;
    double total;
    while (fin >> idT >> name >> count >> total) {
        cout << idT << " " << name << " " << count << " " << total << " VND" << endl;
    }
    fin.close();
}
void Order::writeFile() {
    ofstream fout("OrderData.txt", ios::app);
    if (!fout.is_open()) {
        cout << "Loi khi mo file de ghi." << endl;
        return;
    }
	    fout << tab.getTableID() << " " << nameOrder << " " << Count << " " << Total << endl;
	    fout.close();
    cout << "Da luu vao file." << endl;
}
void Order::deleteFile() {
 	ofstream f("OrderData.txt", ios::trunc);
    if (!f.is_open()) {
        cout << "Loi khi mo file de xoa." << endl;
        return;
    }
    f.close();
    cout << "Da xoa toan bo don hang.\n";
} 
void Order::OMenu() {
	int choice; 
	do {
		cout << "MENU ORDER" << endl;
		cout << "1.Hien thi menu." << endl; 
		cout << "2.Goi mon." << endl;
		cout << "3.Lich su." << endl;
		cout << "4.Xoa du lieu." << endl; 
		cout << "5.Thoat" << endl;
		cout << "Chon chuc nang : "; cin >> choice; cin.ignore();
		switch(choice) {
			case 1 : showMenu(); break; 
			case 2 : inPut(); break; 
			case 3 : readFile(); break; 
			case 4 : deleteFile(); break; 
			case 5 : cout << "Thoat chuong trinh order." << endl; break; 
			default : cout << "Vui long chon chuc nang hop le." << endl; 
		} 
	} while(choice != 5); 
} 
//FEEDBACK*******************************************************************************
class PAF {
	private : 
		string comment,paymentMethod;
		double VAT,Discount;
		int Rating,idTable; 
	public:
	    PAF();                        
	    int getIdTable();
	    void setIdTable(int idTable);
	    string getPaymentMethod();
	    void setPaymentMethod(string paymentMethod);
	    string getComment();
	    void setComment(string comment);
	    double getVAT();
	    void setVAT(double VAT);
	    double getDiscount();
	    void setDiscount(double Discount);
	    int getRating();
	    void setRating(int Rating);
	    void showOrder();
	    void inPut();           
	    void outPut();  
	    void readFile();
		void writeFile();
		void deleteFile(); 
		void PMenu(); 
};
PAF::PAF() {
	comment = "";  paymentMethod = "";
	Rating = 0; VAT = 0.0; Discount = 0.0; 
}
int PAF::getIdTable() {
	return idTable; 
}
void PAF::setIdTable(int idTable) {
	this->idTable = idTable; 
}
string PAF::getPaymentMethod() {
 	return paymentMethod; 
}
void PAF::setPaymentMethod(string paymentMethod) { 
	this->paymentMethod = paymentMethod; 
}
string PAF::getComment() {
 	return comment; 
}
void PAF::setComment(string comment) { 
	this->comment = comment; 
}
double PAF::getVAT() { 
	return VAT; 
}
void PAF::setVAT(double VAT) { 
	this->VAT = VAT; 
}
double PAF::getDiscount() { 
	return Discount;
}
void PAF::setDiscount(double Discount) { 
	this->Discount = Discount; 
}
int PAF::getRating() { 
	return Rating; 	
}
void PAF::setRating(int Rating) { 
	this->Rating = Rating; 
}
void PAF::showOrder() {
	Order o;
	o.readFile();
}
void PAF::inPut() {
	tableOrder to;
	cout << "MENU THANH TOAN VA PHAN HOI" << endl; 
    cout << "Nhap ban so: "; cin >> idTable; cin.ignore();
    if (!to.isCheckStatus(idTable)) {
        cout << "Ban khong hop le hoac chua duoc dat." << endl;
        return; 
    }
    cout << "Nhap phuong thuc thanh toan : "; getline(cin, paymentMethod);
    cout << "Nhap VAT (neu co): "; cin >> VAT;
    cout << "Nhap giam gia (neu co): "; cin >> Discount;
    cin.ignore();
    cout << "Nhap phan hoi cua khach hang: "; getline(cin, comment);
    cout << "Nhap danh gia : "; cin >> Rating;cin.ignore();
}
void PAF::outPut() {
	cout << "Ban so : " << idTable << endl;
   	cout << "Phuong thuc thanh toan : " << paymentMethod << endl;
    cout << "VAT : " << VAT << " VND" << endl;
    cout << "Giam gia : " << Discount << " VND" << endl;
    cout << "Phan hoi : " << comment << endl;
    cout << "Danh gia : " << Rating << endl;
    cout << "Ban da thanh toan thanh cong." << endl; 
}
void PAF::readFile() {
    ifstream fin("FeedbackData.txt");
    if (!fin.is_open()) {
        cout << "Loi khi mo file de doc." << endl;
        return;
    }
    int id, rating;
    double vat, discount;
    string method, cmt;
    while (fin >> id >> method >> vat >> discount >> cmt >> rating) {
        cout << id << " " << method << " " << vat << " " << discount << " " << cmt << " " << rating << endl; 
    }
    fin.close();
} 
void PAF::writeFile() {
    ofstream fout("FeedbackData.txt", ios::app);
    if (!fout.is_open()) {
        cout << "Loi khi mo file de ghi." << endl;
        return;
    }
    fout << idTable << " " << paymentMethod << " " << VAT << " " << Discount << " " << comment << " " << Rating << endl;
    fout.close();
    cout << "Da luu vao file." << endl;
}
void PAF::deleteFile() {
    ofstream fout("FeedbackData.txt", ios::trunc);
    if (!fout.is_open()) {
        cout << "Loi khi mo file de xoa." << endl;
        return;
    }
    fout.close();
    cout << "Da xoa file feedback." << endl;
}
void PAF::PMenu() {
	int choice; 
	do {
		cout << "--------------------------------------------------------------------------------------------------------" << endl; 
		cout << "MENU THANH TOAN VA PHAN HOI" << endl;
		cout << "1.Hoa don." << endl; 
		cout << "2.Thanh toan." << endl;
		cout << "3.Lich su." << endl;
		cout << "4.Xoa du lieu." << endl; 
		cout << "5.Thoat" << endl;
		cout << "Chon chuc nang : "; cin >> choice; cin.ignore();
		switch(choice) {
			case 1 : showOrder(); break; 
			case 2 : inPut(); outPut(); writeFile(); break; 
			case 3 : readFile(); break; 
			case 4 : deleteFile(); break; 
			case 5 : cout << "Thoat chuong trinh thanh toan va phan hoi." << endl; break; 
			default : cout << "Vui long chon chuc nang hop le." << endl; 
		} 
	} while(choice != 5); 
} 
//MAIN************************************************************************************
int main() {
	Menu mn;
	CManager cm;
	SManager sm;
	tableOrder to; 
	Order o; 
	PAF p; 
	int choice;
	do {
		cout << "CHUC NANG" << endl;
		cout << "1.Quan ly nhan vien." << endl;
		cout << "2.Quan ly khach hang." << endl;
		cout << "3.Quan ly menu." << endl;
		cout << "4.Quan ly ban." << endl; 
		cout << "5.Quan ly dat mon." << endl; 
		cout << "6.Quan ly thanh toan va phan hoi." << endl;
		cout << "7.Thoat." << endl; 
		cout << "Chon chuc nang : "; cin >> choice; cin.ignore(); 
		switch(choice) {
			case 1 : sm.SMenu(); break; 
			case 2 : cm.CMenu(); break; 
			case 3 : mn.MMenu(); break;
			case 4 : to.TMenu(); break; 
			case 5 : o.OMenu(); break; 
			case 6 : p.PMenu(); break; 
			case 7 : cout << "Thoat QUAN LY." << endl; break; 
			default : cout << "Vui long chon chuc nang hop le." << endl; 
			} 
		} while(choice != 7); 
	return 0; 
}
