#include <cstdio>
#include <vector>


struct book_t{
  char* name;
  std::vector<char*> authors;
  int nauthors;
  char* publisher;
  int year;
  long int isbn;

  book_t(){
    this->name = NULL;
    this->nauthors = 0;
    this->publisher = NULL;
    this->year = 0;
    this->isbn = 0;
  }

  ~book_t(){

  }
  void add_author(char* author){
    this->nauthors++;
    this->authors.resize(this->nauthors);
    this->authors[this->nauthors-1] = author;
  }
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
  char* name;
  int ndays;
  std::vector<char*> days;
  std::vector<book_t> books;
  int nbooks;

  library_t(){
    this->name = NULL;
    this->ndays = 0;
    this->nbooks = 0;
  }

  ~library_t(){

  }

  void add_day(char* day){
    this->ndays++;
    this->days.resize(this->ndays);
    this->days[this->ndays-1] = day;
  }

  void add_book(book_t book){
    this->nbooks++;
    this->books.resize(this->nbooks);
    this->books[this->nbooks-1] = book;
  }
  void print(){
    printf("%s\n",this->name);
    for (int i = 0; i < this->ndays; i++) {
      printf("%s,",(char*) this->days[i]);
    }
    printf("\n");
    for (int i = 0; i < this->nbooks; i++) {
      this->books[i].print();
    }
  }
};

int main(int argc, char const *argv[]) {
  library_t Sciences_Library;
  library_t Novel_Library;

  book_t SlBook1;
  book_t SlBook2;
  book_t NlBook1;
  book_t NlBook2;

  Sciences_Library.name = (char*)"Sciences Library";
  Sciences_Library.add_day((char*)"monday");
  Sciences_Library.add_day((char*)"tuesday");
  Sciences_Library.add_day((char*)"wednesday");
  Sciences_Library.add_day((char*)"thursday");

  Novel_Library.name = (char*)"Novel Library";
  Novel_Library.add_day((char*)"tuesday");
  Novel_Library.add_day((char*)"wednesday");
  Novel_Library.add_day((char*)"thursday");
  Novel_Library.add_day((char*)"friday");

  SlBook1.name = (char*)"The C Programming Language";
  SlBook1.add_author((char*)"Brian W. Kernighan");
  SlBook1.add_author((char*)"Dennis M. Ritchie");
  SlBook1.publisher = (char*)"rentice Hall";
  SlBook1.year = 1988;
  SlBook1.isbn = 9780131103627;

  SlBook2.name = (char*)"C: The Complete Reference";
  SlBook2.add_author((char*)"Herbert ScThe C Programming Language");
  SlBook2.publisher = (char*)"McGraw-Hill Education";
  SlBook2.year = 2000;
  SlBook2.isbn = 9780072121247;

  NlBook1.name = (char*)"Harry Potter and the Philosopher’s Stone";
  NlBook1.add_author((char*)"J. K. Rowling");
  NlBook1.publisher = (char*)"Bloomsbury";
  NlBook1.year = 1997;
  NlBook1.isbn = 9780747532699;

  NlBook2.name = (char*)"Harry Potter and the Chamber of Secret";
  NlBook2.add_author((char*)"J. K. Rowling");
  NlBook2.publisher = (char*)"Bloomsbury";
  NlBook2.year = 1998;
  NlBook2.isbn = 9780747538493;

  Sciences_Library.add_book(SlBook1);
  Sciences_Library.add_book(SlBook2);

  Novel_Library.add_book(NlBook1);
  Novel_Library.add_book(NlBook2);

  Novel_Library.print();
  Sciences_Library.print();
  return 0;
}
