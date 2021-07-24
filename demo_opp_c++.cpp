#include<iostream>
#include<string>
using namespace std;
class phan_so{
        int tu_so;
        int mau_so;
    public:
    phan_so(int tu=0,int mau=1)
    {
        tu_so=tu;
        mau_so=mau;
    }
    phan_so operator +(phan_so p)
    {
        phan_so q;
        q.tu_so = tu_so*p.mau_so+mau_so+p.tu_so;
        q.mau_so = mau_so * p.mau_so;
        return q;    
    } 
    phan_so operator /(phan_so p)
    {
        phan_so q;
        q.tu_so=tu_so*p.mau_so;
        q.mau_so=mau_so*p.tu_so;
        return q;
    }
    phan_so operator!()
    {
        phan_so q;
        q.tu_so=mau_so;
        q.mau_so=tu_so;
        return q;
    }
    friend istream&operator>>(istream&is,phan_so p);
    friend ostream&operator<<(ostream &os,phan_so p);
};
istream&operator>>(istream&is,phan_so p)
{
    is>>p.tu_so>>p.mau_so;
    return is;
}
ostream&operator<<(ostream&os,phan_so p){
    os<<p.tu_so<<"/"<<p.mau_so;
    return os;
}
int main()
{
    phan_so p(1,2),q(4,5),r;
    r=!p;
    cout<<r;
    system("pause");
}
