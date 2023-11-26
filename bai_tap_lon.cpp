#include<bits/stdc++.h>
using namespace std;

class Book {
private:
    string masach;
    string tensach;
    string tentacgia;
    int namxuatban;
    double giasach;

public:

    Book(string masach = "", string tensach = "", string tentacgia = "", int namxuatban = 0, double giasach = 0)
        : masach(masach), tensach(tensach), tentacgia(tentacgia), namxuatban(namxuatban), giasach(giasach) {}
      
    bool operator<(const Book &x) const{
	    return giasach<x.giasach;
    }
    
     bool operator>(const Book &x) const{
	    return giasach>x.giasach;
    }
    
    friend ostream& operator<<(ostream& cout, const Book& book){
    	cout<<setw(15)<<book.masach<<setw(20)<<book.tensach<<setw(20)<<book.tentacgia<<setw(15)<<book.namxuatban<<setw(20)<<book.giasach<<"$";
    	return cout;
	}
	
	friend istream & operator>>(istream &cin, Book &book){
	    cout << "Nhap ma so sach: ";
	    cin.ignore();
	    getline(cin, book.masach);
	   	
	    cout << "Nhap ten sach: ";
	    getline(cin, book.tensach);
	    cout << "Nhap ten tac gia: ";
	    getline(cin, book.tentacgia);
	    cout << "Nhap nam xuat ban: ";
	    cin >> book.namxuatban;
	    cout << "Nhap gia sach: ";
	    cin >> book.giasach;
	    return cin;
	}

	friend class ungdung;
};
class ungdung{
	private:
		vector<Book> danhsachBook;
	public:
		void themBook();
	    void xoaBook();
	    void editBook();
	    void timkiemtheotacgia();
	    void searchBook();
	    void hienthisach();
	    void sapxeptheogia();
	    void max_giasach();
	    void min_giasach();
	    void docfile();
	    void ghifile(Book c);
	    void xoahet();
		
};

void ungdung::themBook() {
    Book c;
    cin>>c;
    danhsachBook.push_back(c);
    cout<<"Ban da them sach thanh cong.\n";
}

void ungdung::hienthisach() {
	cout<<setw(70)<<"DANH SACH THONG TIN CAC CUON SACH\n";
    cout << "+---------------------------------------------------------------------------------------------------+\n";
    cout<<setw(15)<<" ma sach "<<setw(20)<<" ten sach "<<setw(20)<<" ten tac gia "<<setw(20)<<" nam xuat ban "<<setw(20)<<" gia sach ";
    cout << "\n+---------------------------------------------------------------------------------------------------+\n";
    for(auto &book:danhsachBook){
    	cout<<book<<endl;
    	 cout << "\n+---------------------------------------------------------------------------------------------------+\n";
	}	
}

void ungdung::xoaBook(){
	cout<<"Nhap ten sach can xoa: ";
	string _tensach;
	cin.ignore(); getline(cin,_tensach);
	for(int i=0;i< danhsachBook.size();i++){
		if(danhsachBook[i].tensach==_tensach){
			danhsachBook.erase(danhsachBook.begin()+i);
		}
	}
}

void ungdung::searchBook(){
	cout<<"Nhap ma sach can tim : ";
	string _masach;
	cin.ignore();
	getline(cin,_masach);
	int dem=0;
	
	for(auto &book :danhsachBook){
		if(book.masach==_masach){
			dem++;
			
		}
	}
	if(dem==0) cout<<"\nThong bao: Khong co thong tin sach do.\n";
	else {
		
		cout<<setw(70)<<"Thong tin sach can tim la: \n";
		cout << "+---------------------------------------------------------------------------------------------------+\n";
	    cout<<setw(15)<<" ma sach "<<setw(20)<<" ten sach "<<setw(20)<<" ten tac gia "<<setw(20)<<" nam xuat ban "<<setw(20)<<" gia sach ";
	    cout << "\n+---------------------------------------------------------------------------------------------------+\n";
		for(auto book :danhsachBook){
			if(book.masach==_masach){
				cout<<book;
				cout << "\n+---------------------------------------------------------------------------------------------------+\n\n";
				break;
			}
		}
	}
}

void ungdung::docfile() {
	Book a;
    ifstream infile;
    infile.open("bai_tap_lon_1.txt");
    string _masach, _tentacgia, _tensach;
    int _namxuatban;
    double _giasach;
    char c;
    while(!infile.eof()){
    	getline(infile,_masach);
    	getline(infile,_tentacgia);
    	getline(infile,_tensach);
		infile>>_namxuatban;
		infile.get(c);
		infile>>_giasach;
		infile.get(c); 
     	danhsachBook.push_back(Book(_masach, _tensach, _tentacgia, _namxuatban, _giasach));  
		if(infile.eof()) break; 	
	}

    infile.close();
}

void ungdung::ghifile(Book c){
	ofstream outfile;
	outfile.open("bai_tap_lon_1.txt",ios::app);
	
}
void ungdung::sapxeptheogia(){
	sort(danhsachBook.begin(),danhsachBook.end());
}

void ungdung::max_giasach(){
	Book max=danhsachBook.front();
	for(auto book:danhsachBook){
		if(book.giasach > max.giasach){
			max=book;
		}
	}
	cout<<"+---------------------------------Thong tin sach co gia lon nhat------------------------------------+"<<endl;
	cout << "\n+---------------------------------------------------------------------------------------------------+\n";
	cout<<setw(15)<<" ma sach "<<setw(20)<<" ten sach "<<setw(20)<<" ten tac gia "<<setw(20)<<" nam xuat ban "<<setw(20)<<" gia sach ";
	cout << "\n+---------------------------------------------------------------------------------------------------+\n";
	cout<<max;
	cout << "\n+---------------------------------------------------------------------------------------------------+\n";
}

void ungdung::min_giasach(){
	Book min=danhsachBook.front();
	for(auto book:danhsachBook){
		if(book.giasach < min.giasach){
			min=book;
		}
	}
	
	cout<<"+---------------------------------Thong tin sach co gia nho nhat------------------------------------+"<<endl;
	cout << "\n+---------------------------------------------------------------------------------------------------+\n";
	cout<<setw(15)<<" ma sach "<<setw(20)<<" ten sach "<<setw(20)<<" ten tac gia "<<setw(20)<<" nam xuat ban "<<setw(20)<<" gia sach ";
	cout << "\n+---------------------------------------------------------------------------------------------------+\n";
	cout<<min;
	cout << "\n+---------------------------------------------------------------------------------------------------+\n";
}

void ungdung::timkiemtheotacgia(){
	cout<<"Nhap ten tac gia can tim: ";
	string tentg;
	cin.ignore();
	auto dem=0;
	getline(cin,tentg);
	for(auto book:danhsachBook){
		if(book.tentacgia==tentg){
			dem=1;
		}
	}
	if(dem==0) cout<<"\nKhong co sach cua tac gia : "<<tentg<<endl;
	else if(dem==1){
		cout<<"\n"<<setw(60)<<"Thong tin sach cua tac gia "<<tentg<<endl;
		cout << "\n+---------------------------------------------------------------------------------------------------+\n";
		cout<<setw(15)<<" ma sach "<<setw(20)<<" ten sach "<<setw(20)<<" ten tac gia "<<setw(20)<<" nam xuat ban "<<setw(20)<<" gia sach ";
		cout << "\n+---------------------------------------------------------------------------------------------------+\n";
		for(auto book:danhsachBook){
			if(book.tentacgia==tentg){
				cout<<book;
				cout << "\n+---------------------------------------------------------------------------------------------------+\n";
			}
		}
		
	}
}

void ungdung::editBook(){
	string _masach,_tensach,_tentacgia;
	int _namxuatban;
	double _giasach;
	cout<<"Nhap ma sach de thay doi thong tin: ";cin.ignore(); getline(cin,_masach);
	for(auto it=danhsachBook.begin();it!=danhsachBook.end();it++){
		if(it->masach == _masach){
			cout<<"Nhap ten sach: ";getline(cin,_tensach);
			cout<<"Nhap ten tac gia: ";getline(cin,_tentacgia);
			cout<<"Nhap nam xuat ban: ";cin>>_namxuatban;
			cout<<"Nhap gia tien sach: ";cin>>_giasach;
			it->tensach=_tensach;
			it->tentacgia=_tentacgia;
			it->namxuatban=_namxuatban;
			it->giasach=_giasach;
			cout<<"\nDa cap nhat thanh cong.\n";
			return;
		}
		
	}
	cout<<"\nKhong co ma sach thoa man.Vui long nhap lai.\n\n";	
}

void ungdung::xoahet(){
	danhsachBook.clear();
}
class app{
	private:
		ungdung a;
	public:
		void menu(){
			a.docfile();
			while(1){
				cout<<"+________________________MENU________________________+\n";
				cout<<"1.Them thong tin Book can thiet.\n";
				cout<<"2.In ra man hinh danh sach Book.\n";
				cout<<"3.Tim kiem Book bat ki theo ma sach.\n";
				cout<<"4.Sap xep danh sach Book theo gia (nho->lon).\n";
				cout<<"5.Tim sach co gia lon nhat.\n";
				cout<<"6.Tim sach co gia thap nhat.\n";
				cout<<"7.Xoa thong tin Book theo ten sach.\n";
				cout<<"8.Liet ke cac cuon sach theo tac gia.\n";
				cout<<"9.Xoa het danh sach Book.\n";
				cout<<"10.Cap nhat lai thong tin sach theo ma sach.\n ";
				cout<<"0.Thoat!\n";
				cout<<"+_____________________________________________________+\n";
				cout<<"\nNhap lua chon : ";
				int lc;cin>>lc;
				switch(lc){
					case 1:
						system("cls");
						a.themBook();
						break;
					case 2:
						system("cls");
						a.hienthisach();
						break;
					case 3:
						system("cls");
						a.searchBook();
						break;
					case 4:
						system("cls");
						a.sapxeptheogia();
						break;
					case 5:
						system("cls");
						a.max_giasach();
						break;
					case 6:
						system("cls");
						a.min_giasach();
						break;
					case 7:
						system("cls");
						a.xoaBook();
						break;
					case 8:
						system("cls");
						a.timkiemtheotacgia();
						break;
					case 9:
						system("cls");
						a.xoahet();
						break;
					case 10:
						system("cls");
						a.editBook();
						break;
					default:
						return ;
			}
		}
    }   
};
int main() {
     app x;
     x.menu();
     return 0;
}
