#include <QCoreApplication>
#include "Firebase.hpp"
int main(int argc, char *argv[]) {
	QCoreApplication a(argc, argv);
	Firebase fb;
	QFile csvFile("C:/Users/YIQ25/Documents/Academics/ECE1140/Prototypes/firebase/Blueline.csv");
	fb.getJsonDocFromCsvFile(csvFile);
	return a.exec();
}
