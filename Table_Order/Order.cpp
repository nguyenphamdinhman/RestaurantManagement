#include "Order.hpp"
#include <iostream>
using namespace std;
class Order {
	private : 
	 	string orderID,dishStatus; 
	 	int Quantity; 
	 	Customer cus;
		Table tab; 
	    Dish dishes[MAX_DISH];
	public : 
	    Order(); 
	    void inPut();
		void outPut();
		string getOrderID();
  		void setOrderID(string orderID);
		int getQuantity();
		void setQuantity(int Quantity);
		string getDishStatus();
  		void setDishStatus(string dishStatus);  
		double addUp(); 
}; 
Order::Order() {
	dishStatus = "NONE"; orderID = ""; 
	Quantity = 0; 
} 
string Order::getOrderID() {
	return orderID; 
}
void Order::setOrderID(string orderID) {
	this->orderID = orderID; 
}
int Order::getQuantity() {
	return Quantity; 
}
void Order::setQuantity(int Quantity) {
	this->Quantity = Quantity; 
}
string Order::getDishStatus() {
	return dishStatus; 
}
void Order::setDishStatus(string dishStatus) {
    this->dishStatus = dishStatus;
}
void Order::inPut() {
    cout << "|------------------------------------------------------|" << endl;
    cout << "Nhap ma don hang : "; getline(cin, orderID);
    cout << "Nhap thong tin khach hang : " << endl; cus.inPut();
    cout << "Nhap thong tin ban : " << endl; tab.inPut();
    cout << "Nhap so luong mon an: "; cin >> Quantity; cin.ignore();
    for (int i = 0; i < Quantity; i++) {
        cout << "|------------------------------------------------------|" << endl;
        dishes[i].inPut();
    }
    cout << "Nhap trang thai mon an : "; getline(cin, dishStatus);
}

void Order::outPut() {
	cout << "|------------------------------------------------------|" << endl;
    cout << "Ma don hang: " << orderID << endl;
    cus.outPut();
    tab.outPut();
    cout << "So luong mon an: " << Quantity << endl;
    for (int i = 0; i < Quantity; i++) {
        cout << "|------------------------------------------------------|" << endl;
        dishes[i].outPut();
    }
    cout << "Trang thai mon an: " << dishStatus << endl;
}
double Order::addUp() {
    double sum = 0;
    for (int i = 0; i < Quantity; i++) {
        sum += dishes[i].getPrice() * dishes[i].getQuantity();
    }
    return sum;
}

