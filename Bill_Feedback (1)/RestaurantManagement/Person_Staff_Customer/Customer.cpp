#include <iostream>
using namespace std;
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
int main() {

	{
 	int kh; cout << "Nhap so khach hang : "; cin >> kh; cin.ignore();
	Customer *customers = new Customer[kh];
	
	ofstream fout("Customer.txt");
	if(!fout.is_open()) {
		cout << "Khong mo duoc file de ghi." << endl;
		return 1; 
	} 
	for(int i = 0; i < kh; i++) {
		cout << "-----------------------------------------------------------" << endl;	
		customers[i].inPut();
		customers[i].writeFile(fout); 
		cout << "Ghi file thanh cong!" << endl; 
	} 
	fout.close();
	
	ifstream fin("Customer.txt");
	if(!fin.is_open()) {
		cout << "Khong mo duoc file de doc." << endl;
		return 1; 
	} 
	Customer c; 
	while(c.readFile(fin)) {
		c.outPut(); 
	} 
	fin.close();
	delete[] customers;
	}
}
