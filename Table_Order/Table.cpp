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
