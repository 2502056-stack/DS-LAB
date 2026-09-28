#include <iostream>
#include <string>
using namespace std;

class Product
{
private:
    string productID;
    Product* next;

public:
    Product(string id)
    {
        productID = id;
        next = NULL;
    }

    string getProductID()
    {
        return productID;
    }

    Product* getNext()
    {
        return next;
    }

    void setNext(Product* node)
    {
        next = node;
    }
};

class ShoppingCart
{
private:
    Product* head;

public:
    ShoppingCart()
    {
        head = NULL;
    }

    void addProduct(string productID)
    {
        Product* newProduct = new Product(productID);

        if (head == NULL)
        {
            head = newProduct;
            return;
        }

        Product* temp = head;

        while (temp->getNext() != NULL)
        {
            temp = temp->getNext();
        }

        temp->setNext(newProduct);
    }

    void displayCart()
    {
        if (head == NULL)
        {
            cout << "Shopping Cart is empty." << endl;
            return;
        }

        Product* temp = head;

        cout << "Shopping Cart: ";

        while (temp != NULL)
        {
            cout << temp->getProductID();

            if (temp->getNext() != NULL)
            {
                cout << " -> ";
            }

            temp = temp->getNext();
        }

        cout << endl;
    }

    void removeProduct(string productID)
    {
        if (head == NULL)
        {
            cout << "Shopping Cart is empty." << endl;
            return;
        }
        if (head->getProductID() == productID)
        {
            Product* temp = head;
            head = head->getNext();

            delete temp;

            cout << "Product " << productID
                 << " removed." << endl;

            return;
        }

        Product* current = head;
        while (current->getNext() != NULL &&
               current->getNext()->getProductID() != productID)
        {
            current = current->getNext();
        }

        if (current->getNext() == NULL)
        {
            cout << "Product " << productID
                 << " not found." << endl;
            return;
        }
        Product* temp = current->getNext();

        current->setNext(temp->getNext());

        delete temp;

        cout << "Product " << productID
             << " removed." << endl;
    }
};

int main()
{
    ShoppingCart cart;

    cart.addProduct("P101");
    cart.addProduct("P205");
    cart.addProduct("P310");
    cart.addProduct("P415");

    cart.displayCart();

    cout << "Remove Product: P310" << endl;

    cart.removeProduct("P310");

    cout << "Updated Cart:" << endl;
    cart.displayCart();

    return 0;
}

