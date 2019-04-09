#include <cstdio>
#include <vector>

class doc_t{
  char* name;
  int year;

  public : doc_t(){
    this->name = NULL;
    this->year = 0;
  }
  public : char* get_name(){
    return this->name;
  }
  public : int get_year(){
    return this->year;
  }
  public : void set_name(char* name){
    this->name = name;
  }
  public : void set_year(int year){
    this->year = year;
  }
  public :virtual void print()=0;

};

class audio_doc_t : public virtual doc_t{
  int duration;
  public : audio_doc_t(){
    this->duration = 0;
  }
  public : int get_duration(){
    return this->duration;
  }
  public : void set_duration(int duration){
    this->duration = duration;
  }
  public :virtual void print()=0;

};

class textual_doc_t : public virtual doc_t{
  public :virtual void print()=0;
};

class video_doc_t : public  doc_t{
  int duration;
  bool color_available;
  public : video_doc_t(){
    this->duration = 0;
    this->color_available = false;
  }
  public : int get_duration(){
    return this->duration;
  }
  public : bool get_color_available(){
    return this->color_available;
  }
  public : void set_duration(int duration){
    this->duration = duration;
  }
  public : void set_color_available(bool color_available){
    this->color_available = color_available;
  }
  public :virtual void print()=0;
};

class audio_tape_t : public audio_doc_t{
  public : void print(){
    printf("audio_tape_t(%s,%d,%d)",this->get_name(),this->get_year(),this->get_duration());
  }
};

class audio_cd_t : public audio_doc_t{
  public : void print(){
    printf("audio_cd_t(%s,%d,%d)",this->get_name(),this->get_year(),this->get_duration());
  }
};

class book_t : public textual_doc_t{
  std::vector<char*> authors;
  int nauthors;
  char* publisher;
  long int isbn;

  public : book_t(){
    this->nauthors = 0;
    this->publisher = NULL;
    this->isbn = 0;
  }
  // public : void set_name(char* name){
  //   this->name = name;
  // }
  // public : void set_year(int year){
  //   this->year = year;
  // }
  public : void set_nauthors(int nauthors){
    this->nauthors = nauthors;
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
  public : void print(){
    printf("book_t(%s,",this->get_name() );
    printf("),");
    printf("%s,",this->publisher );
    printf("%d,", this->get_year());
    printf("%ld,", this->isbn);
  }
};

class newspaper_t : public textual_doc_t{
  char* publisher;
  long int issn;
  public : newspaper_t(){
    this->publisher = NULL;
    this->issn = 0;
  }
  char* get_publisher(){
    return this->publisher;
  }
  public : long int get_issn(){
    return this->issn;
  }
  public : void set_publisher(char* publisher){
    this->publisher = publisher;
  }
  public : void set_issn(long int issn){
    this->issn = issn;
  }
  public : void print(){
    printf("newspaper_t(%s,%d,%s,%ld)",this->get_name(),this->get_year(),this->publisher,this->issn);
  }
};

class video_tape_t : public video_doc_t{
  public : void print(){
    printf("video_tape_t(%s,%d,%d,%d)",this->get_name(),this->get_year(),this->get_duration(),this->get_color_available());
  }
};

class dvd_t : public video_doc_t{
  public : void print(){
    printf("dvd_t(%s,%d,%d,%d)",this->get_name(),this->get_year(),this->get_duration(),this->get_color_available());
  }
};

class blu_ray_t : public video_doc_t{
  public : void print(){
    printf("blu_ray_t(%s,%d,%d,%d)",this->get_name(),this->get_year(),this->get_duration(),this->get_color_available());
  }
};

class audio_text_t :public audio_doc_t, textual_doc_t{
  public : void print(){
    printf("audio_text_t(%s,%d,%d)",this->get_name(),this->get_year(),this->get_duration());
  }
};

class library_t : public doc_t{
  char* name;
  int ndays;
  std::vector<char*> days;
  std::vector<doc_t*> docs;
  int ndocs;

  public : library_t(){
    this->name = NULL;
    this->ndays = 0;
    this->ndocs = 0;
  }

  public : void set_name(char* name){
    this->name = name;
  }
  public : void set_ndays(int ndays){
    this->ndays = ndays;
  }
  public : void set_nbooks(int nbooks){
    this->ndocs = ndocs;
  }
  public : void add_day(char* day){
    this->ndays++;
    this->days.resize(this->ndays);
    this->days[this->ndays-1] = day;
  }

  public : void add_doc(doc_t* doc){
    this->ndocs++;
    this->docs.resize(this->ndocs);
    this->docs[this->ndocs-1] = doc;
  }
  public : void print(){
    printf("library_t(%s,",this->name);
    for (int i = 0; i < this->ndays; i++) {
      printf("%s,",(char*) this->days[i]);
    }
    printf(")\n");
    for (int i = 0; i < this->ndocs; i++) {
      this->docs[i]->print();
      printf("\n");
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
  audio_tape_t audioTape1;
  audio_cd_t audioCD1;
  newspaper_t newspaper1;
  video_tape_t videoTape1;
  dvd_t dvd1;
  blu_ray_t bluray1;
  audio_text_t audioText1;

  doc_t* p_SlBook1 = &SlBook1;
  doc_t* p_SlBook2 = &SlBook2;
  doc_t* p_NlBook1 = &NlBook1;
  doc_t* p_NlBook2 = &NlBook2;
  doc_t* p_audioTape1 = &audioTape1;
  doc_t* p_audioCD1 = &audioCD1;
  doc_t* p_newspaper1 = &newspaper1;
  doc_t* p_videoTape1 = &videoTape1;
  doc_t* p_dvd1 = &dvd1;
  doc_t* p_bluray1 = &bluray1;
  doc_t* p_audioText1 = &audioText1;


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

  audioTape1.set_name((char*)"Killers");
  audioTape1.set_year(1981);
  audioTape1.set_duration(2298);

  audioCD1.set_name((char*)"The Book of Souls");
  audioCD1.set_year(2015);
  audioCD1.set_duration(5531);

  newspaper1.set_name((char*)"The Guardian");
  newspaper1.set_year(1821);
  newspaper1.set_publisher((char*)"Guardian Media Group");
  newspaper1.set_issn(02613077);

  videoTape1.set_name((char*)"Aladdin");
  videoTape1.set_year(1992);
  videoTape1.set_duration(5400);
  videoTape1.set_color_available(true);

  dvd1.set_name((char*)"The Lion King");
  dvd1.set_year(1994);
  dvd1.set_duration(5280);
  dvd1.set_color_available(true);

  bluray1.set_name((char*)"Zootopia");
  bluray1.set_year(2016);
  bluray1.set_duration(6480);
  bluray1.set_color_available(true);

  audioText1.set_name((char*)"Harry Potter and the Philosopher's Stone");
  audioText1.set_year(1997);
  audioText1.set_duration(18000);




  Sciences_Library.add_doc(p_SlBook1);
  Sciences_Library.add_doc(p_SlBook2);

  Novel_Library.add_doc(p_NlBook1);
  Novel_Library.add_doc(p_NlBook2);
  Novel_Library.add_doc(p_audioTape1);
  Novel_Library.add_doc(p_audioCD1);
  Novel_Library.add_doc(p_newspaper1);
  Novel_Library.add_doc(p_videoTape1);
  Novel_Library.add_doc(p_dvd1);
  Novel_Library.add_doc(p_bluray1);
  Novel_Library.add_doc(p_audioText1);

  Novel_Library.print();
  Sciences_Library.print();
  return 0;
}
