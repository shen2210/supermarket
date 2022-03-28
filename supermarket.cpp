#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
int dem = 0;

struct THONG_TIN_SP {
	int id;
	string tenSP;
	int soluong;
	int giatien;
	string nsx;
	
	void nhapSP(){
		cout<<"Nhap ma san pham : "; cin >> id;
		cin.ignore();
		cout<<"Nhap ten san pham : "; getline(cin,tenSP);
		cout<<"Nhap so luong : "; cin >> soluong;
		cout<<"Nhap menh gia cua san pham : "; cin >> giatien;
		cin.ignore();
		cout<<"Nhap ngay san xuat : "; getline(cin,nsx);
	}
	
	void xuatInfSP(){
		cout<<setw(2)<<++dem<<setw(8)<<id<<setw(20)<<tenSP<<setw(20)<<soluong<<setw(20)<<giatien<<setw(20)<<nsx<<endl;
	}
};

struct THONG_TIN_KH {
	int ma;
	string tenKH;
	int namsinh;
	string diachi;
	int thanhtien;
	
	void nhapKH(){
		cout<<"Nhap ma khach hang : "; cin >> ma;
		cin.ignore();
		cout<<"Nhap ten khach hang : "; getline(cin,tenKH);
		cout<<"Nhap nam sinh : "; cin >> namsinh;
		cin.ignore();
		cout<<"Nhap dia chi : "; getline(cin,diachi);
	}
	
	void xuatInfKH(){
		cout<<setw(2)<<ma<<setw(30)<<tenKH<<setw(20)<<namsinh<<setw(30)<<diachi<<setw(20)<<thanhtien<<endl;
	}
};

typedef THONG_TIN_SP infSP;
typedef THONG_TIN_KH infKH;

void menu();
void tieuDe1();
void tieuDe2();
void nhapSL(int &);
void nhapDSSP(infSP *sp, int sl);
void boSungSL(infSP *sp,int sl, int idSP);
void xuatDSSP(infSP *sp, int sl);
void nhapSLKH(int &n);
void nhapDSKH(infKH *kh, infSP *sp, int n, int &sl);
void xuatDSKH(infKH *kh, int n);
void them1KH(infKH* kh, infSP *sp, int &n, int &sl);
void sua1KH(infKH *kh, int n, int ma);
void swap(infKH &kh1,infKH &kh2);
void sapXepThanhTien(infKH *kh,int n);
int Max(infKH *kh,int n);
void inMaxThanhTien(infKH *kh,int n);
void sua1SP(infSP *sp, int sl, int idsp);
void them1SP(infSP *sp, int &sl);
void Press();

int main(){
	infSP* SP; infKH* KH;
	SP = new infSP[100];
	KH = new infKH[100];
	int sl, n, chon;

	while(1){
		menu();
		cout<<"Nhap lua chon : ";cin>>chon;
		switch(chon){
			case 1:
				nhapSL(sl);
				nhapDSSP(SP,sl);
				Press();
				break;
			case 2:
				xuatDSSP(SP,sl);
				Press();
				break;
			case 3:
				nhapSLKH(n);
				nhapDSKH(KH,SP,n,sl);
				Press();
				break;
			case 4:
				xuatDSKH(KH,n);
				Press();
				break;
			case 5:
				them1KH(KH,SP,n,sl);	
				Press();
				break;
			case 6:
				int maKH;
				cout<<"Nhap ma khach hang can sua: ";cin>>maKH;
				sua1KH(KH,n,maKH);
				Press();
				break;
			case 7:
				int maSP;
				cout<<"Nhap ma san pham can bo sung them so luong: ";cin>>maSP;
				boSungSL(SP,sl,maSP);
				Press();
				break;
			case 8:
				sapXepThanhTien(KH,n);
				Press();
				break;
			case 9:
				inMaxThanhTien(KH,n);
				Press();
				break;
			case 10:
				int idSP;
				cout<<"Nhap ma khach hang can sua: ";cin>>idSP;
				sua1SP(SP,sl,idSP);
				Press();
				break;
			case 11:
				them1SP(SP,sl);	
				Press();
				break;
			case 0: 
				delete[] SP;
				delete[] KH;
				return 0;
		}
	}
}

void menu(){
	cout<<"-----------------------MENU------------------------\n";
	cout<<" 1. Nhap danh sach san pham \n";
	cout<<" 2. Hien thi danh sach san pham\n";
	cout<<" 3. Nhap danh sach khach hang \n";
	cout<<" 4. Hien thi danh sach khach hang\n";
	cout<<" 5. Them thong tin 1 khach hang\n";
	cout<<" 6. Chinh sua thong tin 1 khach hang\n"; 
	cout<<" 7. Bo sung so luong san pham \n";
	cout<<" 8. Sap xep tang dan so tien khach hang da mua va in danh sach\n";
	cout<<" 9. In thong tin khach hang co thanh tien cao nhat \n";
	cout<<" 10. Chinh sua thong tin 1 san pham\n"; 
	cout<<" 11. Them thong tin 1 san pham moi\n"; 
	cout<<" 0. Thoat\n";
	cout<<"---------------------------------------------------\n";
}

void Press()
{
    system("pause");
    system("cls");
}

void tieuDe1(){
	cout<<setw(3)<<"STT"<<setw(8)<<"MA SP"<<setw(20)<<"TEN SP"<<setw(20)<<"SO LUONG"<<setw(20)<<"GIA"<<setw(18)<<"NSX"<<endl;
}

void tieuDe2(){
	cout<<setw(3)<<"MA KH"<<setw(25)<<"TEN KH"<<setw(20)<<"NAM SINH"<<setw(25)<<"DIA CHI"<<setw(30)<<"THANH TIEN"<<endl;
}

// nhap so luong sieu thi them so luong
void nhapSL(int &sl){
	do {
		cout<<"Nhap so luong san pham : "; cin >>sl;
	} while (sl <= 0 );
}

// nhap danh sach so luong san pham sieu thi 
void nhapDSSP(infSP *sp, int sl){
	int c =0;
	for (int i = 0; i < sl; i++) {
		do{
			c = 0;
			cout<<"San pham "<< i + 1 <<endl;
			sp[i].nhapSP(); cout<<endl;
			for(int j=0;j<i;j++){
				if(sp[i].id == sp[j].id){
					cout<<"\nMa san pham da ton tai !\nBo sung so luong san pham thuc hien chuc nang 7 \n";
					c++; 
				}
			}
		} while (c!=0);
	}
}

// in danh sach san pham cua sieu thi
void xuatDSSP(infSP *sp, int sl){
	cout<<"\n-------------------------------------Danh sach san pham---------------------------------------\n";
	tieuDe1();
	for (int i = 0; i < sl; i++) sp[i].xuatInfSP();
}

// bo sung so luong cho san pham da co id
void boSungSL(infSP *sp,int sl, int idSP){
	dem = 0;
	infSP tmp;
	for (int i =0;i<sl;i++){
		if(sp[i].id == idSP){
			cout<<"So luong can them la : ";cin>>tmp.soluong;
			sp[i].soluong += tmp.soluong;
			return;
		}
	}
	cout<<"Ma san pham khong ton tai !\n";
}

// nhap so luong khach hang
void nhapSLKH(int &n)
{
    do
    {
        cout <<"Nhap so luong khach hang: ";
        cin >>n;
        if(n<0)
            cout <<"Moi ban nhap lai!"<<endl;
    }while(n<0);
}

// nhap danh sach khach hang
void nhapDSKH(infKH *kh, infSP *sp, int n, int &sl){
	int slsp, masp,soluong;
	int c,d;
	for (int i = 0; i < n; i++) {
		do{
			c = 0;
			cout<<"Khach hang "<< i + 1 <<endl;
			kh[i].nhapKH(); kh[i].thanhtien = 0;
			for(int j=0;j<i;j++){
				if(kh[i].ma == kh[j].ma){
					cout<<"\nTrung ma khach hang. Hay nhap lai!!! \n";
					c++; 
				}
			}
		} while (c!=0);
				
		do {
			cout<<"Nhap so luong san pham khach hang mua : ";cin>>slsp;
		} while (slsp > sl );
		
		for(int j =0;j<slsp;j++){
			lable1:cout<<"Nhap ma san pham "<<j+1<<" : ";cin>>masp;
			d=0;
			for(int k=0;k<sl;k++){			
				if(sp[k].id == masp){
					lable2:cout<<"Nhap so luong: ";cin>>soluong;
					if (soluong < sp[k].soluong){
						kh[i].thanhtien += sp[k].giatien*soluong;
						sp[k].soluong -= soluong;
						d = 0;
						break;
					}
					else {
						cout<<"Chua thoa so luong\n"; goto lable2;
						break;
					}
				} else d++;
			}
			if(d>0) {
				cout<<"Nhap sai ma san pham . Hay nhap lai !\n";
				goto lable1;
			}
		}
		cout << endl;
	}
}

// in danh sach khach hang
void xuatDSKH(infKH *kh, int n){
	cout<<"\n------------------------------------------Danh sach khach hang-------------------------------------------\n";
	tieuDe2();
	for (int i = 0; i < n; i++) kh[i].xuatInfKH();	
}

// them 1 khach hang bat ky
void them1KH(infKH* kh, infSP *sp, int &n, int &sl){
	n++;
	cout<<"Nhap thong tin khach hang can them: "<<endl;
	nhap:kh[n-1].nhapKH();
	for (int i=0;i<n-1;i++){
		if(kh[i].ma == kh[n-1].ma) {
			cout<<"Ma khach hang bi trung. Hay nhap lai!!\n";goto nhap;
		}
	}
	int slsp, masp, soluong, d;
	
	do {
		cout<<"Nhap so luong san pham khach hang mua : ";cin>>slsp;
	} while (slsp > sl );
		
	for(int j =0;j<slsp;j++){
		lable1:cout<<"Nhap ma san pham "<<j+1<<" : ";cin>>masp;		
		d=0;
		for(int k=0;k<sl;k++){			
			if(sp[k].id == masp){
				lable2:cout<<"Nhap so luong: ";cin>>soluong;
				if (soluong < sp[k].soluong){
					kh[n-1].thanhtien += sp[k].giatien*soluong;
					sp[k].soluong -= soluong;
					d = 0;
					break;
				}
				else {
					cout<<"Chua thoa so luong\n"; goto lable2;
					break;
				}
			} else d++;
		}
		if(d>0) {
			cout<<"Nhap sai ma san pham . Hay nhap lai !\n";
			goto lable1;
		}
	}
}

// chinh sua thong tin 1 khach hang
void sua1KH(infKH *kh, int n, int maKH){
	int chon;
	for (int i =0;i<n;i++){
		if(kh[i].ma == maKH){
			do{
				cout<<"\n1. Sua ten khach hang \n";
				cout<<"2. Sua nam sinh khach hang\n";
				cout<<"0. Hoan thanh\n";
				cout<<"Nhap lua chon : ";cin >> chon;
				if (chon == 1){
					cin.ignore();
					cout<<"Nhap ten khach hang : "; getline(cin,kh[i].tenKH);
				}
				if (chon == 2){
					cout<<"Nhap nam sinh khach hang : "; cin>>kh[i].namsinh;
				}
			}
			while (chon == 1 || chon == 2);
			return;
		}
	}
	cout<<"Ma khach hang khong ton tai !\n";
}

void swap(infKH &kh1,infKH &kh2){
	infKH tmp;
	tmp = kh1;
	kh1 = kh2;
	kh2 = tmp;
}

// Sap xep tang dan so tien khach hang da mua va in danh sach
void sapXepThanhTien(infKH *kh,int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(kh[i].thanhtien > kh[j].thanhtien){
				swap(kh[i],kh[j]);
			}
		}
	}
	xuatDSKH(kh,n);
}

// tim max thanh tien
int Max(infKH *kh,int n){
	int max = kh[0].thanhtien;
	for(int i=1;i<n;i++){
		if(kh[i].thanhtien > max) max = kh[i].thanhtien;
	}
	return max;
}

// in ra khach hang co thanh tien cao nhat
void inMaxThanhTien(infKH *kh,int n){
	cout<<"Thong tin nhung khach hang co thanh tien cao nhat \n";
	tieuDe2();
	for(int i=0;i<n;i++){
		if(kh[i].thanhtien == Max(kh,n)) kh[i].xuatInfKH();
	}
}

// chinh sua thong tin 1 san pham
void sua1SP(infSP *sp, int sl, int idsp){
	dem = 0; 
	cin.ignore();
	for(int i=0;i<sl;i++){
		if(sp[i].id == idsp){
			cout<<"Nhap ten moi: ";getline(cin,sp[i].tenSP);
			cout<<"Nhap so luong moi: "; cin >> sp[i].soluong;
			cout<<"Nhap menh gia cua san pham moi: "; cin >> sp[i].giatien;
			cin.ignore();
			cout<<"Nhap ngay san xuat moi: "; getline(cin,sp[i].nsx);
			return;
		}
	}
	cout<<"Khong tim thay ma san pham !\n";
}

// them thong tin 1 san pham moi
void them1SP(infSP *sp, int &sl){
	sl++; dem = 0; 
	cout<<"Nhap thong tin san pham moi can them : \n"; 
	sp[sl-1].nhapSP(); 
} 
