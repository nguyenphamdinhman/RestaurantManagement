#include "Feedback.hpp"
#include <iostream>
using namespace std;
class FB : public Customer {
	private : 
		string Comment,feedBackID;
	    int Rating; 
	    Time feedBackTime; 
	public : 
	    FB();
	    void inPut();
		void outPut(); 
		string getComment();
		void setComment(string Comment);
		string getFeedBackID();
		void setFeedBackID(string feedBackID);
		int getRating();
		void setRating(int Rating); 	
}; 
FB::FB() {
	Comment = "-----"; feedBackID = "NONE";
	Rating = 0; Time = {0,0,0}; 
}
string FB::getComment() {
	return Comment; 
}
void FB::setComment(string Comment) {
	this->Comment = Comment; 
}
int FB::getRating() {
	return Rating; 
}
void FB::setRating(int Rating) {
	this->Rating = Rating; 
}
void FB::inPut() {
    cout << "Nhap noi dung feedback : "; getline(cin,Comment);
    cout << "Nhap danh gia (1-5 sao) : "; cin >> Rating;cin.ignore();
    cout << "Nhap thoi gian feedback : " << endl;
	inputTime(feedBackTime);
}
void FB::outPut() {
    cout << "Noi dung feedback : " << Comment << endl;
    cout << "Sao danh gia : " << Rating << "sao" << endl;
    cout << "Thoi gian feedback : "; outputTime(feedBackTime); cout << endl;
} 

