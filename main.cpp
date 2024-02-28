#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

//======================SanPham======================//
// Khai bao Node
struct SanPham{
	int maSP, soLuong;
	char tenSP[30], ngayNhap[20], loaiSP[20];
	float donGiaSP;
};

// Khai bao mot phan tu trong danh sach
struct NodeSP{
	SanPham data;
	NodeSP *next;
};

// Kieu danh sach lien ket
struct ListSP{
    NodeSP *Head;
    NodeSP *Tail;
};

// Tao danh sach rong
void InitSP(ListSP &sp)
{
    sp.Head = sp.Tail = NULL;
}

// Tao mot Node moi
NodeSP *getNodeSP(SanPham x)
{
	NodeSP *p;
	p = new NodeSP; // Cap phat vung nho cho Node
	if(p==NULL)
	{
		cout<<"Khong du bo nho!";
		return NULL;
    }
    p -> data = x; // Goi du lieu cho phan tu p
    p -> next = NULL;
    return p;
}

// Chen mot phan tu vao dau danh sach
void addHeadSP(ListSP &sp, NodeSP *p)
{
	if(sp.Head==NULL) // Danh sach rong
	{
		sp.Head = sp.Tail = p;
	}
	else
	{
	p -> next = sp.Head;
	sp.Head = p;
	}
}

// Chen mot phan tu vao cuoi danh sach
void addTailSP(ListSP &sp, NodeSP *p)
{
	if(sp.Head == NULL)
	{
		sp.Head = sp.Tail = p;
	}
	else
	{
		sp.Tail -> next = p;
		sp.Tail = p;
	}
}

// Chen mot phan tu vao sau q
void addAfterSP(ListSP &sp, NodeSP *q, NodeSP *p)
{
	if(q!=NULL)
	{
		p -> next = q -> next;
		q -> next = p;
		if(q==sp.Tail)
		sp.Tail = p;
	}
}

// Xoa phan tu sau node q trong danh sach
bool removeAfterSP(ListSP &sp, NodeSP *q)
{
	if(q!=NULL && q->next!=NULL)
	{
		NodeSP *p = q->next;
	    q->next = p -> next;
	    if (p == sp.Tail)
	    {
	    	sp.Tail = p;
	    }
	    delete p;
	    return true;
	}
	else
	return false;
}

// Nhap san pham
void NhapSP(SanPham &x)
{
	cout<<"___________________"<<endl;
    cout<<"Nhap Ma San Pham: ";
    cin>>x.maSP;
    fflush(stdin);
    cout<<"Nhap Ten San Pham: ";
    gets(x.tenSP);
    cout<<"Nhap Ngay Nhap: ";
    gets(x.ngayNhap);
    cout<<"Nhap Loai San Pham: ";
    gets(x.loaiSP);
    cout<<"Nhap Don Gia San Pham: ";
    cin>>x.donGiaSP;
    cout<<"Nhap So Luong San Pham: ";
    cin>>x.soLuong;
}

// Hien san pham
void HienSP() {
    cout.setf(ios::left);
    cout<<"\n"<<setw(15)<<"Ma San Pham";
    cout<<setw(18)<<"Ten San Pham";
    cout<<setw(15)<<"Ngay Nhap";
    cout<<setw(15)<<"Loai San Pham";
    cout<<setw(13)<<"Don Gia";
    cout<<setw(19)<<"So Luong";
}

void XuatSP(SanPham x)
{
	cout.setf(ios::left);
    cout<<"\n"<<setw(15)<<x.maSP<<setw(18)<<x.tenSP<<setw(15)<<x.ngayNhap<<setw(15)<<x.loaiSP<<setw(13)<<x.donGiaSP<<setw(19)<<x.soLuong;
}

// Nhap danh sach san pham
void NhapDSSP(ListSP &sp)
{
    int n;
    SanPham x;
    NodeSP *p;
    cout<<"\nNhap So San Pham: ";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        NhapSP(x);
        p=getNodeSP(x);
        addTailSP(sp,p);
    }
}

// Hien danh sach san pham
void XuatDSSP(ListSP sp)
{
    NodeSP *p;
    cout<<"\nDanh Sach Cac San Pham: "<<endl;
    cout.setf(ios::left);
    HienSP();
    for(p=sp.Head; p!=NULL; p=p->next)
    {
        XuatSP(p->data);
    }
}

// Tim kiem theo ma SP
NodeSP *SearchMaSP(ListSP sp , int k)
{
    NodeSP *p;
    for(p=sp.Head; p!=NULL;p=p->next)
        if(p->data.maSP == k)
        break;
        return p;
}

// Sap xep san pham tang dan theo ma
void SapXepTangTheoMaSP(ListSP &sp)
{
    NodeSP *p , *q;
    SanPham tg;
    for(p=sp.Head; p!=NULL;p=p->next)
    {
         for(q=p->next;q!=NULL;q=q->next)
         {
             if(p->data.maSP > q->data.maSP)
             {
                tg=p->data;
                p->data=q->data;
                q->data=tg;
             }
         }
    }
    XuatDSSP(sp);
}

// Sap xep tang dan theo Ten, neu ten trung nhau thi sap xep theo gia
void SapXepTangTheoTenSP(ListSP &sp)
{
	NodeSP *p, *q;
	SanPham tg, tm;
        for(p=sp.Head; p!=NULL;p=p->next){
            for(q=p->next;q!=NULL;q=q->next){
                if (strcmp(p->data.tenSP, q->data.tenSP) > 0){
                    tg = p->data;
                    p->data = q->data;
                    q->data = tg;    
                }else if( strcmp(p->data.tenSP, q->data.tenSP)==0 ){
                	if(p->data.donGiaSP>q->data.donGiaSP){
                		tm = p->data;
                		p->data = q->data;
                		q->data = tm;
					}
				}
            }
        }
        cout<<"\nDanh Sach Sap Xep Theo Ten San Pham: ";
        XuatDSSP(sp);
}

// Dem san pham co gia lon hon 250000
void DemGiaSPLonHon250(ListSP &sp )
{
	NodeSP *p;
	int dem=0;
	for(p=sp.Head; p!=NULL;p=p->next){
		if (p->data.donGiaSP > 250000) {
		dem++;
			}
		}
		cout<<"So San Pham Co Don Gia Lon Hon 250000 La: "<<dem<<endl;
}

// Xoa san pham dau danh sach
void removeHeadSP(ListSP &sp)
{
	NodeSP *p;
    if(sp.Head==NULL)
    {
        sp.Head=sp.Tail=NULL;
    }
    else
    {
        p=sp.Head;
        sp.Head=sp.Head->next;
        delete p;
    }
    cout<<"\nDanh Sach Sau Khi Xoa La: "<<endl;

    XuatDSSP(sp);
}

// Xoa san pham cuoi danh sach
void removeTailSP(ListSP &sp)
{
		NodeSP *p = sp.Head;
		NodeSP *q = new NodeSP;
		while(p->next != sp.Tail)
		p = p -> next;
		q = p;
		p = p -> next;
		sp.Tail = q;
		sp.Tail->next = NULL;
		delete p;
}
/*
//Xoa san pham vi tri bât ki theo ma don hang  
void XoaTheoMa(ListSP &sp, int maSPtim)
{
	if (sp.Head == NULL )
	{
		return;
	}
	else if( sp.Head->data.maSP == maSPtim)
	{
		removeHeadSP(sp);
		return;
	}
	else{
	NodeSP *rdh=new NodeDH;
	for ( NodeDH *kdh=T.Head; kdh!=NULL; kdh = kdh->next )
	{
		if (kdh->info.maDonHang == MaDH)
		{
			
			rdh->next = kdh->next;
			delete(kdh);
			return;
		}
		rdh=kdh;				
	}
}
}

// Xoa Node voi khoa k
bool removeNode (ListSP &sp, int k)
{
	NodeSP *p = sp.Head;
	NodeSP *q = NULL;
	while(p!=NULL)
	{
		if(p->data == k)
		break;
		q=p;
		p=p->next;
	}
	if(p==NULL)
	cout<<"Khong tim thay k";
	return false;
	} else if(q==NULL){
	}
	else{
    }
}

// Xoa san pham bat ky
void removeFree(ListSP &sp, int k){
	if(k<=1) removeHeadSP(sp);
	else
	if(k>=n) removeTailSP(sp);
	else{
		int dem = 0;
		// if(!isEmpty(sp)){
		NodeSP *p = sp.Head;
		NodeSP *q = new NodeSP;
		while(p!=NULL){
			dem++;
			q = p;
			if(dem == k)
			break;
			else
			p = p -> next;;
			}
		NodeSP *r = sp.Head;
		while(r->next!=q)
		r = r->next;
		r->next = q->next;
		delete q;
		}
}	
*/

// Xoa toan bo list
void removeList(ListSP &sp)
{
	NodeSP *p;
	while(sp.Head != NULL)
	{
		p = sp.Head;
		sp.Head = p -> next;
		delete p;
	}
	sp.Tail = NULL;
}

// Them san pham vap cuoi danh sach
void themSP(ListSP &sp)
{
    int n;
    SanPham x;
    cout<<"\nNhap San Pham Ban Muon Them:\n";
    NhapSP(x);
    NodeSP *p=getNodeSP(x);
    addTailSP(sp,p);
    XuatDSSP(sp);
}


// Them san pham vao dau danh sach
void themSPDauDS(ListSP &sp)
{
    int n;
    SanPham x;
    cout<<"\nNhap San Pham Ban Muon Them:\n";
    NhapSP(x);
    NodeSP *p=getNodeSP(x);
    addHeadSP(sp,p);
    XuatDSSP(sp);
}

// Luu File
void luuFileSP(FILE *f,ListSP sp)
{
	f=fopen("SanPham.txt","wb");
	int n=0;
	NodeSP *p;
	for(p=sp.Head;p!=NULL;p=p->next)
	n=n+1;
	fwrite(&n,sizeof(int),1,f);
	for(p=sp.Head;p!=NULL;p=p->next)
	fwrite(&p->data,sizeof(SanPham),1,f);
	fclose(f);
	cout<<"\nDa luu file thanh cong!";
}

// Doc file
void docFileSP(FILE *f,ListSP &sp)
{
	SanPham x;
	int i,n;
	NodeSP *p;
	f=fopen("SanPham.txt","rb");
	fread(&n,sizeof(int),1,f);
	for(i=0;i<n;i++)
	{
		fread(&x,sizeof(SanPham),1,f);
		p=getNodeSP(x);
		addHeadSP(sp,p);
	}
	fclose(f);
	cout<<"Doc File Thanh Cong!";
}

//======================NhanVien======================//
// Khai bao Node
struct NhanVien{
	int maNV;
	int Luong;
	char tenNV[30], gioiTinh[20], soDienThoai[12];
	float heSoLuong;
};

// Khai bao mot phan tu trong danh sach
struct NodeNV{
	NhanVien data;
	NodeNV *next;
};

// Kieu danh sach lien ket
struct ListNV{
    NodeNV *Head;
    NodeNV *Tail;
 };

// Tao danh sach rong
void InitNV(ListNV &nv)
{
    nv.Head = nv.Tail = NULL;
}

// Tao mot Node moi
NodeNV *getNodeNV(NhanVien x)
{
	NodeNV *a;
	a = new NodeNV; // Cap phat vung nho cho Node
	if(a==NULL)
	{
		cout<<"Khong du bo nho!";
		return NULL;
    }
    a -> data = x; // Goi du lieu cho phan tu p
    a -> next = NULL;
    return a;
}


// Chen mot phan tu vao dau danh sach
void addHeadNV(ListNV &nv, NodeNV *a)
{
	if(nv.Head==NULL) // Danh sach rong
	{
		nv.Head = nv.Tail = a;
	}
	else
	{
	a -> next = nv.Head;
	nv.Head = a;
	}
}

// Chen mot phan tu vao cuoi danh sach
void addTailNV(ListNV &nv, NodeNV *a)
{
	if(nv.Head == NULL)
	{
		nv.Head = nv.Tail = a;
	}
	else
	{
		nv.Tail -> next = a;
		nv.Tail = a;
	}
}

// Nhap nhan vien
void NhapNV(NhanVien &x)
{
	cout<<"___________________"<<endl;
    cout<<"Nhap Ma Nhan Vien: ";
    cin>>x.maNV;
    fflush(stdin);
    cout<<"Nhap Ten Nhan Vien: ";
    gets(x.tenNV);
    cout<<"Nhap Gioi Tinh: ";
    gets(x.gioiTinh);
    cout<<"Nhap So Dien Thoai: ";
    gets(x.soDienThoai);
    cout<<"Nhap He So Luong: ";
    cin>>x.heSoLuong;
    x.Luong = x.heSoLuong *4050000;
}

// Hien nhan vien
void HienNV() {
    cout.setf(ios::left);
    cout<<"\n"<<setw(15)<<"Ma Nhan Vien";
    cout<<setw(18)<<"Ten Nhan Vien";
    cout<<setw(15)<<"Gioi Tinh";
    cout<<setw(15)<<"So Dien Thoai";
    cout<<setw(13)<<"He So Luong";
    cout<<setw(19)<<"Luong";
}

void XuatNV(NhanVien x)
{
	cout.setf(ios::left);
    cout<<"\n"<<setw(15)<<x.maNV<<setw(18)<<x.tenNV<<setw(15)<<x.gioiTinh<<setw(15)<<x.soDienThoai<<setw(13)<<x.heSoLuong<<setw(19)<<x.Luong;
}

// Nhap danh sach nhan vien
void NhapDSNV(ListNV &nv)
{
    int n;
    NhanVien x;
    NodeNV *a;
    cout<<"\nNhap So Nhan Vien: ";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        NhapNV(x);
        a=getNodeNV(x);
        addTailNV(nv,a);
    }
}

// Hien danh sach nhan vien
void XuatDSNV(ListNV nv)
{
    NodeNV *a;
    cout<<"\nDanh Sach Nhan Vien: "<<endl;
    cout.setf(ios::left);
    HienNV();
    for(a=nv.Head; a!=NULL;a=a->next)
    {
        XuatNV(a->data);
    }
}

// Tim kiem theo ma nhan vien
NodeNV *SearchMaNV(ListNV nv , int k)
{
    NodeNV *a;
    for(a=nv.Head; a!=NULL;a=a->next)
        if(a->data.maNV == k)
        break;
        return a;
}

// Tim kiem theo ten nhan vien
void searchTenNV(ListNV nv ) {
	NodeNV *a;
	string HoTen;
	cout << "Nhap Ten Nhan Vien Can Tim Kiem : ";
	cin >> HoTen;
	for (NodeNV* a = nv.Head; a != NULL; a = a->next) {
		if (a->data.tenNV == HoTen) {
			HienNV();
			XuatNV(a->data);
		}
	}
}

// Tinh tong luong nhan vien
void TongLuongNV(ListNV nv){
 	int S=0;
 	NodeNV *a;
	for(a=nv.Head; a!=NULL;a=a->next) {
		S += a->data.Luong;
	}
	cout<<"Tong Luong Nhan Vien Trong Cua Hang La: "<<S<<endl;
}
	
// Sap xep danh sach giam dan theo ma nhan vien
void SapXepTangTheoMaNV(ListNV &nv)
{
    NodeNV *a,*b;
    NhanVien tg;
    for(a=nv.Head;a!=NULL;a=a->next)
    {
        for(b=a->next;b!=NULL;b=b->next)
        {
            if(a->data.maNV < b->data.maNV)
            {
                tg=a->data;
                a->data=b->data;
                b->data=tg;
            }
        }
    }
    XuatDSNV(nv);
}

// Xoa phan tu dau danh sach
void removeHeadNV(ListNV &nv)
{
	NodeNV *a;
    if(nv.Head==NULL)
    {
        nv.Head=nv.Tail=NULL;
    }
    else
    {
        a=nv.Head;
        nv.Head=nv.Head->next;
        delete a;
    }
    cout<<"\nDanh Sach Sau Khi Xoa La: "<<endl;
    XuatDSNV(nv);
}

// Nhan vien co luong cao nhat
void NhanVienCoLuongCaoNhat(ListNV nv){
	NodeNV* a;
	int Max=nv.Head->data.Luong;
	for (NodeNV* a = nv.Head; a != NULL; a = a->next) {
	if(a->data.Luong>Max){
		Max=a->data.Luong;	
		if (a->data.Luong == Max) {
			HienNV();
			XuatNV(a->data);
			}
		}
	}
}

// Nhan vien co luong thap nhat
void NhanVienCoLuongThapNhat(ListNV nv){
	NodeNV* a;
	int Min=nv.Head->data.Luong;
	for (NodeNV* a = nv.Head; a != NULL; a = a->next) {
	if(a->data.Luong<Min){
		Min=a->data.Luong;	
		if (a->data.Luong == Min) {
			HienNV();
			XuatNV(a->data);
			}
		}
	}
}

// Them nhan vien 
void themNV(ListNV &nv)
{
    int n;
    NhanVien x;
    cout<<"\nNhap Nhan Vien Ban Muon Them: \n";
    NhapNV(x);
    NodeNV *a=getNodeNV(x);
    addTailNV(nv,a);
    XuatDSNV(nv);
}

// Luu File
void luuFileNV(FILE *f,ListNV nv)
{
	f=fopen("NhanVien.txt","wb");
	int n=0;
	NodeNV *a;
	for(a=nv.Head;a!=NULL;a=a->next)
	n=n+1;
	fwrite(&n,sizeof(int),1,f);
	for(a=nv.Head;a!=NULL;a=a->next)
	fwrite(&a->data,sizeof(NhanVien),1,f);
	fclose(f);
	cout<<"\nDa luu file thanh cong!";
}

// Doc file
void docFileNV(FILE *f,ListNV &nv)
{
	NhanVien x;
	int i,n;
	NodeNV *a;
	f=fopen("NhanVien.txt","rb");
	fread(&n,sizeof(int),1,f);
	for(i=0;i<n;i++)
	{
		fread(&x,sizeof(NhanVien),1,f);
		a=getNodeNV(x);
		addHeadNV(nv,a);
	}
	fclose(f);
	cout<<"Doc File Thanh Cong!";
}

//======================HoaDon======================//
// Khai bao Node
struct ThongTin{
    int maSP, soLuongBan;
    float donGia, thanhTien;
};

struct HoaDon{
	ThongTin ds[30];
	int maHD, maNV, soSP;
	char ngayXuatHD[20];
	float tongTien;
};

// Khai bao mot phan tu trong danh sach
struct NodeHD{
	HoaDon data;
	NodeHD *next;
};

// Kieu danh sach lien ket
struct ListHD{
    NodeHD *Head;
    NodeHD *Tail;
 };

// Tao danh sach rong
void InitHD(ListHD &hd)
{
    hd.Head = hd.Tail = NULL;
}

// Tao mot Node moi
NodeHD *getNodeHD(HoaDon x)
{
	NodeHD *o;
	o = new NodeHD; // Cap phat vung nho cho Node
	if(o == NULL)
	{
		cout<<"Khong du bo nho!";
		return NULL;
    }
    o -> data = x; // Goi du lieu cho phan tu p
    o -> next = NULL;
    return o;
}


// Chen mot phan tu vao dau danh sach
void addHeadHD(ListHD &hd, NodeHD *o)
{
	if(hd.Head==NULL) // Danh sach rong
	{
		hd.Head = hd.Tail = o;
	}
	else
	{
	o -> next = hd.Head;
	hd.Head = o;
	}
}

// Chen mot phan tu vao cuoi danh sach
void addTailHD(ListHD &hd, NodeHD *o)
{
	if(hd.Head == NULL)
	{
		hd.Head = hd.Tail = o;
	}
	else
	{
		hd.Tail -> next = o;
		hd.Tail = o;
	}
}

// Chen mot phan tu vao sau t
void addAfterHD(ListHD &hd, NodeHD *t, NodeHD *o)
{
	if(t!=NULL)
	{
		o -> next = t -> next;
		t -> next = o;
		if(t==hd.Tail)
		hd.Tail = o;
	}
}

// Xoa phan tu sau node t trong danh sach
bool removeAfterHD(ListHD &hd, NodeHD *t)
{
	if(t!=NULL && t->next!=NULL)
	{
		NodeHD *o = t->next;
	    t->next = o -> next;
	    if (o == hd.Tail)
	    {
	    	hd.Tail = o;
	    }
	    delete o;
	    return true;
	}
	else
	return false;
}

// Nhap hoa don
void NhapHD(HoaDon &x,ListNV &nv,ListSP &sp)
{
    NodeNV *pnv;
    NodeSP *psp;
    cout<<"___________________"<<endl;
    cout<<"Nhap Ma Hoa Don: ";
    cin>>x.maHD;
    do{
        cout<<"Nhap Ma Nhan Vien: ";
        cin>>x.maNV;
        pnv= SearchMaNV(nv,x.maNV);
        if(pnv==NULL)
        {
            cout<<"Khong Ton Tai Ma Nhan Vien!"<<endl;
        }
    }while(pnv==NULL);
	
    cout<<"Nhap Ngay Xuat Hoa Don: ";
    fflush(stdin);
    gets(x.ngayXuatHD);

    cout<<"Nhap So San Pham Da Ban: ";
    cin>>x.soSP;
    for(int i=0; i<x.soSP ;i++)
    {
        do{
        cout<<"Nhap Ma San Pham: ";
        cin>>x.ds[i].maSP;
        psp= SearchMaSP(sp,x.ds[i].maSP);
        if(psp==NULL)
        {
            cout<<"Khong Ton Tai Ma San Pham!"<<endl;
        }
        }while(psp==NULL);
        cout<<"Nhap So Luong San Pham Ban: ";
        cin>>x.ds[i].soLuongBan;
        cout<<"Nhap Don Gia: ";
        cin>>x.ds[i].donGia;
        x.ds[i].thanhTien= x.ds[i].soLuongBan * x.ds[i].donGia;
    }
    cout<<"\n---------------------------------------\n";
    x.tongTien=0;
    for( int i=0; i<x.soSP; i++){
     x.tongTien=x.tongTien + x.ds[i].thanhTien;
    }
}

// Hien hoa don
void HienHD()
{
	cout.setf(ios::left);
    cout<<"\n"<<setw(15)<<"MA SAN PHAM";
    cout<<setw(20)<<"SO LUONG BAN";
    cout<<setw(20)<<"DON GIA";
    cout<<setw(20)<<"THANH TIEN";
}

void XuatHD(HoaDon x)
{
	cout.setf(ios::left);
	cout<<"\n******Thong Tin Hoa Don******";
	cout<<"\n                             ";
    cout<<"\nMa Hoa Don: " <<setw(3)<<x.maHD;
    cout<<"\nMa Nhan Vien: "<<setw(3)<<x.maNV;
    cout<<"\nNgay Xuat Hoa Don: "<<setw(3)<<x.ngayXuatHD;
    cout<<"\n---------------------------------------\n";
    cout<<"\nSo San Pham Da Ban: "<<setw(3)<<x.soSP;
    cout.setf(ios::left);
    HienHD();
    for(int i=0; i<x.soSP; i++)
    {
    	cout.setf(ios::left);

        cout<<"\n"<<setw(15)<<x.ds[i].maSP;
        cout<<setw(20)<<x.ds[i].soLuongBan;
        cout<<setw(20)<<x.ds[i].donGia;
        cout<<setw(20)<<x.ds[i].thanhTien;  
    }
    cout<<"\n                           ";
    cout<<"\nTong tien ban duoc: "<<setw(3)<<x.tongTien;
    cout<<"\n========================================\n";
}

// Nhap danh sach hoa don
void NhapDSHD(ListHD &hd,ListNV &nv,ListSP &sp)
{
    int n;
    HoaDon x;
    NodeHD *o;
    cout<<"\nNhap So Hoa Don: ";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        NhapHD(x,nv,sp);
        o=getNodeHD(x);
        addTailHD(hd,o);
    }
}

// Hien danh sach hoa don
void XuatDSHD(ListHD hd)
{
    NodeHD *o;
    cout<<"\nDanh Sach Cac Hoa Don: "<<endl;
    for(o=hd.Head; o!=NULL;o=o->next)
    {
        XuatHD(o->data);
    }
}

//Tong tien cac hoa don
void tongTienHD(ListHD hd)
{
	int s=0;
	NodeHD *o;
	for(o=hd.Head;o!=NULL;o=o->next)
	{
		s=s+o->data.tongTien;
	}
	cout<<"\nTong Tien Cac Hoa Don Da Lap La: "<<setprecision(3)<<s<<endl;
}

// Tim kiem theo ma
NodeHD *SearchMaHD(ListHD hd , int k)
{
    NodeHD *o;
    for(o=hd.Head; o!=NULL;o=o->next)
        if(o->data.maHD == k)
        break;
        return o;
}

// Sap xep hoa don tang dan theo ma
void SapXepTangTheoMaHD(ListHD &hd)
{
    NodeHD *o , *w;
    HoaDon tg;
    for(o=hd.Head; o!=NULL;o=o->next)
    {
         for(w=o->next;w!=NULL;w=w->next)
         {
             if(o->data.maHD > w->data.maHD)
             {
                tg=o->data;
                o->data=w->data;
                w->data=tg;
             }
         }
    }
    XuatDSHD(hd);
}

// Xoa hoa don dau danh sach
void removeHeadHD(ListHD &hd)
{
	NodeHD *o;
    if(hd.Head==NULL)
    {
        hd.Head=hd.Tail=NULL;
    }
    else
    {
        o=hd.Head;
        hd.Head=hd.Head->next;
        delete o;
    }
    cout<<"\nDanh Sach Sau Khi Xoa La: "<<endl;
    XuatDSHD(hd);
}

// Them hoa don
void themHD(ListHD &hd,ListNV &nv,ListSP &sp)
{
    int n;
    HoaDon x;
    cout<<"\nNhap Hoa Don Ban Muon Them: \n";
    NhapHD(x,nv,sp);
    NodeHD *o=getNodeHD(x);
    addTailHD(hd,o);
    XuatDSHD(hd);
}

// Luu File
void luuFileHD(FILE *f,ListHD hd)
{
	f=fopen("HoaDon.txt","wb");
	int n=0;
	NodeHD *o;
	for(o=hd.Head;o!=NULL;o=o->next)
	n = n+1;
	fwrite(&n,sizeof(int),1,f);
	for(o=hd.Head;o!=NULL;o=o->next)
	fwrite(&o->data,sizeof(HoaDon),1,f);
	fclose(f);
	cout<<"\nDa luu file thanh cong!";
}

// Doc file
void docFileHD(FILE *f,ListHD &hd)
{
	HoaDon x;
	int i,n;
	NodeHD *o;
	f=fopen("HoaDon.txt","rb");
	fread(&n,sizeof(int),1,f);
	for(i=0;i<n;i++)
	{
		fread(&x,sizeof(HoaDon),1,f);
		o=getNodeHD(x);
		addHeadHD(hd,o);
	}
	fclose(f);
	cout<<"Doc File Thanh Cong!";
}

// Main
int main()
{
    FILE *f;
    int k,chon, chonSP, chonNV, chonHD;
    ListSP sp;
    ListNV nv;
    ListHD hd;
    InitSP(sp);
    InitNV(nv);
    InitHD(hd);

    NodeSP *p,*q;
    NodeNV *a,*b;
    NodeHD *o, *w;

	while(true) {
            label73:
            while(true) {
                cout<<"\n|=======================QUAN LY CUA HANG THOI TRANG=======================|";
                cout<<"\n|1. San Pham                                                              |";
                cout<<"\n|2. Nhan Vien                                                             |";
                cout<<"\n|3. Hoa Don                                                               |";
                cout<<"\n|0. Thoat Chuong Trinh                                                    |";
                cout<<"\n|===================================END===================================|";
                cout<<"\nMoi Ban Chon:";
                cin>>chon;
                switch(chon)
                {
                case 0:
                    exit(0);
                    break;
                {
				 case 1:

					 while(true)
                        {

                        if (chon == -99)
                        {
                            goto label73;
                        }
                        cout<<"\n1. Nhap Danh Sach San Pham";
                        cout<<"\n2. In Dach Sach San Pham";
						cout<<"\n3. Tim Kiem San Pham Theo Ma";
                        cout<<"\n4. Sap Xep Danh Sach San Pham Tang Dan Theo Ma";
                        cout<<"\n5. Dem So San Pham Co Don Gia Lon Hon 250000";
						cout<<"\n6. Xoa San Pham Dau Danh Sach";
                        cout<<"\n7. Them San Pham Vao Cuoi Danh Sach";
                        cout<<"\n8. Ghi File San Pham";
                        cout<<"\n9. Doc File San Pham";
						cout<<"\n10. Ve Chuong Trinh Chinh";
						cout<<"\n---Moi Ban Chon: ";
                        cin>>chonSP;
                        switch(chonSP)
                       {
					   	 case 1 :
                            {
                                NhapDSSP(sp);
                                break;
                            }
                        case 2:
                            {
                                XuatDSSP(sp);
                                break;
                            }
						case 3:
						    {
                                cout<<"Nhap Ma Can Tim: ";
                                cin>>k;
                                p=SearchMaSP(sp,k);
                                if(p==NULL)
                                {
                                    cout<<"\nKhong Tim Thay!";
                                    break;
                                }
                                else
                                {
                                    cout<<"\nDa Tim Thay!"<<endl;
                                    HienSP();
                                    XuatSP(p->data);
                                    break;
                                }
                            }
                        case 4:
						    {
                                SapXepTangTheoMaSP(sp);
                                break;
                            }
						case 5:
                        	{
                        		DemGiaSPLonHon250(sp);
                        		break;
                        	}
						case 6:
                            {
                                removeHeadSP(sp);
                                break;
                            }
						case 7:
						    {
                                themSP(sp);
                                break;
                            }
                        case 8:
						    luuFileSP(f,sp);
							break;
                        case 9:
						    docFileSP(f,sp);
							break;
                        case 10: chon = -99;
                            }
                            }
                    }
				 case 2:
                        while(true)
                        {
                        if (chon == -99)
                        {
                            goto label73;
                        }
                        cout<<"\n 1 . Nhap Danh Sach Nhan Vien";
                        cout<<"\n 2 . In Dach Sach Nhan Vien";
						cout<<"\n 3 . Tim Kiem Nhan Vien Theo Ma";
						cout<<"\n 4 . Tong Luong Nhan Vien Trong Cua Hang";
                        cout<<"\n 5 . Sap Xep Danh Sach Nhan Vien Giam Dan Theo Ma";
                        cout<<"\n 6 . Xoa Nhan Vien Dau Danh Sach";
                        cout<<"\n 7 . Them Nhan Vien Vao Cuoi Danh Sach";
                        cout<<"\n 8 . Ghi File Nhan Vien";
                        cout<<"\n 9 . Doc File Nhan Vien";
                        cout<<"\n 10 . Ve Chuong Trinh Chinh";
                        cout<<"\n---Moi Ban Chon: ";
                        cin>>chonNV;
                        switch(chonNV)
                        {
                        case 1:
                        {
                                NhapDSNV(nv);
                                break;
                        }
                        case 2:
                            {
                                XuatDSNV(nv);
                                break;
                            }
                        case 3:
							{
                                cout<<"Nhap Ma Can Tim: ";
                                cin>>k;
                                a=SearchMaNV(nv,k);
                                if(a==NULL)
                                {
                                    cout<<"\nKhong Tim Thay!";
                                    break;
                                }
                                else
                                {
                                    cout<<"\nDa Tim Thay!"<<endl;
                                    HienNV();
                                    XuatNV(a->data);
                                    break;
                                }
                            }
                        case 4:
                        	{
                        		TongLuongNV(nv);
                        		break;
                        	}
                        case 5:
						    {
                                SapXepTangTheoMaNV(nv);
                                break;
                            }
                        case 6:
						    {
                                removeHeadNV(nv);
                                break;
                            }
						case 7:
						    {
                                themNV(nv);
                                break;
                            }
						case 8:
                                luuFileNV(f,nv);
								break;
                        case 9:
                                docFileNV(f,nv);
								break;
                        case 10: chon = -99;
                         }
                        }
                case 3:
                        while(true)
                        {
                        if (chon == -99)
                        {
                            goto label73;

                        }
                        cout<<"\n 1 . Nhap Danh Sach Hoa Don";
                        cout<<"\n 2 . In Dach Sach Hoa Don";
						cout<<"\n 3 . Tong Tien Tat Ca Cac Hoa Don ";
                        cout<<"\n 4 . Tim Kiem Hoa Don Theo Ma";
                        cout<<"\n 5 . Sap Xep Danh Sach Hoa Don Tang Dan Theo Ma";
                        cout<<"\n 6 . Xoa Hoa Don Dau Danh Sach";
                        cout<<"\n 7 . Them Hoa Don Vao Cuoi Danh Sach";
                        cout<<"\n 8 . Ghi File Hoa Don";
                        cout<<"\n 9 . Doc File Hoa Don";
                        cout<<"\n 10 . Ve chuong trinh chinh";
                        cout<<"\n---Moi Ban Chon: ";
                        cin>>chonHD;
                        switch(chonHD)
                        {
                        case 1:
                            {
                                NhapDSHD(hd,nv,sp);
                                break;
                            }
                        case 2:
                            {
                                XuatDSHD(hd);
                                break;
                            }
                        case 3:
						    {
                        		tongTienHD(hd);
                        		break;
							}
                        case 4:
						    {
                               cout<<"Nhap Ma Can Tim: "; cin>>k;
                               o=SearchMaHD(hd,k);
                               if(o==NULL)
                               {
                                   cout<<"\nKhong Tim Thay!";
                                   break;
                               }
                               else
                               {
                                   cout<<"\nDa Tim Thay!"<<endl;
                                   HienHD();
                                   XuatHD(o->data);
                                   break;
                               }
                            }
                        case 5:
                            {
                                SapXepTangTheoMaHD(hd);
                                break;
                            }
						case 6:
                            {
                                removeHeadHD(hd);
                                break;
                            }
						case 7:
						    {
                                themHD(hd,nv,sp);
                                break;
                            }
						case 8:
						        luuFileHD(f,hd);
								break;
                        case 9:
						        docFileHD(f,hd);
								break;
                        case 10: chon = -99;
                       }
                }
            }
        }
    }
}

