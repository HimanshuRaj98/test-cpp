#include<iostream.h>
#include<conio.h>
int main()
{
  while(!kbhit())
   cout<<" you haven't pressed a key.\n";
  return 0;
}
