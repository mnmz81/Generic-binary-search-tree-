#include "Simulation.h"
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip> 
#include <cstring>
#include <stdlib.h>


using namespace std;

void error() {
    cerr << "ERROR: Invalid input."<<endl;
    exit(1);
}

int main(int argc, char *argv[])
{
    if (argc != 3) error();
    Simulation a(argv[1],argv[2]);
    a.Run();
    return 0;
}
