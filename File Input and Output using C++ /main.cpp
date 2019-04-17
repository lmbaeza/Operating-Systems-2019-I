#include <iostream>
#include <fstream>
#include <string>

using std::string;

using std::cout;
using std::endl;

using std::ifstream;
using std::ios;
using std::ofstream;

struct People {
    string name;
    int age;
    float weight;
};

void load(void *ap) {
    struct People * ptr = (struct People*)ap;
    ptr->name = "Luis Miguel Baez Aponte";
    ptr->age = 20;
    ptr->weight = 67.8;
}

void write(void * ap) {
    struct People * people = (struct People*)ap;

    ofstream out("dataStruct.dat");
    out.write((char *)people, sizeof(People));
    out.flush();
}

void read(void * ap) {
    struct People * people_read = (struct People*)ap;

    ifstream in("dataStruct.dat");
    in.read((char *)people_read, sizeof(People));
    in.close();
}

int main(int argc, char *argv[]) {
    struct People p;
    struct People *people = &p;

    load(people);
    write(people);   

    struct People p1;
    struct People *people_read = &p1;

    read(people_read);

    cout << people_read->name <<" - "<<people_read->age<<" - "<<people_read->weight<< endl;
    //Luis Miguel Baez Aponte - 20 - 67.8

    return 0;
}