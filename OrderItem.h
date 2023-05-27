#ifndef SHOP_ORDERITEM_H
#define SHOP_ORDERITEM_H

#include "Product.h"

class OrderItem {
private:
    Product* _product;
    int _amount;

public:
    OrderItem(Product *product, int amount) : _product(product), _amount(amount) {}

    Product* GetProduct() {
        return _product;
    }

    int GetAmount() {
        return _amount;
    }

    void SetAmount(int amount) {
        if (amount < 0) {
            _amount = 0;
        } else {
            _amount = amount;
        }
    }
};


#endif //SHOP_ORDERITEM_H
