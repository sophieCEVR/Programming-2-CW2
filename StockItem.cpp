/* 
 * File:   StockItem.cpp
 * Author: 100021268
 * 
 * Created on 15 March 2018, 14:18
 */

#include "StockItem.h"
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

//StockItem super class methods (inherited by the subclasses) 
StockItem::StockItem(string type, string stockcode, int numberheld, int unitprice, string other){
    this->type        = type;
    this->stockcode   = stockcode;
    this->numberheld  = numberheld;
    this->unitprice   = unitprice;
    this->other       = other;
}
StockItem::StockItem(){

    this->type        = "";
    this->stockcode   = "";
    this->numberheld  = 0;
    this->unitprice   = 0;
    this->other       = "";
}

StockItem::StockItem(const StockItem& orig) {}

//output stream operator overloading allows for printing of StockItem type objects 
std::ostream& operator<<(std::ostream &os, const StockItem &s)
{
    os << s.type << ' ' << s.stockcode << ' ' << to_string(s.numberheld) << ' ' << to_string(s.unitprice) << ' ' << s.other;
    return os;
}

//input stream operator overloading, feed it a file and it creates the correct subclass of object with correctly seperated information.
istream& operator>> (istream& is, StockItem* s)  
{ 
    string numHeld = "";
    string unitPrice = "";
 
    getline(is,s->type, ',');
    getline(is,s->stockcode, ',');
    getline(is,numHeld, ',');
    
    s->numberheld = stoi(numHeld);
    
    if(s->type.compare("diode")==0){
        getline(is, unitPrice);
        s->unitprice = stoi(unitPrice);
        s = new Diode(s->type, s->stockcode, s->numberheld, s->unitprice, s->other);
    }
    else{
        getline(is,unitPrice, ',');
        s->unitprice = stoi(unitPrice);
        getline(is,s->other);
        s->other.pop_back();
        s->other.erase(0,1);
        if(s->type.compare("resistor")==0){
            s = new Resistor(s->type, s->stockcode, s->numberheld, s->unitprice, s->other);
        }
        else if(s->type.compare("capacitor")==0){
            s = new Capacitor(s->type, s->stockcode, s->numberheld, s->unitprice, s->other);
        }
        else if(s->type.compare("transistor")==0){
            s = new Transistor(s->type, s->stockcode, s->numberheld, s->unitprice, s->other);
        }
        else if(s->type.compare("IC")==0){
            s = new IC(s->type, s->stockcode, s->numberheld, s->unitprice, s->other);
        }
    }
    return is;
}  

StockItem::~StockItem(){};


//Resistor Type Sub-class
Resistor::Resistor(string type, string stockcode, int numberheld, int unitprice, string other) : StockItem(type, stockcode, numberheld, unitprice, other) {}
Resistor::Resistor(const StockItem& orig){}
Resistor::Resistor(){} 
Resistor::~Resistor(){};

//Diode Type Sub-class
Diode::Diode(string type, string stockcode, int numberheld, int unitprice, string other) : StockItem(type, stockcode, numberheld, unitprice, other) {}
Diode::Diode(const StockItem& orig){}
Diode::Diode(){}  
Diode::~Diode(){};

//Capacitor Type Sub-class
Capacitor::Capacitor(string type, string stockcode, int numberheld, int unitprice, string other) : StockItem(type, stockcode, numberheld, unitprice, other) {}
Capacitor::Capacitor(const StockItem& orig){}
Capacitor::Capacitor(){}
Capacitor::~Capacitor(){}

//Transistor Type Sub-class
Transistor::Transistor(string type, string stockcode, int numberheld, int unitprice, string other) : StockItem(type, stockcode, numberheld, unitprice, other) {}
Transistor::Transistor(const StockItem& orig){}
Transistor::Transistor(){}  
Transistor::~Transistor(){};

//IC Type Sub-class
IC::IC(string type, string stockcode, int numberheld, int unitprice, string other) : StockItem(type, stockcode, numberheld, unitprice, other) {}
IC::IC(const StockItem& orig){}
IC::IC(){}
IC::~IC(){};