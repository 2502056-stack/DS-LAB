#include <iostream>
#include <string>
using namespace std;

// Node structure for each order
struct Order {
    string orderID;
    string customerName;
    string foodItem;
    Order* next;
};

// Food Delivery class
class FoodDelivery {
private:
    Order* head;

public:
    // Constructor
    FoodDelivery() {
        head = nullptr;
    }

    // 1. Add a new order at the end
    void addOrder(string orderID, string customerName, string foodItem) {

        Order* newOrder = new Order;

        newOrder->orderID = orderID;
        newOrder->customerName = customerName;
        newOrder->foodItem = foodItem;
        newOrder->next = nullptr;

        // If list is empty
        if (head == nullptr) {
            head = newOrder;
        }
        else {
            Order* temp = head;

            // Move to the last order
            while (temp->next != nullptr) {
                temp = temp->next;
            }

            temp->next = newOrder;
        }

        cout << "Order " << orderID << " added successfully.\n";
    }

    // 2. Display all pending orders
    void displayOrders() {

        if (head == nullptr) {
            cout << "No pending orders.\n";
            return;
        }

        Order* temp = head;

        cout << "\n===== Pending Orders =====\n";

        while (temp != nullptr) {

            cout << "Order ID: " << temp->orderID << endl;
            cout << "Customer Name: " << temp->customerName << endl;
            cout << "Food Item: " << temp->foodItem << endl;
            cout << "--------------------------\n";

            temp = temp->next;
        }
    }

    // 3. Search for an order using Order ID
    void searchOrder(string orderID) {

        Order* temp = head;

        while (temp != nullptr) {

            if (temp->orderID == orderID) {

                cout << "\nOrder found!\n";
                cout << "Order ID: " << temp->orderID << endl;
                cout << "Customer Name: " << temp->customerName << endl;
                cout << "Food Item: " << temp->foodItem << endl;

                return;
            }

            temp = temp->next;
        }

        cout << "Order " << orderID << " does not exist.\n";
    }

    // 4. Remove an order after it has been delivered
    void removeOrder(string orderID) {

        // If list is empty
        if (head == nullptr) {
            cout << "Order " << orderID << " does not exist.\n";
            return;
        }

        // If first order is being removed
        if (head->orderID == orderID) {

            Order* temp = head;

            head = head->next;

            delete temp;

            cout << "Order " << orderID << " delivered and removed.\n";

            return;
        }

        Order* temp = head;

        // Find the order
        while (temp->next != nullptr &&
               temp->next->orderID != orderID) {

            temp = temp->next;
        }

        // Order not found
        if (temp->next == nullptr) {

            cout << "Order " << orderID << " does not exist.\n";

            return;
        }

        // Remove the order
        Order* orderToDelete = temp->next;

        temp->next = orderToDelete->next;

        delete orderToDelete;

        cout << "Order " << orderID
             << " delivered and removed.\n";
    }

    // 5. Add an urgent order at the beginning
    void addUrgentOrder(string orderID,
                        string customerName,
                        string foodItem) {

        Order* newOrder = new Order;

        newOrder->orderID = orderID;
        newOrder->customerName = customerName;
        newOrder->foodItem = foodItem;

        // New order points to current first order
        newOrder->next = head;

        // New order becomes the first order
        head = newOrder;

        cout << "Urgent Order " << orderID
             << " received.\n";
    }

    // 6. Display updated pending-order list
    void displayOrderIDs() {

        if (head == nullptr) {
            cout << "No pending orders.\n";
            return;
        }

        Order* temp = head;

        cout << "\nPending Orders:\n";

        while (temp != nullptr) {

            cout << temp->orderID;

            if (temp->next != nullptr) {
                cout << " -> ";
            }

            temp = temp->next;
        }

        cout << endl;
    }

    // Destructor
    ~FoodDelivery() {

        Order* temp;

        while (head != nullptr) {

            temp = head;

            head = head->next;

            delete temp;
        }
    }
};


// Main function
int main() {

    FoodDelivery delivery;

    int choice;

    string orderID;
    string customerName;
    string foodItem;

    do {

        cout << "\n====================================\n";
        cout << "   ONLINE FOOD DELIVERY SYSTEM\n";
        cout << "====================================\n";

        cout << "1. Add New Order\n";
        cout << "2. Display All Pending Orders\n";
        cout << "3. Search Order\n";
        cout << "4. Remove Delivered Order\n";
        cout << "5. Add Urgent Order\n";
        cout << "6. Display Updated Order List\n";
        cout << "7. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {

            // Add normal order
            case 1:

                cout << "Enter Order ID: ";
                cin >> orderID;

                cout << "Enter Customer Name: ";
                getline(cin >> ws, customerName);

                cout << "Enter Food Item: ";
                getline(cin >> ws, foodItem);

                delivery.addOrder(
                    orderID,
                    customerName,
                    foodItem
                );

                break;


            // Display all orders
            case 2:

                delivery.displayOrders();

                break;


            // Search order
            case 3:

                cout << "Enter Order ID to search: ";
                cin >> orderID;

                delivery.searchOrder(orderID);

                break;


            // Remove delivered order
            case 4:

                cout << "Enter Order ID to remove: ";
                cin >> orderID;

                delivery.removeOrder(orderID);

                break;


            // Add urgent order
            case 5:

                cout << "Enter Urgent Order ID: ";
                cin >> orderID;

                cout << "Enter Customer Name: ";
                getline(cin >> ws, customerName);

                cout << "Enter Food Item: ";
                getline(cin >> ws, foodItem);

                delivery.addUrgentOrder(
                    orderID,
                    customerName,
                    foodItem
                );

                break;


            // Display updated list
            case 6:

                delivery.displayOrderIDs();

                break;


            // Exit
            case 7:

                cout << "Exiting program...\n";

                break;


            default:

                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 7);


    return 0;
}
