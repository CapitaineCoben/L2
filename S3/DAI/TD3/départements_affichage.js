// Lance l'exécution quand tout est chargé
window.addEventListener('load', go);

// SAM Design Pattern
let actions, model, state, view;

// Point d'entrée de l'application
function go() {
  console.log('GO !');

  model.init({departments: départements, mode: 'asList_for'});
  state.samRender(model);
}

//------------------------------------------------------------------ Actions ---
// Actions lancées par des événements
//
actions = {

  changeMode: function(data) {
    let selectedMode = data.e.target.value;
    model.samPresent({mode: selectedMode});
  },

  filter: function(data) {
    let filterValue = data.e.target.value;
    model.samPresent({filter: filterValue});
  },

  filterRegions: function(data) {
    let checkValue = data.e.target.checked;
    model.samPresent({filterRegions: checkValue});
  }
};
//-------------------------------------------------------------------- Model ---
// Unique source de vérité de l'application
//
model = {
  departments: [], // tableau contenant données sur les départements
  mode: '',        // mode de rendu 'asList_for', 'asList_map', 'asTable_for'...
  depFilter: '',   // filtre à appliquer aux données sur les départements
  filterRegions: false,  // inclure les régions dans le filtrage

  init: function(data) {
    this.departments = data.departments;
    this.mode = data.mode;
  },

  samPresent: function(data) {
    const has = Object.prototype.hasOwnProperty;   // test si la propriété
                                                   // d'un objet est présente
    if (has.call(data, 'mode')) {
      this.mode = data.mode;
    }

    if (has.call(data, 'filter')) {
      this.depFilter = data.filter;
    }

    if (has.call(data, 'filterRegions')) {
      this.filterRegions = data.filterRegions;
    }

    state.samRender(this);
  }
};
//-------------------------------------------------------------------- State ---
// Ã‰tat de l'application avant affichage
//
state = {
  currentFilter: undefined,         // le filtre courant appliquÃ© Ã  departments
  currentFilterRegions: undefined,  // inclure ou pas le filtrage des rÃ©gions
  depFiltered: [],                  // version filtrÃ©e de departments

  samRender: function(model) {
    this.samRepresentAndDisplay(model);
    // this.samNap(model);
  },

  samRepresentAndDisplay: function(model) {
    let representation = 'Oops, should not see this...';

    if ( this.currentFilter !== model.depFilter
      || this.currentFilterRegions !== model.filterRegions) {
      this.currentFilter = model.depFilter;
      this.currentFilterRegions = model.filterRegions;
      // TODO: Choisir ci-dessous la fonction de filtrage
      //this.depFiltered = this.filterDepartments_for(model.departments);
      this.depFiltered = this.filterDepartments_filter(model.departments);
    }

    representation = view.occurences(model, this);

    switch (model.mode) {
      case "asList_for":
        representation += view.asList_for(model, this);
        break;
      case "asList_map":
        representation += view.asList_map(model, this);
        break;
      case "asTable_for":
        representation += view.asTable_for(model, this);
        break;
      case "asTable_map":
        representation += view.asTable_map(model, this);
        break;
      default:
        representation += view.error(model.mode);
    }
    view.samDisplay(representation);
  },

  // Filtrage des dÃ©partements
  filterDepartments_filter: function(depArray){
    if (this.currentFilter == '') return depArray;

    let filtered = depArray.filter( (v,i,a)=> v[0].toLowerCase().includes(this.currentFilter.toLowerCase()));

    return filtered;
  },


  // version avec boucle for
  filterDepartments_for: function(depArray) {
    if (this.currentFilter == '') return depArray;
    let filtered = [];
    for (let i = 0; i < depArray.length; i++) {
      if (depArray[i][0].toLowerCase().includes(this.currentFilter.toLowerCase())) {
          filtered.push(depArray[i]);
      }
      
    }

    return filtered;
  },
};
//--------------------------------------------------------------------- View ---
// Génération du HTML et affichage
//
view = {

  samDisplay: function(representation) {
    const app = document.getElementById('app');
    app.innerHTML = representation;
  },

  occurences: function(model, state) {
    let nbOcc = 42;  // TODO: Quel est le nombre d'éléments dans le tableau filtré ?
    return `
        <p>${nbOcc} occurence</p>
    `;
  },

  asList_for: function(model, state) {
    let items = '';
    let a = state.depFiltered;
    for (var i = 0; i < a.length; i++) {
      const dep = a[i][0];
      const reg = a[i][2];
      items += `<li><b>${dep}</b> (${reg})</li>`
    }

    return `
        <ul>
          ${items}
        </ul>
      `;
  },

  asList_map: function(model, state) {
    return `
        <ul>
          ${state.depFiltered.map((v) => `<li><b>${v[0]}</b> (${v[2]})</li>`).join('')}
        </ul>
      `;
  },

  asTable_for: function(model, state) {
    let items = '';
    let a = state.depFiltered;
    item  = `<th>N°</th><th>Départements</th><th>Régions</th>`
    for (var i = 0; i < a.length; i++) {
      const dep = a[i][0];
      const reg = a[i][2];
      const num = i+1;
      items += `<tr><td>${num}</td><td>${dep}</td> <td>${reg}</td></tr>`
    }

    return `
        <table class="table table-bordered">
          ${item}
          ${items}
        </table>
      `;
  },

  asTable_map: function(model, state) {
    item  = `<th>N°</th><th>Départements</th><th>Régions</th>`
    return `
      <table class="table table-bordered">
      ${item}
      ${state.depFiltered.map((v) => `<tr><td>${v[1]}</td><td>${v[0]}</td><td>${v[2]}</td></tr>`).join('')}
      </table>
    `;
  },

  error: function(caseValue) {
    return `
      <p>Problème : <b>state.representation(model)</b> : que faire avec "${caseValue}" ?</p>
    `;
  }
};
