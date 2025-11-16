#include<iostream>
#include<string>
#include<iomanip> 
#include<fstream> 
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
