#include "Project.h"

Project::Project()
{
    projectId = 0;
    location = " ";
    currentCost = 0.0;
    budget_size = 5;
    budget_count = 0;
    budgets = new Budget[budget_size];
}

Project::Project(int pr_id,int ma_id,string lo,string ma_na,string ma_ph,string ma_em,double cu,int bu_s)
{
    projectId = pr_id;
    managerId = ma_id;
    location = lo;
    managerName = ma_na;
    managerPhone = ma_ph;
    managerEmail = ma_em;
    currentCost = cu;
    budget_size = bu_s;
    budget_count = 0;
    budgets = new Budget[budget_size];
}

void Project::getData()
{
    cout << "Enter project ID : ";
    cin >> projectId;
    cout << "Enter location : ";
    cin.ignore();
    getline(cin,location);
    cout << "\t     Enter Manager Data \t" << endl;
    cout<<"Enter Manager id : ";
    cin>>managerId;
    cin.ignore();
    cout<<"Enter Manager name : ";
    getline(cin,managerName);
    cout<<"Enter Manager phone : ";
    getline(cin,managerPhone);
    cout<<"Enter Manager Email : ";
    getline(cin,managerEmail);
    cout<<endl;
    cout << "Enter current cost : ";
    cin >> currentCost;
    int n=0;
    cout<<"How many Budgets ?"<<endl;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int id;
        double value;
        cout << (i+1) << " : ";
        cout<<"Enter Budget id : ";
        cin>>id;
        cout<<"Enter Budget value : ";
        cin>>value;
        Budget* new_budget = new  Budget(id,value);
        budgets[budget_count++] = *new_budget;
    }

}
void Project::addBudget()
{
    bool a = false;

    Budget *new_budget = new Budget();
    new_budget->getData();
    budgets[budget_count++] = *new_budget;
    //bool added = 1;
}
void Project::getTotalBudget()
{
    if(budget_count==0)
    {
        cout<< "NO BUDGET FOUND!\n";
        return;
    }
    for(int i=0; i<budget_count;i++)
    {
        cout << (i+1) << " : ";
        budgets[i].print();
    }
}
void Project::print()
{
    cout << "Project ID : " << projectId << endl;
    cout << "Location : " << location << endl;
    cout << endl;
    cout << "Manager : " << endl;
    cout<<"Manager id : "<<managerId<<endl;
    cout<<"Manager Name : "<<managerName<<endl;
    cout<<"Manager Phone : "<<managerPhone<<endl;
    cout<<"Manager Email : "<<managerEmail<<endl;
    cout << endl;
    cout << "Current cost : " << currentCost << endl;
    getTotalBudget();
    cout << "cc " << budget_count << endl;
}
Project::~Project()
{
    delete []budgets;
}
