/* 
 * File:   StockItem.h
 * Author: 100021268
 *
 * Created on 15 March 2018, 14:18
 */

#ifndef STOCKITEM_H
#define STOCKITEM_H
#include <string>
#include <cstdlib>
using namespace std;

//StockItem Super class
class StockItem {
public:
    string type;
    string stockcode;
    int numberheld;
    int unitprice;
    string other;
    StockItem(string type, string stockcode, int numberheld, int unitprice, string other);
    StockItem(const StockItem& orig);
    StockItem();
 
    string getType()const 
    {
       return type;
    }
    
    string getStockcode() const
    {
       return stockcode;
    }
    
    int getNumberheld() const
    {
       return numberheld;
    }

    int getUnitprice() const
    {
       return unitprice;
    }    
        
    string getOther() const
    {
       return other;
    }
    friend std::ostream& operator<<(std::ostream &os, const StockItem &s);
    friend std::istream& operator>> (std::istream& is, StockItem* s);
    
    virtual ~StockItem();
};

std::ostream& operator<<(std::ostream &os, const StockItem &s);

//Resistor Type Sub-class
class Resistor :
    public StockItem
{
public:
    Resistor(string type, string stockcode, int numberheld, int unitprice, string other);
    Resistor(const StockItem& orig);
    Resistor();
    virtual ~Resistor();
};

//Diode Type Sub-class
class Diode :
    public StockItem
{
public:
    Diode(string type, string stockcode, int numberheld, int unitprice, string other);
    Diode(const StockItem& orig);
    Diode();   
    virtual ~Diode();
};

//Capacitor Type Sub-class
class Capacitor : 
    public StockItem
{
public:
    Capacitor(string type, string stockcode, int numberheld, int unitprice, string other);
    Capacitor(const StockItem& orig);
    Capacitor();   
    virtual ~Capacitor();
};

//Transistor Type Sub-class
class Transistor : 
    public StockItem
{
public:
    Transistor(string type, string stockcode, int numberheld, int unitprice, string other);
    Transistor(const StockItem& orig);
    Transistor();  
    virtual ~Transistor(); 
};

//IC Type Sub-class
class IC :
    public StockItem
{
public:
    IC(string type, string stockcode, int numberheld, int unitprice, string other);
    IC(const StockItem& orig);
    IC();   
    virtual ~IC();
};


std::ostream& operator<<(std::ostream &os, const StockItem &s);
#endif /* STOCKITEM_H */
