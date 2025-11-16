#include<iostream>
#include<fstream>
#include<iomanip> 
#include"../Include/Staff.hpp"
using namespace std; 

Staff::Staff() {
	Salary = 0; Hours = 0; Bonus = 0;Support = 0; 
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
void Staff::writeFile(ofstream &f) {
	Person::writeFile(f);
	f << staffID << endl;
	f << homeTown << endl; 
	f << Role << endl;
	f << Department << endl;
	f << startDate << endl;
	if (Role == "Quan ly" || Role == "Nhan vien") {
        f << Salary << endl;
        f << Bonus << endl;
    } 
    else if (Role == "Lam them") {
        f << Hours << endl;
        f << Support << endl;
    }
	f << payRoll() << endl;
}
bool Staff::readFile(ifstream &f) {
	if(!Person::readFile(f)) return false;
	getline(f,staffID);
	getline(f,homeTown); 
	getline(f,Role);
	getline(f,Department);
	getline(f,startDate);
	if (Role == "Quan ly" || Role == "Nhan vien") {
        f >> Salary;
        f >> Bonus;
        f.ignore();
        Hours = 0; Support = 0; 
    } else if (Role == "Lam them") {
        f >> Hours;
        f >> Support;
        f.ignore();
        Salary = 0; Bonus = 0;
	}
	double Income; f >> Income;
    f.ignore();
	return true; 
}
void Staff::inPut() {
	Person::inPut();
	cout << fixed << setprecision(2);
    cout << "Nhap ID nhan vien : "; getline(cin,staffID);
    cout << "Nhap que quan : "; getline(cin,homeTown);
	cout << "Nhap chuc vu (Quan ly / Nhan vien / Lam them) : "; getline(cin,Role);
	cout << "Nhap phong ban (Bep / Phuc vu / Thu ngan ) : "; getline(cin,Department); 
	cout << "Nhap ngay bat dau lam viec : "; getline(cin,startDate); 
	if (Role == "Quan ly" || Role == "Nhan vien") {
		cout << "Nhap luong co ban : "; cin >> Salary; 
        cout << "Nhap tien thuong: "; cin >> Bonus; 
        Hours = 0; Support = 0;
    } else if (Role == "Lam them") {
        cout << "Nhap so gio lam: "; cin >> Hours;
        cout << "Nhap tien phu cap (neu co): "; cin >> Support;
        Salary = 0; Bonus = 0;
    }
    cin.ignore(); 
}
double Staff::payRoll() {
	if(Role == "Quan ly") {
		return Salary + Bonus * 1.5;
	}
	else if(Role == "Nhan vien") {
		if(Department == "Bep") return Salary + Bonus;
		else if(Department == "Phuc vu" || Department == "Thu ngan") return Salary + Bonus * 0.5;
		else return Salary;
	}
	else if(Role == "Lam them") { 
		return 35000 * Hours + Support;
	}
	return 0; 
}
void Staff::outPut() {
	Person::outPut();
	cout << "ID : " << staffID << endl; 
	cout << "QUE QUAN : " << homeTown << endl; 
	cout << "CHUC VU : " << Role << endl;
	cout << "PHONG BAN : " << Department << endl; 
	cout << "NGAY BAT DAU : " << startDate << endl; 
	cout << "LUONG CO BAN: " << Salary << endl;
	cout << "THU NHAP : " << payRoll() << endl; 
	cout << "-----------------------------------------------------------" << endl;
}
int main() {
	    { 
		int nv; cout << "Nhap so nhan vien : "; cin >> nv; cin.ignore(); 
	 		Staff *staffs = new Staff[nv];
	  	
		ofstream fout("Staff.txt"); 
	  		if(!fout.is_open()) { 
	  			cout << "Khong mo duoc file de ghi." << endl;
	   			return 1;
			} 
	   		for(int i = 0; i < nv; i++) { 
	   			cout << "-----------------------------------------------------------" << endl;
					staffs[i].inPut(); 
		 			staffs[i].writeFile(fout); 
		 			cout << "Ghi file thanh cong!" << endl;
				}
					fout.close();
		ifstream fin("Staff.txt"); 
			if(!fin.is_open()) { 
		   		cout << "Khong mo duoc file de doc." << endl; 
		   		return 1; 
			} 
			    while(s.readFile(fin)) {
					s.outPut(); 
				}
		   	fin.close(); 
		delete[] staffs; 
	}	
}
