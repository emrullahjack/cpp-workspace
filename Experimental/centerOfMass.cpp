// Work in progress...

#include <iostream>
#include <vector>

using namespace std;

class Location {
private:
  int row, col;

public:
  Location ();
  Location (int arow, int acol);
  int getRow() {return row;}
  int getCol() {return col;}
};

Location::Location () {
  col = row = -5;
}

Location::Location(int arow, int acol) {
  row = arow;
  col = acol;
}

class Obj {
private:
  double mass;
  Location loc;

public:
  Obj (Location aloc);
};

Obj::Obj (Location aloc) {
  loc = aloc;
}

int centerOfMass(/* arguments */) {
  /* code */
  return 0;
}

// Driver code
int main(int argc, char const *argv[]) {


  return 0;
}
