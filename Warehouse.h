#ifndef SHOP_WAREHOUSE_H
#define SHOP_WAREHOUSE_H

#include <vector>

#include "OrderItem.h"

using namespace std;

class Warehouse {
private:
    vector<OrderItem*>* _items;

public:
    Warehouse() {
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

    void Del(Product* product) {
        for (auto i = _items->begin(); i < _items->end(); ++i) {
            if ((*i)->GetProduct()->GetTitle() == product->GetTitle()) {
                _items->erase(i);
                break;
            }
        }
    }

    void SetNewAmount(Product* product, int new_amount) {
        if (new_amount <= 0) {
            Del(product);
        } else {
            for (auto item : *_items) {
                if (item->GetProduct()->GetTitle() == product->GetTitle()) {
                    item->SetAmount(new_amount);
                    break;
                }
            }
        }
    }

    void SubAmount(Product* product, int amount) {
        int old_amount;
        for (auto item : *_items) {
            if (item->GetProduct()->GetTitle() == product->GetTitle()) {
                old_amount = item->GetAmount();
                break;
            }
        }
        int new_amount = old_amount - amount;

        SetNewAmount(product, new_amount);
    }

    vector<OrderItem*> GetAll() {
        return *_items;
    }

    Product* GetById(int id) {
        if (id == 0) {
            return nullptr;
        } else {
            return _items->at(id - 1)->GetProduct();
        }
    }
};


#endif //SHOP_WAREHOUSE_H
