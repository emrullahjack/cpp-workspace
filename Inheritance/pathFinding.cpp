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

int main(int argc, char const *argv[]) {
  vector<vector<Location> > grid;
  vector<vector<Location> >::iterator it;

  int argrow, argcol = 20;

  it = grid.begin();
  for (int i = 1; i <= argrow; i++) {
    vector<Location> v;
    grid.insert(it, v);

    vector<Location>::iterator it1 = it->begin();
    for (int j = 1; j <= argcol; j++) {
      Location loc (i, j);
      it1->insert(it1, loc);
      it1++;
    }

    it++;
  }

  for (vector<vector<Location> >::iterator i = grid.begin(); i < grid.end(); i++) {

    for (vector<Location>::iterator j = i->begin(); j < i->end(); j++) {
      cout << "_ ";
      if (j == i->end() - 1) {
        cout << endl;
      }
    }

  }

  return 0;
}
