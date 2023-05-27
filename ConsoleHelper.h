#ifndef SHOP_CONSOLEHELPER_H
#define SHOP_CONSOLEHELPER_H

#include <iostream>
#include <vector>

#include "OrderItem.h"

using namespace std;

void PrintOrderItem(OrderItem* item) {
    cout << item->GetProduct()->GetTitle() << " : " << item->GetProduct()->GetPrice() << " -> " << item->GetAmount() << endl;
}

void PrintItems(vector<OrderItem*> items) {
    for (int i = 0; i < items.size(); ++i) {
        cout << i + 1 << " : ";
        PrintOrderItem(items[i]);
    }
}


#endif //SHOP_CONSOLEHELPER_H
