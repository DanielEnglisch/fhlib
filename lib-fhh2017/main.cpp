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

};

//Overloading of << for class Vec3
std::ostream& operator<<(ostream& stream, const Vec3i& other) {
	stream << "[" << other.x << ", " << other.y << ", " << other.z << "]";
	return stream;
}

void addVectorsTo(LinkedList<Vec3i>*& vecs) {
	vecs->add(Vec3i(1,2,3));
	vecs->add(Vec3i(4, 5, 6));
	vecs->add(Vec3i(7, 8, 9));
}

int main() {

	LinkedList<Vec3i>* vectors = new LinkedList<Vec3i>();
	addVectorsTo(vectors);

	LinkedList<Vec3i>::Node* obj = 0;

	for (obj = vectors->Begin(); obj != nullptr; vectors->Next(obj)) {
		obj->data.x += 1;
		obj->data.y += 1;
		obj->data.z += 1;
		cout << "Vec: " << obj->data << endl;
	}
	cin.get();

	return  0;
}