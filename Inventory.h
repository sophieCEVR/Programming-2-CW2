/* 
 * File:   Inventory.h
 * Author: 100021268
 *
 * Created on 15 March 2018, 14:18
 */



#ifndef INVENTORY_H
#define INVENTORY_H
#include <string>
#include <cstdlib>
#include <list>
#include <iostream>
#include "StockItem.h"

class Inventory {
public:
    list<StockItem*> InventoryList;

    virtual void add(StockItem*stockitem);
    virtual void toString();
    virtual void sortByUnitPriceAsc();
    virtual void largestStock();
    virtual void NPNTransistorCheck();
    virtual void totalResistance();
    virtual void unitPricesAbove(int price);
    
    Inventory();
    
    Inventory(const Inventory& orig);
   
    virtual ~Inventory();

private:

};

#endif /* INVENTORY_H */