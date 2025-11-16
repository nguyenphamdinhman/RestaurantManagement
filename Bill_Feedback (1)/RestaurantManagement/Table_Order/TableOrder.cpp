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
