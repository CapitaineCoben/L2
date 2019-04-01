/**
* \file metal.h
*/
#ifndef METAL_H
#define METAL_H
#include <string> // for string
using namespace std; // for string
/**
* A metal.
*/
class metal_t
{
float buy_price; /**< The buy price, in dollars (example: 100.10). */
float demand_quantity; /**< The demand quantity, in tonnes (example: 1000.11). */
protected:
string name; /**< The name (example: "Gold"). */
string symbol; /**< The symbol (example: "Au"). */
public:
/**
* Constructs a new metal.
* Initializes its buy price and its demand quantity to 0.
* Initializes its name and its symbol to "undefined".
*/
metal_t();
/**
* Gets the buy price for this metal.
* \return The buy price for this metal.
*/
float get_buy_price() const;
/**
* Gets the demand quantity for this metal.
* \return The demand quantity for this metal.
*/
float get_demand_quantity() const;
/**
* Gets the name for this metal.
* \return The name for this metal.
*/
string get_name() const;
/**
* Gets the symbol for this metal.
* \return The symbol for this metal.
*/
string get_symbol() const;
/**
* Handles the m command for this metal.
* Calls the << overloaded operator on this metal.
*/
void handle_m() const;
/**
* Handles the mbp command for this metal.
* Calls the handle_m method on this metal if the condition is satisfied.
* \param price The mbp command parameter.
*/
void handle_mbp(float price) const;
/**
* Handles the mbpge command for this metal.
* Calls the handle_m method on this metal if the
* \param price The mbpge command parameter.
*/
void handle_mbpge(float price) const;
/**
* Handles the mbpgt command for this metal.
* Calls the handle_m method on this metal if the
* \param price The mbpgt command parameter.
*/
void handle_mbpgt(float price) const;
/**
* Handles the mbple command for this metal.
* Calls the handle_m method on this metal if the
* \param price The mbple command parameter.
*/
void handle_mbple(float price) const;
/**
* Handles the mbplt command for this metal.
* Calls the handle_m method on this metal if the
* \param price The mbplt command parameter.
*/
void handle_mbplt(float price) const;
/**
* Handles the mdq command for this metal.
* Calls the handle_m method on this metal if the
* \param qty The mdq command parameter.
*/
void handle_mdq(float qty) const;
/**
* Handles the mdqge command for this metal.
* Calls the handle_m method on this metal if the
* \param qty The mdqge command parameter.
*/
void handle_mdqge(float qty) const;
/**
* Handles the mdqgt command for this metal.
* Calls the handle_m method on this metal if the
* \param qty The mdqgt command parameter.
*/
void handle_mdqgt(float qty) const;
/**
* Handles the mdqle command for this metal.
* Calls the handle_m method on this metal if the
* \param qty The mdqle command parameter.
*/
void handle_mdqle(float qty) const;
/**
* Handles the mdqlt command for this metal.
* Calls the handle_m method on this metal if the
* \param qty The mdqlt command parameter.
*/
void handle_mdqlt(float qty) const;
/**
* Handles the mn command for this metal.
* Calls the handle_m method on this metal if the
* \param name The mn command parameter.
*/
void handle_mn(string name) const;
/**
* Handles the ms command for this metal.
* Calls the handle_m method on this metal if the
* \param symbol The ms command parameter.
*/
void handle_ms(string symbol) const;
/**
* Sets the buy price for this metal.
* \param buy_price The buy price for this metal.
*/
void set_buy_price(float buy_price);
/**
* Sets the demand quantity for this metal.
* \param demand_quantity The demand quantity for
*/
void set_demand_quantity(float demand_quantity);
};
/**
* Inserts a metal into an output stream.
* The inserted string is "(BPN: BPV $, DQN: DQV t, NN: NV, SN: SV)".
* BPN and BPV: The buy price attribute name and value.
* DQN and DQV: The demand quantity attribute name and value.
* NN and NV: The name attribute name and value.
* SN and SV: The symbol attribute name and value.
* \param os The output stream.
* \param metal The metal.
* \return The output stream.
*/
ostream &operator<<(ostream &os, const metal_t &metal);
#endif
