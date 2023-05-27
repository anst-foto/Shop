#include <iostream>

#include "Order.h"
#include "Warehouse.h"

#include "ConsoleHelper.h"

using namespace std;

int main() {
    Warehouse* warehouse = new Warehouse();
    warehouse->Add(new Product("Prod 1", 10), 10);
    warehouse->Add(new Product("Prod 2", 50), 1);
    warehouse->Add(new Product("Prod 3", 5), 2);
    warehouse->Add(new Product("Prod 4", 100), 100);

    Order* order = new Order();

    do {
        cout << "*** PRODUCTS ***" << endl;
        PrintItems(warehouse->GetAll());

        int input;
        cin >> input;

        if (input == 0) {
            break;
        }

        int amount;
        cout << "Enter amount : ";
        cin >> amount;

        auto product = warehouse->GetById(input);
        order->Add(product, amount);
        warehouse->SubAmount(product, amount);
    } while (true);

    cout << endl << endl;

    cout << "=== ORDER ===" << endl;
    PrintItems(order->GetAll());

    return 0;
}
