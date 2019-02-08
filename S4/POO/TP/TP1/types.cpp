#include <cstdio>
#include <climits>
#include <cfloat>
#include <cwchar>
int main() {
  printf("bool : %lu byte(s), %d to %d\n",sizeof(bool),false,true );
  printf("char : %lu byte(s), %d to %d\n",sizeof(char),CHAR_MIN,CHAR_MAX );
  printf("signed char : %lu byte(s), %d to %d\n",sizeof(signed char),SCHAR_MIN,SCHAR_MAX);
  printf("unsigned char : %lu byte(s), %d to %d\n",sizeof(unsigned char),0,UCHAR_MAX);
  printf("wchar_t : %lu byte(s), %d to %d\n",sizeof(wchar_t),WCHAR_MIN,WCHAR_MAX);
  printf("short : %lu byte(s), %d to %d\n",sizeof(short),SHRT_MIN,SHRT_MAX);
  printf("unsigned short : %lu byte(s), %d to %d\n",sizeof(unsigned short),0,USHRT_MAX);
  printf("int : %lu byte(s), %d to %d\n",sizeof(int),INT_MIN,INT_MAX);
  printf("unsigned int : %lu byte(s), %d to %u\n",sizeof(unsigned int),0,UINT_MAX);
  printf("long : %lu byte(s), %ld to %ld\n",sizeof(long),LONG_MIN,LONG_MAX);
  printf("unsigned long : %lu byte(s), %d to %lu\n",sizeof(unsigned long),0,ULONG_MAX);
  printf("float : %lu byte(s), %e to %e\n",sizeof(float),FLT_MIN,FLT_MAX);
  printf("double : %lu byte(s), %e to %e\n",sizeof(double),DBL_MIN,DBL_MAX);
  printf("long double : %lu byte(s), %Le to %Le\n",sizeof(long double),LDBL_MIN,LDBL_MAX);
  return 0;
}
