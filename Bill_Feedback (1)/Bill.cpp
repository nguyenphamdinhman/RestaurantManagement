#include "Bill.hpp"
#include <iostream>
using namespace std;

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
	    double getTotal();
		void setTotal(double Total); 
	    FB getFeedBack();
 	   	void setFeedBack(FB fb);
};

Bill::Bill() {
	billID = "-----"; paymentMethod = "NONE";
	VAT = 0; Discount = 0;  
}
double Bill::getTotal() {
	return Total; 
}
void Bill::setTotal(double Total) {
	this->Total = Total; 
}
FB Bill::getFeedBack() {
	return fb;
}
void Bill::setFeedBack(FB fb) {
	this->fb = fb;
}
void Bill::inPut() {
	cout << "|------------------------------------------------------|" << endl;
	cout << "Nhap ma hoa don : "; getline(cin,billID);
    cout << "Nhap phuong thuc thanh toan : "; getline(cin,paymentMethod);
    cout << "Nhap phi VAT : "; cin >> VAT;
    cout << "Nhap giam gia : "; cin >> Discount; cin.ignore();
    cout << "Nhap thoi gian xuat hoa don : " << endl;
	inputTime(timeBill);
	cout << "Nhap danh gia khach hang : " << endl;
    fb.inPut();
}
void Bill::outPut() {
	cout << "|------------------------------------------------------|" << endl;
    cout << "Ma hoa don : " << billID << endl;
    cout << "Phuong thuc thanh toan : " << paymentMethod << endl;
    cout << "VAT : " << VAT * 100 << "%" << endl;
    cout << "Giam gia : " << Discount * 100 << "%" << endl;
    cout << "Tong bill : " << addUp() << " VND" << endl;
    cout << "Thoi gian xuat hoa don : "; outputTime(timeBill); cout << endl;
  	cout << "|-------------------------FEEDBACK-------------------------|" << endl; 
    fb.outPut();
}
double Bill::addUp() {
	double base = Order::addUp();
    Total = base * (1 + VAT) * (1 - Discount); 
    return Total;
} 

