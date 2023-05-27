#ifndef SHOP_PRODUCT_H
#define SHOP_PRODUCT_H

#include <string>

using namespace std;

class Product {
private:
    string _title;
    double _price;

public:
    Product(string title, double price) {
        _title = title;
        _price = price;
    }

    string GetTitle() {
        return _title;
    }

    double GetPrice() {
        return _price;
    }
};


#endif //SHOP_PRODUCT_H
