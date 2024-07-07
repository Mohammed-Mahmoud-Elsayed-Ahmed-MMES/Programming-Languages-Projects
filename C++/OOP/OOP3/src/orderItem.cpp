#include "orderItem.h"
//have a relation with product by object of product
orderItem::orderItem()
{
    salePrice = 0.0;
    quantity = 0.0;
}
orderItem::orderItem(double sa_pr,double qu)
{
    salePrice = sa_pr;
    quantity = qu;
}
void orderItem::getData()
{
    pro.getData();
    cout << "Enter Sale Price : ";
    cin >> salePrice;
    cout << "Enter Quantity : ";
    cin >> quantity;
}
void orderItem::updateQuantity(double newQuantity)
{
    pro.updateProduct();
    cout << "Enter New Quantity : ";
    cin >> newQuantity;
    quantity = newQuantity;
}
void orderItem::operator++()
{
    if((quantity+1) <= st.getQuantity())
    {
        quantity++;
    }
    else
    {
        cout << "The Quantity is Not Available " << endl;
    }
}
void orderItem::operator--()
{
    if((quantity-1) <= st.getQuantity())
    {
        quantity--;
    }
    else
    {
        cout << "The Quantity is Not Available " << endl;
    }
}
void orderItem::operator+=(int n)
{
    cout << "Enter the Extra Amount : ";
    cin >> n;
    if((quantity+n) <= st.getQuantity())
    {
        quantity+=n;
    }
    else
    {
        cout<<"The Quantity is Not Available"<<endl;
    }
}
void orderItem::operator-=(int n)
{
    cout << "Enter the Missing Amount : ";
    cin >> n;
    if((quantity-n) <= st.getQuantity())
    {
        quantity-=n;
    }
    else
    {
        cout<<"The Quantity is Not Available"<<endl;
    }
}
string orderItem::print()
{
    return pro.print() + "\nSale Price : " + to_string(salePrice) +
           "\nQuantity : " + to_string(quantity);
}
orderItem::~orderItem()
{
    //dtor
}
