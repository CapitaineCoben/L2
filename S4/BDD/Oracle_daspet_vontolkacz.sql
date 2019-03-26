create table ARTICLES (
  CODART number(5),
  NOMART char(20),
  PRIX number(5),
  RAYON char(6),
  CODCAT number(5),
  constraint PK_ARTICLES primary key(CODART),
  constraint FK_NCAT_CATEGORIES foreign key(CODCAT) references CATEGORIES,
  constraint Ck_RAYON check (RAYON='Homme' or RAYON='Femme' or RAYON='Enfant')
);

create table CATEGORIES (
  CODCAT number(5),
  NOMCAT char(20),
  constraint PK_CATEGORIES primary key (CODCAT)
);

create table PRESENT (
  CODART number(5),
  NUMMAG number(5),
  TAILLE number(5),
  STOCK number(5),
  constraint PK_PRESENT primary key(TAILLE),
  constraint FK_CODART_ARTICLES foreign key(CODART) references ARTICLES,
  constraint FK_NUMMAG_MAGASINS foreign key(NUMMAG) references MAGASINS,
  constraint CK_TAILLE check (TAILLE <= 56 and TAILLE >= 34)
);

create table MAGASINS (
  NUMMAG number(5),
  NOMMAG char(20),
  ADRESSEMAG char(20),
  CODPOST char(5),
  VILLEMAG char(10),
  constraint PK_MAGASINS primary key(NUMMAG)
);
