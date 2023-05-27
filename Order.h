#ifndef SHOP_ORDER_H
#define SHOP_ORDER_H

#include <vector>

#include "OrderItem.h"

using namespace std;

class Order {
private:
    vector<OrderItem*>* _items;

public:
    Order() {
        _items = new vector<OrderItem *>;
    }

    void Add(Product* product, int amount) {
        for (auto item : *_items) {
            if (item->GetProduct()->GetTitle() == product->GetTitle()) {
                return;
            }
        }

        _items->push_back(new OrderItem(product, amount));
    }

    void SetNewAmount(Product* product, int new_amount) {
        for (auto item : *_items) {
            if (item->GetProduct()->GetTitle() == product->GetTitle()) {
                item->SetAmount(new_amount);
                break;
            }
        }
    }

    void Del(Product* product) {
        for (auto i = _items->begin(); i < _items->end(); ++i) {
            if ((*i)->GetProduct()->GetTitle() == product->GetTitle()) {
                _items->erase(i);
                break;
            }
        }
    }

    void Clear() {
        _items->clear();
    }

    vector<OrderItem*> GetAll() {
        return *_items;
    }
};


#endif //SHOP_ORDER_H
