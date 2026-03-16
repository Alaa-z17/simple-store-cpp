#include<iostream>
using namespace std;

enum enCategory { Food = 1, Electronics = 2, Clothing = 3 };

struct stProduct
{
    unsigned short ID = 0;
    string Name = "";
    double Price = 0.0;
    unsigned short Stock = 0;
    enCategory Category =enCategory::Food;
};

struct stCartItem
{
    stProduct Product;
    unsigned short Quantity = 0;
    double TotalPrice = 0.0;
};

struct stInvoice
{
    stCartItem Items[100];
    unsigned short NumberOfItems = 0;
    double SubTotal = 0.0;
    float Discount = 0.0;
    double Total = 0.0;
};
stProduct CreateProduct(unsigned short ID, string Name,
    double Price, unsigned short Stock, enCategory Category)
{
    stProduct Product;
    Product.ID = ID;
    Product.Name = Name;
    Product.Price = Price;
    Product.Stock = Stock;
    Product.Category = Category;
    return Product;
}

string GetCategoryName(enCategory Category)
{
    string arrCategories[3] = { "Food", "Electronics", "Clothing" };
    return arrCategories[Category - 1];
}

void LoadProductList(stProduct arrProducts[], unsigned short& ProductCount)
{
    arrProducts[0] = CreateProduct(1, "Apple", 1.5, 100, enCategory::Food);
    arrProducts[1] = CreateProduct(2, "Banana", 0.75, 150, enCategory::Food);
    arrProducts[2] = CreateProduct(3, "Laptop", 999, 10, enCategory::Electronics);
    arrProducts[3] = CreateProduct(4, "Phone", 499, 20, enCategory::Electronics);
    arrProducts[4] = CreateProduct(5, "T-Shirt", 19.99, 50, enCategory::Clothing);
    arrProducts[5] = CreateProduct(6, "Jeans", 49.99, 30, enCategory::Clothing);
    ProductCount = 6;
}

void PrintProductList(stProduct arrProducts[], unsigned short ProductCount)
{
    cout << "\n_________________________________\n";
    cout << "        Product List\n";
    cout << "_________________________________\n";
    cout << "ID  Name          Price   Stock   Category\n";
    cout << "_________________________________\n";
    for (unsigned short i = 0; i < ProductCount; i++)
    {
        cout << arrProducts[i].ID << "   ";
        cout << arrProducts[i].Name << "\t\t";
        cout << arrProducts[i].Price << "\t";
        cout << arrProducts[i].Stock << "\t";
        cout << GetCategoryName(arrProducts[i].Category) << endl;
    }
    cout << "_________________________________\n";
}
stProduct FindProductByID(unsigned short ID,
    stProduct arrProducts[], unsigned short ProductCount)
{
    for (unsigned short i = 0; i < ProductCount; i++)
    {
        if (arrProducts[i].ID == ID)
            return arrProducts[i];
    }
    stProduct EmptyProduct;
    return EmptyProduct;
}

bool IsProductExist(unsigned short ID,
    stProduct arrProducts[], unsigned short ProductCount)
{
    for (unsigned short i = 0; i < ProductCount; i++)
    {
        if (arrProducts[i].ID == ID)
            return true;
    }
    return false;
}

unsigned short ReadProductID(stProduct arrProducts[],
    unsigned short ProductCount)
{
    unsigned short ID = 0;
    do
    {
        cout << "Enter Product ID: ";
        cin >> ID;
    } while (!IsProductExist(ID, arrProducts, ProductCount));
    return ID;
}

unsigned short ReadProductQuantity(stProduct Product)
{
    unsigned short Quantity = 0;
    do
    {
        cout << "Enter Quantity (Available: " << Product.Stock << "): ";
        cin >> Quantity;
    } while (Quantity < 1 || Quantity > Product.Stock);
    return Quantity;
}

void AddItemToCart(stInvoice& Invoice, stProduct arrProducts[],
    unsigned short ProductCount)
{
    stCartItem CartItem;
    CartItem.Product = FindProductByID(ReadProductID(arrProducts, ProductCount),arrProducts, ProductCount);
    CartItem.Quantity = ReadProductQuantity(CartItem.Product);
    CartItem.TotalPrice = CartItem.Product.Price * CartItem.Quantity;
    Invoice.Items[Invoice.NumberOfItems] = CartItem;
    Invoice.NumberOfItems++;
    Invoice.SubTotal += CartItem.TotalPrice;
}

void PrintCart(stInvoice Invoice)
{
    cout << "\n_________________________________\n";
    cout << "           Your Cart\n";
    cout << "_________________________________\n";
    for (unsigned short i = 0; i < Invoice.NumberOfItems; i++)
    {
        cout << Invoice.Items[i].Product.Name << "\t";
        cout << "x" << Invoice.Items[i].Quantity << "\t";
        cout << "$" << Invoice.Items[i].TotalPrice << endl;
    }
    cout << "_________________________________\n";
    cout << "SubTotal: $" << Invoice.SubTotal << endl;
}
int main()
{
    return 0;
}