#include <cstdio>

class shape_t{
  public :float width;
  public :float height;
  public : shape_t(float w,float h){
    this->width = w;
    this->height = h;
  }
  public : float get_height() const
  {
    return this->height;
  }
  public : float get_width() const
  {
    return this->width;
  }
  public :vitual void print(){
    printf("Shape\n");
    printf("largeur : %f\n",this->width);
    printf("heuteur : %f\n",this->height);
  }  // delete formePtr
  // delete rectanglePtr;
  // delete trianglePtr;
  // delete cerclePtr;
};
class rectangle_t: public shape_t{
  public :rectangle_t(float w,float h): shape_t(w,h){
  }
  public :void print(){
    printf("Rectangle\n");
    printf("largeur : %f\n",this->width);
    printf("heuteur : %f\n",this->height);
  }
};
class triangle_t: public shape_t{
  public :triangle_t(float w,float h): shape_t(w,h){
  }
  public :void print(){
    printf("Triangle\n");
    printf("largeur : %f\n",this->width);
    printf("heuteur : %f\n",this->height);
  }
};
class circle_t: public shape_t{
  float diameter;
  public :circle_t(float d): shape_t(d,d){
    this->diameter = d;
  }
  public :void print(){
    printf("Cercle\n");
    printf("diametre : %f\n",this->diameter);
  }
};
int main(int argc, char const *argv[]) {
//  shape_t forme(2.5,3.6);
  // rectangle_t rectangle(10,20);
  // triangle_t triangle(30,30);
  // circle_t cercle(40);
  shape_t * formePtr =new shape_t(2.5,3.6);
  shape_t * rectanglePtr =new rectangle_t(10,20);
  shape_t * trianglePtr =new triangle_t(30,30);
  shape_t * cerclePtr =new circle_t(40);
  // formePtr = &forme;
  // rectanglePtr = &rectangle;
  // trianglePtr = &triangle;
  // cerclePtr = &cercle;
  formePtr->print();
  rectanglePtr->print();
  trianglePtr->print();
  cerclePtr->print();
  // delete formePtr
  // delete rectanglePtr;
  // delete trianglePtr;
  // delete cerclePtr;
  return 0;
}
