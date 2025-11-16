#include<iostream>
#include<string>
#include<iomanip> 
#include<fstream> 
#define MAX_TABLE 50 
#define MAX_DISH 100 
using namespace std;

// TIME************************************************************************** 

struct Time {
	int hour,minute,second; 
}; 
void inputTime(Time &t) { 
    cout << "Nhap gio : "; cin >> t.hour;
    cout << "Nhap phut : "; cin >> t.minute;
    cout << "Nhap giay : "; cin >> t.second;
    cin.ignore(); 
}
void outputTime(const Time &t) {
    cout << setfill('0') << setw(2) << t.hour << ":"
         << setw(2) << t.minute << ":"
         << setw(2) << t.second;
}

// DATE**************************************************************************
 
struct Date {
	int day,month,year; 
}; 
void inputDate(Date &d) { 
    cout << "Nhap ngay : "; cin >> d.day;
    cout << "Nhap thang : "; cin >> d.month;
    cout << "Nhap nam : "; cin >> d.year;
    cin.ignore(); 
}
void outputDate(const Date &d) {
    cout << setfill('0') << setw(2) << d.day << "/"
         << setw(2) << d.month << "/"
         << setw(2) << d.year;
}

//*******************************************************************************

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
	cout << "-----------------------------------------------------------" << endl;	
	cout << "HO VA TEN : " << Name << endl;
	cout << "NGAY SINH : " << birthDate << endl;
	cout << "GIOI TINH : " << Gender << endl;
	cout << "DIA CHI : " << Address << endl; 
	cout << "SO DIEN THOAI : " << Phone << endl; 
}

//*****************************************************************************************

class Customer: public Person {
	private : 
	    string customerID,email;  
	    bool emailCheck; 
	public :
	 	Customer(); 
	 	void inPut();
		void outPut();
		string getCustomerID();
		void setCustomerID(string customerID);
		string getEmail();
		void setEmail(string email);
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
void Customer::inPut() {
	Person::inPut();
	cout << "Nhap ID khach hang : "; getline(cin,customerID);
	cout <<	"Nhap email khach hang :"; getline(cin,email);
	if(email.empty()) {
		emailCheck = false; 
		email = "X"; 
	} else {
		emailCheck = true; 
	} 
}
void Customer::outPut() {
	Person::outPut();
	cout << "ID khach hang : " << customerID << endl; 
	if(emailCheck) {
		cout << "Email : " << email << endl; 
	} else {
		cout << "Email : X " << endl; 
	} 
}

//*****************************************************************************************

class Dish {
	private : 
	    string dishID,Name,Type;
		int Price,Quantity; 
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
		int getQuantity(); 
		void setQuantity(int Quantity);
		void inPut();
		void outPut();
		void writeFile(ofstream &f);
		bool readFile(ifstream &f);
};
Dish::Dish() {
	dishID = "", Name = "" , Type = ""; 
	Price = 0; Quantity = 0; 
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
int Dish::getQuantity() {
	return Quantity; 
}
void Dish::setQuantity(int Quantity) {
	this->Quantity = Quantity; 
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

//*****************************************************************************************

class Menu {
	private : 
	    Dish dishes[MAX_DISH];
	    int Quantity; 
	public : 
		Menu(); 
		Dish& getDish(int index);
		int getQuantity();
		void displayMenu(); 
		void addDish();
		void searchDish();
		void deleteDish(); 
		void updateDish(); 
		void sortDish(); 
		int findName(const string &name);
		void writeFile();
		void readFile(); 
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
Dish& Menu::getDish(int index) {
    return dishes[index];
}
int Menu::getQuantity() {
	return Quantity; 
}
void Menu::displayMenu() {
    cout << "---------------------------MENU--------------------------------" << endl;
    cout << setw(10) << "ID" << setw(30) << "MON AN" << setw(20) << "LOAI MON" << setw(15) << "GIA" << endl;
    for(int i = 0; i < Quantity; i++) {
        dishes[i].outPut();
    }
    cout << "-----------------------------------------------------------" << endl;
}
void Menu::addDish() {
	if(Quantity >= MAX_DISH) {
		cout << "Dat gioi han." << endl;
		return; 
	} 
	cout << "-----------------------------------------------------------" << endl;
	int count; cout << "Nhap so luong mon an muon them : "; cin >> count; cin.ignore();
	cout << endl;
		for(int i = 0; i < count; i++) {
			cout << "-----------------------------------------------------------" << endl;
			dishes[Quantity].inPut();
			Quantity++; 
	}
	cout << "Them mon thanh cong" << endl; 
}
void Menu::deleteDish() {
	cout << "-----------------------------------------------------------" << endl;
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
	cout << "-----------------------------------------------------------" << endl;
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
	cout << "-----------------------------------------------------------" << endl;
	for(int i = 0; i < Quantity; i++) {
		for(int j = i + 1; j < Quantity; j++) {
			int typeI = typeOrder(dishes[i].getType());
            int typeJ = typeOrder(dishes[j].getType());
                if(typeI > typeJ || (typeI == typeJ && dishes[i].getName() > dishes[j].getName())) {
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
int Menu::findName(const string &name) {
 	for (int i = 0; i < Quantity; i++) {
        if (dishes[i].getName() == name) return i;
    }
    return -1; 
}
void Menu::writeFile() {
	ofstream f("MenuData.txt");
		if(!f.is_open()) {
			cout << "Khong mo duoc file de ghi." << endl;
			return; 
		} 
	f << Quantity << endl; 
	for(int i = 0; i < Quantity ; i++) {
		dishes[i].writeFile(f);
	}
	f.close();
	cout << "Da luu menu vao file Dish.txt ." << endl; 
}	
void Menu::readFile() {
	ifstream f("MenuData.txt");
		if(!f.is_open()) {
			cout << "Khong mo duoc file de ghi." << endl;
			return; 
		} 
	f >> Quantity; f.ignore();
	for(int i = 0; i < Quantity; i++) {
		dishes[i].readFile(f);
	}
	f.close();
	cout << "Da doc menu tu file Dish.txt ." << endl; 
}

//*****************************************************************************************

class Table {
	private : 
	    string tableStatus;
		int numberCustomer,tableID; 
	public : 
		Table(); 
		Table& getTable(int index);
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

//*****************************************************************************************

class tableOrder {
	private : 
		Table tables[MAX_TABLE];
		int numberTable; 
	public :
		Table& getTable(int index);
		int getNumberTable();
		void setNumberTable(int numberTable); 
		void initTable();
		void tableList();
		void bookTable(int id,int customer);
		void freeTable(int id); 
		void writeFile();
		void readFile(); 
}; 
Table& tableOrder::getTable(int index) {
	return tables[index];
}
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

//*****************************************************************************************

class Order {
	private : 
	 	string orderID,dishStatus; 
	 	int Quantity; 
	 	Customer cus;
		Table tab; 
	    Dish dishes[MAX_DISH];
	    double Total; 
	public : 
	    Order(); 
	    void inPut(Menu &mn, tableOrder &to);
		void outPut();
		string getOrderID();
  		void setOrderID(string orderID);
  		string getDishStatus();
  		void setDishStatus(string dishStatus);
  		void writeFile(); 
		double addUp(); 
}; 
Order::Order() {
	dishStatus = "DANG LAM"; orderID = ""; 
	Quantity = 0;Total = 0; 
} 
string Order::getOrderID() {
	return orderID; 
}
void Order::setOrderID(string orderID) {
	this->orderID = orderID; 
}
string Order::getDishStatus() {
	return dishStatus; 
}
void Order::setDishStatus(string dishStatus) {
    this->dishStatus = dishStatus;
}
void Order::inPut(Menu &mn, tableOrder &to) {
    cout << "|------------------------------------------------------|" << endl;
    cout << "Nhap ma don hang : "; getline(cin, orderID);
    cout << "Nhap thong tin khach hang : " << endl; cus.inPut();
    int tableNumber; 
    cout << "Nhap ban so : " << endl; cin >> tableNumber; cin.ignore();
    	if (tableNumber < 1 || tableNumber > to.getNumberTable()) {
        cout << "Ban khong hop le." << endl;
		return; 	
    }
    tab = to.getTable(tableNumber - 1);
    mn.displayMenu();
    int count; cout << "Nhap so luong mon muon goi: "; cin >> count; cin.ignore();
    Quantity = 0; Total = 0;
    for (int i = 0; i < count; i++) {
        string dishName; int quantity;
        cout << "Nhap ten mon thu " << i + 1 << ": "; getline(cin, dishName);
        int index = mn.findName(dishName);
        	if (index == -1) {
            cout << "Khong tim thay mon " << dishName << endl;
			continue;
		}
        cout << "Nhap so luong: "; cin >> quantity; cin.ignore();
        dishes[Quantity] = mn.getDish(index);
		dishes[Quantity].setQuantity(quantity);  
		Quantity++;
    }
    Total = addUp();
    cout << "Tong tien : " << Total << " VND" << endl; 
}

void Order::outPut() {
	cout << "|------------------------------------------------------|" << endl;
    cout << "Ma don hang: " << orderID << endl;
    cus.outPut();
    tab.outPut();
    cout << "Trang thai mon : " << dishStatus << endl;
    for (int i = 0; i < Quantity; i++) {
        cout << "|------------------------------------------------------|" << endl;
        dishes[i].outPut();
    }
    cout << "|------------------------------------------------------|" << endl;
    cout << "Tong tien: " << addUp() << " VND" << endl;
}
void Order::writeFile() {
    ofstream f("OrderData.txt", ios::app);
    if (!f.is_open()) { cout << "Khong mo duoc OrderData.txt de ghi.\n"; return; }
    f << orderID << "|" << tab.getTableID() << "|" << addUp() << "|" << dishStatus << endl;
    f.close();
    cout << "Da luu don hang vao OrderData.txt" << endl;
}
double Order::addUp() {
    double sum = 0;
    for (int i = 0; i < Quantity; i++) {
        sum += dishes[i].getPrice() * dishes[i].getQuantity();
    }
    return sum;
}

//************************************************************************************************

class FB {
	private : 
		string Comment;
	    double Rating; 
	    Time feedBackTime; 
	public : 
	    FB();
		string getComment();
		void setComment(string Comment);
		double getRating();
		void setRating(double Rating); 
		void inPut();
		void outPut(); 	
		void writeFile(ofstream &f);
		bool readFile(ifstream &f);
}; 
FB::FB() {
	Comment = "", Rating = 0;
	feedBackTime = {0,0,0}; 
} 
string FB::getComment() {
	return Comment; 
}
void FB::setComment(string Comment) {
	this->Comment = Comment; 
}
double FB::getRating() {
	return Rating; 
}
void FB::setRating(double Rating) {
	this->Rating = Rating; 
}
void FB::inPut() {
	cout << "Nhap phan hoi : "; getline(cin,Comment);
	cout << "Nhap sao danh gia : "; cin >> Rating; cin.ignore(); 
	cout << "Nhap thoi gian phan hoi : "; inputTime(feedBackTime);
}
void FB::outPut() {
	cout << "Phan hoi : '" << Comment << "'" << endl;
	cout << "Danh gia : " << Rating << "sao" << endl; 
	cout << "Thoi gian phan hoi : ";  outputTime(feedBackTime); cout << endl;  
} 
//****************************************************************************
	
class Bill : public Order {
	private : 	
		string billID,paymentMethod;
		double VAT,Discount,Total;     
	   	FB fb; 
	   	Time timeBill; 
	public :
		Bill(); 	
		void inPut();
		void outPut();
	    double addUp(); 
};
Bill::Bill() {
	billID = "";paymentMethod = "";
	VAT = 0;Discount = 0;Total = 0; 
	timeBill = {0,0,0}; 
} 
void Bill::inPut() {
	cout << "-------------------------------- TAO HOA DON-----------------------------------" << endl;
	cout << "Nhap ID hoa don : "; getline(cin,billID);
	cout << "Danh sach mon da goi : "<< endl;
		Menu mn; tableOrder to;
	    mn.readFile(); to.readFile();
	    Order::inPut(mn, to);  
	cout << "Chon phuong thuc thanh toan : "; getline(cin,paymentMethod);
	cout << "Nhap phi VAT (%) : "; cin >> VAT;  
	cout << "Nhap giam gia (%) : "; cin >> Discount;
	cout << "Nhap thoi gian xuat hoa don : "; inputTime(timeBill);
		Total = Order::addUp() * (1 + VAT - Discount);
	cout << "Vui long de lai phan hoi cho quan : " << endl;
		fb.inPut();
} 
void Bill::outPut() {
	cout << "|------------------------------------------------------|" << endl;
		cout << "Ma hoa don: " << billID << endl;
	    cout << "Thoi gian: "; outputTime(timeBill); cout << endl;
	    cout << "Danh sach mon da goi : "<< endl;
	    Order::outPut();
        cout << "VAT : " << VAT	<< "%" << endl;
        cout << "Giam gia: " << Discount << "%" << endl;
        cout << "|------------------------------------------------------|" << endl;
        cout << "Tong cong : " << Total << endl; 
        cout << "Tong tien : " << fixed << setprecision(0) << Total << " VND\n";
        cout << "Phuong thuc thanh toan: " << paymentMethod << endl;
}
int main() {
	Menu mn; mn.readFile();
    tableOrder to; to.readFile();

    int choice,id,customer;
    do {
         cout << "|-------------------------DAT BAN VA MON-----------------------------|" << endl;
        cout << "1.Hien thi MENU." << endl;
        cout << "2.Hien thi danh sach ban." << endl;
        cout << "3.Dat ban." << endl;
        cout << "4.Giai phong ban."<< endl;
        cout << "5.Goi mon." << endl;
        cout << "6.Lich su goi mon." << endl;
        cout << "7.Xuat hoa don." << endl; 
        cout << "8.Thoat." << endl;
        cout << "Chon chuc nang : "; cin >> choice; cin.ignore(); 

        switch(choice) {
            case 1: mn.displayMenu(); break;
            case 2: to.tableList(); break;
            case 3: 
				cout << "So ban: "; cin >> id;
   				cout << "So khach: "; cin >> customer;
				to.bookTable(id,customer);
				break;
            case 4: 
            	cout << "Chon ban muon giai phong : "; cin >> id; 
				to.freeTable(id); 
				break;
            case 5: { 
				Order o; 
				o.inPut(mn,to);
				o.writeFile();
				break; }
            case 6: {
                ifstream f("OrderData.txt");
                string line;
                while(getline(f, line)) cout << line << endl;
                break;
            }
            case 7: {
			    Bill b;
			    b.inPut();
			    b.outPut();
			    break;
			}
            case 8: cout << "Cam on quy khach! " << endl; break;
            default: cout << "Lua chon khong hop le." << endl; break;
        }
    } while(choice != 7);

    to.readFile(); 
    return 0;
} 
