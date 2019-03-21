#include <cstdio>
#include <cstdlib>


class person_t{
  char* firstname;
  char* lastname;

  public :person_t(char* firstname, char* lastname){
    this->firstname = firstname;
    this->lastname = lastname;
  }
  char* get_firstname(){
    return this->firstname;
  }
  char* get_lastname(){
    return this->lastname;
  }
  public :void print(){
    printf("%s\n",this->firstname);
    printf("%s\n",this->lastname);
  }
};

class course_t{
  char* name;
  public :course_t(){
    this->name = NULL;
  }
  public :course_t(char* name){
    this->name = name;
  }
  public :char* get_name(){
    return this->name;
  }
};

class student_t : public person_t{
  course_t *courses;
  int ncourses;
  public :student_t(char* firstname, char* lastname) : person_t(firstname,lastname){
    this->courses = (course_t*) malloc(sizeof(course_t));
    this->courses = NULL;
    this->ncourses = 0;
  }
  ~student_t(){
    delete this->courses
  }
  public :void add_course(course_t course){
    this -> ncourses ++;
    this -> courses = (course_t*) realloc(this -> courses,sizeof(course_t*)*this -> ncourses);
    this -> courses[this -> ncourses-1] = course;

  }
  public :void print(){
    printf("%s\n", this->get_firstname());
    printf("%s\n", this->get_lastname());
    for (int i = 0; i < this->ncourses; i++) {
      printf("%s\n", this->courses[i].get_name());
    }
  }

};

int main(int argc, char const *argv[]) {
  student_t jb((char*)"Jean",(char*)"Bon"),pe((char*)"Paul",(char*)"Emploi"),aa((char*)"Anne",(char*)"Alyse");
  course_t tp((char*)"Techniques de Programmation"),poo((char*)"Programmation orienté objet"),too((char*)"technologie orienté objet");
  jb.add_course(tp);
  pe.add_course(tp);
  aa.add_course(tp);
  pe.add_course(poo);
  aa.add_course(poo);
  aa.add_course(too);
  jb.print();
  pe.print();
  aa.print();
  return 0;
}
