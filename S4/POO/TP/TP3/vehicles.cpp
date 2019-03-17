#include <cstdio>

class vehicles_t{
  public :float fuel,fuel_cons,fuel_max;
  public :char* name;
  public : vehicles_t(char* name,float f,float f_c,float f_m){
      this->fuel = f;
      this->fuel_cons = f_c;
      this->fuel_max = f_m;
      this->name = name;
  }
  bool move(float km){
    if (km>0 and (km*this->fuel_cons/100)<this->fuel) {
      this->fuel -= (km*this->fuel_cons/100);
      printf("car moved (%.2f km).\n",km);
      return true;
    }else{
      printf("unable to move the car (%.2f)\n", km);
      return false;
    }
  }
  bool refuel(float l){
    if (this->fuel+l>this->fuel_max) {
      return false;
    }else{
     this->fuel += l;
     return true;
    }
  }
  virtual void print() = 0;

  float get_fuel(){
    return this->fuel;
  }
  float get_fuel_cons(){
    return this->fuel_cons;
  }
  float get_fuel_max(){
    return this->fuel_max;
  }
  char* get_name(){
    return this->name;
  }
};

class car_t : public vehicles_t{
  public :bool hand_brake_enable;

  public :car_t(char* name,float fuel,float fuel_cons,float fuel_max,bool hand_brake_enable): vehicles_t(name,fuel,fuel_cons,fuel_max){
    this->hand_brake_enable = hand_brake_enable;
  }
  public :void set_hand_brake_enable(bool hand_brake_enable){
    this->hand_brake_enable = hand_brake_enable;
  }
  public :bool move(float km){
    if (this->hand_brake_enable) {
      printf("unable to move the car (%.2f)\n", km);
      return false;
    }else{
      return(vehicles_t::move(km));
    }
  }
  public :void print(){
    printf("Car (%s, %.2f/%.2f l, %.2f l/100 km, hand brake: %d)\n", this->name, this->fuel, this->fuel_max, this->fuel_cons, this->hand_brake_enable);
  }
};

int main(int argc, char const *argv[]) {
  car_t mca((char*)"Mercedes A-Class",1.7,11,2.10,0);
  car_t bmw((char*)"BMW X4",57.2,11.30,65,0);
  mca.print();
  mca.move(1);
  mca.print();
  mca.move(100);
  mca.print();
  bmw.print();
  bmw.move(1);
  bmw.print();
  bmw.move(100);
  bmw.print();
  bmw.set_hand_brake_enable(1);
  bmw.print();
  bmw.move(100);
  bmw.print();
  mca.refuel(0.51);
  bmw.refuel(19.21);
  mca.print();
  bmw.print();
  return 0;
}
