#ifndef PRODUCT_H
#define PRODUCT_H

#include<iostream>
#include<string>
#include<cstring>
#include<ctime>

using namespace std;

class Product
{
    public:
        Product();
        Product(int pr_id,int pr_ty,string pr_nu,string pr_na,double pr_pr);
        void getData();

        void setProductID(int pr_id){productID = pr_id;};
        int getProductID(){return productID;};
        void setPoductPrice(double pr_pr){productPrice = pr_pr;};
        double getProductPrice(){return productPrice;};
        void updateProduct();
        string print();

        friend istream&operator >>(istream&in,Product&p);
        friend ostream&operator <<(ostream&out,Product&p);
        virtual ~Product();

    protected:

    private:
        int productID,productType;
        string productNumber,productName;
        double productPrice;
};

#endif // PRODUCT_H
