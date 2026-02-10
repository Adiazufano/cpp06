#include <iostream>
#include "Serializer.hpp"

int main() {
	Data myData;
	myData.id = 42;
	myData.name = "test_1";

	Data* ptrOriginal = &myData;
	
	uintptr_t raw = Serializer::serialize(ptrOriginal);
	
	Data* ptrFinal = Serializer::deserialize(raw);

	cout << "--- Verificación de Direcciones ---" << endl;
	cout << "Dirección Original (ptr):    " << ptrOriginal << endl;
	cout << "Valor Serializado (raw):     " << raw << " (decimal)" << endl;
	cout << "Dirección Final (deser):     " << ptrFinal << endl;

	cout << "\n--- Verificación de Datos ---" << endl;
	if (ptrOriginal == ptrFinal) {
		cout << "✅ ÉXITO: Los punteros son idénticos." << endl;
		cout << "ID:    " << ptrFinal->id << endl;
		cout << "Name:  " << ptrFinal->name << endl;
	} else {
		cout << "❌ ERROR: El puntero ha cambiado durante el proceso." << std::endl;
	}
	return 0;
}