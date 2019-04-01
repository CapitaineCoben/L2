/**
* \file refinery.h
*/
#ifndef REFINERY_H
#define REFINERY_H
#include <string> // for string
#include <vector> // for vector
#include "metal.h" // for metal_t
using namespace std; // for string
/**
* A day (of the week, from monday to sunday).
*/
enum day_t
{
monday,
tuesday,
wednesday,
thursday,
friday,
saturday,
sunday
};
/**
* A refinery.
*/
class refinery_t
{
string city; /**< The city (example: "Pau"). */
vector<day_t> days; /**< The days (on which work is done for this refinery) */
string mail; /**< The mail address (example: "pau-refinery@pau.fr"). */
vector<metal_t> metals; /**< The metals (refined by this refinery). */
string name; /**< The name (example: "Pau refinery"). */
int postal_code; /**< The postal code (example: "64000"). */
string street; /**< The street (example: "1 rue Richelieu"). */
string web; /**< The web address (example: "http://pau-refinery.pau.fr/"). */
public:
refinery_t();
/**
* Accesses to the element of days at the specified index for this refinery.
* Calls the at method on days.
* \param index The index.
* \return The element of days at the specified index for this refinery.
*/
day_t days_at(int index) const;
/**
* Adds an element at the end of days for this refinery.
* Calls the push_back method on days.
* \param day The element.
*/
void days_push_back(day_t day);
/**
* Gets the size of days for this refinery.
* Calls the size method on days.
* \return The size of days for this refinery.
*/
int days_size() const;
/**
* Gets the city for this refinery.
* \return The city for this refinery.
*/
string get_city() const;
/**
* Gets the mail address for this refinery.
* \return The mail address for this refinery.
*/
string get_mail() const;
/**
* Gets the name for this refinery.
* \return The name for this refinery.
*/
string get_name() const;
/**
* Gets the postal code for this refinery.
* \return The postal code for this refinery.
*/
int get_postal_code() const;
/**
* Gets the street for this refinery.
* \return The street for this refinery.
*/
string get_street() const;
/**
* Gets the web address for this refinery.
* \return The web address for this refinery.
*/
string get_web() const;
/**
* Handles the addr command for this refinery.
* Prints "NV, SV, PCV, CV\n".
* NV: The name attribute value.
* SV: The street attribute value.
* PCV: The postal_code attribute value.
* CV: The city attribute value.
*/
void handle_addr() const;
/**
* Handles the contact command for this refinery.
* Calls the handle_addr, handle_mail and handle_web methods on this refinery.
*/
void handle_contact() const;
/**
* Handles the m command for this refinery.
* Iterates on metals to call the handle_m method on its elements.
*/
void handle_m() const;
/**
* Handles the mail command for this refinery.
* Prints "MV\n".
* MV: The mail attribute value.
*/
void handle_mail() const;
/**
* Handles the mbp command for this refinery.
* Iterates on metals to call the handle_mbp method on its elements.
* \param price The mbp command parameter.
*/
void handle_mbp(float price) const;
/**
* Handles the mbpge command for this refinery.
* Iterates on metals to call the handle_mbpge method on its elements.
* \param price The mbpge command parameter.
*/
void handle_mbpge(float price) const;
/**
* Handles the mbpgt command for this refinery.
* Iterates on metals to call the handle_mbpgt method on its elements.
* \param price The mbpgt command parameter.
*/
void handle_mbpgt(float price) const;
/**
* Handles the mbple command for this refinery.
* Iterates on metals to call the handle_mbple method on its elements.
* \param price The mbple command parameter.
*/
void handle_mbple(float price) const;
/**
* Handles the mbplt command for this refinery.
* Iterates on metals to call the handle_mbplt method on its elements.
* \param price The mbplt command parameter.
*/
void handle_mbplt(float price) const;
/**
* Handles the mdq command for this refinery.
* Iterates on metals to call the handle_mdq method on its elements.
* \param qty The mdq command parameter.
*/
void handle_mdq(float qty) const;
/**
* Handles the mdqge command for this refinery.
* Iterates on metals to call the handle_mdqge method on its elements.
* \param qty The mdqge command parameter.
*/
void handle_mdqge(float qty) const;
/**
* Handles the mdqgt command for this refinery.
* Iterates on metals to call the handle_mdqgt method on its elements.
* \param qty The mdqgt command parameter.
*/
void handle_mdqgt(float qty) const;
/**
* Handles the mdqle command for this refinery.
* Iterates on metals to call the handle_mdqle method on its elements.
* \param qty The mdqle command parameter.
*/
void handle_mdqle(float qty) const;
/**
* Handles the mdqlt command for this refinery.
* Iterates on metals to call the handle_mdqlt method on its elements.
* \param qty The mdqlt command parameter.
*/
void handle_mdqlt(float qty) const;
/**
* Handles the mn command for this refinery.
* Iterates on metals to call the handle_mn method on its elements.
* \param name The mn command parameter.
*/
void handle_mn(string name) const;
/**
* Handles the ms command for this refinery.
* Iterates on metals to call the handle_ms method on its elements.
* \param symbol The ms command parameter.
*/
void handle_ms(string symbol) const;
/**
* Handles the r command for this refinery.
* Calls the << overloaded operator on this metal.
*/
void handle_r() const;
/**
* Handles the web command for this refinery.
* Prints "WV\n".
* WV: The web attribute value.
*/
void handle_web() const;
/**
* Accesses to the element of metals at the specified index for this refinery.
* Calls the at method on metals.
* \param index The index.
* \return The element of metals at the specified index for this refinery.
*/
metal_t metals_at(int index) const;
/**
* Adds an element at the end of metals for this refinery.
* Calls the push_back method on metals.
* \param metal The element.
*/
void metals_push_back(metal_t metal);
/**
* Gets the size of metals for this refinery.
* Calls the size method on metals.
* \return The size of metals for this refinery.
*/
int metals_size() const;
/**
* Sets the city for this refinery.
* \param city The city for this refinery.
*/
void set_city(string city);
/**
* Sets the mail address for this refinery.
* \param mail The mail address for this refinery.
*/
void set_mail(string mail);
/**
* Sets the name for this refinery.
* \param name The name for this refinery.
*/
void set_name(string name);
/**
* Sets the postal code for this refinery.
* \param postal_code The postal code for this refinery.
*/
void set_postal_code(int postal_code);
/**
* Sets the street for this refinery.
* \param street The street for this refinery.
*/
void set_street(string street);
/**
* Sets the web address for this refinery.
* \param web The web address for this refinery.
*/
void set_web(string web);
};
/**
* Inserts a refinery into an output stream.
* The inserted string is "(CN: CV, DN: (DV1, ..., DVN), MAN: MAV, MEN: (MEV1, ..., MEVN), NN: NV,
PCN: PCV, SN: SV, WN: WV)".
* CN and CV: The city attribute name and value.
* DN, DV1 and DVN: The days attribute name and values (from 1 to N).
* MAN and MAV: The mail attribute name and value.
* MEN, MEV1 and MEVN: The metals attribute name and values (from 1 to N).
* NN and NV: The name attribute name and values.
* PCN and PCV: The postal code attribute name and values.
* SN and SV: The street attribute name and values.
* WN and WV: The web attribute name and values.
* \param os The output stream.
* \param refinery The refinery.
* \return The output stream.
*/
ostream &operator<<(ostream &os, const refinery_t &refinery);
#endif
