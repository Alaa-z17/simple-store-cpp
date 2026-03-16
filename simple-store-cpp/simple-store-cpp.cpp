#include<iostream>
using namespace std;

enum enCategory { Food = 1, Electronics = 2, Clothing = 3 };

struct stProduct
{
    unsigned short ID = 0;
    string Name = "";
    float Price = 0;
    unsigned short Stock = 0;
    enCategory Category;
};

struct stCartItem
{
    stProduct Product;
    unsigned short Quantity = 0;
    float TotalPrice = 0;
};

struct stInvoice
{
    stCartItem Items[100];
    unsigned short NumberOfItems = 0;
    float SubTotal = 0;
    float Discount = 0;
    float Total = 0;
};

int main()
{
    return 0;
}