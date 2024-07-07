#include "Product.h"

Product::Product()
{
    productID = 0;
    productType = 0;
    productName = " ";
    productNumber = " ";
    productPrice = 0.0;
}
Product::Product(int pr_id,int pr_ty,string pr_nu,string pr_na,double pr_pr)
{
    productID = pr_id;
    productType = pr_ty;
    productName = pr_na;
    productNumber = pr_nu;
    productPrice = pr_pr;
}
void Product::getData()
{
    cout << "Enter Product ID : ";
    cin >> productID;
    cin.ignore();
    cout << "Enter Product Name : ";
    getline(cin,productName);
    cout << "Enter Product Number : ";
    getline(cin,productNumber);
    cout << "Enter Product Price : ";
    cin >> productPrice;
    cout << "Enter Product Type : ";
    cin >> productType;
}
void Product::updateProduct()
{
    cout << "Enter new Product ID : ";
    cin >> productID;
    cout<<"Enter new Product Name : ";
    cin>>productName;
    cout<<"Enter new ProductNumber : ";
    cin>>productNumber;
    cout<<"Enter new Product Price : ";
    cin>>productPrice;
    cout<<"Enter new Product Type : ";
    cin>>productType;
}
istream&operator >>(istream&in,Product&p)
{
    cout << "Enter Product ID : ";
    in >> p.productID;
    in.ignore();
    cout << "Enter Product Name : ";
    getline(in,p.productName);
    cout << "Enter Product Number : ";
    getline(in,p.productNumber);
    cout << "Enter Product Price : ";
    in >> p.productPrice;
    cout << "Enter Product Type : ";
    in >> p.productType;
    return in;

}
string Product::print()
{
    return "Product ID : " + to_string(productID) +
    "\nProduct Name : " + productName +
    "\nProduct Number : " + productNumber +
    "\nProduct Price : " + to_string(productPrice) +
    "\nProduct Type : " + to_string(productType);
}
ostream&operator <<(ostream&out,Product&p)
{
    out << "Product ID : " << p.productID << endl
    << "Product Name : " << p.productName << endl
    << "Product Number : " << p.productNumber << endl
    << "Product Price : " << p.productPrice << endl
    << "Product Type : " << p.productType << endl;
    return out;
}
Product::~Product()
{
    //dtor
}
