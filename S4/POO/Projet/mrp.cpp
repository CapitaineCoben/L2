#include <iostream>
#include <cstring>
#include <vector>
#include <stdlib.h>
#include "pugixml.hpp"
#include "pugiconfig.hpp"
#include "refinery.h"
#include "copper.h"
#include "gold.h"
#include "silver.h"
#include "str_to_float_error.h"
#include "str_to_int_error.h"
#include "str_to_long_error.h"
using namespace std;
using namespace pugi;

int main(int argc, char const *argv[]) {
  xml_document xmlDoc;
  xml_node xmlNode;
  refinery_t pau_refinery;
  char * endPtr;


// Vérification du bon nombre d'arguments
  if (argc != 2) {
    cerr << "invalid number of arguments" << endl;
    return 1;
  }

//génération du document a parti du xml et vérification
  xml_parse_result result = xmlDoc.load_file(argv[1]);
  if (result.description() !=(string) "No error") {
    cerr << "unable to parse the document" << endl;
    return 1;
  }

// parcour du fichier xml et remplissage de la rafinerie
  for (xml_node refinery = xmlDoc.first_child(); refinery.name() ==(string) "refinery"; refinery = refinery.next_sibling()){

    // cout << refinery.first_attribute().value() << endl;
    pau_refinery.set_name(refinery.first_attribute().value());// acces au nom de la rafinerie

    //gestion du contact
      //gestion de l'addresse
    xml_node_iterator i = refinery.first_child().first_child().begin();
    // cout << i->child_value() << endl;
    pau_refinery.set_street(i->child_value());
    i++;
    // cout << i->child_value() << endl;
    pau_refinery.set_postal_code(strtol(i->child_value(),&endPtr,10));
    i++;
    // cout << i->child_value() << endl;
    pau_refinery.set_city(i->child_value());
      //gestion du mail et du web
    i = refinery.first_child().begin();
    i++;
    // cout << i->child_value() << endl;
    pau_refinery.set_mail(i->child_value());
    i++;
    // cout << i->child_value() << endl;
    pau_refinery.set_web(i->child_value());
    //gestion des jours
    i = refinery.begin();
    i++;
    for (xml_node_iterator k = i->begin();k != i->end(); k++) {
      //création du jour correspondant
      day_t day;
      if(strcmp(k->child_value(),"Monday")==0){ day = monday;}
      if(strcmp(k->child_value(),"Tuesday")==0){ day = tuesday;}
      if(strcmp(k->child_value(),"Wednesday")==0){ day = wednesday;}
      if(strcmp(k->child_value(),"Thursday")==0){ day = thursday;}
      if(strcmp(k->child_value(),"Friday")==0){ day = friday;}
      if(strcmp(k->child_value(),"Saturday")==0){ day = saturday;}
      if(strcmp(k->child_value(),"Sunday")==0){ day = sunday;}
      //insertion du jour dans la rafinerie
      pau_refinery.days_push_back(day);
      // cout << k->child_value() << endl;
    }
    //gestion des metaux
    i++;
    for (xml_node_iterator k = i->begin(); k != i->end(); k++) {
      //création du metal correspondant
      metal_t* metal;
      // cout << k->first_attribute().value() << endl;
      if(strcmp(k->first_attribute().value(),"Copper")==0){ metal = new copper_t;}
      if(strcmp(k->first_attribute().value(),"Gold")==0){ metal = new gold_t;}
      if(strcmp(k->first_attribute().value(),"Silver")==0){ metal = new silver_t;}
      //gestion du prix
      metal->set_buy_price(strtof(k->first_child().child_value(),&endPtr));
      // cout << k->first_child().child_value() << endl;
      //gestion de la quantité
      metal->set_demand_quantity(strtof(k->last_child().child_value(),&endPtr));
      // cout << k->last_child().child_value() << endl;
      //insertion du metal dans la rafinerie
      pau_refinery.metals_push_back(*metal);
    }
  }


pau_refinery.handle_r();

//gestion des commandes utilisateur







  return 0;
}
