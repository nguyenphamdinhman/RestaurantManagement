class PAF {
	private : 
		string comment,paymentMethod;
		double VAT,Discount;
		int Rating,idTable; 
	public:
	    PAF();                        
	    int getIdTable();
	    void setIdTable(int idTable);
	    string getPaymentMethod();
	    void setPaymentMethod(string paymentMethod);
	    string getComment();
	    void setComment(string comment);
	    double getVAT();
	    void setVAT(double VAT);
	    double getDiscount();
	    void setDiscount(double Discount);
	    int getRating();
	    void setRating(int Rating);
	    void showOrder();
	    void inPut();           
	    void outPut();  
	    void readFile();
		void writeFile();
		void deleteFile(); 
		void PMenu(); 
};
PAF::PAF() {
	comment = "";  paymentMethod = "";
	Rating = 0; VAT = 0.0; Discount = 0.0; 
}
int PAF::getIdTable() {
	return idTable; 
}
void PAF::setIdTable(int idTable) {
	this->idTable = idTable; 
}
string PAF::getPaymentMethod() {
 	return paymentMethod; 
}
void PAF::setPaymentMethod(string paymentMethod) { 
	this->paymentMethod = paymentMethod; 
}
string PAF::getComment() {
 	return comment; 
}
void PAF::setComment(string comment) { 
	this->comment = comment; 
}
double PAF::getVAT() { 
	return VAT; 
}
void PAF::setVAT(double VAT) { 
	this->VAT = VAT; 
}
double PAF::getDiscount() { 
	return Discount;
}
void PAF::setDiscount(double Discount) { 
	this->Discount = Discount; 
}
int PAF::getRating() { 
	return Rating; 	
}
void PAF::setRating(int Rating) { 
	this->Rating = Rating; 
}
void PAF::showOrder() {
	Order o;
	o.readFile();
}
void PAF::inPut() {
	tableOrder to;
	cout << "MENU THANH TOAN VA PHAN HOI" << endl; 
    cout << "Nhap ban so: "; cin >> idTable; cin.ignore();
    if (!to.isCheckStatus(idTable)) {
        cout << "Ban khong hop le hoac chua duoc dat." << endl;
        return; 
    }
    cout << "Nhap phuong thuc thanh toan : "; getline(cin, paymentMethod);
    cout << "Nhap VAT (neu co): "; cin >> VAT;
    cout << "Nhap giam gia (neu co): "; cin >> Discount;
    cin.ignore();
    cout << "Nhap phan hoi cua khach hang: "; getline(cin, comment);
    cout << "Nhap danh gia : "; cin >> Rating;cin.ignore();
}
void PAF::outPut() {
	cout << "Ban so : " << idTable << endl;
   	cout << "Phuong thuc thanh toan : " << paymentMethod << endl;
    cout << "VAT : " << VAT << " VND" << endl;
    cout << "Giam gia : " << Discount << " VND" << endl;
    cout << "Phan hoi : " << comment << endl;
    cout << "Danh gia : " << Rating << endl;
    cout << "Ban da thanh toan thanh cong." << endl; 
}
void PAF::readFile() {
    ifstream fin("FeedbackData.txt");
    if (!fin.is_open()) {
        cout << "Loi khi mo file de doc." << endl;
        return;
    }
    int id, rating;
    double vat, discount;
    string method, cmt;
    while (fin >> id >> method >> vat >> discount >> cmt >> rating) {
        cout << id << " " << method << " " << vat << " " << discount << " " << cmt << " " << rating << endl; 
    }
    fin.close();
} 
void PAF::writeFile() {
    ofstream fout("FeedbackData.txt", ios::app);
    if (!fout.is_open()) {
        cout << "Loi khi mo file de ghi." << endl;
        return;
    }
    fout << idTable << " " << paymentMethod << " " << VAT << " " << Discount << " " << comment << " " << Rating << endl;
    fout.close();
    cout << "Da luu vao file." << endl;
}
void PAF::deleteFile() {
    ofstream fout("FeedbackData.txt", ios::trunc);
    if (!fout.is_open()) {
        cout << "Loi khi mo file de xoa." << endl;
        return;
    }
    fout.close();
    cout << "Da xoa file feedback." << endl;
}
void PAF::PMenu() {
	int choice; 
	do {
		cout << "--------------------------------------------------------------------------------------------------------" << endl; 
		cout << "MENU THANH TOAN VA PHAN HOI" << endl;
		cout << "1.Hoa don." << endl; 
		cout << "2.Thanh toan." << endl;
		cout << "3.Lich su." << endl;
		cout << "4.Xoa du lieu." << endl; 
		cout << "5.Thoat" << endl;
		cout << "Chon chuc nang : "; cin >> choice; cin.ignore();
		switch(choice) {
			case 1 : showOrder(); break; 
			case 2 : inPut(); outPut(); writeFile(); break; 
			case 3 : readFile(); break; 
			case 4 : deleteFile(); break; 
			case 5 : cout << "Thoat chuong trinh thanh toan va phan hoi." << endl; break; 
			default : cout << "Vui long chon chuc nang hop le." << endl; 
		} 
	} while(choice != 5); 
} 
