class Order {
	private : 
		Dish dishes[MAX_DISH];
		Table tab; 
	 	int Count; 
	    double Total; 
	    string nameOrder; 
	public:
	    Order();
	    int getCount();
	    void setCount(int Count);
	    double getTotal();
	    void setTotal(double Total);
	    void showMenu();
	    void inPut();
	    void outPut();
	    void writeFile();
	    void readFile();
	    void deleteFile();
	    void OMenu(); 
};
Order::Order() {
	Count = 0;Total = 0; 
} 
int Order::getCount() {
	return Count; 
}
void Order::setCount(int Count) {
	this->Count = Count; 
}
double Order::getTotal() {
	return Total; 
}
void Order::setTotal(double Total) {
	this->Total = Total; 
}
void Order::showMenu() {
	Menu mn; 
	mn.loadFile();
	mn.showMenu(); 
} 
void Order::inPut() {
	int idT; 
	tableOrder to; 
    cout << "Nhap ban so: "; cin >> idT; cin.ignore(); 
    if (!to.isCheckStatus(idT)) {
        cout << "Ban khong hop le." << endl;
        return;
    }
    tab = to.getTableId(idT);
    cout << "Nhap ten mon : "; getline(cin,nameOrder); 
    cout << "Nhap so luong : "; cin >> Count; cin.ignore(); 
    fstream fin("MenuData.txt");
	if(!fin.is_open()) {
		cout << "Loi khi mo file." << endl;
		return; 
	} 
	string idD, dish, type;
    double price = 0;Total = 0;
    bool found = false;
	while (getline(fin, idD)) {
        getline(fin, dish);
        getline(fin, type);
        fin >> price;
        fin.ignore();
        if (dish == nameOrder) {
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Khong tim thay mon nay." << endl;
        return;
    }
    Total = price * Count; 
    cout << "Tong tien : " << Total << " VND" << endl; 
}
void Order::outPut() {
    cout << "Ban so : " << tab.getTableID() << endl;
	cout << "Mon : " << nameOrder << endl;
	cout << "So luong : " << Count << endl; 
    cout << "Tong tien: " << Total << " VND" << endl;
}
void Order::readFile() {
	ifstream fin("OrderData.txt"); 
		if(!fin.is_open()) {
			cout << "Loi ghi mo file de doc." << endl;
			return; 
	} 
	int idT, count;
    string name;
    double total;
    while (fin >> idT >> name >> count >> total) {
        cout << idT << " " << name << " " << count << " " << total << " VND" << endl;
    }
    fin.close();
}
void Order::writeFile() {
    ofstream fout("OrderData.txt", ios::app);
    if (!fout.is_open()) {
        cout << "Loi khi mo file de ghi." << endl;
        return;
    }
	    fout << tab.getTableID() << " " << nameOrder << " " << Count << " " << Total << endl;
	    fout.close();
    cout << "Da luu vao file." << endl;
}
void Order::deleteFile() {
 	ofstream f("OrderData.txt", ios::trunc);
    if (!f.is_open()) {
        cout << "Loi khi mo file de xoa." << endl;
        return;
    }
    f.close();
    cout << "Da xoa toan bo don hang.\n";
} 
void Order::OMenu() {
	int choice; 
	do {
		cout << "MENU ORDER" << endl;
		cout << "1.Hien thi menu." << endl; 
		cout << "2.Goi mon." << endl;
		cout << "3.Lich su." << endl;
		cout << "4.Xoa du lieu." << endl; 
		cout << "5.Thoat" << endl;
		cout << "Chon chuc nang : "; cin >> choice; cin.ignore();
		switch(choice) {
			case 1 : showMenu(); break; 
			case 2 : inPut(); break; 
			case 3 : readFile(); break; 
			case 4 : deleteFile(); break; 
			case 5 : cout << "Thoat chuong trinh order." << endl; break; 
			default : cout << "Vui long chon chuc nang hop le." << endl; 
		} 
	} while(choice != 5); 
} 
