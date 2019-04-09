#include <cstdio>
#include <vector>


class book_t{
  char* name;
  std::vector<char*> authors;
  int nauthors;
  char* publisher;
  int year;
  long int isbn;

  public : book_t(){
    this->name = NULL;
    this->nauthors = 0;
    this->publisher = NULL;
    this->year = 0;
    this->isbn = 0;
  }

  public :~book_t(){
  }
  public : void set_name(char* name){
    this->name = name;
  }
  public : void set_nauthors(int nauthors){
    this->nauthors = nauthors;
  }
  public : void set_year(int year){
    this->year = year;
  }
  public : void set_isbn(long int isbn){
    this->isbn = isbn;
  }
  public : void set_publisher(char* publisher){
    this->publisher = publisher;
  }
  public : void add_author(char* author){
    this->nauthors++;
    this->authors.resize(this->nauthors);
    this->authors[this->nauthors-1] = author;
  }
  public :const void print(){
    printf("%s\n",this->name );
    for (int i = 0; i < this->nauthors; i++) {
      printf("%s\n", this->authors[i]);
    }
    printf("%s\n",this->publisher );
    printf("%d\n", this->year);
    printf("%ld\n", this->isbn);
  }
};

class library_t{
  char* name;
  int ndays;
  std::vector<char*> days;
  std::vector<book_t> books;
  int nbooks;

  public : library_t(){
    this->name = NULL;
    this->ndays = 0;
    this->nbooks = 0;
  }

  public :~library_t(){
  }

  public : void set_name(char* name){
    this->name = name;
  }
  public : void set_ndays(int ndays){
    this->ndays = ndays;
  }
  public : void set_nbooks(int nbooks){
    this->nbooks = nbooks;
  }
  public : void add_day(char* day){
    this->ndays++;
    this->days.resize(this->ndays);
    this->days[this->ndays-1] = day;
  }

  public : void add_book(book_t book){
    this->nbooks++;
    this->books.resize(this->nbooks);
    this->books[this->nbooks-1] = book;
  }
  public :const void print(){
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

  Sciences_Library.set_name((char*)"Sciences Library");
  Sciences_Library.add_day((char*)"monday");
  Sciences_Library.add_day((char*)"tuesday");
  Sciences_Library.add_day((char*)"wednesday");
  Sciences_Library.add_day((char*)"thursday");

  Novel_Library.set_name((char*)"Novel Library");
  Novel_Library.add_day((char*)"tuesday");
  Novel_Library.add_day((char*)"wednesday");
  Novel_Library.add_day((char*)"thursday");
  Novel_Library.add_day((char*)"friday");

  SlBook1.set_name((char*)"The C Programming Language");
  SlBook1.add_author((char*)"Brian W. Kernighan");
  SlBook1.add_author((char*)"Dennis M. Ritchie");
  SlBook1.set_publisher((char*)"rentice Hall");
  SlBook1.set_year(1988);
  SlBook1.set_isbn(9780131103627);

  SlBook2.set_name((char*)"C: The Complete Reference");
  SlBook2.add_author((char*)"Herbert ScThe C Programming Language");
  SlBook2.set_publisher((char*)"McGraw-Hill Education");
  SlBook2.set_year(2000);
  SlBook2.set_isbn(9780072121247);

  NlBook1.set_name((char*)"Harry Potter and the Philosopher’s Stone");
  NlBook1.add_author((char*)"J. K. Rowling");
  NlBook1.set_publisher((char*)"Bloomsbury");
  NlBook1.set_year(1997);
  NlBook1.set_isbn(9780747532699);

  NlBook2.set_name((char*)"Harry Potter and the Chamber of Secret");
  NlBook2.add_author((char*)"J. K. Rowling");
  NlBook2.set_publisher((char*)"Bloomsbury");
  NlBook2.set_year(1998);
  NlBook2.set_isbn(9780747538493);

  Sciences_Library.add_book(SlBook1);
  Sciences_Library.add_book(SlBook2);

  Novel_Library.add_book(NlBook1);
  Novel_Library.add_book(NlBook2);

  Novel_Library.print();
  Sciences_Library.print();
  return 0;
}
