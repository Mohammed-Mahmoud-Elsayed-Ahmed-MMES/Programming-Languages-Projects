#include <iostream>         // cin, cout
#include <cstdlib>          // cls
#include <windows.h>        // Sleep
#include <cstring>          // string, to_string
#include <bits/stdc++.h>    // stringstream
#include <windows.h>        // SetConsoleTextAttribute
#include <fstream>
#include <cmath>

#include "Customers.h"
#include "Product.h"
#include "Stock.h"
#include "Order.h"
#include "Transaction.h"
#include "Payment.h"

using namespace std;

Customers cu(100);
Stock st;
Payment py;

//CUSTOMERS DATA
int m_customer_count = 0;
int m_customer_size = 5;
Customers* m_customerList = new Customers [m_customer_size];

//PRODUCT DATA
int m_product_count = 0;
int m_product_size = 5;
Product* m_productList = new Product [m_product_size];

//STOCK DATA
int m_stock_count = 0;
int m_stock_size = 5;
Stock* m_stockList = new Stock [m_product_size];

//OREDER DATA
int static order_count = 0;
int order_size = 5;
Order* orderList = new Order[order_size];

//TRANSACTION DATA
int static transaction_count = 0;
int transaction_size = 5;
Transaction* transactionList = new Transaction[transaction_size];

HANDLE cout_handle = GetStdHandle(STD_OUTPUT_HANDLE);

/** ASSISTANT INLINE FUNCTIONS **/
inline void wait_or_clear(unsigned int sec, bool clear_screen = false)
{
    Sleep(sec*1000);
    if (clear_screen) system("cls");
}

inline void printline(string msg, bool end_line = true, int color_code=15)
{
    SetConsoleTextAttribute(cout_handle, color_code);
    cout <<  msg << (end_line?"\n":"\t");
}

inline void print_try_again()
{
    printline("\n\n\n\aInvalid Choice Try Again!!!!!!!!",1,4);
    wait_or_clear(3, 1);
}

/** MAIN PRINT MENU FUNCTION **/
int get_menu_choise(string menu, int level = 0)
{
    stringstream X(menu);
    string line, padding;
    int i = 1;
    for(int p=0; p<level+1; ++p)
        padding +="\t";

    while (getline(X, line, ','))
        printline(padding + to_string(i++) + ". " + line,1,level+11);

    printline(level?padding+"0. RETURN BACK":padding+"0. EXIT APP",1,5);
    int c;
    printline("ENTER YOUR CHOICE :",false,2);
    cin >> c;
    return c;
}

/** DATA ENTRY AND SUB MENU **/
void sub_sub_menu_1_product()
{
    int c = -1;
    while (c!=0)
    {
        wait_or_clear(0, 1);
        printline("\n\nMAIN MENU -> DATA ENTRY -> PRODCUTS ....");
        c = get_menu_choise("ADD,EDIT,DELELE",2);
        switch(c)
        {
        case 1:
        {
            printline("Do it here ADD NEW PRODUCT");
            int n;
            cout << "\tEnter how many Products you want to ADD???? " ;
            cin >> n;
            for(int i = 0; i < n; ++i)
            {
                cout << (i+1) << " : " << endl;
                if(m_product_count < m_product_size)
                {
                    cin >> m_productList[m_product_count++];//
                }
                else
                {
                    cout << "No more room for Products! \n";
                }
            }
            system("pause");
            break;
        }
        case 2:

        {
            printline("Do it here EDIT PRODUCT BY ID");
            int product_id=0;
            cout << "Enter Product ID to Edit : ";
            cin >> product_id;
            if (m_product_count == 0)
            {
                cout<<"NO PRODUCT EXIST~!\n";
                return;
            }
            bool updated = false;
            for (int i=0; i< m_product_count; ++i)
            {
                if (m_productList [i] .getProductID() == product_id )
                {
                    m_productList[i].updateProduct();
                    updated = true;
                    break;
                }
            }
            if (updated)
            {
                cout<<"PRODUCT UPDATED SUCESSFULLY! \n";
            }
            else
            {
                cout <<"NO PRODUCT EXIST\n";
            }
            system("pause");
            break;
        }

        case 3:
        {
            printline("Do it here DELETE PRODUCT BY ID");
            int product_id = 0;
            cout << "Enter Product ID to Delete : ";
            cin >> product_id;
            /*m_stockList->DeletProduct(int product_id);
            int product_id=0;
            cout << "Enter Product ID to Update: ";
            cin >> product_id;*/
            if (m_product_count == 0)
            {
                cout<<"NO PRODUCT EXIST~!\n";
                return;
            }
            bool deleted = false;
            for (int i=0; i< m_product_count; ++i)
            {
                if (m_productList [i] .getProductID() == product_id )
                {
                    if (i == m_product_count-1)
                    {
                        m_product_count--;
                    }
                    else
                    {
                        //replace deleted with last product
                        m_productList [i]= m_productList [m_product_count-1];
                        m_product_count--;
                    }
                    deleted = true;
                    break;
                }
            }
            if (deleted)
            {
                cout<<"PRODUCT DELETED SUCESSFULLY! \n";
            }
            else
            {
                cout <<"NO PRODUCT EXIST\n";
            }
            system("pause");
            break;
        }
        case 0:
            return;
        default:
            print_try_again();
        }
    }
}

void sub_sub_menu_1_customer()
{
    int c = -1;
    while (c!=0)
    {
        wait_or_clear(0, 1);
        printline("\n\nMAIN MENU -> DATA ENTRY -> CUSTOMERS ....");
        c = get_menu_choise("ADD,EDIT,DELELE",2);
        switch(c)
        {
        case 1:
            printline("Do it here ADD NEW CUSTOMER");
            int n;
            cout << "\tEnter how many customers you want to ADD???? " ;
            cin >> n;
            for(int i = 0; i < n; ++i)
            {
                cout << (i+1) << " : " << endl;
                cin >> m_customerList[m_customer_count++];
                //cu.addCustomer();
            }
            system("pause");
            break;
        case 2:
        {
            printline("Do it here EDIT CUSTOMER BY ID");
            int customer_id=0;
            cout << "Enter Customer ID to Edit: ";
            cin >> customer_id;
            m_customerList->updateCustomer(customer_id);
            //cu.updateCustomer(customer_id);
            system("pause");
            break;
        }
        case 3:
        {
            printline("Do it here DELETE CUSTOMER BY ID");
            int customer_id = 0;
            cout << "Enter Customer ID to delete: ";
            cin >> customer_id;
            m_customerList->deletCustomer(customer_id);
            system("pause");
            break;
        }
        case 0:
            return;
        default:
            print_try_again();
        }
    }
}

void sub_sub_menu_1_stock()
{
    int c = -1;
    while (c!=0)
    {
        wait_or_clear(0, 1);
        printline("\n\nMAIN MENU -> DATA ENTRY -> STOCK ....");
        c = get_menu_choise("ADD PRODUCT,UPDATE QUANTITY BY ID,CLEAR STOCK",2);
        switch(c)
        {
        case 1:
            printline("Do it here ADD PRODUCT TO STOCK BY ID");
            int n;
            cout << "\tEnter how many PRODUCT you want to ADD???? " ;
            cin >> n;
            for(int i = 0; i < n; ++i)
            {
                cout << (i+1) << " : " << endl;
                int product_id = 0;
                cout << "Enter Product ID to Add : ";
                cin >> product_id;
                if (m_product_count == 0)
                {
                    cout<<"NO PRODUCT EXIST~!\n";
                    return;
                }

                for (int i=0; i< m_product_count; ++i)
                {
                    if (m_productList [i] .getProductID() == product_id )
                    {
                        cout << m_productList[i];
                        break;
                    }
                }
                cin >> m_stockList[m_stock_count++];
            }
            system("pause");
            break;
        case 2:
        {
            printline("Do it here UPDATE PRODUCT QUANTITY BY ID");
            bool isUpdated = false;
            int stock_id = 0;
            cout << "Enter Stock ID to Search For It : ";
            cin >> stock_id;
            int product_id = 0;
            for(int i = 0; i < m_stock_count; i++)
            {
                if(m_stockList[i].getStockID() == stock_id)
                {
                    cout << "Enter Product ID to Update : ";
                    cin >> product_id;
                    m_stockList[i].updateStock(product_id);
                    isUpdated = true;
                }
            }
            if(isUpdated)
            {
                cout << "PRODUCT UPDATED SUCCESSFULY IN STOCK \n";
            }
            else
            {
                cout << "PRODUCT DIDN'T UPDATED SUCCESSFULY IN STOCK \n";
            }
            //st.updateStock(product_id);                       //1
            //int quantity = 0;
            /*for(int i = 0; i < m_stock_count; ++i)
            {
                cout << (i+1) << " : " << endl;
                m_stockList[i].updateStock(product_id);*/          //2

            /*cout << "Enter New Quantity : ";
            cin >> quantity;
            m_stockList[i].setQuantity(quantity);*/
            //}

            /*int quantity = 0;
            cout << "Enter New Quantity : ";
            cin >> quantity;
            st.setQuantity(quantity);*/
            system("pause");
            break;
        }
        case 3:
        {
            printline("Do it here CLEAR STOCK");
            bool isFounded = false;
            int stock_id = 0;
            cout << "Enter Stock ID to Search For It : ";
            cin >> stock_id;
            int product_id = 0;
            for(int i = 0; i < m_stock_count; i++)
            {
                if(m_stockList[i].getStockID() == stock_id)
                {
                    cout << "Enter Product ID to Clear : ";
                    cin >> product_id;
                    m_stockList[i].DeletProduct(product_id);
                    isFounded = true;
                }
            }
            if(isFounded)
            {
                cout << "PRODUCT DELETED SUCCESSFULY FROM STOCK \n";
            }
            else
            {
                cout << "PRODUCT DIDN'T DELETED SUCCESSFULY FROM STOCK \n";
            }
            system("pause");
            break;
        }
        case 0:
            return;
        default:
            print_try_again();
        }
    }
}

void sub_menu_1_data_entry()
{
    int c = -1;
    while (c!=0)
    {
        wait_or_clear(0, 1);
        printline("\n\nMAIN MENU -> DATA ENTRY ....");
        c = get_menu_choise("PRODUCT,CUSTOMER,STOCK",1);
        switch(c)
        {
        case 1:
            sub_sub_menu_1_product();
            break;
        case 2:
            sub_sub_menu_1_customer();
            break;
        case 3:
            sub_sub_menu_1_stock();
            break;
        case 0:
            return;
        default:
            print_try_again();
        }
    }
}

/** SALSES AND SUB MENU **/

void sub_sub_menu_2_order()
{
    int c = -1;
    while (c!=0)
    {
        wait_or_clear(0, 1);
        printline("\n\nMAIN MENU -> SALES PROCESS -> ORDERS....");
        c = get_menu_choise("ADD NEW,UPDATE,DELETE",2);
        switch(c)
        {
        case 1:
        {
            printline("Do it here 1 ADD NEW ORDER");
            int n;
            cout << "Enter how many Orders you want to ADD???? " ;
            cin >> n;
            for(int i = 0; i < n; ++i)
            {
                cout << (i+1) << " : " << endl;
                if(order_count < order_size)
                {
                    int customer_id=0;
                    cout << "Enter Customer ID to ADD IT'S DATA to the ORDER : ";
                    cin >> customer_id;
                    if(m_customerList[i].searchForCustomer(customer_id))
                    {
                        cout << m_customerList[i];
                        cin >> orderList[order_count++];         //1
                    }
                }
                else
                {
                    cout << "No more room for Products! \n";
                }
            }
            system("pause");
            break;
        }
        case 2:
        {
            printline("Do it here 2 UPADTE ORDER BY ID");
            int order_id = 0;
            cout << "Enter Order ID to Update : ";
            cin >> order_id;
            if (order_count == 0)
            {
                cout<<"NO ORDER EXIST~!\n";
                return;
            }
            bool updated = false;
            for (int i = 0; i< order_count; ++i)
            {
                if (orderList [i] .getOrderID() == order_id )
                {
                    int status = 0;
                    cout << "Enter Status : ";
                    cin >> status;
                    orderList[i].updateOrder(order_id,status);
                    updated = true;
                    break;
                }
            }
            if (updated)
            {
                cout << "\tORDER UPDATED SUCCEFULY\n";
            }
            else
            {
                cout <<"NO ORDER EXIST\n";
            }
            system("pause");
            break;
        }
        case 3:
        {
            printline("Do it here 3 DELETE ORDER BY ID");
            int order_id = 0;
            cout << "Enter Order ID to Update : ";
            cin >> order_id;
            if (order_count== 0)
            {
                cout<<"NO ORDER EXIST~!\n";
                return;
            }
            bool deleted = false;
            for (int i=0; i< order_count; ++i)
            {
                if (orderList [i] .getOrderID() == order_id )
                {
                    if (i == order_count-1)
                    {
                        order_count--;
                    }
                    else
                    {
                        //replace deleted with last product
                        orderList[i]= orderList[order_count-1];
                        order_count--;
                    }
                    deleted = true;
                    break;
                }
            }
            if (deleted)
            {
                cout<<"\tORDER DELETED SUCESSFULLY! \n";
            }
            else
            {
                cout <<"\tNO ORDER EXIST\n";
            }
            system("pause");
            break;
        }
        case 0:
            return;
        default:
            print_try_again();
        }
    }
}

void sub_sub_menu_2_transaction()
{
    int c = -1;
    while (c!=0)
    {
        wait_or_clear(0, 1);
        printline("\n\nMAIN MENU -> SALES PROCESS -> TRANSACTIONS ....");
        c = get_menu_choise("ADD NEW,UPDATE,DELETE",2);
        switch(c)
        {
        case 1:
        {
            printline("Do it here 1 ADD NEW TRANSACTION");
            int n;
            cout << "Enter how many Transactions you want to ADD???? " ;
            cin >> n;
            for(int i = 0; i < n; ++i)
            {
                cout << (i+1) << " : " << endl;
                int a;
                cout << "Enter how many Orders you want to ADD to a Single Transaction???? " ;
                cin >> a;
                for(int i = 0; i < a; ++i)
                {
                    int order_id = 0;
                    cout << "Enter Order ID to Put into Transaction : ";
                    cin >> order_id;
                    if (order_count== 0)
                    {
                        cout<<"NO ORDER EXIST~!,PLEASE ENTER ORDER IN ORDER LIST AND TRY AGAIN!!\n";
                        return;
                    }
                    bool updated = false;
                    for (int i=0; i< order_count; ++i)
                    {
                        if (orderList [i] .getOrderID() == order_id )
                        {
                            cout << orderList[i];
                            updated = true;
                            break;
                        }
                    }
                }
                if(transaction_count < transaction_size)
                {
                    transactionList[transaction_count++].getData();//
                }
                else
                {
                    cout << "No more room for Transactions! \n";
                }
                system("pause");
                break;
            }
            case 2:
            {
                printline("Do it here 2 UPADTE TRANSACTION BY ID");
                int order_id = 0;
                cout << "Enter Order ID to Update : ";
                cin >> order_id;
                if (transaction_count == 0)
                {
                    cout<<"NO TRANSACTION EXIST~!\n";
                    return;
                }
                bool updated = false;
                for (int i=0; i< transaction_count; ++i)
                {
                    if (transactionList [i] .getOrderID() == order_id )
                    {
                        transactionList[i].updateTransaction(order_id);
                        updated = true;
                        break;
                    }
                }
                if (updated)
                {
                    cout<<"TRANSACTION UPDATED SUCESSFULLY! \n";
                }
                else
                {
                    cout <<"NO TRANSACTION EXIST\n";
                }
                system("pause");
                break;
            }
            case 3:
            {
                printline("Do it here 2 DELETE TRANSACTION BY ID");
                int order_id = 0;
                cout << "Enter Order ID to Update : ";
                cin >> order_id;
                if (transaction_count == 0)
                {
                    cout<<"NO TRANSACTION EXIST~!\n";
                    return;
                }
                bool deleted = false;
                for (int i=0; i< transaction_count; ++i)
                {
                    if (transactionList [i] .getOrderID() == order_id )
                    {
                        if (i == transaction_count-1)
                        {
                            transaction_count--;
                        }
                        else
                        {
                            //replace deleted with last Transaction
                            transactionList[i]= transactionList[transaction_count-1];
                            transaction_count--;
                        }
                        deleted = true;
                        break;
                    }
                }
                if (deleted)
                {
                    cout<<"TRANSACTION DELETED SUCESSFULLY! \n";
                }
                else
                {
                    cout <<"NO TRANSACTION EXIST\n";
                }
                system("pause");
                break;
            }
            case 0:
                return;
            default:
                print_try_again();
            }
        }
    }
}
void sub_menu_2_sales_process()
{
    int c = -1;
    while (c!=0)
    {
        wait_or_clear(0, 1);
        printline("\n\nMAIN MENU -> SALES PROCESS ....");
        c = get_menu_choise("ORDER,TRANSCATION",1);
        switch(c)
        {
        case 1:
            sub_sub_menu_2_order();
            break;
        case 2:
            sub_sub_menu_2_transaction();
            break;
        case 0:
            return;
        default:
            print_try_again();
        }
    }
}


/** PRINTS AND SUB MENU **/


void sub_menu_3_prints()
{
    int c = -1;
    while (c!=0)
    {
        wait_or_clear(0, 1);
        printline("\n\nMAIN MENU -> PRINTS ....");
        c = get_menu_choise("PRODUCT,STOCK,CUSTOMER,ORDERS,TRANSACTIONS,PROFIT",1);
        switch(c)
        {
        case 1:
        {
            printline("Do it here 1 PRINT PRODUCTS");
            cout << "**********PROJECT LIST**********" << endl;
            for (int i = 0 ; i < m_product_count; ++i)
            {
                cout << (i+1) << " : " ;
                ofstream myfile;
                myfile.open ("PRODUCTS.txt",ios::app);
                cout << m_productList[i] << endl;
                myfile << m_productList[i] << endl;
                cout << endl;
                myfile.close();
            }
            ifstream myFile;
            myFile.open("PRODUCTS.txt",ios::in);
            if (myFile.is_open())
            {
                string line;
                while(getline(myFile,line))
                {
                    cout << line << endl;
                }
                myFile.close();
            }
            system("pause");
            break;
        }
        case 2:
        {
            printline("Do it here 2 PRINT STOCK");
            cout << "**********STOCK LIST**********" << endl;
            for (int i = 0 ; i < m_stock_count; ++i)
            {
                ofstream myfile;
                myfile.open ("CUSTOMERS.txt",ios::app);
                myfile << m_stockList[i] << "\n";
                cout << m_stockList[i];
                cout << endl;
                myfile.close();

            }
            ifstream myFile;
            myFile.open("STOCKS.txt",ios::in);
            if (myFile.is_open())
            {
                string line;
                while(getline(myFile,line))
                {
                    cout << line << endl;
                }
                myFile.close();
            }
            system("pause");
            break;
        }
        case 3:
        {
            printline("Do it here 3 PRINT CUSTOMERS");
            for (int i = 0 ; i < m_customer_count; ++i)
            {
                cout << (i+1) << " : " ;
                cout << m_customerList[i] << "\n";

            }
            /*for (int i = 0 ; i < m_customer_count; ++i)
            {
                ofstream myfile;
                myfile.open ("CUSTOMERS.txt",ios::app);
                myfile << m_customerList[i] << "\n";
                cout << endl;
                myfile.close();
            }*/
            ifstream myFile;
            myFile.open("CUSTOMERS.txt",ios::in);
            if (myFile.is_open())
            {
                string line;
                while(getline(myFile,line))
                {
                    cout << line << endl;
                }
                myFile.close();
            }
            system("pause");
            break;
        }
        case 4:
        {
            printline("Do it here 4 PRINT ORDERS");
            cout << "**********ORDER LIST**********" << endl;
            for (int i = 0 ; i < order_count; ++i)
            {
                cout << (i+1) << " : " ;
                ofstream myfile;
                myfile.open ("ORDERS.txt",ios::app);
                cout << orderList[i] << "\n";
                myfile << orderList[i] << "\n";
                myfile.close();
                cout << endl;
            }
            /*ifstream myFile;
            myFile.open("ORDERS.txt",ios::in);
            if (myFile.is_open())
            {
                string line;
                while(getline(myFile,line))
                {
                    cout << line << endl;
                }
                myFile.close();
            }*/
            system("pause");
            break;
        }
        case 5:
        {
            printline("Do it here 5 PRINT TRANSACTIONS");
            cout << "**********TRANSACTION LIST**********" << endl;
            for (int i = 0 ; i < transaction_count; ++i)
            {
                cout << (i+1) << " : " ;
                ofstream myfile;
                myfile.open ("TRANSACTIONS.txt",ios::app);
                myfile << orderList[i] << "\n";
                cout << orderList[i] << "\n";
                myfile << transactionList[i] << "\n";
                cout << transactionList[i] << "\n";
                myfile.close();
            }
            ifstream myFile;
            myFile.open("TRANSACTIONS.txt",ios::in);
            if (myFile.is_open())
            {
                string line;
                while(getline(myFile,line))
                {
                    cout << line << endl;
                }
                myFile.close();
            }
            system("pause");
            break;
        }
        case 6:
        {
            printline("Do it here 6 CALC PROFIT");
            py.print();
            for (int i = 0 ; i < transaction_count; ++i)
            {
                cout << (i+1) << " : " ;
                ofstream myfile;
                myfile.open ("PROFIT.txt",ios::app);
                double profit = py.pay()-(m_productList[i].getProductPrice()*orderList[i].orderList[i].getSalePrice());
                cout << "Profit : " << profit << endl;
                myfile << "Profit : " << profit << endl;
                myfile.close();
            }
            ifstream myFile;
            myFile.open("PROFIT.txt",ios::in);
            if (myFile.is_open())
            {
                string line;
                while(getline(myFile,line))
                {
                    cout << line << endl;
                }
                myFile.close();
            }
            //Function Of Profit = pay-(product price*sale price)
            system("pause");
            break;
        }
        case 0:
            return;
        default:
            print_try_again();
        }
    }
}

/** MAIN FUNCTION **/
int main()
{
    printline("START APPLICATION ....",1,6);
    wait_or_clear(1,1);
    int c = -1;
    while (c!=0)
    {
        wait_or_clear(0,1);
        printline("\n\nMAIN MENU ....",1,10);
        c = get_menu_choise("DATA ENTRY,SALES PROCESS,PRINTS",0);
        switch(c)
        {
        case 1:
            sub_menu_1_data_entry();
            break;
        case 2:
            sub_menu_2_sales_process();
            break;
        case 3:
            sub_menu_3_prints();
            break;
        case 0:
            printline("\n\n\a\t\t\tGoodbye :)......\n\n\n\n\n\n",1,112);
            break;
        default:
            print_try_again();
            wait_or_clear(3, true);
        }
    }
    return 0;
}
