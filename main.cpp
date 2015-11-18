#include "proy_lib.h"

#define ESCAPE 27

using namespace vision;

/** @function main */
int main( int argc, char** argv )
{
   // matchSURF("baboon200_rotated.jpg", "baboon200.jpg");
    matchORB("baboon200_rotated.jpg", "baboon200.jpg");
    cout<<"Funcionamiento correcto"<<endl;
}

