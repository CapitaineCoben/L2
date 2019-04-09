#include <cstdio>

enum day_t {
  monday,tuesday,wednesday,thursday,friday,saturday,sunday
};

struct book_t{
  char name[100];
  char authors[10][100];
  int nauthors;
  char publisher[100];
  int year;
  long int isbn;

  void print(){
    printf("%s\n",this->name );
    for (int i = 0; i < this->nauthors; i++) {
      printf("%s\n", this->authors[i]);
    }
    printf("%s\n",this->publisher );
    printf("%d\n", this->year);
    printf("%ld\n", this->isbn);
  }
};

struct library_t{
  char name[100];
  int ndays;
  d_t days[7];
  b_t books[100];
  int nbooks;

  void print(){
    printf("%s\n",this->name);
    printf("%s\n",(char*) this->days);
    for (int i = 0; i < this->nbooks; i++) {
      this->books[i].print();
    }
  }
};

int main(int argc, char const *argv[]) {
  l_t Sciences_Library={
    "Sciences Library",
    4,
    {monday,thursday,wednesday,thursday},
    {
    {//livre N°1
      "The C Programming Language",
      {//auteurs
        "Brian W. Kernighan","Dennis M. Ritchie"
      },
      2,"rentice Hall",1988,9780131103627
    },
    {//livre N°2
      "C: The Complete Reference",
      {//auteurs
        "Herbert Schildt"
      },
      1,"McGraw-Hill Education",2000,9780072121247
    }

    },2,
  };

  l_t Novel_Library={
    "Novel Library",
    4,
    {thursday,wednesday,thursday,friday},
    {
    {//livre N°1
      "Harry Potter and the Philosopher’s Stone",
      {//auteurs
        "J. K. Rowling"
      },
      1,"Bloomsbury",1997,9780747532699
    },
    {//livre N°2
      "Harry Potter and the Chamber of Secret",
      {//auteurs
        "J. K. Rowling"
      },
      1,"Bloomsbury",1998,9780747538493

    },
  },2,

  };

  Novel_Library.print();
  Sciences_Library.print();
  return 0;
}
