#include<iostream>
#include<string>
#include<iomanip> 
#include<fstream> 
#define MAX_DISH 100 
using namespace std;

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

//*****************************************************************************************

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
