// A console application for tracking the movements of an MapObject on a coordinate
// system. Feel free to use it by all means. written by Emrullah Jack Oztosun.
#include <iostream>
#include <vector>
#include <unistd.h>
#include <ctype.h>

#define PAST_POSITION_MAX 4

using namespace std;

class CoordinateSystem {
    int hLength;
    int vLength;
    vector<vector<char> > plain;

    public:

        int getHLength() {
            return hLength;
        }

        int getVLength() {
            return vLength;
        }

        vector<vector<char> > getplain() {
            return plain;
        }

        void setPointOnPlain(int x, int y, char r) {
            plain[y][x] = r;
        }

        void clearPointOnPlain(int x, int y) {
            plain[y][x] = ' ';
        }

        CoordinateSystem(int horizontalLength, int verticalLength);
        void draw(); // Draw the coordinate system to the console
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

class MapObject {
    int hPosition;
    int vPosition;
    char representation;

    int pastHPositions[PAST_POSITION_MAX] = {-1, -1, -1, -1};
    int pastVPositions[PAST_POSITION_MAX] = {-1, -1, -1, -1};
    int pastPositionCounter;

    public:

        void incrementPastCounter() {
            pastHPositions[pastPositionCounter] = hPosition;
            pastVPositions[pastPositionCounter] = vPosition;
            pastPositionCounter = (pastPositionCounter + 1) % PAST_POSITION_MAX;
        }

        void setPastPosition(CoordinateSystem *csp) {

            if (pastHPositions[pastPositionCounter] != -1) { // something going wrong here in this method
                csp->setPointOnPlain(pastHPositions[i], pastVPositions[i], tolower(representation));
            }

            if (pastHPositions[(pastPositionCounter + 1) % PAST_POSITION_MAX] != -1) {
                csp->clearPointOnPlain(pastHPositions[(pastPositionCounter + 1) % PAST_POSITION_MAX], pastVPositions[(pastPositionCounter + 1) % PAST_POSITION_MAX]);
            }
        }

        MapObject(int horizontalPosition, int verticalPosition, char representation);
        void initMapObject(CoordinateSystem *csp);  // Initalize the MapObject on the coordinate system
        void moveMapObject(CoordinateSystem *csp, char direction); // Move the MapObject on the coordinate system
};

MapObject::MapObject(int hPosition, int vPosition, char representation) {
    this->hPosition = hPosition;
    this->vPosition = vPosition;
    this->representation = representation;
    pastPositionCounter = 4;
}

void MapObject::initMapObject(CoordinateSystem *csp) {
    csp->setPointOnPlain(hPosition, vPosition, representation);
}

// Make the MapObject move on the given coordinate system
void MapObject::moveMapObject(CoordinateSystem *csp, char direction) {
    if (direction == 'i') {
        incrementPastCounter();
        vPosition -= 1;
        csp->setPointOnPlain(hPosition, vPosition, representation);
        setPastPosition(csp);
    } else if (direction == 'u') {
        incrementPastCounter();
        hPosition -= 1;
        vPosition -= 1;
        csp->setPointOnPlain(hPosition, vPosition, representation);
        setPastPosition(csp);
    } else if (direction == 'j') {
        incrementPastCounter();
        hPosition -= 1;
        csp->setPointOnPlain(hPosition, vPosition, representation);
        setPastPosition(csp);
    } else if (direction == 'm') {
        incrementPastCounter();
        hPosition -= 1;
        vPosition += 1;
        csp->setPointOnPlain(hPosition, vPosition, representation);
        setPastPosition(csp);
    } else if (direction == ',') {
        incrementPastCounter();
        vPosition += 1;
        csp->setPointOnPlain(hPosition, vPosition, representation);
        setPastPosition(csp);
    } else if (direction == '.') {
        incrementPastCounter();
        hPosition += 1;
        vPosition += 1;
        csp->setPointOnPlain(hPosition, vPosition, representation);
        setPastPosition(csp);
    } else if (direction == 'l') {
        incrementPastCounter();
        hPosition += 1;
        csp->setPointOnPlain(hPosition, vPosition, representation);
        setPastPosition(csp);
    } else if (direction == 'o') {
        incrementPastCounter();
        hPosition += 1;
        vPosition -= 1;
        csp->setPointOnPlain(hPosition, vPosition, representation);
        setPastPosition(csp);
    } else {
        printf("%s\n", "Err: invalid input to move MapObject");
    }
}

int main(int argc, char const *argv[]) {
    CoordinateSystem cs(89, 46);
    CoordinateSystem *csp = &cs;
    cs.draw();
    MapObject o(5, 5, 'T');
    o.initMapObject(csp);

    while (true) {
      o.moveMapObject(csp, '.');
      cs.draw();
      cout << "\n";
      sleep(1);
    }

    return 0;
}
