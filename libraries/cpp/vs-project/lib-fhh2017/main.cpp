#include "lib-fhh2017.h"
#include <string>

using namespace std;

struct Vec3i {
	int x, y, z;

	Vec3i()
		: x(-1), y(-1), z(-1)
	{}

	Vec3i(int x, int y, int z)
	: x(x), y(y), z(z)
	{}


	void operator+=(Vec3i& other) {
		x += other.x;
		y += other.y;
		z += other.z;
	}

	void operator+=(int other) {
		x += other;
		y += other;
		z += other;
	}


};

//Overloading of << for class Vec3
ostream& operator<<(ostream& stream, const Vec3i& other) {
	stream << "[" << other.x << ", " << other.y << ", " << other.z << "]";
	return stream;
}

void addVectorsTo(LinkedList<Vec3i>*& vecs) {
	vecs->add({ 1, 2, 3 });
	vecs->add({ 4, 5, 6 });
	vecs->add({ 7, 8, 9 });
}

int main() {

	LinkedList<Vec3i>* vectors = new LinkedList<Vec3i>();
	addVectorsTo(vectors);

	LinkedList<Vec3i>::Node* obj = 0;
	cin.get();

	for (obj = vectors->Begin(); obj != nullptr; vectors->Next(obj)) {
		obj->data += 1;
		cout << "Vec: " << obj->data << endl;
	}
	cin.get();

	return  0;
}