#include<iostream>
#include<fstream>
#include"../Include/Person.hpp"
using namespace std;

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
int main() {
	{ 
	int ps; cout << "Nhap so nguoi : "; cin >> ps; cin.ignore(); 
	Person *persons = new Person[ps];
	
	ofstream fout("Person.txt"); 
	if(!fout.is_open()) { 
	  	cout << "Khong mo duoc file de ghi." << endl;
	   	return 1; 
	} 
	for(int i = 0; i < nv; i++) { 
		cout << "-----------------------------------------------------------" << endl;
		persons[i].inPut(); 
		persons[i].writeFile(fout); 
		cout << "Ghi file thanh cong!" << endl; 
	}
	fout.close();
	
	ifstream fin("Person.txt"); 
		if(!fin.is_open()) { 
		   cout << "Khong mo duoc file de doc." << endl; 
		   return 1;
		} 
		   Person p; 
		   while(p.readFile(fin)) {
				p.outPut();
		    }
		  		fin.close(); 
	delete[] persons; 
	}	
} 
