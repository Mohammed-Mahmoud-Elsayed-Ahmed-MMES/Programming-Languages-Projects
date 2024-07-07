#ifndef STOCK_H
#define STOCK_H

#include<iostream>
#include<string>
#include<cstring>
#include<ctime>
#include <Product.h>

using namespace std;

class Stock
{
    public:
        Stock();
        Stock(int st_id,int stCo,int pr_s,int pro_id,int qua);

        void getData();
        void addStock();
        void updateStock(int );
        void DeletProduct(int );

        void setStockID(int st_id){stockID = st_id;};
        int getStockID(){return stockID;};
        void setQuantity(int qua){quantity = qua;};
        int getQuantity();

        friend istream&operator >>(istream&in,Stock&s);
        friend ostream&operator <<(ostream&out,Stock&s);

        void print();
        virtual ~Stock();

    protected:

    private:
        int stockID,stockCount,stock_count,stock_size;
        int product_id,quantity,product_count,product_size;
        Product* productList;
        Stock* stockList;
};

#endif // STOCK_H
