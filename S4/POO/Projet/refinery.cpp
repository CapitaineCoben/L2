#include <iostream>
#include <cstring>
#include <vector>
#include "refinery.h"
using namespace std;



refinery_t::refinery_t(){
  this->city = "undefined";
  this->mail = "undefined";
  this->name = "undefined";
  this->postal_code = 0;
  this->street = "undefined";
  this->web = "undefined";
}

day_t refinery_t::days_at(int index) const{
  return this->days[index];
}

void refinery_t::days_push_back(day_t day){
  this->days.push_back(day);
}

int refinery_t::days_size() const{
  return this->days.size();
}

string refinery_t::get_city() const{
  return this->city;
}

string refinery_t::get_mail() const{
  return this->mail;
}

string refinery_t::get_name() const{
  return this->name;
}

int refinery_t::get_postal_code() const{
  return this->postal_code;
}

string refinery_t::get_street() const{
  return this->street;
}

string refinery_t::get_web() const{
  return this->web;
}

void refinery_t::handle_addr() const{
  cout << this->get_name() << ", " << this->get_street() << ", " << get_postal_code() << ", " << get_city() << endl;
}

void refinery_t::handle_contact() const{
  this->handle_addr();
  this->handle_mail();
  this->handle_web();
}

void refinery_t::handle_m() const{
  for (int i = 0; i < (int) this->metals.size(); i++) {
    this->metals[i].handle_m();
  }
}

void refinery_t::handle_mail() const{
  cout << this->get_mail() << endl;
}

void refinery_t::handle_mbp(float price) const{
  for (int i = 0; i < (int) this->metals.size(); i++) {
    this->metals[i].handle_mbp(price);
  }
}

void refinery_t::handle_mbpge(float price) const{
  for (int i = 0; i < (int) this->metals.size(); i++) {
    this->metals[i].handle_mbpge(price);
  }
}

void refinery_t::handle_mbpgt(float price) const{
  for (int i = 0; i < (int) this->metals.size(); i++) {
    this->metals[i].handle_mbpgt(price);
  }
}

void refinery_t::handle_mbple(float price) const{
  for (int i = 0; i < (int) this->metals.size(); i++) {
    this->metals[i].handle_mbple(price);
  }
}

void refinery_t::handle_mbplt(float price) const{
  for (int i = 0; i < (int) this->metals.size(); i++) {
    this->metals[i].handle_mbplt(price);
  }
}

void refinery_t::handle_mdq(float qty) const{
  for (int i = 0; i < (int) this->metals.size(); i++) {
    this->metals[i].handle_mdq(qty);
  }
}

void refinery_t::handle_mdqge(float qty) const{
  for (int i = 0; i < (int) this->metals.size(); i++) {
    this->metals[i].handle_mdqge(qty);
  }
}

void refinery_t::handle_mdqgt(float qty) const{
  for (int i = 0; i < (int) this->metals.size(); i++) {
    this->metals[i].handle_mdqgt(qty);
  }
}

void refinery_t::handle_mdqle(float qty) const{
  for (int i = 0; i < (int) this->metals.size(); i++) {
    this->metals[i].handle_mdqle(qty);
  }
}

void refinery_t::handle_mdqlt(float qty) const{
  for (int i = 0; i < (int) this->metals.size(); i++) {
    this->metals[i].handle_mdqlt(qty);
  }
}

void refinery_t::handle_mn(string name) const{
  for (int i = 0; i < (int) this->metals.size(); i++) {
    this->metals[i].handle_mn(name);
  }
}

void refinery_t::handle_ms(string symbol) const{
  for (int i = 0; i < (int) this->metals.size(); i++) {
    this->metals[i].handle_ms(symbol);
  }
}

void refinery_t::handle_r() const{
  cout << *this;
}

void refinery_t::handle_web() const{
  cout << this->get_web() << endl;
}

metal_t refinery_t::metals_at(int index) const{
  return this->metals.at(index);
}

void refinery_t::metals_push_back(metal_t metal){
  this->metals.push_back(metal);
}

int refinery_t::metals_size() const{
  return this->metals.size();
}

void refinery_t::set_city(string city){
  this->city = city;
}

void refinery_t::set_mail(string mail){
  this->mail = mail;
}

void refinery_t::set_name(string name){
  this->name = name;
}

void refinery_t::set_postal_code(int postal_code){
  this->postal_code = postal_code;
}

void refinery_t::set_street(string street){
  this->street = street;
}

void refinery_t::set_web(string web){
  this->web = web;
}

ostream &operator<<(ostream &os, const refinery_t &refinery){
  os << "(city: " << refinery.get_city() << ", days: (";
  for (int i = 0; i < (int) refinery.days_size(); i++) {
    switch (refinery.days_at(i)) {
      case 0: os << ("day: Monday");break;
			case 1: os << ("day: Tuesday") ;break;
			case 2: os << ("day: Wednesday") ;break;
			case 3: os << ("day: Thursday") ;break;
			case 4: os << ("day: Friday") ;break;
			case 5: os << ("day: Saturday") ;break;
			case 6: os << ("day: Sunday") ;break;
    }
    if(i+1 == (int) refinery.days_size()){os << ")";}else{os << ", ";}
  }
  os << ", mail: " << refinery.get_mail() << ", metals: (";
  for (int i = 0; i < (int) refinery.metals_size(); i++) {
    refinery.metals_at(i).handle_m();
    if(i+1 == (int) refinery.metals_size()){os << ")";}else{os << ", ";}
  }
  os << ", name: " << refinery.get_name();
  os << ", postal_code: " << refinery.get_postal_code();
  os << ", street: " << refinery.get_street();
  os << ", web: " << refinery.get_web() << ")" << endl;

  return os;
}
