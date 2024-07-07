#include "Stock.h"

Stock::Stock()
{
    product_id = 0;
    quantity = 0;
    product_count = 0;
    stockCount = 0;
    stock_count = 0;
    product_size = 5;
    productList = new Product [product_size];
}
Stock::Stock(int st_id,int stCo,int pr_s,int pro_id,int qua)
{
    product_id = pro_id;
    quantity = qua;
    product_count;
    stockCount = stCo;
    stock_count;
    product_size = pr_s;
    productList = new Product [product_size];
}
void Stock::getData()
{
    //Stock::addStock();
    cout << "Enter Product Quantity : ";
    cin >> quantity ;
}
void Stock::addStock()
{
    /*Stock *new_stock = new Stock();    //1
    new_stock->getData();
    stockList[stock_count++] = *new_stock;*/
    /*Product* new_product = new Product();          //2
    new_product->getData();
    productList[product_count++] = *new_product;*/
}
void Stock::updateStock(int product_id)
{
    if(product_count == 0)
    {
        cout<<"NO STOCK EXIST~!\n";
        return ;
    }
    bool updated = false;
    int quantity = 0;
    for(int i = 0; i < product_count; ++i)
    {
        if(productList[i].getProductID() == product_id)
        {
            productList[i].updateProduct();


            updated = true;
            if(updated)
            {
                cout << "Enter New Quantity : ";
                cin >> quantity;
                stockList[i].setQuantity(quantity);
            }
            break;
        }
    }
    if(updated)
    {
        cout<<"PRODUCT UPDATED SUCESSFULLY!\n";
    }
    else
    {
        cout<<"NO PRODUCT EXIST\n";
    }
}
void Stock::DeletProduct(int product_id)
{
    if(product_count == 0)
    {
        cout<<"NO PRODUCT EXIST~!\n";
        return ;
    }
    bool deleted = false;

    for(int i = 0; i < product_count ; ++i)
    {
        if(productList[i].getProductID() == product_id)
        {
            if(i == product_count-1)
            {
                product_count--;
            }
            else
            {
                productList[i]= productList[product_count-1];
                product_count--;
            }
            deleted = true;
            break;
        }
    }
    if(deleted)
    {
        cout<<"\tPRODUCT DELETED SUCESSFULLY!\n";
    }
    else
    {
        cout<<"\tNO PRODUCT EXIST\n";
    }
}
int Stock::getQuantity()
{
    return quantity;
}
istream&operator >>(istream&in,Stock&s)
{
    cout << "Enter Stock ID : ";
    in >> s.stockID;
    cout << "Enter Quantity : ";
    in >> s.quantity;
    return in;
}
void Stock::print()
{
    for(int i = 0; i < product_count; ++i)
    {
        cout << (i+1) << " : "<< productList[i].print() << endl;
    }
}
ostream&operator <<(ostream&out,Stock&s)
{
    s.print();
    out << "Stock ID : " << s.stockID << endl << "Quantity : " << s.quantity << endl;
    return out;
}

Stock::~Stock()
{
    delete [] productList;
}
