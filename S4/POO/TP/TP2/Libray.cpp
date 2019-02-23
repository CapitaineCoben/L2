#include <cstdio>

   struct book_t{
		char *name;
		char **authors;
		int nauthors;
		char *publisher;
		int year;
		long int isbn;
    void print(){
      printf("Titre : %s\n", this->name);
      printf("Ecrit par : ");
      for (int i = 0; i < this->nauthors; ++i){printf("%s\n", this->authors[i]);}
      printf("Edition : %s\n", this->publisher);
      printf("Année : %d\n", this->year);
      printf("ISBN : %ld\n", this->isbn);
    }
	};


	 enum day_e{
		monday,tuesday,wednesday,thursday,friday,saturday,sunday
	};


	 struct library_t{
		char *name;
		int ndays;
		day_e *days;
		book_t *books;
		int nbooks;
    void print(){
      printf("biliothèque : %s\n", this->name);
      printf("ouverte %d jours sur 7\n", this->ndays);
      printf("jours d'ouverture : ");
      for (int i = 0; i < this->ndays; ++i){
        switch(this->days[i]){
          case 0: printf("monday, ");break;
          case 1: printf("tuesday, ") ;break;
          case 2: printf("wednesday, ") ;break;
          case 3: printf("thursday, ") ;break;
          case 4: printf("friday, ") ;break;
          case 5: printf("saturday, ") ;break;
          case 6: printf("sunday,") ;break;
          default : fprintf(stderr, "invalid day value\n");
        }
      }
      printf("\n");
      printf("nombre de livres en stock : %d\n", this->nbooks);
      for (int i = 0; i < this->nbooks; ++i)
      {
        printf("livre N°%d:\n", i+1);
        this->books->print();
      }
    }
	};

int main(int argc, char const *argv[]) {
  return 0;
}
