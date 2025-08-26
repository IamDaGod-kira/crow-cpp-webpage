#include <iostream>
#include "crow_all.h"
using namespace std;

int main() {
	crow::SimpleApp app;

	CROW_ROUTE(app, "/")([]{
		auto file = crow::mustache::load_text("index.html");
		return file;
		
});

	app.port(8080).multithreaded().run();
}
