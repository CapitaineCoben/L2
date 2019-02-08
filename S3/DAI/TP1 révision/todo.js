"use strict";  // le mode strict impose une version plus exigente de Javascript

// Demande le lancement de l'exécution quand toute la page Web sera chargée
window.addEventListener('load', go);

// SAM Design Pattern : http://sam.js.org/
let actions,
  model,
  state,
  view;

// Point d'entrée de l'application
function go() {
  console.log('GO !');


  // Appelle l'affichage de l'application.
  state.samUpdate(model);
}

//------------------------------------------------------------------ Actions ---
// Actions appelées dans le code HTML quand des événements surviennent
//
actions = {

  // Demande au modèle d'ajouter un item à son tableau de tâches à faire.
  // Lui envoit pour cela un objet avec une propriété 'inputField' qui
  // désigne l'id de l'élément qui contient le texte à ajouter.
  addItem(data) {
    let text = document.getElementById(data.inputField).value;
    if (text != '') {
      model.samPresent({
        do : 'newItem',
        newItem: text
      });
    }
  },

  rayItem(data){
    let done;
    if (model.items[data.index].done == '') {
      done = 'done';
    }else {
      done = '';
    }
    model.samPresent({
      do : 'rayItem',
      done : done,
      index : data.index,
    });
  },

  removeDoneItems(){
    let items=[];
    model.items.forEach((v,i,a)=>{
      if (v.done != 'done') {
        items[i] = v;
      }
    model.samPresent({
      do :'removeDoneItems',
      items : items
      })
    });
  }

};
//-------------------------------------------------------------------- Model ---
// Unique source de vérité de l'application
//
model = {
  items: [],


  // Demande au modèle de se mettre à jour en fonction des données qu'on
  // lui présente.
  // l'argument data est un objet confectionné dans les actions.
  // Les propriétés de data désignent la modification à faire sur le modèle.
  samPresent(data) {
    const has = Object.prototype.hasOwnProperty; // test si la propriété
    // d'un objet est présente

    // Si l'objet data possède la propriété 'newItem'
    // alors on ajoute ce nouvel item au tableau de tâches de model.
    switch (data.do) {
      case 'newItem':
        this.items.push({text :data.newItem, done : ''});
        break;

      case 'rayItem':
        this.items[data.index].done = data.done;
      break;

      case 'removeDoneItems':
        this.items = data.items;
      break;
      default:

    }


    // Demande à l'état de l'application de prendre en compte la modification
    // du modèle
    state.samUpdate(this);
  }
};
//-------------------------------------------------------------------- State ---
// État de l'application avant affichage
//
state = {

  samUpdate(model) {
    this.samRepresent(model);
    // this.samNap(model);
  },

  // Met à jour l'état de l'application, construit le code HTML correspondant,
  // et demande son affichage.
  samRepresent(model) {
    let representation = 'Oops, should not see this...';

    representation = view.normalInterface(model, this);

    // Appel l'affichage du HTML généré.
    view.samDisplay(representation);
  }
};
//--------------------------------------------------------------------- View ---
// Génération de portions en HTML et affichage
//
view = {

  // Injecte le HTML dans une balise de la page Web.
  samDisplay(representation) {
    const app = document.getElementById('app');
    app.innerHTML = representation;
  },

  // Renvoit le HTML
  normalInterface(model, state) {
    let li_items = this.listItems(model,state);
    return `
      <h2> Todo List </h2>
      <input id="inputText" type="text" />
      <button onclick="actions.addItem( {e: event, inputField:'inputText'} )">Todo</button>
      <ul>
      	${li_items}
      </ul>
      <button onclick="actions.removeDoneItems()">Remove done items</button>
      `;
  },

  listItems(model, state) {
    let li_items = [],done;
    console.log(model.items);
    li_items = model.items.map((v,i,a)=> `<li  onclick="actions.rayItem({index : ${i}})" class="${v.done}">${v.text}</li>`)
    console.log(li_items);
    return li_items.join('\n');
  }

};
