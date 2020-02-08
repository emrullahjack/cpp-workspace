// A console application for tracking the movements of an object on a coordinate
// system. Feel free to use it by all means. written by Emrullah Jack Oztosun.
#include <iostream>
#include <vector>

using namespace std;

class CoordinateSystem {
    int hLength;
    int vLength;
    vector<vector<char> > plain;

    public:

        int gethLength() {
            return hLength;
        }

        int getvLength() {
            return vLength;
        }

        vector<vector<char> > getplain() {
            return plain;
        }

        void setPointOnPlain(int x, int y, char r) {
            plain[y][x] = r;
        }

        CoordinateSystem(int horizontalLength, int verticalLength);

        void draw(); // Draw the coordinate system to the console
};

class Object {
    int hPosition;
    int vPosition;
    char representation;

    public:
        Object(int horizontalPosition, int verticalPosition, char representation);

        void initObject(CoordinateSystem *csp);  // Initalize the object on the coordinate system

        void moveObject(CoordinateSystem *csp); // Move the object on the coordinate system
};

CoordinateSystem::CoordinateSystem(int hLength, int vLength) {
    this->hLength = hLength;
    this->vLength = vLength;
    plain = vector<vector<char> >(vLength, vector<char> (hLength, ' '));

    for (int i = 0; i < hLength; i++) {
        if (i == 0)
            plain[vLength/2][i] = '<';
        else if (i == hLength - 1)
            plain[vLength/2][i] = '>';
        else
            plain[vLength/2][i] = '+';
    }

    for (int i = 0; i < vLength; i++) {
        if (i == 0)
            plain[i][hLength/2] = '^';
        else if (i == vLength - 1)
            plain[i][hLength/2] = 'v';
        else
            plain[i][hLength/2] = '+';
    }

}

void CoordinateSystem::draw() {
    system("clear");

    for (int i = 0; i < vLength; i++) {

        for (int j = 0; j < hLength; j++) {
            cout << plain[i][j] << " ";
        }

        cout << "\n";
    }
}

Object::Object(int hPosition, int vPosition, char representation) {
    this->hPosition = hPosition;
    this->vPosition = vPosition;
    this->representation = representation;
}

void Object::initObject(CoordinateSystem *csp) {
    csp->setPointOnPlain(hPosition, vPosition, representation);
}

// Make the object move on the given coordinate system
void Object::moveObject(CoordinateSystem *csp, char direction) {
    if (direction == 'i') {
        vPosition += 1;
        csp->setPointOnPlain(hPosition, vPosition, representation);
    }
}

int main(int argc, char const *argv[]) {
    CoordinateSystem cs(89, 46);
    CoordinateSystem *csp = &cs;
    cs.draw();
    Object o(5, 5, 'R');
    o.initObject(csp);

    cs.draw();
    cout << "\n";
    return 0;
}
