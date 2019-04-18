#include <iostream>
#include <cstring>
#include "metal.h"
using namespace std;

metal_t::metal_t(){
  this->buy_price = 0;
  this->demand_quantity = 0;
  this->name = "undefined";
  this->symbol = "undefined";
}

float metal_t::get_buy_price() const{
  return this->buy_price;
}

float metal_t::get_demand_quantity()const{
  return this->demand_quantity;
}

string metal_t::get_name()const{
  return this->name;
}

string metal_t::get_symbol()const{
  return this->symbol;
}

void metal_t::handle_m() const{
  cout << * this << endl;
}

void metal_t::handle_mbp(float price) const{
  if (price == this->buy_price) {
    this->handle_m();
  }
}

void metal_t::handle_mbpge(float price) const{
  if (price <= this->buy_price) {
    this->handle_m();
  }
}

void metal_t::handle_mbpgt(float price) const{
  if (price < this->buy_price) {
    this->handle_m();
  }
}

void metal_t::handle_mbple(float price) const{
  if (price >= this->buy_price) {
    this->handle_m();
  }
}

void metal_t::handle_mbplt(float price) const{
  if (price > this->buy_price) {
    this->handle_m();
  }
}

void metal_t::handle_mdq(float qty) const{
  if (qty == this->demand_quantity) {
    this->handle_m();
  }
}

void metal_t::handle_mdqge(float qty) const{
  if (qty <= this->demand_quantity) {
    this->handle_m();
  }
}

void metal_t::handle_mdqgt(float qty) const{
  if (qty < this->demand_quantity) {
    this->handle_m();
  }
}

void metal_t::handle_mdqle(float qty) const{
  if (qty >= this->demand_quantity) {
    this->handle_m();
  }
}

void metal_t::handle_mdqlt(float qty) const{
  if (qty > this->demand_quantity) {
    this->handle_m();
  }
}

void metal_t::handle_mn(string name) const{
  if (this->name == name) {
    this->handle_m();
  }
}


void metal_t::handle_ms(string symbol) const{
  if (this->symbol == symbol) {
    this->handle_m();
  }
}

void metal_t::set_buy_price(float buy_price){
  this->buy_price = buy_price;
}

void metal_t::set_demand_quantity(float demand_quantity){
  this->demand_quantity = demand_quantity;
}

ostream& operator<<(ostream &os, const metal_t &metal){
  os << "(buy-price: "<<metal.get_buy_price()<<" $, demand-quantity: "<<metal.get_demand_quantity()<<" t, name: "<<metal.get_name()<<", symbol: "<<metal.get_symbol()<<")";
  return os;
}
