CREATE TABLE OUVRAGES(
    CODOUV char(5) NOT NULL,
    TITOUV char(5) NOT NULL,
    NPPAGE number(4) NOT NULL,
    ANEDIT number(4) NOT NULL,
    LANGUE char(5) NOT NULL,
    NOMEDIT char(5) NOT NULL,
    NOMAUT char(5) NOT NULL,
    PRENOMAUT char(5) NOT NULL,
constraint PK_OUVRAGES primary key (CODOUV)
constraint OK_LANGUE check (LANGUE='Français' OR LANGUE='Anglais' OR LANGUE='Espagnol')
constraint NN_NBPAGE check (NBPAGE>0)
);

CREATE TABLE EXEMPLAIRES(
    CODEX char(5) NOT NULL,
    CODOUV char(5) NOT NULL,
    DATEENTIB date NOT NULL,
constraint PK_EXEMPLAIRES primary key (CODEX)
constraint FK_CODOUV foreign key (CODOUV)
                references OUVRAGES
);

CREATE TABLE PERSONNES(
    CODPERS char(5) PRIMARY KEY,
    NOMPERS char(5) NOT NULL,
    PRENOMPERS char(5) NOT NULL,
    RUEPERS char(5) NOT NULL,
    CPPERS char(5) NOT NULL,
    VILLEPERS char(5) NOT NULL,
    SEXE char(1) NOT NULL,
    DATIINSCRIPT date NOT NULL,
    DNAISS date NOT NULL,
    CODBIB char(5) NOT NULL,
constraint PK_PERSONNES primary key (CODPERS)
constraint OK_SEXE check (SEXE='F' OR SEXE='M')
constraint OK_DATNAISS check (DNAISS<DATIINSCRIPT)
);

CREATE TABLE PRET(
    CODEX char(5) PRIMARY KEY,
    CODPERS char(5) NOT NULL,
    DATEP date NOT NULL,
constraint FK_CODPERS foreign key (CODPERS)
                    references PERSONNES
);

CREATE TABLE PRESENT(
  CODBIB char(5) NOT NULL,
  CODOUV char(5) NOT NULL,
);

CREATE TABLE BIBLIOTHEQUES(
  CODBIB char(5) PRIMARY KEY,
  NOMBIB char(5) NOT NULL,
  RUEBIB char(5) NOT NULL,
  CPBIB char(5) NOT NULL,
  VILLEBIB char(5) NOT NULL,
);
