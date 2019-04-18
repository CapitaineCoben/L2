#include <iostream>
#include <cstring>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
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

void print_help(){
  cout << "addr: prints the refinery address" << endl
       << "contact: prints the refinery contact information" << endl
       << "help: prints this help" << endl
       << "m: prints the refinery metals" << endl
       << "mail: prints the refinery mail address" << endl
       << "mbp PRICE: prints the refinery metals with the buy price equal to PRICE" << endl
       << "mbpge PRICE: prints the refinery metals with the buy price greater than or equal to PRICE" << endl
       << "mbpgt PRICE: prints the refinery metals with the buy price greater than PRICE" << endl
       << "mbple PRICE: prints the refinery metals with the buy price less than or equal to PRICE" << endl
       << "mbplt PRICE: prints the refinery metals with the buy price less than PRICE" << endl
       << "mdq QTY: prints the refinery metals with the demand quantity equal to QTY" << endl
       << "mdqge QTY: prints the refinery metals with the demand quantity greater than or equal to QTY" << endl
       << "mdqgt QTY: prints the refinery metals with the demand quantity greater than QTY" << endl
       << "mdqle QTY: prints the refinery metals with the demand quantity less than or equal to QTY" << endl
       << "mdqlt QTY: prints the refinery metals with the demand quantity less than QTY" << endl
       << "mn NAME: prints the refinery metals with the name containing NAME" << endl
       << "ms SYMBOL: prints the refinery metals with the symbol containing SYMBOL" << endl
       << "quit: quits MRP" << endl
       << "r: prints the refinery information" << endl
       << "version: prints the MRP version" << endl
       << "web: prints the refinery web address" << endl;
}

void print_version(){
  cout << "MRP (Metal Refinery Program) 20190417" << endl << endl
       << "Copyright (C) 2019 Daspet Romain and Vontolkacz Karol." << endl << endl
       << "Written by Daspet Romain <daspet.romain@univ-pau.fr> and Vontolkacz Karol <vontolkacz.karol@univ-pau.fr>." << endl;
}

int main(int argc, char const *argv[]) {
  xml_document xmlDoc;
  xml_node xmlNode;
  refinery_t pau_refinery;
  char * endPtr;


// Vérification du bon nombre d'arguments
  if (argc != 2) {
    cerr << argv[0] << ": invalid number of arguments" << endl;
    return 1;
  }

//génération du document a parti du xml et vérification
  xml_parse_result result = xmlDoc.load_file(argv[1]);
  if (result.description() !=(string) "No error") {
    cerr << argv[0] << ": unable to parse the document" << endl;
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

//gestion des commandes utilisateur
char* saisie = new char;
do {
  cout << "MRP> ";
  fgets(saisie,100,stdin);
  if (strlen(saisie) >= 18) {
    cerr << "too many characters for the command" << endl;
  }else {
      if (strstr(saisie,"addr\n")) { pau_refinery.handle_addr();
      } else if (strstr(saisie,"contact\n")) { pau_refinery.handle_contact();
      } else if (strstr(saisie,"help\n")) { print_help();
      } else if (strstr(saisie,"m\n")) { pau_refinery.handle_m();
      } else if (strstr(saisie,"mail\n")) { pau_refinery.handle_mail();

      } else if (strstr(saisie,"mbp")) {
        if (strstr(saisie,"mbpge")) {
          if (strlen(saisie) <= 7) {cerr << argv[0] << ": missing parameter for the mbpge command" << endl;
          }else if(strtof(&saisie[5],NULL) == 0){cerr << argv[0] << ": invalid parameter for the mbp command" << endl;
          }else {pau_refinery.handle_mbpge(strtof(&saisie[5],NULL));}

        } else if (strstr(saisie,"mbpgt")) {
          if (strlen(saisie) <= 6) {cerr << argv[0] << ": missing parameter for the mbpgt command" << endl;
          }else if(strtof(&saisie[5],NULL) == 0){cerr << argv[0] << ": invalid parameter for the mbp command" << endl;
          }else {pau_refinery.handle_mbpgt(strtof(&saisie[5],NULL));}

        } else if (strstr(saisie,"mbple")) {
          if (strlen(saisie) <= 6) {cerr << argv[0] << ": missing parameter for the mbple command" << endl;
          }else if(strtof(&saisie[5],NULL) == 0){cerr << argv[0] << ": invalid parameter for the mbp command" << endl;
          }else {pau_refinery.handle_mbple(strtof(&saisie[5],NULL));}

        } else if (strstr(saisie,"mbplt")) {
          if (strlen(saisie) <= 6) {cerr << argv[0] << ": missing parameter for the mbplt command" << endl;
          }else if(strtof(&saisie[5],NULL) == 0){cerr << argv[0] << ": invalid parameter for the mbp command" << endl;
          }else {pau_refinery.handle_mbplt(strtof(&saisie[5],NULL));}

        }else{
          if (strlen(saisie) <= 5) {cerr << argv[0] << ": missing parameter for the mbp command" << endl;
          }else if(strtof(&saisie[3],NULL) == 0){cerr << argv[0] << ": invalid parameter for the mbp command" << endl;
          }else {pau_refinery.handle_mbp(strtof(&saisie[3],NULL));}
        }
      }  else if (strstr(saisie,"mdq")) {
        if (strstr(saisie,"mdqge")) {
          if (strlen(saisie) <= 7) {cerr << argv[0] << ": missing parameter for the mdqge command" << endl;
          }else if(strtof(&saisie[5],NULL) == 0){cerr << argv[0] << ": invalid parameter for the mdq command" << endl;
          }else {pau_refinery.handle_mdqge(strtof(&saisie[5],NULL));}

        } else if (strstr(saisie,"mdqgt")) {
          if (strlen(saisie) <= 6) {cerr << argv[0] << ": missing parameter for the mdqgt command" << endl;
          }else if(strtof(&saisie[5],NULL) == 0){cerr << argv[0] << ": invalid parameter for the mdq command" << endl;
          }else {pau_refinery.handle_mdqgt(strtof(&saisie[5],NULL));}

        } else if (strstr(saisie,"mdqle")) {
          if (strlen(saisie) <= 6) {cerr << argv[0] << ": missing parameter for the mdqle command" << endl;
          }else if(strtof(&saisie[5],NULL) == 0){cerr << argv[0] << ": invalid parameter for the mdq command" << endl;
          }else {pau_refinery.handle_mdqle(strtof(&saisie[5],NULL));}

        } else if (strstr(saisie,"mdqlt")) {
          if (strlen(saisie) <= 6) {cerr << argv[0] << ": missing parameter for the mdqlt command" << endl;
          }else if(strtof(&saisie[5],NULL) == 0){cerr << argv[0] << ": invalid parameter for the mdq command" << endl;
          }else {pau_refinery.handle_mdqlt(strtof(&saisie[5],NULL));}

        }else{
          if (strlen(saisie) <= 5) {cerr << argv[0] << ": missing parameter for the mdq command" << endl;
          }else if(strtof(&saisie[3],NULL) == 0){cerr << argv[0] << ": invalid parameter for the mdq command" << endl;
          }else {pau_refinery.handle_mdq(strtof(&saisie[3],NULL));}
        }

      } else if (strstr(saisie,"mn")) {
        if (strlen(saisie) <= 4) {cerr << argv[0] << ": missing parameter for the mn command" << endl;
      }else if(strtof(&saisie[3],NULL) != 0){cerr << argv[0] << ": invalid parameter for the mdq command" << endl;
    }else {saisie[strlen(saisie)-1] = '\0'; pau_refinery.handle_mn(&saisie[3]);}

      } else if (strstr(saisie,"ms")) {
        if (strlen(saisie) <= 4) {cerr << argv[0] << ": missing parameter for the ms command" << endl;
      }else if(strtof(&saisie[3],NULL) != 0){cerr << argv[0] << ": invalid parameter for the mdq command" << endl;
    }else {saisie[strlen(saisie)-1] = '\0'; pau_refinery.handle_ms(&saisie[3]);}

      } else if (strstr(saisie,"r\n")) { pau_refinery.handle_r();
      } else if (strstr(saisie,"version\n")) { print_version();
      } else if (strstr(saisie,"web\n")) { pau_refinery.handle_web();
      }else if (strstr(saisie,"quit\n")) {
      }else {cerr << argv[0] << ": invalid command"<< endl;}
  }
} while(strcmp(saisie,"quit\n"));






  return 0;
}
